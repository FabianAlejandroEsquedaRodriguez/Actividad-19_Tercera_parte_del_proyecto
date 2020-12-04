#include "videogame.h"
#include "civilizacion.h"

VideoGame::VideoGame(){
    //Constructor
}

void VideoGame::setNombreUsuario(const string& nombre_usuario){
    this->nombre_usuario = nombre_usuario;
}
string VideoGame::getNombreUsuario(){
    return nombre_usuario;
}

void VideoGame::agregar_civilizacion(const Civilizacion& civi){
    civilizaciones.push_back(civi);
}

void VideoGame::insertar_pos_valida(const Civilizacion& civi, size_t pos){
    civilizaciones.insert(civilizaciones.begin()+pos, civi);
}

void VideoGame::inicializar(const Civilizacion& civi, size_t n){
    //Vector de civilizaciones repetidas n veces

    civilizaciones = vector<Civilizacion>(n, civi);//Numero de veces y el vector a agregar
}

Civilizacion VideoGame::primera_civilizacion(){
    return civilizaciones.front();
}

Civilizacion VideoGame::ultima_civilizacion(){
    return civilizaciones.back();
}

void VideoGame::ordenar_nombre(){
    sort(civilizaciones.begin(), civilizaciones.end());//Ordenar desde el inicio del vector hasta el final
}

//Uso de funciones lambda
void VideoGame::ordenar_ubX(){
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [] (Civilizacion c1, Civilizacion c2) {return c1.getUbicacionX() > c2.getUbicacionX();});
}
//Uso de funciones lambda
void VideoGame::ordenar_ubY(){
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [] (Civilizacion c1, Civilizacion c2) {return c1.getUbicacionY() > c2.getUbicacionY();});
}
//Uso de funciones lambda
void VideoGame::ordenar_puntuacion(){
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [] (Civilizacion c1, Civilizacion c2) {return c1.getPuntuacion() > c2.getPuntuacion();});
}

void VideoGame::eliminar_civilizacion(string &nombre){
    VideoGame vg;
    int i=0;
    Civilizacion civi;

    while(i < civilizaciones.size() && civilizaciones[i].getNombre() != nombre){
        i++;
    }
    if(i < civilizaciones.size()){
        cout<<endl<<endl<<"\t\t\tELIMINANDO CIVILIZACION"<<endl<<endl;
        civilizaciones.erase(civilizaciones.begin()+i);
    }
    else{
        cout<<endl<<endl<<"\t\t\tNO SE ENCONTRO LA CIVILIZACION CON EL NOMBRE: "<<nombre<<endl<<endl;
    }  
}

Civilizacion* VideoGame::buscar_civilizacion(const Civilizacion& civi){

    auto it = find(civilizaciones.begin(), civilizaciones.end(), civi);//Recorre todo el vector y busca ela civilizacion civi

    if(it == civilizaciones.end()){//Si el iterador esta apuntando al final del vector
        return nullptr;//No se encontró la civilizacion
    } 
    else{
        //Accede a la posicion y con & me va a regresar la posicion de memoria donde esta esa civilizacion
        return &(*it);//Acceder al elemento haciendo referencia a un puntero
    }
}

void VideoGame::modificar_civilizacion(Civilizacion *civi){
    size_t opc;
    int ubicaciones;
    float punt;
    string nombre;

    do{
        cout<<"\t\t\tMODIFICAR ATRIBUTOS INDIVIDUALES DE LA CIVILIZACION"<<endl<<endl;
        cout<<"1) NOMBRE"<<endl;
        cout<<"2) UBICACION EN X"<<endl;
        cout<<"3) UBICACION EN Y"<<endl;
        cout<<"4) PUNTUACION"<<endl;
        cout<<"0) TERMINAR"<<endl;

        cout<<"\n\nDIGITA UNA OPCION: ";
        cin>>opc;
        cin.ignore();

        cout<<endl<<endl;

        switch(opc){
            case 1: cout<<"MODIFICAR NOMBRE: "; getline(cin, nombre); civi->setNombre(nombre);
                    cout<<"\n\n"; system("pause"); system("cls"); break;
            case 2: cout<<"MODIFICAR UBICACION EN X: "; cin>>ubicaciones; civi->setUbicacionX(ubicaciones);
                    cout<<"\n\n"; system("pause"); system("cls");  break;
            case 3: cout<<"MODIFICAR UBICACION EN Y: "; cin>>ubicaciones; civi->setUbicacionY(ubicaciones);
                    cout<<"\n\n"; system("pause"); system("cls");  break;
            case 4: cout<<"MODIFICAR PUNTUACION: "; cin>>punt; civi->setPuntuacion(punt);
                    cout<<"\n\n"; system("pause"); system("cls");  break;
        }
        
    }while(opc != 0);
}

size_t VideoGame::total(){
    return civilizaciones.size();
}

void VideoGame::resumen(){
    cout << left;
    cout << "\n";
    cout << setw(22)<<"NOMBRE";
    cout << setw(20)<<"UBICACION EN X";
    cout << setw(20)<<"UBICACION EN Y";
    cout << setw(15)<<"PUNTUACION";
    cout << endl << endl;

    for(size_t i=0; i < civilizaciones.size(); i++){
        cout<<civilizaciones[i];

        cout<<endl;
    }
}

void VideoGame::respaldar_civilizaciones(){//Modificar para que tenga como parametro el vector de civilizaciones
    
    ofstream archivo("civilizaciones.txt", ios::out);

    if(archivo.is_open()){
        for (int i = 0; i < civilizaciones.size(); ++i) {
            Civilizacion &c = civilizaciones[i];
            archivo<<c.getNombre()<<endl;
            archivo<<c.getUbicacionX()<<endl;
            archivo<<c.getUbicacionY()<<endl;
            archivo<<c.getPuntuacion()<<endl;

            c.respaldar_aldeanos();
        }
    }
    
    archivo.close();
}

void VideoGame::recuperar(){
    ifstream archivo("civilizaciones.txt");
    
    Civilizacion c;
    
    if(archivo.is_open()){
        string temp;
       
        while(true){
            getline(archivo, temp);
                if(archivo.eof()){
                  break;   
                }
                c.setNombre(temp);

                getline(archivo, temp);
                c.setUbicacionX(stoi(temp));

                getline(archivo, temp);
                c.setUbicacionY(stoi(temp));

                getline(archivo, temp);
                c.setPuntuacion(stof(temp));

                agregar_civilizacion(c);
            }
    }
    archivo.close();  
    c.recuperar_aldeanos(civilizaciones);  
}