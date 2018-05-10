#ifndef MENUUSR_H
#define MENUUSR_H

#include "usuario.h"
#include "academico.h"
#include <fstream>
#include <iostream>
#define ARCH_USR "Usuarios.txt"
#define ARCH_AC "Academicos.txt"
#define ARCH_NO_REG "No_Registro.txt"


using namespace std;

class MenuUsr {
private:
    Academico academico;
    Usuario usuario;
    void pausa();
public:
    MenuUsr();
    MenuUsr(const Academico & academico, const Usuario & usuario);
    void menuPrincipal();
    void infoPersonal();
    void formacion();
    void produccion();
    void docencia();
    void tutoria();
    virtual ~MenuUsr();

};

#endif // MENUUSR_H
