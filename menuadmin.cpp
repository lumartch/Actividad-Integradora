#include "menuadmin.h"

MenuAdmin::MenuAdmin() {
    //ctor
}

MenuAdmin::~MenuAdmin() {
    //dtor
}

MenuAdmin::MenuAdmin(const Academico& academico, const Usuario& usuario) {
    //Inicializa el No de registro para proximas insersiones
    ifstream file_reg(string(DIR) + string(ARCH_NO_REG));
    file_reg.read((char*)&this->noReg, sizeof(int));
    file_reg.close();

    //Nace el menu con los datos de la cuenta usuario y del academico
    this->academico = academico;
    this->usuario = usuario;
    menuPrincipal();
}

void MenuAdmin::menuPrincipal() {
    string opc;
    do {
        system("clear");
        cout << "No.Registros : " << noReg << endl;
        cout << "*** Menu del administrador -> " << academico.getNombre() << " ***" << endl << endl;
        cout << "1) Administrar perfil."<< endl;
        cout << "2) Administrar usuarios."<< endl;
        cout << "3) Administrar academicos."<< endl;
        cout << "4) Administrar producción academica."<< endl;
        cout << "0) Salir..." << endl << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "1" and opc != "2" and opc != "3" and opc != "0");
        if(opc == "1") {
            administrarPerfil();
        } else if(opc == "2") {
            administrarUsuarios();
        } else if(opc == "3") {
            administrarAcademicos();
        } else if(opc == "4") {
            administrarProduccion();
        } else {
            cout << endl << "Gracias por usar el administrador de usuarios.";
        }
        if(opc != "0" and opc != "1") {
            pausa();
        }
    } while(opc != "0");
}

void MenuAdmin::administrarPerfil() {
    //Abre el menu de usuario, especificamente para el Administrador loggeado
    new MenuUsr(this->academico, this->usuario);
}

void MenuAdmin::administrarUsuarios() {
    string opc;
    do {
        system("clear");
        cout << "*** Administracion de usuarios ***" << endl << endl;
        cout << "1) Agregar usuario." << endl;
        cout << "2) Mostrar usuario." << endl;
        cout << "3) Modificar usuario." << endl;
        cout << "4) Eliminar usuario." << endl;
        cout << "0) Salir..." << endl<< endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "1" and opc != "2" and opc != "3" and opc != "4" and opc != "0");
        if(opc == "1") {
            agregarUsuario();
        } else if(opc == "2") {
            mostrarUsuario();
        } else if(opc == "3") {
            modificarUsuario();
        } else if(opc == "4") {
            eliminarUsuario();
        } else {
            cout << endl << endl << "Gracias por usar el administrador de usuarios...";
        }
        if(opc != "0") {
            pausa();
        }
    } while(opc != "0");
}

void MenuAdmin::administrarAcademicos()
{

}

void MenuAdmin::administrarProduccion()
{

}

void MenuAdmin::agregarUsuario() {
    system("clear");
    cout << "*** Agregar nuevo usuario ***" << endl << endl;
    Usuario newUsuario;
    string auxStr;
    //Implementar unico usuario
    bool existencia = false;
    do {
        cout << "Ingrese el username: ";
        getline(cin, auxStr);
        if(existeUsername(auxStr)) {
            existencia = true;
            cout << endl << "Username ya existe. Intente de nuevo.";
        } else {
            existencia = false;
        }
    } while(existencia);
    newUsuario.setUsername(auxStr);

    cout << "Ingrese la contraseña: ";
    getline(cin, auxStr);
    newUsuario.setPassword(auxStr);

    cout << "Elija el tipo de usuario." << endl;
    cout << "1) Administrador." << endl;
    cout << "2) Usuario." << endl;
    do {
        cout << ">> ";
        getline(cin, auxStr);
    } while(auxStr != "1" and auxStr != "2");
    if(auxStr == "1") {
        newUsuario.setTipo("Admin");
    } else {
        newUsuario.setTipo("User");
    }
    newUsuario.setNoReg(++noReg);
    insertarUsuario(newUsuario);
    cout << endl << "Usuario registrado exitosamente.";
}

void MenuAdmin::mostrarUsuario() {
    system("clear");
    cout << "*** Mostrar usuario ***" <<endl << endl;
    ifstream arch_usr(string(DIR) + string(ARCH_USR));
    if(!arch_usr.good()) {
        cout << "ERROR. No existe el archivo.";
        arch_usr.close();
        return;
    }
    ifstream arch_ac(string(DIR) + string(ARCH_AC));
    while(!arch_usr.eof()) {
        Usuario usr;
        arch_usr.read((char*)&usr, sizeof(Usuario));
        if(arch_usr.eof()) { break; }

        Academico ac;
        cout << usr.toString();
        arch_ac.seekg(usr.getDireccionFisica(), ios::beg);
        arch_ac.read((char*)&ac, sizeof(Academico));
        cout << ac.toString()<< endl;
    }
}

void MenuAdmin::modificarUsuario() {
    system("clear");
    string username;
    cout << "*** Modificación de usuario ***" << endl << endl;
    cout << "Ingrese el usuario (username) a buscar: ";
    getline(cin, username);
    if(existeUsername(username)){

    }
    else{
        cout << "No existe el usuario buscado.";
    }
}

void MenuAdmin::eliminarUsuario() {

}

void MenuAdmin::pausa() {
    cout << endl << endl << "Presione [enter] para continuar...." << endl;
    cin.ignore();
}

bool MenuAdmin::existeUsername(const std::string& username) {
    ifstream file(string(DIR) + string(ARCH_USR));
    if(!file.good()) {
        return false;
    }
    bool resultado = false;
    while(!file.eof()) {
        Usuario usr;
        file.read((char*)&usr, sizeof(Usuario));
        if(file.eof()) { break; }

        if(usr.getUsername() == username) {
            resultado = true;
            break;
        }
    }
    file.close();
    return resultado;
}

void MenuAdmin::insertarUsuario(Usuario& usuario) {
    Academico academico;
    //Crea el registro dentro del archivo de academicos
    academico.setNombre(std::string(usuario.getUsername()));
    ofstream arch_ac(string(DIR) + string(ARCH_AC), ios::app);
    long int direccionFisica = arch_ac.tellp();
    arch_ac.write((char*)&academico, sizeof(Academico));
    arch_ac.close();
    //Toma el valor de la posicion física del academico y la asigna al usuario
    usuario.setDireccionFisica(direccionFisica);
    ofstream arch_usr(string(DIR) + string(ARCH_USR), ios::app);
    arch_usr.write((char*)&usuario, sizeof(Usuario));
    arch_usr.close();
    //Sobreescribe el valor del no de registros
    ofstream file_reg(string(DIR) + string(ARCH_NO_REG));
    file_reg.write((char*)&noReg, sizeof(int));
    file_reg.close();
}
