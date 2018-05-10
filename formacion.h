#ifndef FORMACION_H
#define FORMACION_H

#include "fecha.h"

class Formacion {
private:
    char username[20];
    char tipo[30];
    char nombre[20];
    char institucion[30];
    Fecha fechaInicio;
    Fecha fechaFinal;
    Fecha fechaObtencion;
    char cedula[20];
public:
    Formacion();
    void setUsername(const std::string &username);
    void setTipo(const std::string &tipo);
    void setNombre(const std::string &nombre);
    void setInstitucion(const std::string &institucion);
    void setFechaInicio(const Fecha& fechaInicio);
    void setFechaFinal(const Fecha& fechaFinal);
    void setFechaObtencion(const Fecha& fechaObtencion);
    void setCedula(const std::string &cedula);
    char* getUsername();
    char* getTipo();
    char* getNombre();
    char* getInstitucion();
    Fecha getFechaInicio();
    Fecha getFechaFinal();
    Fecha getFechaObtencion();
    char* getCedula();
    virtual ~Formacion();

};

#endif // FORMACION_H
