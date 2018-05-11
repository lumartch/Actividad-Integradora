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
        cout << "*** Menu del usuario " << this->academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Administrar información personal." << endl;
        cout << "2) Administrar formación academica." << endl;
        cout << "3) Administrar producción academica." << endl;
        cout << "4) Administrar docencia." << endl;
        cout << "5) Administrar tutoria." << endl;
        cout << "6) Mostrar información." << endl;
        cout << "7) Configuración." << endl;
        cout << "0) Salir..." << endl << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "1" and opc != "2" and opc != "3" and opc != "4" and opc != "5" and opc != "6" and opc != "7" and opc != "0");
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
        } else if(opc == "6") {
        } else if(opc == "7") {
        } else {
            //Abre el archivo y coloca el puntero en la posicion de escritura para sobreescribir el academico
            fstream file_academico(string(DIR) + string(ARCH_AC), ios::in|ios::out);
            file_academico.seekp(usuario.getDireccionFisica(), ios::beg);
            file_academico.write((char*)&academico, sizeof(Academico));
            file_academico.close();
            cout << endl << "Gracias por usar el administrador de usuario....";
        }
        if(opc != "0") {
            pausa();
        }
    } while(opc != "0");
}

void MenuUsr::infoPersonal() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de informacion personal - "<< this->academico.getNombre() <<" ***" << endl << endl;
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
            cout << endl << "Terminando de modificar información personal...";
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
        cout << "*** Dependientes economicos de " << this->academico.getNombre() << " ***" << endl << endl;
        cout << "1) Agregar dependiente." << endl;
        cout << "2) Mostrar dependientes." << endl;
        cout << "3) Modificar dependiente." << endl;
        cout << "4) Eliminar dependiente." << endl;
        cout << "0) Salir..." << endl << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "0" and opc != "1" and opc != "2"
                and opc != "3" and opc != "4");
        if(opc == "1") {
            string nombre, edad;
            bool bandera = true;
            do {
                //Revisar si no hay homonimos
                cout << endl << "Ingrese el nombre del dependiente: ";
                getline(cin, nombre);
                if(existeDependiente(nombre)) {
                    string opc;
                    cout << "Existe el nombre de dependiente. ¿Desea ingresar un homonimo del dependiente?(S/N): ";
                    do {
                        cout << ">> ";
                        getline(cin, opc);
                    } while(opc != "s" and opc != "S" and opc != "n" and opc != "N");
                    if(opc == "s" or opc == "S") {
                        bandera = true;
                    } else {
                        bandera = false;
                    }
                } else {
                    bandera = true;
                }
            } while(!bandera);
            cout << "Ingrese la edad del dependiente: ";
            getline(cin, edad);

            //Ingresa informacion dentro del objeto
            Dependiente dep;
            dep.setNoReg(this->academico.getNoReg());
            dep.setNombre(nombre);
            dep.setEdad(atoi(edad.c_str()));

            //Guarda dentro del archivo el objeto
            guardaDependiente(dep, string(DIR) + string(ARCH_DEPENDIENTE));

            cout << endl <<"¡Nuevo dependiente agregado exitosamente!";
        } else if(opc == "2") {
            system(CLEAR);
            cout << "*** Mostrando dependientes economicos del academico " << this->academico.getNombre() << " ***" << endl << endl;
            ifstream file(string(DIR) + string(ARCH_DEPENDIENTE));
            if(!file.good()) {
                file.close();
                ofstream file_dep(string(DIR) + string(ARCH_DEPENDIENTE));
                file_dep.close();
                cout << "ERROR. No existe el archivo. Creando archivo...";
                return;
            }
            int i = 1;
            bool bandera = false;
            while(!file.eof()) {
                Dependiente dep;
                file.read((char*)&dep, sizeof(Dependiente));
                if(file.eof()) {
                    break;
                }
                //Busca si existe el nombre de dependiente por el usuario
                if(dep.getNoReg() == academico.getNoReg()) {
                    bandera = true;
                    cout << "Dependiente #" << i << endl;
                    cout << "Nombre: " << dep.getNombre() << endl;
                    cout << "Edad: " << dep.getEdad() << endl << endl;
                    i++;
                }
            }
            file.close();
            if(!bandera) {
                cout << "No hay dependientes para este usuario." << endl;
            }
        } else if(opc == "3") {
            string nombre;
            cout << endl << "Ingrese el nombre del dependiente a modificar: ";
            getline(cin, nombre);
            if(existeDependiente(nombre)) {
                Dependiente dep;
                long int posArchivo = 0;
                //Busca al dependiente dentro del archivo
                fstream file_out(string(DIR) + string(ARCH_DEPENDIENTE), ios::in|ios::out);
                while(!file_out.eof()) {
                    file_out.read((char*)&dep, sizeof(Dependiente));
                    if(file_out.eof()) {
                        break;
                    }
                    //Rompe el ciclo cuando encuentra al Dependiente para modificarlo
                    if(string(dep.getNombre()) == nombre and dep.getNoReg() != academico.getNoReg()) {
                        //Toma la posicion en el archivo y la guarda para despues sobreescribir para la modificación
                        posArchivo = file_out.tellg();
                        posArchivo -= sizeof(Dependiente);
                        break;
                    }
                }
                file_out.close();
                //Menú de modificación
                string opc;
                do {
                    system(CLEAR);
                    cout << "** Dependiente: " << dep.getNombre() << " -> Edad: " << dep.getEdad() << " ***" << endl << endl;
                    cout << "¿Que desea modificar?" << endl;
                    cout << "1) Nombre." << endl;
                    cout << "2) Edad." << endl;
                    cout << "0) Salir..." << endl << endl;
                    do {
                        cout << ">> ";
                        getline(cin, opc);
                    } while(opc != "1" and opc != "2" and opc != "0");

                    if(opc == "1") {
                        string nombre;
                        bool bandera = false;
                        do {
                            cout << endl << "Ingrese el nuevo nombre del dependiente: ";
                            getline(cin, nombre);
                            if(existeDependiente(nombre)) {
                                cout << "El nombre de dependiente ya existe, intente con uno nuevo." << endl;
                                bandera = true;
                            } else {
                                bandera = false;
                            }
                        } while(bandera);
                        dep.setNombre(nombre);
                    } else if(opc == "2") {
                        string edad;
                        cout << endl << "Ingrese la nueva edad del dependiente: ";
                        getline(cin, edad);
                        dep.setEdad(atoi(edad.c_str()));
                    } else {
                        //Sobreescribe el dependiente en la posicion de memoria previamente obtenida
                        fstream file(string(DIR) + string(ARCH_DEPENDIENTE), ios::in|ios::out);
                        file.seekg(posArchivo, ios::beg);
                        file.write((char*)& dep, sizeof(Dependiente));
                        file.close();
                        cout << endl << "Modificación completa del dependiente.";
                    }
                    if(opc != "0") {
                        pausa();
                    }
                } while(opc != "0");

            } else {
                cout << endl << "No existe el dependiente.";
            }
        } else if(opc == "4") {
            string nombre;
            cout << endl << "Ingrese el nombre del dependiente a eliminar: ";
            getline(cin, nombre);
            if(existeDependiente(nombre)) {
                ifstream file_out(string(DIR) + string(ARCH_DEPENDIENTE));
                while(!file_out.eof()) {
                    Dependiente dep;
                    file_out.read((char*)&dep, sizeof(Dependiente));
                    if(file_out.eof()) {
                        break;
                    }
                    //Crea el archivo temporal para guardar los registros, menos el que se quiere eliminar
                    if(string(dep.getNombre()) != nombre and dep.getNoReg() != academico.getNoReg()) {
                        guardaDependiente(dep, string(DIR) + "Temporal.txt");
                    }
                }
                file_out.close();
                //Eliminacion del archivo viejo y sustitucion por el nuevo
                string rem = string(DIR) + string(ARCH_DEPENDIENTE);
                string rena = string(DIR) + "Temporal.txt";
                remove(rem.c_str());
                rename(rena.c_str(), rem.c_str());
                cout << "Se elimino el dependiente exitosamente.";
            } else {
                cout << endl << "No existe el dependiente.";
            }
        } else {
            cout << endl << "Regresando al menú de administración de información personal...";
        }
        if(opc != "0") {
            pausa();
        }
    } while(opc != "0");
}

