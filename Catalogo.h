#pragma once
#include <iostream>
#include <string>
#include "Video.h"
using namespace std;

class Catalogo {
  protected:
    vector<Video*> videos;
    string plataforma;
  public:
    Catalogo();
    Catalogo(string plataforma);
    void mostrarCatalogo();
    void calificar(string id, int calificacion);
    void mostrarPorCalificacion(int minima, int eleccion);
    void mostrarPorGenero(string genero, int eleccion);
};