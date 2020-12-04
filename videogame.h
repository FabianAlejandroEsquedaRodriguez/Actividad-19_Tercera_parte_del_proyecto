#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "civilizacion.h"

using namespace std;

class VideoGame{
    public:
    VideoGame();

    void setNombreUsuario(const string& nombre_usuario);
    string getNombreUsuario();

    void agregar_civilizacion(const Civilizacion& civi);
    void insertar_pos_valida(const Civilizacion& civi, size_t pos);
    void inicializar(const Civilizacion& civi, size_t n);
    
    Civilizacion primera_civilizacion();
    Civilizacion ultima_civilizacion();

    void ordenar_nombre();
    void ordenar_ubX();
    void ordenar_ubY();
    void ordenar_puntuacion();

    void eliminar_civilizacion(string &nombre);
    Civilizacion* buscar_civilizacion(const Civilizacion& civi);//Va a retornar un puntero de la posicion
                                                                //del vector donde esta el elemento que vamos a buscar
    void modificar_civilizacion(Civilizacion *civi);
    size_t total();

    void resumen();

    void respaldar_civilizaciones();//Modificar para que tenga como parametro el vector de civilizaciones
    void recuperar();

    friend VideoGame& operator << (VideoGame& vg, const Civilizacion& civi){
        vg.agregar_civilizacion(civi);//Llamamos a la funcion y mandamos una civilizacion

        return vg;
    }

    private:
        string nombre_usuario;
        vector<Civilizacion> civilizaciones;//Vector de civilizaciones
};

#endif