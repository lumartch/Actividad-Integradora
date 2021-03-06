#ifndef MENUADMIN_H
#define MENUADMIN_H

#include "menuusr.h"
#include "AVL.hpp"

class MenuAdmin {
private:
    int noReg;
    Academico academico;
    Usuario usuario;
    BTree<Usuario>* arbol;
    bool existeUsername(const std::string& username);
    void insertarUsuario(Usuario& usuario);
    bool formatoNumero(const std::string& numero);
    bool formatoEmail(const std::string&email);
    void guardaDependiente(Dependiente& dep, const std::string& archivo);
    bool existeDependiente(const std::string&nombre, Academico &ac);
    void guardaFormacion(Formacion& form, const std::string& archivo);
    bool existeFormacion(const std::string &tipo, const std::string &nombre, Academico &ac);
    void guardaDocencia(Docencia& doc, const std::string& archivo);
    bool existeDocencia(const std::string& nombre, Academico &ac);
    void guardaTutoria(Tutoria &tut, const std::string& archivo);
    void guardaProduccion(Produccion &pro, const std::string& archivo);
    bool existeProduccion(const std::string& tipo, const std::string& nombre, Academico &ac);
    bool existeNoRegProduccion(const std::string& noRegistro, Academico &ac);
    void guardaAutor(Autor& aut, const std::string& archivo);
    bool existeAutor(const std::string& nombre, const std::string& noRegistro);
    bool existeTutoria(const std::string& nombreTutorado, Academico &ac);
    bool fechaCorrecta(const std::string& fecha);
    Fecha regresaFecha(std::string&fecha);
public:
    MenuAdmin();
    //MenuAdmin(const Academico & academico, const Usuario & usuario);
    MenuAdmin(const Academico & academico, const Usuario & usuario, BTree<Usuario>*arbol){
        //Inicializa el No de registro para proximas insersiones
        ifstream file_reg(string(DIR) + string(ARCH_NO_REG));
        file_reg.read((char*)&this->noReg, sizeof(int));
        file_reg.close();
        
        //Nace el menu con los datos de la cuenta usuario y del academico
        this->arbol=arbol;
        this->academico = academico;
        this->usuario = usuario;
        menuPrincipal();
    }
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
    void docencia(Academico &ac);
    void tutoria(Academico &ac);
    void modificarAcademico();
    void eliminarAcademico();
    void administrarProduccion();
    void administrarPerfil();
    void pausa();
    virtual ~MenuAdmin();

};

#endif // MENUADMIN_H
