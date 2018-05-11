#include "menuusr.h"

MenuUsr::MenuUsr() {
    //ctor
}

MenuUsr::~MenuUsr() {
    //dtor
}

MenuUsr::MenuUsr(const Academico& academico, const Usuario& usuario) {
    //Inicializa con los datos de dos objetos, Usuario contiene la direccion de archivo del Academico
    //para cuando se terminen las modificaciones
    this->academico = academico;
    this->usuario = usuario;
    menuPrincipal();
}

void MenuUsr::menuPrincipal() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Menu del usuario " << this->academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Administrar información personal." << endl;
        cout << "2) Administrar formación academica." << endl;
        cout << "3) Administrar producción academica." << endl;
        cout << "4) Administrar docencia." << endl;
        cout << "5) Administrar tutoria." << endl;
        cout << "6) Mostrar información." << endl;
        cout << "7) Configuración." << endl;
        cout << "0) Salir..." << endl << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "1" and opc != "2" and opc != "3" and opc != "4" and opc != "5" and opc != "6" and opc != "7" and opc != "0");
        if(opc == "1") {
            infoPersonal();
        } else if(opc == "2") {
            formacion();
        } else if(opc == "3") {
            produccion();
        } else if(opc == "4") {
            docencia();
        } else if(opc == "5") {
            tutoria();
        } else if(opc == "6") {
        } else if(opc == "7") {
        } else {
            //Abre el archivo y coloca el puntero en la posicion de escritura para sobreescribir el academico
            fstream file_academico(string(DIR) + string(ARCH_AC), ios::in|ios::out);
            file_academico.seekp(usuario.getDireccionFisica(), ios::beg);
            file_academico.write((char*)&academico, sizeof(Academico));
            file_academico.close();
            cout << endl << "Gracias por usar el administrador de usuario....";
        }
        if(opc != "0"){
            pausa();
        }
    } while(opc != "0");
}

void MenuUsr::infoPersonal() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de informacion personal - "<< this->academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Actualizar nombre." << endl;
        cout << "2) Actualizar domicilio." << endl;
        cout << "3) Actualizar ciudad." << endl;
        cout << "4) Actualizar telefono." << endl;
        cout << "5) Actualizar email." << endl;
        cout << "6) Actualizar estado civil." << endl;
        cout << "7) Administrar dependientes economicos." << endl;
        cout << "0) Salir..." << endl << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "1" and opc != "2" and opc != "3" and opc != "4" and
                opc != "5" and opc != "6" and opc != "7" and opc != "0");
        //Edicion del perfil de usuario
        if(opc == "1") {
            string nombre;
            cout << endl << "Ingrese el nuevo nombre del academico: ";
            getline(cin, nombre);
            academico.setNombre(nombre);
            cout << endl << "¡Nombre actualizado!";
        } else if(opc == "2") {
            string domicilio;
            cout << endl << "Ingrese el nuevo domicilio del academico: ";
            getline(cin, domicilio);
            academico.setDomicilio(domicilio);
            cout << endl << "¡Domicilio actualizado!";
        } else if(opc == "3") {
            string ciudad;
            cout << endl << "Ingrese la nueva ciudad del academico: ";
            getline(cin, ciudad);
            academico.setCiudad(ciudad);
            cout << endl << "¡Ciudad actualizada!";
        } else if(opc == "4") {
            string telefono;
            cout << endl << "Ingrese el nuevo telefono del academico: ";
            getline(cin, telefono);
            academico.setTelefono(telefono);
            cout << endl << "¡Telefono actualizado!";
        } else if(opc == "5") {
            string email;
            cout << endl << "Ingrese el nuevo email del academico: ";
            getline(cin, email);
            academico.setEmail(email);
            cout << endl << "¡Email actualizado!";
        } else if(opc == "6") {
            string estadoCivil;
            cout << endl << "Seleccione el estado civil del academico." << endl;
            cout << "1) Soltero." << endl;
            cout << "2) Casado." << endl << endl;
            do {
                cout << ">> ";
                getline(cin, estadoCivil);
            } while(estadoCivil != "1" and estadoCivil != "2");
            if(estadoCivil == "1") {
                academico.setEstadoCivil("Soltero");
            } else {
                academico.setEstadoCivil("Casado");
            }
            cout << endl << "¡Estado civil actualizado!";
        } else if(opc == "7") {
            dependientesEconomicos();
        } else {
            cout << endl << "Terminando de modificar información personal...";
        }
        if(opc != "0") {
            pausa();
        }
    } while(opc != "0");
}