void MenuUsr::formacion() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de la formación academica de - "<< this->academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nuevo grado de estudios." << endl;
        cout << "2) Mostrar grados de estudio." << endl;
        cout << "3) Modificar grado de estudio." << endl;
        cout << "4) Eliminar grado de estudio." << endl;
        cout << "0) Salir..." << endl << endl;
        cout << ">> ";
        getline(cin, opc);
        if(opc == "1") {
            system(CLEAR);
            string tipoGrado, opc;
            cout << "*** Ingresando formación del academico " << this->academico.getNombre() << " ***" << endl << endl;
            cout << "Elija el tipo de grado." << endl;
            cout << "1) Licenciatura." << endl;
            cout << "2) Especialidad." << endl;
            cout << "3) Maestria." << endl;
            cout << "4) Doctorado." << endl << endl;
            do {
                cout << ">> ";
                getline(cin, tipoGrado);
            } while(opc != "1" and opc != "2" and opc != "3" and opc != "4");
            if(opc == "1") {
                tipoGrado = "Licenciatura";
            } else if(opc == "2") {
                tipoGrado = "Especialidad";
            } else if(opc == "3") {
                tipoGrado = "Maestria";
            } else {
                tipoGrado = "Doctorado";
            }
            cout << endl;
            string nombreGrado, institucion;
            cout << "Ingrese el nombre del grado: ";
            getline(cin, nombreGrado);
            //Si ya existe el grado no lo guarda y regresa al menu principal
            if(existeFormacion(tipoGrado, nombreGrado)) {
                cout << endl << "La formación intenta agregar ya existe. Es imposible registrarla." << endl;
                return;
            }
            cout << "Ingrese la institución de procedencia: ";
            getline(cin, institucion);
            Fecha fechaIni, fechaFin, fechaOb;
            //Corroborar el formato despues
            string fecha;
            cout << "Ingrese la fecha de inicio de cursos (Formato: DD/MM/AAAA): ";
            getline(cin, fecha, '/');
            fechaIni.setDia(atoi(fecha.c_str()));
            getline(cin, fecha, '/');
            fechaIni.setMes(atoi(fecha.c_str()));
            getline(cin, fecha, '\n');
            fechaIni.setAnio(atoi(fecha.c_str()));
            cout << "Ingrese la fecha de fin de cursos (Formato: DD/MM/AAAA): ";
            getline(cin, fecha, '/');
            fechaFin.setDia(atoi(fecha.c_str()));
            getline(cin, fecha, '/');
            fechaFin.setMes(atoi(fecha.c_str()));
            getline(cin, fecha, '\n');
            fechaFin.setAnio(atoi(fecha.c_str()));
            cout << "Ingrese la fecha de obtención (Formato: DD/MM/AAAA): ";
            getline(cin, fecha, '/');
            fechaOb.setDia(atoi(fecha.c_str()));
            getline(cin, fecha, '/');
            fechaOb.setMes(atoi(fecha.c_str()));
            getline(cin, fecha, '\n');
            fechaOb.setAnio(atoi(fecha.c_str()));
            string cedula;
            cout << "Ingrese el número de cédula profesional: ";
            getline(cin, cedula);

            //Crea el objeto de la formación profesional
            Formacion form;
            form.setNoReg(this->academico.getNoReg());
            form.setTipo(tipoGrado);
            form.setNombre(nombreGrado);
            form.setInstitucion(institucion);
            form.setFechaInicio(fechaIni);
            form.setFechaFinal(fechaFin);
            form.setFechaObtencion(fechaOb);
            form.setCedula(cedula);
            guardaFormacion(form, string(DIR) + string(ARCH_FORMACION));
        } else if(opc == "2") {
            system(CLEAR);
            cout << "*** Formación academica actual de " << this->academico.getNombre() << " ***" << endl << endl;
            ifstream file(string(DIR) + string(ARCH_FORMACION));
            if(!file.good()) {
                file.close();
                ofstream file_form(string(DIR) + string(ARCH_FORMACION));
                file_form.close();
                cout << "ERROR. No existe el archivo. Creando archivo...";
                return;
            }
            bool bandera = false;
            while(!file.eof()) {
                Formacion form;
                file.read((char*)&form, sizeof(Formacion));
                if(file.eof()) {
                    break;
                }
                //Busca si existe el nombre de dependiente por el usuario
                if(form.getNoReg() == academico.getNoReg()) {
                    bandera = true;
                    cout << "Titulo: " << form.getTipo() << " " << form.getNombre() << endl;
                    cout << "Institución academica: " << form.getInstitucion() << endl;
                    cout << "Fecha de inicio: " << form.getFechaInicio().toString() << " -> Fecha de fin: " << form.getFechaFinal().toString() << endl;
                    cout << "Fecha de obtencion: " << form.getFechaObtencion().toString() << " -> Cedula: " << form.getCedula() << endl << endl;
                }
            }
            file.close();
            if(!bandera) {
                cout << "No hay formación academica para este usuario." << endl;
            }
        } else if(opc == "3") {
            system(CLEAR);
            string tipoGrado, opc;
            cout << "*** Modificar formación academica de " << academico.getNombre() << " ***" << endl << endl;
            cout << "Elija el tipo y nombre de grado a modificar." << endl;
            cout << "1) Licenciatura." << endl;
            cout << "2) Especialidad." << endl;
            cout << "3) Maestria." << endl;
            cout << "4) Doctorado." << endl << endl;
            do {
                cout << ">> ";
                getline(cin, opc);
            } while(opc != "1" and opc != "2" and opc != "3" and opc != "4");
            if(opc == "1") {
                tipoGrado = "Licenciatura";
            } else if(opc == "2") {
                tipoGrado = "Especialidad";
            } else if(opc == "3") {
                tipoGrado = "Maestria";
            } else {
                tipoGrado = "Doctorado";
            }
            string nombreGrado;
            cout << endl << "Ingrese el nombre: ";
            getline(cin, nombreGrado);
            //Verifica si existe la formación academica
            if(existeFormacion(tipoGrado, nombreGrado)) {
                Formacion form;
                long int posArchivo = 0;
                //Busca al dependiente dentro del archivo
                fstream file_out(string(DIR) + string(ARCH_FORMACION), ios::in|ios::out);
                while(!file_out.eof()) {
                    file_out.read((char*)&form, sizeof(Formacion));
                    if(file_out.eof()) {
                        break;
                    }
                    //Rompe el ciclo cuando encuentra la formacion para modificarla
                    if(string(form.getTipo()) == tipoGrado and string(form.getNombre()) == nombreGrado
                            and form.getNoReg() == academico.getNoReg()) {
                        //Toma la posicion en el archivo y la guarda para despues sobreescribir para la modificación
                        posArchivo = file_out.tellg();
                        posArchivo -= sizeof(Formacion);
                        break;
                    }
                }
                file_out.close();
                //Menu de modificación
                string opc;
                do {
                    system(CLEAR);
                    cout << "*** Modificación de formación " << form.getTipo() << " " << form.getNombre() << " ***" << endl << endl;
                    cout << "1) Tipo." << endl;
                    cout << "2) Nombre" << endl;
                    cout << "3) Fecha de inicio." << endl;
                    cout << "4) Fecha de fin." << endl;
                    cout << "5) Fecha de obtención." << endl;
                    cout << "6) Cedula." << endl;
                    cout << "0) Salir..." << endl << endl;
                    do {
                        cout << ">> ";
                        getline(cin, opc);
                    } while(opc != "0" and opc != "1" and opc != "2" and opc != "3" and opc != "4" and opc != "5" and opc != "6");
                    if(opc == "1") {
                        string tipoGrado, opc;
                        cout << endl << "Elija el tipo de grado." << endl;
                        cout << "1) Licenciatura." << endl;
                        cout << "2) Especialidad." << endl;
                        cout << "3) Maestria." << endl;
                        cout << "4) Doctorado." << endl << endl;
                        do {
                            cout << ">> ";
                            getline(cin, opc);
                        } while(opc != "1" and opc != "2" and opc != "3" and opc != "4");
                        if(opc == "1") {
                            tipoGrado = "Licenciatura";
                        } else if(opc == "2") {
                            tipoGrado = "Especialidad";
                        } else if(opc == "3") {
                            tipoGrado = "Maestria";
                        } else {
                            tipoGrado = "Doctorado";
                        }
                        if(existeFormacion(tipoGrado, form.getNombre())) {
                            cout << endl << "La formación intenta agregar ya existe. Es imposible registrarla." << endl;
                        } else {
                            form.setTipo(tipoGrado);
                        }
                    } else if (opc == "2") {
                        string nombreGrado;
                        cout << "Ingrese el nombre del grado: ";
                        getline(cin, nombreGrado);
                        if(existeFormacion(form.getTipo(), nombreGrado)) {
                            cout << endl << "La formación intenta agregar ya existe. Es imposible registrarla." << endl;
                        } else {
                            form.setNombre(nombreGrado);
                        }
                    } else if (opc == "3") {
                        Fecha fechaIni;
                        string fecha;
                        cout << "Ingrese la fecha de inicio de cursos (Formato: DD/MM/AAAA): ";
                        getline(cin, fecha, '/');
                        fechaIni.setDia(atoi(fecha.c_str()));
                        getline(cin, fecha, '/');
                        fechaIni.setMes(atoi(fecha.c_str()));
                        getline(cin, fecha, '\n');
                        fechaIni.setAnio(atoi(fecha.c_str()));
                        form.setFechaInicio(fechaIni);
                    } else if (opc == "4") {
                        Fecha fechaFin;
                        string fecha;
                        cout << "Ingrese la fecha de fin de cursos (Formato: DD/MM/AAAA): ";
                        getline(cin, fecha, '/');
                        fechaFin.setDia(atoi(fecha.c_str()));
                        getline(cin, fecha, '/');
                        fechaFin.setMes(atoi(fecha.c_str()));
                        getline(cin, fecha, '\n');
                        fechaFin.setAnio(atoi(fecha.c_str()));
                        form.setFechaFinal(fechaFin);
                    } else if (opc == "5") {
                        Fecha fechaOb;
                        string fecha;
                        cout << "Ingrese la fecha de obtención (Formato: DD/MM/AAAA): ";
                        getline(cin, fecha, '/');
                        fechaOb.setDia(atoi(fecha.c_str()));
                        getline(cin, fecha, '/');
                        fechaOb.setMes(atoi(fecha.c_str()));
                        getline(cin, fecha, '\n');
                        fechaOb.setAnio(atoi(fecha.c_str()));
                        form.setFechaObtencion(fechaOb);
                    } else if (opc == "6") {
                        string cedula;
                        cout << "Ingrese el número de cédula profesional: ";
                        getline(cin, cedula);
                        form.setCedula(cedula);
                    } else {
                        fstream file(string(DIR) + string(ARCH_FORMACION), ios::in|ios::out);
                        file.seekg(posArchivo, ios::beg);
                        file.write((char*)& form, sizeof(Formacion));
                        file.close();
                        cout << endl << "Modificación completa de la formación.";
                    }
                } while(opc != "0");
            } else {
                cout << endl << "No existe la formación.";
            }

        } else if(opc == "4") {
            system(CLEAR);
            string tipoGrado, opc;
            cout << "*** Eliminando formación  de " << academico.getNombre() << " ***" << endl << endl;
            cout << "Elija el tipo y nombred de grado a eliminar." << endl;
            cout << "1) Licenciatura." << endl;
            cout << "2) Especialidad." << endl;
            cout << "3) Maestria." << endl;
            cout << "4) Doctorado." << endl << endl;
            do {
                cout << ">> ";
                getline(cin, opc);
            } while(opc != "1" and opc != "2" and opc != "3" and opc != "4");
            if(opc == "1") {
                tipoGrado = "Licenciatura";
            } else if(opc == "2") {
                tipoGrado = "Especialidad";
            } else if(opc == "3") {
                tipoGrado = "Maestria";
            } else {
                tipoGrado = "Doctorado";
            }
            string nombreGrado;
            cout << endl << "Ingrese el nombre: ";
            getline(cin, nombreGrado);
            //Verifica si existe la formación academica
            if(existeFormacion(tipoGrado, nombreGrado)) {
                ifstream file_out(string(DIR) + string(ARCH_FORMACION));
                while(!file_out.eof()) {
                    Formacion form;
                    file_out.read((char*)&form, sizeof(Formacion));
                    if(file_out.eof()) {
                        break;
                    }
                    //Crea el archivo temporal para guardar los registros, menos el que se quiere eliminar
                    if(string(form.getTipo()) != tipoGrado and string(form.getNombre()) != nombreGrado
                            and form.getNoReg() != academico.getNoReg()) {
                        guardaFormacion(form, string(DIR) + "Temporal.txt");
                    }
                }
                file_out.close();
                //Eliminacion del archivo viejo y sustitucion por el nuevo
                string rem = string(DIR) + string(ARCH_FORMACION);
                string rena = string(DIR) + "Temporal.txt";
                remove(rem.c_str());
                rename(rena.c_str(), rem.c_str());
                cout << "Se elimino la formación exitosamente.";
            } else {
                cout << endl << "No existe la formación.";
            }
        } else {
            cout << endl << "Regresando al menú de administración de información personal...";
        }
        if(opc != "0") {
            pausa();
        }
    } while(opc != "0");

}

