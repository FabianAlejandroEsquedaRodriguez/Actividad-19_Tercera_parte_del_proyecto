#include <iostream>
#include "menu_civilizaciones.h"
#include "videogame.h"
#include "civilizacion.h"

using namespace std;

int main(){
    system("color F4");

    VideoGame vg;//En esta instancia se crea nuestro vector de civilizaciones

    //Menu para manipular un objeto de la clase VideoGame
    string opc;

    do{
        cout<<"\t\t\tMENU DE OPCIONES PARA CIVILIZACIONES"<<endl<<endl;
        cout<<"1) NOMBRE DE USUARIO"<<endl;
        cout<<"2) NOMBRE DE LA CIVILIZACION"<<endl;
        cout<<"3) INSERTAR CIVILIZACION EN UNA POSICION"<<endl;
        cout<<"4) CREAR CIVILIZACIONES"<<endl;
        cout<<"5) PRIMERA CIVILIZACION"<<endl;
        cout<<"6) ULTIMA CIVILIZACION"<<endl;
        cout<<"7) ORDENAR"<<endl;
        cout<<"8) ELIMINAR CIVILIZACION"<<endl;
        cout<<"9) BUSCAR CIVILIZACION"<<endl;
        cout<<"10) MODIFICAR CIVILIZACION"<<endl;
        cout<<"11) RESUMEN"<<endl;
        cout<<"12) RESPALDAR CIVILIZACIONES"<<endl;
        cout<<"13) RECUPERAR CIVILIZACIONES"<<endl;
        cout<<"0) Salir"<<endl;

        cout<<endl<<"ELIGE UNA OPCION: ";
        getline(cin, opc);
        system("cls");
        

        if(opc == "1"){
            cout<<"\t\t\tREGISTRA TU NOMBRE DE USUARIO"<<endl<<endl;
            string nombre_usuario;

            cout<<"DIGITA TU NOMBRE DE USUARIO: ";
            getline(cin, nombre_usuario);

            cout<<endl<<endl<<endl<<"\t\t\tNOMBRE DE USUARIO REGISTRADO"<<endl<<endl;
            cin.ignore();

            vg.setNombreUsuario(nombre_usuario);
        }

        if(opc == "2"){
            cout<<"\t\t\tAGREGAR CIVILIZACION"<<endl<<endl;
            cout<<"NOMBRE DE USUARIO: "<<vg.getNombreUsuario()<<endl<<endl;

            Civilizacion c;
            cin>>c;

            vg.agregar_civilizacion(c);
            cin.ignore();
        }

        if(opc == "3"){
            cout<<"\t\t\tINSERTAR CIVILIZACION EN UNA POSICION VALIDA"<<endl<<endl;
            cout<<"NOMBRE DE USUARIO: "<<vg.getNombreUsuario()<<endl<<endl;
            Civilizacion c;

            size_t pos;

            cin>>c;//Se hace uso de la sobrecarga del operador >>

            cout<<endl<<"Digita una posicion: ";
            cin>>pos;

            cin.ignore();

            if(pos >= vg.total()){
                cout<<endl<<"Posicion no valida"<<endl;
            }
            else{
                vg.insertar_pos_valida(c, pos);
            }
        }

        if(opc == "4"){
            cout<<"\t\t\tINICIALIZAR EL VECTOR\n\n";
            cout<<"NOMBRE DE USUARIO: "<<vg.getNombreUsuario()<<endl<<endl;

            Civilizacion c;
            size_t n;
            
            cin>>c;//Se hace uso de la sobrecarga del operador >>

            cout<<endl<<"Numero de veces a repetir la civilizacion: ";
            cin>>n;

            cin.ignore();

            vg.inicializar(c, n);
        }

        if(opc == "5"){
            cout<<"\t\t\tPRIMERA CIVILIZACION REGISTRADA"<<endl<<endl;
            cout<<"NOMBRE DE USUARIO: "<<vg.getNombreUsuario()<<endl<<endl;

            Civilizacion c;

            if(vg.total() > 0){
                cout << left;
                cout << "\n";
                cout << setw(22)<<"NOMBRE";
                cout << setw(20)<<"UBICACION EN X";
                cout << setw(20)<<"UBICACION EN Y";
                cout << setw(15)<<"PUNTUACION";
                cout << endl << endl;
                
                cout<<vg.primera_civilizacion();
            }
            else{
                cout<<endl<<endl<<"NO HAY NINGUNA CIVILIZACION REGISTRADA"<<endl<<endl;
            }
        }

        if(opc == "6"){
            cout<<"\t\t\tULTIMA CIVILIZACION REGISRADA"<<endl<<endl;
            cout<<"NOMBRE DE USUARIO: "<<vg.getNombreUsuario()<<endl<<endl;

            Civilizacion c;

            if(vg.total() > 0){
                cout << left;
                cout << "\n";
                cout << setw(22)<<"NOMBRE";
                cout << setw(20)<<"UBICACION EN X";
                cout << setw(20)<<"UBICACION EN Y";
                cout << setw(15)<<"PUNTUACION";
                cout << endl << endl;
                
                cout<<vg.ultima_civilizacion();
            }
            else{
                cout<<endl<<endl<<"NO HAY NINGUNA CIVILIZACION REGISTRADA"<<endl<<endl;
            }
        }

        if(opc == "7"){
            cout<<"\t\t\tORDENAR CIVILIZACIONES"<<endl<<endl;
            cout<<"NOMBRE DE USUARIO: "<<vg.getNombreUsuario()<<endl<<endl;

            size_t opc;

            cout<<"1) POR NOMBRE"<<endl;
            cout<<"2) POR UBICACION EN X"<<endl;
            cout<<"3) POR UBICACION EN Y"<<endl;
            cout<<"4) POR PUNTUACION"<<endl;

            cout<<"\n\nDIGITA UNA OPCION: ";
            cin>>opc;
            cin.ignore();

            cout<<"\n\n";

            switch(opc){
                case 1: vg.ordenar_nombre(); cout<<"ORDENANDO POR NOMBRE"<<endl; break;
                case 2: vg.ordenar_ubX(); cout<<"ORDENANDO POR UBICACION EN X"<<endl; break;
                case 3: vg.ordenar_ubY(); cout<<"ORDENANDO POR UBICACION EN Y"<<endl; break;
                case 4: vg.ordenar_puntuacion(); cout<<"ORDENANDO POR PUNTUACION"<<endl; break;
            }
        }

        if(opc == "8"){
            cout<<"\t\t\tELIIMINAR UNA CIVILIZACION"<<endl<<endl;
            cout<<"NOMBRE DE USUARIO: "<<vg.getNombreUsuario()<<endl<<endl;

            string nombre;

            cout<<"Nombre de la civilizacion a eliminar: "; 
            getline(cin, nombre);
            
            vg.eliminar_civilizacion(nombre);
        }

        if(opc == "9"){
            cout<<"\t\t\tBUSCAR UNA CIVILIZACION\n\n";
            cout<<"NOMBRE DE USUARIO: "<<vg.getNombreUsuario()<<endl<<endl;

            string nombre;
            Civilizacion c;
            cout<<"NOMBRE DE LA CIVILIZACION A BUSCAR: ";
            getline(cin, nombre);

            c.setNombre(nombre);


            Civilizacion *ptr = vg.buscar_civilizacion(c);

            if (ptr == nullptr){
                cout<<"\n\n\t\t\tNo se encontro la civilizacion que quieres buscar"<<endl;
            }
            else{
                system("cls");

                cout<<"\t\t\tCIVILIZACION ENCONTRADA"<<endl<<endl;
                
                cout << left;
                cout << "\n";
                cout << setw(22)<<"NOMBRE";
                cout << setw(20)<<"UBICACION EN X";
                cout << setw(20)<<"UBICACION EN Y";
                cout << setw(15)<<"PUNTUACION";
                cout << endl;

                cout<<endl<<*ptr<<endl<<endl<<endl;//Se hace la referenciacion para que pueda imprimir la computadora

                system("pause"); system("cls");
                menu(*ptr);
            }
        }

        if(opc == "10"){
            cout<<"\t\t\tMODIFICAR CIVILIZACION"<<endl<<endl;
            cout<<"NOMBRE DE USUARIO: "<<vg.getNombreUsuario()<<endl<<endl;

            string nombre;
            Civilizacion c;
            cout<<"NOMBRE DE LA CIVILIZACION A MODIFICAR: ";
            getline(cin, nombre);

            c.setNombre(nombre);

            Civilizacion *ptr = vg.buscar_civilizacion(c);

            if(ptr == nullptr){
                cout<<"\n\nNO SE ENCONTRO LA CIVILIZACION"<<endl<<endl;
            }
            else{
                system("cls");
                cout<<"\t\t\tCIVILIZACION A MODIFICAR"<<endl;
                
                cout << left;
                cout << "\n";
                cout << setw(22)<<"NOMBRE";
                cout << setw(20)<<"UBICACION EN X";
                cout << setw(20)<<"UBICACION EN Y";
                cout << setw(15)<<"PUNTUACION";
                cout<<endl;

                cout<<endl<< *ptr<<endl<<endl;
                vg.modificar_civilizacion(ptr);
            }
        }

        if(opc == "11"){
            cout<<"\t\t\tCIVILIZACIONES REGISTRADAS"<<endl<<endl;
            cout<<"NOMBRE DE USUARIO: "<<vg.getNombreUsuario()<<endl<<endl;

            vg.resumen();
        }

        if(opc =="12"){
            cout<<"\t\t\tRESPALDANDO CIVILIZACIONES Y ALDEANOS EN UN ARCHIVO .TXT"<<endl<<endl;
                vg.respaldar_civilizaciones();
        }

        if(opc == "13"){
            cout<<"\t\t\tRECUPERANDO CIVILIZACIONES"<<endl<<endl;

            vg.recuperar();
        }

        if(opc == "0"){
            break;
        }

        cout<<endl<<endl;
        system("pause"); system("cls");

    }while(opc != "0");

    return 0;
}