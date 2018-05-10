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
        cout << "*** Menu del usuario " << academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Administrar información personal." << endl;
        cout << "2) Administrar formación academica." << endl;
        cout << "3) Administrar producción academica." << endl;
        cout << "4) Administrar docencia." << endl;
        cout << "5) Administrar tutoria." << endl;
        cout << "0) Salir..." << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "1" and opc != "2" and opc != "3" and opc != "4" and opc != "5" and opc != "0");
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
        } else {
            //Abre el archivo y coloca el puntero en la posicion de escritura para sobreescribir el academico
            fstream file_academico(string(DIR) + string(ARCH_AC), ios::in|ios::out);
            file_academico.seekp(usuario.getDireccionFisica(), ios::beg);
            file_academico.write((char*)&academico, sizeof(Academico));
            file_academico.close();
            cout << endl << "Gracias por usar el administrador de usuario....";
        }
        pausa();
    } while(opc != "0");
}

void MenuUsr::infoPersonal() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de informacion personal - "<< academico.getNombre() <<" ***" << endl << endl;
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
            cout << "Terminando de modificar información personal...";
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
        cout << "*** Dependientes economicos de " << academico.getNombre() << " ***" << endl << endl;
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

        }
        else if(opc == "2"){}
        else if(opc == "3"){}
        else if(opc == "4"){}
        else{
            cout << "Regresando al menú de administración de información personal...";
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
        cout << "*** Administracion de la formación academica - "<< academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nuevo grado de estudios." << endl;
        cout << "2) Mostrar grados de estudio." << endl;
        cout << "3) Modificar grado de estudio." << endl;
        cout << "4) Eliminar grado de estudio." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
    } while(opc != "0");

}


void MenuUsr::produccion() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de la producción academica - "<< academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nueva producción." << endl;
        cout << "2) Mostrar producciones." << endl;
        cout << "3) Modificar producción." << endl;
        cout << "4) Eliminar producción." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
    } while(opc != "0");
}

void MenuUsr::docencia() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de la docencia - "<< academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nueva docencia." << endl;
        cout << "2) Mostrar docencias." << endl;
        cout << "3) Modificar docencia." << endl;
        cout << "4) Eliminar docencia." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
    } while(opc != "0");
}

void MenuUsr::tutoria() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de la tutoria - "<< academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nueva tutoria." << endl;
        cout << "2) Mostrar tutorias." << endl;
        cout << "3) Modificar tutoria." << endl;
        cout << "4) Eliminar tutoria." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
    } while(opc != "0");
}

void MenuUsr::pausa() {
    cout << endl << "Presione [enter] para continuar..." << endl;
    cin.ignore();
}