void MenuUsr::produccion() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de la producción academica - "<< this->academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nueva producción." << endl;
        cout << "2) Mostrar producciones." << endl;
        cout << "3) Modificar producción." << endl;
        cout << "4) Eliminar producción." << endl;
        cout << "0) Salir..." << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "0" and opc != "2" and opc != "3" and opc != "4");
        if(opc == "1") {
        }
        else if(opc == "2") {}
        else if(opc == "3") {}
        else if(opc == "4") {}
        else {
            cout << endl << "Regresando al menú de administración de información personal...";
        }
        if(opc != "0") {
            pausa();
        }
    } while(opc != "0");
}

void MenuUsr::docencia() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de la docencia - "<< this->academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nueva materia." << endl;
        cout << "2) Mostrar materia." << endl;
        cout << "3) Modificar materia." << endl;
        cout << "4) Eliminar materia." << endl;
        cout << "0) Salir..." << endl << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "0" and opc != "1" and opc != "2" and opc != "3" and opc != "4");
        if(opc == "1") {
            cout << endl;
            Docencia doc;
            string nombre, fecha, horasSemanales;
            Fecha fechaIni, fechaFin;

            cout << "Ingrese el nombre de la materia: ";
            getline(cin, nombre);
            if(existeDocencia(nombre)) {
                cout << "Ya existe la materia. Es imposible registrarla." << endl << endl;
            } else{
                cout << "Ingrese la fecha de inicio de cursos (Formato: DD/MM/AAAA): ";
                getline(cin, fecha, '/');
                fechaIni.setDia(atoi(fecha.c_str()));
                getline(cin, fecha, '/');
                fechaIni.setMes(atoi(fecha.c_str()));
                getline(cin, fecha, '\n');
                fechaIni.setAnio(atoi(fecha.c_str()));
                cout << "Ingrese la fecha de fin de cursos (Formato: DD/MM/AAAA): ";
                getline(cin, fecha, '/');
                fechaFin.setDia(atoi(fecha.c_str()));
                getline(cin, fecha, '/');
                fechaFin.setMes(atoi(fecha.c_str()));
                getline(cin, fecha, '\n');
                fechaFin.setAnio(atoi(fecha.c_str()));
                cout << "Ingrese las horas semanales: ";
                getline(cin, horasSemanales);
                //Guarda informacion dentro del objeto
                doc.setNoReg(this->academico.getNoReg());
                doc.setNombre(nombre);
                doc.setFechaInicio(fechaIni);
                doc.setFechaFin(fechaFin);
                doc.setCantidadHoras(horasSemanales);
                //Guarda en el archivo
                guardaDocencia(doc, string(DIR) + string(ARCH_DOCENCIA));
            }
        } else if(opc == "2") {
            system(CLEAR);
            cout << "*** Docencia academica actual de " << this->academico.getNombre() << " ***" << endl << endl;
            ifstream file(string(DIR) + string(ARCH_DOCENCIA));
            if(!file.good()) {
                file.close();
                ofstream file_form(string(DIR) + string(ARCH_DOCENCIA));
                file_form.close();
                cout << "ERROR. No existe el archivo. Creando archivo...";
                return;
            }
            bool bandera = false;
            while(!file.eof()) {
                Docencia doc;
                file.read((char*)&doc, sizeof(Docencia));
                if(file.eof()) {
                    break;
                }
                //Busca si existe el nombre de dependiente por el usuario
                if(doc.getNoReg() == academico.getNoReg()) {
                    bandera = true;
                    cout << "Materia: " << doc.getNombre() << endl;
                    cout << "Fecha de inicio: " << doc.getFechaInicio().toString() << " -> Fecha de fin: " << doc.getFechaFin().toString() << endl;
                    cout << "Horas semanales: " << doc.getCantidadHoras() << endl << endl;
                }
            }
            file.close();
            if(!bandera) {
                cout << "No hay materias registradas para este usuario." << endl;
            }
        } else if(opc == "3") {
            system(CLEAR);
            string nombre;
            cout << "*** Modificar materia de " << academico.getNombre() << " ***" << endl << endl;
            cout << "Ingrese el nombre de la materia a modificar: ";
            getline(cin, nombre);
            //Verifica si existe la formación academica
            if(existeDocencia(nombre)) {
                Docencia doc;
                long int posArchivo = 0;
                //Busca al dependiente dentro del archivo
                fstream file_out(string(DIR) + string(ARCH_DOCENCIA), ios::in|ios::out);
                while(!file_out.eof()) {
                    file_out.read((char*)&doc, sizeof(Docencia));
                    if(file_out.eof()) {
                        break;
                    }
                    //Rompe el ciclo cuando encuentra la formacion para modificarla
                    if(string(doc.getNombre()) == nombre and doc.getNoReg() == academico.getNoReg()) {
                        //Toma la posicion en el archivo y la guarda para despues sobreescribir para la modificación
                        posArchivo = file_out.tellg();
                        posArchivo -= sizeof(Docencia);
                        break;
                    }
                }
                file_out.close();
                //Menu de modificación
                string opc;
                do {
                    system(CLEAR);
                    cout << "*** Modificación de la materia " << doc.getNombre() << " ***" << endl << endl;
                    cout << "1) Nombre" << endl;
                    cout << "2) Fecha de inicio." << endl;
                    cout << "3) Fecha de fin." << endl;
                    cout << "4) Horas semanales." << endl;
                    cout << "0) Salir..." << endl << endl;
                    do {
                        cout << ">> ";
                        getline(cin, opc);
                    } while(opc != "0" and opc != "1" and opc != "2" and opc != "3" and opc != "4");
                    cout << endl;
                    if(opc == "1") {
                        string nombre;
                        cout << "Ingrese el nombre de la materia: ";
                        getline(cin, nombre);
                        if(existeDocencia(nombre)) {
                            cout << "Ya existe la materia. Es imposible registrarla." << endl << endl;
                        } else {
                            doc.setNombre(nombre);
                        }
                    } else if (opc == "2") {
                        Fecha fechaIni;
                        string fecha;
                        cout << "Ingrese la fecha de inicio de cursos (Formato: DD/MM/AAAA): ";
                        getline(cin, fecha, '/');
                        fechaIni.setDia(atoi(fecha.c_str()));
                        getline(cin, fecha, '/');
                        fechaIni.setMes(atoi(fecha.c_str()));
                        getline(cin, fecha, '\n');
                        fechaIni.setAnio(atoi(fecha.c_str()));
                        doc.setFechaInicio(fechaIni);
                    } else if (opc == "3") {
                        Fecha fechaFin;
                        string fecha;
                        cout << "Ingrese la fecha de fin de cursos (Formato: DD/MM/AAAA): ";
                        getline(cin, fecha, '/');
                        fechaFin.setDia(atoi(fecha.c_str()));
                        getline(cin, fecha, '/');
                        fechaFin.setMes(atoi(fecha.c_str()));
                        getline(cin, fecha, '\n');
                        fechaFin.setAnio(atoi(fecha.c_str()));
                        doc.setFechaFin(fechaFin);
                    } else if (opc == "4") {
                        string horasSemanales;
                        cout << "Ingrese las horas semanales: ";
                        getline(cin, horasSemanales);
                        doc.setCantidadHoras(horasSemanales);
                    } else {
                        fstream file(string(DIR) + string(ARCH_DOCENCIA), ios::in|ios::out);
                        file.seekg(posArchivo, ios::beg);
                        file.write((char*)& doc, sizeof(Docencia));
                        file.close();
                        cout << endl << "Modificación completa de la materia.";
                    }
                } while(opc != "0");
            } else {
                cout << endl << "No existe la materia.";
            }
        } else if(opc == "4") {
            system(CLEAR);
            string nombre;
            cout << "*** Eliminando materia de " << academico.getNombre() << " ***" << endl << endl;
            cout << "Ingrese el nombre de la materia a eliminar: ";
            getline(cin, nombre);
            //Verifica si existe la formación academica
            if(existeDocencia(nombre)) {
                ifstream file_out(string(DIR) + string(ARCH_DOCENCIA));
                while(!file_out.eof()) {
                    Docencia doc;
                    file_out.read((char*)&doc, sizeof(Docencia));
                    if(file_out.eof()) {
                        break;
                    }
                    //Crea el archivo temporal para guardar los registros, menos el que se quiere eliminar
                    if(string(doc.getNombre()) != nombre and doc.getNoReg() != academico.getNoReg()) {
                        guardaDocencia(doc, string(DIR) + "Temporal.txt");
                    }
                }
                file_out.close();
                //Eliminacion del archivo viejo y sustitucion por el nuevo
                string rem = string(DIR) + string(ARCH_DOCENCIA);
                string rena = string(DIR) + "Temporal.txt";
                remove(rem.c_str());
                rename(rena.c_str(), rem.c_str());
                cout << "Se elimino la materia exitosamente.";
            } else {
                cout << endl << "No existe la materia.";
            }
        } else {
            cout << endl << "Regresando al menú de administración de información personal...";
        }
        if(opc != "0") {
            pausa();
        }
    } while(opc != "0");
}

