#ifndef MENUADMIN_H
#define MENUADMIN_H

#include "menuusr.h"

class MenuAdmin {
private:
    int noReg;
    Academico academico;
    Usuario usuario;
    bool existeUsername(const std::string& username);
    void insertarUsuario(Usuario& usuario);
    Usuario regresaUsuario(const std::string& username);
    Academico regresaAcademico(const int& noReg);
public:
    MenuAdmin();
    MenuAdmin(const Academico & academico, const Usuario & usuario);
    void menuPrincipal();
    void administrarUsuarios();
    void administrarAcademicos();
    void administrarProduccion();
    void agregarUsuario();
    void mostrarUsuario();
    void modificarUsuario();
    void eliminarUsuario();
    void administrarPerfil();
    void pausa();
    virtual ~MenuAdmin();

};

#endif // MENUADMIN_H
