#ifndef PRODUCCION_H
#define PRODUCCION_H

#include <string>
#include <cstring>
#include "fecha.h"

class Produccion {
private:
    int noReg;
    char tipo[30];
    char nombre[30];
    Fecha fechaElaboracion;
    //Lista colaboradores;
    char noRegistro[20];
    char status[10];
public:
    Produccion();
    void setNoReg(const int& noReg);
    void setTipo(const std::string& tipo);
    void setNombre(const std::string& nombre);
    void setFechaElaboracion(const Fecha & fechaElaboracion);
    void setNoRegistro(const std::string& noRegistro);
    void setStatus(const std::string& status);
    int getNoReg();
    char* getTipo();
    char* getNombre();
    Fecha getFechaElaboracion();
    char* getNoRegistro();
    char* getStatus();
    virtual ~Produccion();

};

#endif // PRODUCCION_H