void MenuUsr::tutoria() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Administracion de la tutoria - "<< this->academico.getNombre() <<" ***" << endl << endl;
        cout << "1) Agregar nuevo alumno tutorado." << endl;
        cout << "2) Mostrar alumnos tutorados." << endl;
        cout << "3) Modificar alumno tutorado." << endl;
        cout << "4) Eliminar alumno tutorado." << endl;
        cout << "0) Salir..." << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "0" and opc != "2" and opc != "3" and opc != "4");
        cout << endl;
        if(opc == "1") {
            cout << endl;
            Tutoria tut;
            string nombre, fecha, horasSemanales;
            Fecha fechaIni, fechaFin;
            cout << "Ingrese el nombre del alumno tutorado: ";
            getline(cin, nombre);
            if(existeTutoria(nombre)) {
                cout << "Ya existe el alumno tutorado. Es imposible registrarlo." << endl << endl;
            }else{
                cout << "Ingrese la fecha de inicio de tutoria (Formato: DD/MM/AAAA): ";
                getline(cin, fecha, '/');
                fechaIni.setDia(atoi(fecha.c_str()));
                getline(cin, fecha, '/');
                fechaIni.setMes(atoi(fecha.c_str()));
                getline(cin, fecha, '\n');
                fechaIni.setAnio(atoi(fecha.c_str()));
                cout << "Ingrese la fecha de fin de tutorias (Formato: DD/MM/AAAA): ";
                getline(cin, fecha, '/');
                fechaFin.setDia(atoi(fecha.c_str()));
                getline(cin, fecha, '/');
                fechaFin.setMes(atoi(fecha.c_str()));
                getline(cin, fecha, '\n');
                fechaFin.setAnio(atoi(fecha.c_str()));
                cout << "Ingrese las horas semanales de tutorias: ";
                getline(cin, horasSemanales);
                //Guarda informacion dentro del objeto
                tut.setNoReg(this->academico.getNoReg());
                tut.setNombreTutorado(nombre);
                tut.setFechaInicio(fechaIni);
                tut.setFechaFin(fechaFin);
                tut.setCantidadHoras(horasSemanales);
                //Guarda en el archivo
                guardaTutoria(tut, string(DIR) + string(ARCH_TUTORIA));
            }
        }
        else if(opc == "2") {
            system(CLEAR);
            cout << "*** Alumnos tutorados de " << this->academico.getNombre() << " ***" << endl << endl;
            ifstream file(string(DIR) + string(ARCH_TUTORIA));
            if(!file.good()) {
                file.close();
                ofstream file_tut(string(DIR) + string(ARCH_TUTORIA));
                file_tut.close();
                cout << "ERROR. No existe el archivo. Creando archivo...";
                return;
            }
            bool bandera = false;
            while(!file.eof()) {
                Tutoria tut;
                file.read((char*)&tut, sizeof(Tutoria));
                if(file.eof()) { break; }
                //Busca si existe el nombre de dependiente por el usuario
                if(tut.getNoReg() == academico.getNoReg()) {
                    bandera = true;
                    cout << "Alumno tutorado: " << tut.getNombreTutorado() << endl;
                    cout << "Fecha de inicio: " << tut.getFechaInicio().toString() << " -> Fecha de fin: " << tut.getFechaFin().toString() << endl;
                    cout << "Horas semanales: " << tut.getCantidadHoras() << endl << endl;
                }
            }
            file.close();
            if(!bandera) {
                cout << "No hay alumnos tutorados registrados para este usuario." << endl;
            }
        }
        else if(opc == "3") {
            system(CLEAR);
            string nombre;
            cout << "*** Modificar alumno tutorado de " << academico.getNombre() << " ***" << endl << endl;
            cout << "Ingrese el nombre del alumno a modificar: ";
            getline(cin, nombre);
            //Verifica si existe la formación academica
            if(existeTutoria(nombre)) {
                Tutoria tut;
                long int posArchivo = 0;
                //Busca al dependiente dentro del archivo
                fstream file_out(string(DIR) + string(ARCH_TUTORIA), ios::in|ios::out);
                while(!file_out.eof()) {
                    file_out.read((char*)&tut, sizeof(Tutoria));
                    if(file_out.eof()) { break; }
                    //Rompe el ciclo cuando encuentra la formacion para modificarla
                    if(string(tut.getNombreTutorado()) == nombre and tut.getNoReg() == academico.getNoReg()) {
                        //Toma la posicion en el archivo y la guarda para despues sobreescribir para la modificación
                        posArchivo = file_out.tellg();
                        posArchivo -= sizeof(Tutoria);
                        break;
                    }
                }
                file_out.close();
                //Menu de modificación
                string opc;
                do {
                    system(CLEAR);
                    cout << "*** Modificación del alumno " << tut.getNombreTutorado() << " ***" << endl << endl;
                    cout << "1) Nombre" << endl;
                    cout << "2) Fecha de inicio." << endl;
                    cout << "3) Fecha de fin." << endl;
                    cout << "4) Horas semanales." << endl;
                    cout << "0) Salir..." << endl << endl;
                    do {
                        cout << ">> ";
                        getline(cin, opc);
                    } while(opc != "0" and opc != "1" and opc != "2" and opc != "3" and opc != "4");
                    cout << endl;
                    if(opc == "1") {
                        string nombre;
                        cout << "Ingrese el nombre de la materia: ";
                        getline(cin, nombre);
                        if(existeTutoria(nombre)) {
                            cout << "Ya existe el alumno tutorado. Es imposible registrarlo." << endl << endl;
                        } else {
                            tut.setNombreTutorado(nombre);
                        }
                    } else if (opc == "2") {
                        Fecha fechaIni;
                        string fecha;
                        cout << "Ingrese la fecha de inicio de tutorias (Formato: DD/MM/AAAA): ";
                        getline(cin, fecha, '/');
                        fechaIni.setDia(atoi(fecha.c_str()));
                        getline(cin, fecha, '/');
                        fechaIni.setMes(atoi(fecha.c_str()));
                        getline(cin, fecha, '\n');
                        fechaIni.setAnio(atoi(fecha.c_str()));
                        tut.setFechaInicio(fechaIni);
                    } else if (opc == "3") {
                        Fecha fechaFin;
                        string fecha;
                        cout << "Ingrese la fecha de fin de tutorias (Formato: DD/MM/AAAA): ";
                        getline(cin, fecha, '/');
                        fechaFin.setDia(atoi(fecha.c_str()));
                        getline(cin, fecha, '/');
                        fechaFin.setMes(atoi(fecha.c_str()));
                        getline(cin, fecha, '\n');
                        fechaFin.setAnio(atoi(fecha.c_str()));
                        tut.setFechaFin(fechaFin);
                    } else if (opc == "4") {
                        string horasSemanales;
                        cout << "Ingrese las horas semanales: ";
                        getline(cin, horasSemanales);
                        tut.setCantidadHoras(horasSemanales);
                    } else {
                        fstream file(string(DIR) + string(ARCH_TUTORIA), ios::in|ios::out);
                        file.seekg(posArchivo, ios::beg);
                        file.write((char*)& tut, sizeof(Tutoria));
                        file.close();
                        cout << endl << "Modificación completa del alumno tutorado.";
                    }
                } while(opc != "0");
            } else {
                cout << endl << "No existe la materia.";
            }
        }
        else if(opc == "4") {
            system(CLEAR);
            string nombre;
            cout << "*** Eliminando alumno tutorado de " << academico.getNombre() << " ***" << endl << endl;
            cout << "Ingrese el nombre del alumno a eliminar: ";
            getline(cin, nombre);
            //Verifica si existe la formación academica
            if(existeTutoria(nombre)) {
                ifstream file_out(string(DIR) + string(ARCH_TUTORIA));
                while(!file_out.eof()) {
                    Tutoria tut;
                    file_out.read((char*)&tut, sizeof(Tutoria));
                    if(file_out.eof()) { break; }
                    //Crea el archivo temporal para guardar los registros, menos el que se quiere eliminar
                    if(string(tut.getNombreTutorado()) != nombre and tut.getNoReg() != academico.getNoReg()) {
                        guardaTutoria(tut, string(DIR) + "Temporal.txt");
                    }
                }
                file_out.close();
                //Eliminacion del archivo viejo y sustitucion por el nuevo
                string rem = string(DIR) + string(ARCH_TUTORIA);
                string rena = string(DIR) + "Temporal.txt";
                remove(rem.c_str());
                rename(rena.c_str(), rem.c_str());
                cout << "Se elimino el alumno exitosamente.";
            } else {
                cout << endl << "No existe la el alumno tutorado.";
            }
        }
        else {
            cout << endl << "Regresando al menú de administración de información personal...";
        }
        if(opc != "0") {
            pausa();
        }
    } while(opc != "0");
}

