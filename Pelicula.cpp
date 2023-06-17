#include "Pelicula.h"

Pelicula::Pelicula(string video) {
  int comas = 0;
  string tipo = "";
  string id = "";
  string nombre = "";
  string duracion = "";
  string genero = "";
  for (char caracter : video) {
        if (caracter == 44) {
          comas++;
        } else if (comas == 0) {
          tipo = tipo + caracter;
        } else if (comas == 1) {
          id = id + caracter;
        } else if (comas == 2) {
          nombre = nombre + caracter;
        } else if (comas == 3) {
          duracion = duracion + caracter;
        } else if (comas == 4) {
          genero = genero + caracter;
        } 
  }
  this->tipo = tipo;
  this->id = id;
  this->nombre = nombre;
  this->duracion = duracion;
  this->genero = genero;
  this->calificacion = "SC";
  this->extra = this->calificacion;
};


string Pelicula::getTipo() {
  return this->tipo;
};