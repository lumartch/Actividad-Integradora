#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <cstring>

class Usuario {

private:
    int noReg;
    char username[30];
    char password[30];
    char tipo[20];
    long int direccionFisica;
public:
    Usuario();
    Usuario(const int& noReg, const std::string& username, const std::string& password, const std::string& tipo, const long int& direccionFisica);
    void setNoReg(const int & noReg);
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setTipo(const std::string& tipo);
    void setDireccionFisica(const long int & direccionFisica);
    int getNoRegistro();
    char* getUsername();
    char* getPassword();
    char* getTipo();
    long int getDireccionFisica();
    std::string toString();
    virtual ~Usuario();
    
    bool operator<(const Usuario &t) const
    {
        return strcmp(username, t.username)<0;
        
    }
    bool operator==(const Usuario &t) const
    {
        return strcmp(username, t.username)==0;
        
    }
    friend std::ostream & operator << (std::ostream & os,  Usuario & c){
        std::string x,y;
        x=c.username;
        y=c.password;
        os << x;
        return os;
    }
};

#endif // USUARIO_H
