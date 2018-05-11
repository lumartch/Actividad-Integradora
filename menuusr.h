#ifndef MENUUSR_H
#define MENUUSR_H

//Objetos
#include "usuario.h"
#include "academico.h"
#include "dependiente.h"
#include "docencia.h"

//Dependencias de librerias
#include <fstream>
#include <iostream>

//Definicion del nombre de archivos
#define ARCH_USR "Usuarios.txt"
#define ARCH_AC "Academicos.txt"
#define ARCH_NO_REG "No_Registro.txt"
#define ARCH_DEPENDIENTE "Dependiente_Academico.txt"
#define ARCH_FORMACION "Formacion_Academica.txt"
#define ARCH_PRODUCCION "Produccion_Academica.txt"
#define ARCH_DOCENCIA "Docencia_Academica.txt"
#define ARCH_TUTORIA "Tutoria_academica.txt"

//Definicion del clear o cls junto con el Slash para cada tipo de OS
#ifndef _WIN32
#define CLEAR "clear"
#define MKDIR "mkdir Archivos/"
#define DIR "Archivos/"
#else
#define CLEAR "cls"
#define MKDIR "mkdir Archivos\\"
#define DIR "Archivos\\"
#endif

using namespace std;

class MenuUsr {
private:
    Academico academico;
    Usuario usuario;
    void pausa();
    void guardaDependiente(Dependiente& dep, const std::string& archivo);
    void guardaDocencia(Docencia& doc, const std::string& archivo);
    bool existeDependiente(const std::string& nombre);
public:
    MenuUsr();
    MenuUsr(const Academico & academico, const Usuario & usuario);
    void menuPrincipal();
    void infoPersonal();
    void dependientesEconomicos();
    void imprimirInformacion();
    void formacion();
    void produccion();
    void docencia();
    void tutoria();
    virtual ~MenuUsr();
};

#endif // MENUUSR_H
