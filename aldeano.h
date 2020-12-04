#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>

using namespace std;

class Aldeano{
    public: 
    Aldeano();

    void setNombre(const string &nombre);
    string getNombre() const;

    void setEdad(int edad);
    int getEdad() const;

    void setGenero(const string &genero);
    string getGenero() const;

    void setSalud(float salud);
    float getSalud() const;

    //Sobrecarga del operador >> para leer los datos
    friend istream & operator >> (istream &is, Aldeano &ald){

        cout<<"Nombre: "; 
        getline(cin, ald.nombre);

        cout<<"Edad: ";
        cin>>ald.edad;

        cout<<"Salud: ";
        cin>>ald.salud;
        cin.ignore();

        cout<<"Genero: ";
        getline(cin, ald.genero);

        return is;
    }

    friend ostream & operator << (ostream &os, const Aldeano &ald){
        os<<left;
        os<<setw(20)<<ald.getNombre();
        os<<setw(20)<<ald.getEdad();
        os<<setw(20)<<ald.getSalud();
        os<<setw(15)<<ald.getGenero();

        os<<endl;

        return os;
    }
    
    //sobrecargar el operador < para ordenar por nombre
    bool operator <(const Aldeano &ald){
        return nombre < ald.getNombre();
    }
    bool operator <(const Aldeano &ald) const{
        return nombre < ald.getNombre();
    }
    
    //Sobrecargar operador == para realizar busqueda de aldeanos
    bool operator == (const Aldeano &ald){
        return nombre == ald.getNombre();
    }
    bool operator == (const Aldeano &ald) const{
        return nombre == ald.getNombre();
    }
    
    private:
        string nombre;
        int edad;
        string genero;
        float salud;
};


#endif