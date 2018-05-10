#include "menuusr.h"

MenuUsr::MenuUsr() {
    //ctor
}

MenuUsr::~MenuUsr() {
    //dtor
}

MenuUsr::MenuUsr(const Academico& academico, const Usuario& usuario) {
    this->academico = academico;
    this->usuario = usuario;
    menuPrincipal();
}

void MenuUsr::menuPrincipal() {
    string opc;
    do {
        system("clear");
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
            cout << endl << "Gracias por usar el administrador de usuario....";
        }
        pausa();
    } while(opc != "0");
}

void MenuUsr::infoPersonal() {
    string opc;
    do{
        system("clear");
        cout << "*** Administracion de informacion personal - "<< academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Actualizar nombre." << endl;
        cout << "2) Actualizar domicilio." << endl;
        cout << "3) Actualizar ciudad." << endl;
        cout << "4) Actualizar telefono." << endl;
        cout << "5) Actualizar email." << endl;
        cout << "6) Actualizar estado civil." << endl;
        cout << "7) Administrar dependientes economicos." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
    }while(opc != "0");
}

void MenuUsr::formacion() {
    string opc;
    do{
        system("clear");
        cout << "*** Administracion de la formación academica - "<< academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nuevo grado de estudios." << endl;
        cout << "2) Mostrar grados de estudio." << endl;
        cout << "3) Modificar grado de estudio." << endl;
        cout << "4) Eliminar grado de estudio." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
    }while(opc != "0");
}


void MenuUsr::produccion() {
    string opc;
    do{
        system("clear");
        cout << "*** Administracion de la producción academica - "<< academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nueva producción." << endl;
        cout << "2) Mostrar producciones." << endl;
        cout << "3) Modificar producción." << endl;
        cout << "4) Eliminar producción." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
    }while(opc != "0");
}

void MenuUsr::docencia() {
    string opc;
    do{
        system("clear");
        cout << "*** Administracion de la docencia - "<< academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nueva docencia." << endl;
        cout << "2) Mostrar docencias." << endl;
        cout << "3) Modificar docencia." << endl;
        cout << "4) Eliminar docencia." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
    }while(opc != "0");
}

void MenuUsr::tutoria() {
    string opc;
    do{
        system("clear");
        cout << "*** Administracion de la tutoria - "<< academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nueva tutoria." << endl;
        cout << "2) Mostrar tutorias." << endl;
        cout << "3) Modificar tutoria." << endl;
        cout << "4) Eliminar tutoria." << endl;
        cout << "0) Salir..." << endl;
        cout << ">> ";
        getline(cin, opc);
    }while(opc != "0");
}

void MenuUsr::pausa() {
    cout << endl << "Presione [enter] para continuar..." << endl;
    cin.ignore();
}