void MenuUsr::dependientesEconomicos() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Dependientes economicos de " << this->academico.getNombre() << " ***" << endl << endl;
        cout << "1) Agregar dependiente." << endl;
        cout << "2) Mostrar dependientes." << endl;
        cout << "3) Modificar dependiente." << endl;
        cout << "4) Eliminar dependiente." << endl;
        cout << "0) Salir..." << endl << endl;
        do{
            cout << ">> ";
            getline(cin, opc);
        }while(opc != "0" and opc != "1" and opc != "2"
               and opc != "3" and opc != "4");
        if(opc == "1"){
            string nombre, edad;
            bool bandera = true;
            do{
                //Revisar si no hay homonimos
                cout << "Ingrese el nombre del dependiente: ";
                getline(cin, nombre);
                if(existeDependiente(nombre)){
                    string opc;
                    cout << "Existe el nombre de dependiente. ¿Desea ingresar un homonimo del dependiente?(S/N): ";
                    do{
                        cout << ">> ";
                        getline(cin, opc);
                    }while(opc != "s" and opc != "S" and opc != "n" and opc != "N");
                    if(opc == "s" or opc == "S"){
                        bandera = true;
                    }
                    else{
                        bandera = false;
                    }
                }
                else{
                    bandera = true;
                }
            }while(!bandera);
            cout << "Ingrese la edad del dependiente: ";
            getline(cin, edad);

            //Ingresa informacion dentro del objeto
            Dependiente dep;
            dep.setNoReg(this->academico.getNoReg());
            dep.setNombre(nombre);
            dep.setEdad(atoi(edad.c_str()));

            //Guarda dentro del archivo el objeto
            ofstream file(string(DIR) + string(ARCH_DEPENDIENTE), ios::app);
            file.write((char*) &dep, sizeof(Dependiente));
            file.close();
            cout << endl <<"¡Nuevo dependiente agregado exitosamente!";
        }
        else if(opc == "2"){
            system(CLEAR);
            cout << "*** Mostrando dependientes economicos del academico " << this->academico.getNombre() << " ***" << endl << endl;
            ifstream file(string(DIR) + string(ARCH_DEPENDIENTE));
            if(!file.good()){
                file.close();
                ofstream file_dep(string(DIR) + string(ARCH_DEPENDIENTE));
                file_dep.close();
                cout << "ERROR. No existe el archivo.";
                return;
            }
            int i = 1;
            while(!file.eof()){
                Dependiente dep;
                file.read((char*)&dep, sizeof(Dependiente));
                if(file.eof()){ break; }
                //Busca si existe el nombre de dependiente por el usuario
                if(dep.getNoReg() == academico.getNoReg()){
                    cout  << "Dependiente #" << i << endl;
                    cout << "Nombre: " << dep.getNombre() << endl;
                    cout << "Edad: " << dep.getEdad() << endl << endl;
                    i++;
                }
            }
            file.close();
        }
        else if(opc == "3"){
            string nombre;
            cout << endl << "Ingrese el nombre del dependiente a modificar: ";
            getline(cin, nombre);
            if(existeDependiente(nombre)){
                ifstream file_out(string(DIR) + string(ARCH_DEPENDIENTE));
                while(!file_out.eof()){
                    Dependiente dep;
                    file_out.read((char*)&dep, sizeof(Dependiente));
                    if(file_out.eof()){ break; }
                    if(string(dep.getNombre()) != nombre){
                        ofstream file(string(DIR) + "Temporal.txt");
                        file.write((char*) &dep, sizeof(Dependiente));
                        file.close();
                    }
                }
                file_out.close();
                cout << "Se elimino el dependiente exitosamente.";
                string rem = string(DIR) + string(ARCH_DEPENDIENTE);
                string rena = string(DIR) + "Temporal.txt";
                remove(rem.c_str());
                //rename(rena.c_str(), rem.c_str());
            }
            else{
                cout << endl << "No existe el dependiente.";
            }
        }
        else if(opc == "4"){
            string nombre;
            cout << endl << "Ingrese el nombre del dependiente a eliminar: ";
            getline(cin, nombre);
            if(existeDependiente(nombre)){

            }
            else{
                cout << endl << "No existe el dependiente.";
            }
        }
        else{
            cout << endl << "Regresando al menú de administración de información personal...";
        }
        if(opc != "0"){
            pausa();
        }
    } while(opc != "0");
}

void MenuUsr::formacion() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de la formación academica - "<< this->academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nuevo grado de estudios." << endl;
        cout << "2) Mostrar grados de estudio." << endl;
        cout << "3) Modificar grado de estudio." << endl;
        cout << "4) Eliminar grado de estudio." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
        if(opc != "0"){
            pausa();
        }
    } while(opc != "0");

}


void MenuUsr::produccion() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de la producción academica - "<< this->academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nueva producción." << endl;
        cout << "2) Mostrar producciones." << endl;
        cout << "3) Modificar producción." << endl;
        cout << "4) Eliminar producción." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
        if(opc != "0"){
            pausa();
        }
    } while(opc != "0");
}

void MenuUsr::docencia() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de la docencia - "<< this->academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nueva docencia." << endl;
        cout << "2) Mostrar docencias." << endl;
        cout << "3) Modificar docencia." << endl;
        cout << "4) Eliminar docencia." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
        if(opc != "0"){
            pausa();
        }
    } while(opc != "0");
}

void MenuUsr::tutoria() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de la tutoria - "<< this->academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nueva tutoria." << endl;
        cout << "2) Mostrar tutorias." << endl;
        cout << "3) Modificar tutoria." << endl;
        cout << "4) Eliminar tutoria." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
        if(opc != "0"){
            pausa();
        }
    } while(opc != "0");
}

void MenuUsr::pausa() {
    cout << endl << "Presione [enter] para continuar..." << endl;
    cin.ignore();
}

bool MenuUsr::existeDependiente(const std::string& nombre) {
    ifstream file(string(DIR) + string(ARCH_DEPENDIENTE));
    if(!file.good()){
        file.close();
        ofstream file_dep(string(DIR) + string(ARCH_DEPENDIENTE));
        file_dep.close();
        return false;
    }
    while(!file.eof()){
        Dependiente dep;
        file.read((char*)&dep, sizeof(Dependiente));
        if(file.eof()){ break; }
        //Busca si existe el nombre de dependiente por el usuario
        if(string(dep.getNombre()) == nombre and dep.getNoReg() == academico.getNoReg()){
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

