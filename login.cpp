#include "login.h"

Login::Login() {
    //Crea el directorio de los archivos por defecto
    system(string(MKDIR).c_str());
    crearArchivosDefecto();
    menuLogin();
}

void Login::menuLogin() {
    string opc;
    do {
        system("clear");
        cout << "*** Login de Academicos ***" << endl << endl;
        cout << "1) Iniciar sesion." << endl;
        cout << "0) Salir..." << endl << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "1" and opc != "0");
        if(opc == "1") {
            Usuario auxUsuario;
            string username, password;
            cout << endl << "Ingrese el username: ";
            getline(cin, username);
            cout << "Ingrese la contraseña: ";
            getline(cin, password);
            buscarUsuario(username, password);
        } else {
            cout << endl << "Gracias por usar el administrador de academicos." << endl << endl;
        }
        pausa();
    } while(opc != "0");
}

void Login::buscarUsuario(const std::string& username, const std::string& password) {
    ifstream file(string(DIR) + string(ARCH_USR));
    if(!file.good()){
        return;
    }
    //Posible implementacion del arbol paginado, para busquedas de usuarios
    Usuario usuario;
    bool existe = false;
    while(!file.eof()){
        Usuario usr;
        file.read((char*)&usr, sizeof(Usuario));
        if(file.eof()){break;}

        //Si el usuario y la contraseña leidos del archivo, son iguales
        if(usr.getUsername() == username and usr.getPassword() == password){
            usuario = usr;
            existe = true;
        }
    }

    if(existe){
        //Login de usuario existente
        Academico academico;
        ifstream file_academico(string(DIR) + string(ARCH_AC));
        if(!file_academico){
            cout << "No existe el archivo.";
            file_academico.close();
            return;
        }
        else{
            file_academico.seekg(usuario.getDireccionFisica(), ios::beg);
            file_academico.read((char*)&academico, sizeof(Academico));
        }
        file_academico.close();
        if(std::string(usuario.getTipo()) == "Admin"){
            //Inicia menu de administrador
            new MenuAdmin(academico, usuario);
        }
        else{
            //Inicia menu de usuario normal
            new MenuUsr(academico, usuario);
        }
    }
    //Evita Login de usuario inexistente
    else{
        cout << "No existe el usuario. Intente de nuevo." << endl;
    }
}

void Login::crearArchivosDefecto() {
    //Si no existe el archivo crea nuevos archivos
    ifstream archivo_academicos(string(DIR) + string(ARCH_AC));
    if(archivo_academicos.good()){
       archivo_academicos.close();
       return;
    }
    archivo_academicos.close();

    //Crea nuevo academico Administrador en caso de no existir el documento
    ofstream arch_academicos_nuevo(string(DIR) + string(ARCH_AC));
    Academico ac_admin;
    ac_admin.setNombre("Administrador");
    arch_academicos_nuevo.write((char*)&ac_admin, sizeof(Academico));
    long int direccionFisica = arch_academicos_nuevo.tellp();
    direccionFisica -= sizeof(Academico);
    arch_academicos_nuevo.close();
    //Crea nuevo usuario Administrador
    int noReg = 0;
    Usuario usuario(++noReg, "admin", "admin", "Admin", direccionFisica);
    ofstream file_usuario(string(DIR) + string(ARCH_USR));
    file_usuario.write((char*)&usuario, sizeof(Usuario));
    file_usuario.close();
    //Crea el archivo de contador Por si no existia
    ofstream file_reg(string(DIR) + string(ARCH_NO_REG));
    file_reg.write((char*)&noReg, sizeof(int));
    file_reg.close();
}

void Login::pausa() {
    cout << endl << "Presione [enter] para continuar... " << endl << endl;
    cin.ignore();
}

Login::~Login() {
    //dtor
}
