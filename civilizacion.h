#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iomanip>
#include <algorithm>
#include <list>
#include <vector>
#include <fstream>
#include "aldeano.h"

class Civilizacion{
    public://Metodos 
    Civilizacion();

    void setNombre(const string &nombre);
    string getNombre() const;

    void setUbicacionX(int ubicacion_x);
    int getUbicacionX() const;
    
    void setUbicacionY(int ubicacion_y);
    int getUbicacionY() const;

    void setPuntuacion(float puntuacion);
    float getPuntuacion() const;

    //Opciones del menu para administrar aldeanos
    void agregar_aldeano_inicio(const Aldeano &aldeano); 
    void agregar_aldeano_final(const Aldeano &aldeano);

    void eliminar_nombre(const string &nombre);
    void eliminar_salud(float salud);
    void eliminar_edad();

    void calsificar_nombre();
    void clasificar_edad();
    void clasificar_salud();

    Aldeano* buscar_aldeano(const Aldeano &ald);

    void modificar_aldeano(Aldeano *ald);

    void mostrar();

    void respaldar_aldeanos();
    void recuperar_aldeanos(vector<Civilizacion> &civilizaciones);

    friend ostream& operator << (ostream &os, const Civilizacion& c){
            os<<left;
            os<<setw(22)<<c.nombre;
            os<<setw(20)<<c.ubicacion_x;
            os<<setw(20)<<c.ubicacion_y;
            os<<setw(15)<<c.puntuacion;

            os<<endl;

            return os;
    }

    friend istream& operator >> (istream &is, Civilizacion& c){
        cout<<"Nombre de la civilizacion: ";
        getline(cin, c.nombre);

        cout<<"Ubicacion en X: ";
        cin>>c.ubicacion_x;

        cout<<"Ubicacion en Y: ";
        cin>>c.ubicacion_y;

        cout<<"Puntuacion: ";
        cin>>c.puntuacion;

        return is;
    }

    bool operator<(const Civilizacion& c){
        return nombre > c.nombre;//los ordena por nombre
    }
    bool operator<(const Civilizacion& c) const{
        return nombre > c.nombre;//Los ordena por nombre
    }

    bool operator == (const Civilizacion& c){
        return nombre == c.nombre;
    }
    bool operator == (const Civilizacion& c) const{
        return nombre == c.nombre;
    }

    private:
        list<Aldeano> aldeanos;

        string nombre;
        int ubicacion_x;
        int ubicacion_y;
        float puntuacion;
};


#endif 