void MenuUsr::pausa() {
    cout << endl << "Presione [enter] para continuar..." << endl;
    cin.ignore();
}

void MenuUsr::guardaDependiente(Dependiente& dep, const std::string& archivo) {
    //Guarda dentro del archivo el objeto
    ofstream file(archivo, ios::app);
    file.write((char*) &dep, sizeof(Dependiente));
    file.close();
}

bool MenuUsr::existeDependiente(const std::string& nombre) {
    ifstream file(string(DIR) + string(ARCH_DEPENDIENTE));
    if(!file.good()) {
        file.close();
        ofstream file_dep(string(DIR) + string(ARCH_DEPENDIENTE));
        file_dep.close();
        return false;
    }
    while(!file.eof()) {
        Dependiente dep;
        file.read((char*)&dep, sizeof(Dependiente));
        if(file.eof()) {
            break;
        }
        //Busca si existe el nombre de dependiente por el usuario
        if(string(dep.getNombre()) == nombre and dep.getNoReg() == academico.getNoReg()) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void MenuUsr::guardaFormacion(Formacion& form, const std::string& archivo) {
    //Guarda el objeto dentro del archivo
    ofstream file(archivo, ios::app);
    file.write((char*) &form, sizeof(Formacion));
    file.close();
}

bool MenuUsr::existeFormacion(const std::string& tipo, const std::string& nombre) {
    ifstream file(string(DIR) + string(ARCH_FORMACION));
    if(!file.good()) {
        file.close();
        ofstream file_form(string(DIR) + string(ARCH_FORMACION));
        file_form.close();
        return false;
    }
    while(!file.eof()) {
        Formacion form;
        file.read((char*)&form, sizeof(Formacion));
        if(file.eof()) {
            break;
        }
        //Busca si existe el nombre de formación
        if(string(form.getTipo()) == tipo and string(form.getNombre()) == nombre and form.getNoReg() == academico.getNoReg()) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void MenuUsr::guardaDocencia(Docencia& doc, const std::string& archivo) {
    //Guarda el objeto dentro del archivo
    ofstream file(archivo, ios::app);
    file.write((char*) &doc, sizeof(Docencia));
    file.close();
}

bool MenuUsr::existeDocencia(const std::string& nombre) {
    ifstream file(string(DIR) + string(ARCH_DOCENCIA));
    if(!file.good()) {
        file.close();
        ofstream file_doc(string(DIR) + string(ARCH_DOCENCIA));
        file_doc.close();
        return false;
    }
    while(!file.eof()) {
        Docencia doc;
        file.read((char*)&doc, sizeof(Docencia));
        if(file.eof()) {
            break;
        }
        //Busca si existe el nombre de formación
        if(string(doc.getNombre()) == nombre and doc.getNoReg() == academico.getNoReg()) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void MenuUsr::guardaTutoria(Tutoria& tut, const std::string& archivo) {
    //Guarda el objeto dentro del archivo
    ofstream file(archivo, ios::app);
    file.write((char*) &tut, sizeof(Tutoria));
    file.close();
}

bool MenuUsr::existeTutoria(const std::string& nombreTutorado) {
    ifstream file(string(DIR) + string(ARCH_TUTORIA));
    if(!file.good()) {
        file.close();
        ofstream file_tut(string(DIR) + string(ARCH_TUTORIA));
        file_tut.close();
        return false;
    }
    while(!file.eof()) {
        Tutoria tut;
        file.read((char*)&tut, sizeof(Tutoria));
        if(file.eof()) {
            break;
        }
        //Busca si existe el nombre de formación
        if(string(tut.getNombreTutorado()) == nombreTutorado and tut.getNoReg() == academico.getNoReg()) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void MenuUsr::guardaProduccion(Produccion& pro, const std::string& archivo) {
    //Guarda el objeto dentro del archivo
    ofstream file(archivo, ios::app);
    file.write((char*) &pro, sizeof(Produccion));
    file.close();
}

bool MenuUsr::existeProduccion(const std::string& nombre) {
    ifstream file(string(DIR) + string(ARCH_PRODUCCION));
    if(!file.good()) {
        file.close();
        ofstream file_prod(string(DIR) + string(ARCH_PRODUCCION));
        file_prod.close();
        return false;
    }
    while(!file.eof()) {
        Produccion pro;
        file.read((char*)&pro, sizeof(Produccion));
        if(file.eof()) { break; }
        //Busca si existe el nombre de formación
        if(string(pro.getNombre()) == nombre and pro.getNoReg() == academico.getNoReg()) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}
//Implementar luego expresión regular
bool MenuUsr::fechaCorrecta(const std::string& fecha) {
    regex rx("[0-9]{2}/[0-9]{2}/[0-9]{4}");
    if(regex_match(fecha, rx)) {
        return true;
    }
    return false;
}

