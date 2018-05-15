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
    bool formatoNumero(const std::string& numero);
    bool formatoEmail(const std::string&email);
    void guardaDependiente(Dependiente& dep, const std::string& archivo);
    bool existeDependiente(const std::string&nombre);
    void guardaFormacion(Formacion& form, const std::string& archivo);
    bool existeFormacion(const std::string &tipo, const std::string &nombre);
    void guardaDocencia(Docencia& doc, const std::string& archivo);
    bool existeDocencia(const std::string& nombre);
    void guardaTutoria(Tutoria &tut, const std::string& archivo);
    bool existeTutoria(const std::string& nombreTutorado);
    bool fechaCorrecta(const std::string& fecha);
    Fecha regresaFecha(std::string&fecha);
public:
    MenuAdmin();
    MenuAdmin(const Academico & academico, const Usuario & usuario);
    void menuPrincipal();
    void administrarUsuarios();
    void agregarUsuario();
    void mostrarUsuario();
    void modificarUsuario();
    void eliminarUsuario();
    void administrarAcademicos();
    void mostrarAcademicos();
    void infoPersonal(Academico &ac);
    void dependientesEconomicos(Academico &ac);
    void formacion(Academico &ac);
    void modificarAcademico();
    void eliminarAcademico();
    void administrarProduccion();
    void administrarPerfil();
    void pausa();
    virtual ~MenuAdmin();

};

#endif // MENUADMIN_H
