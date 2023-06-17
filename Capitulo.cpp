#include "Capitulo.h"

Capitulo::Capitulo(string video) {
  int comas = 0;
  string tipo = "";
  string id = "";
  string nombre = "";
  string duracion = "";
  string genero = "";
  string serie = "";
  string episodio = "";
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
        } else if (comas == 5) {
          serie = serie + caracter;
        } else if (comas == 6) {
          episodio = episodio + caracter;
        } 
  }
  this->tipo = tipo;
  this->id = id;
  this->nombre = nombre;
  this->duracion = duracion;
  this->genero = genero;
  this->serie = serie;
  this->episodio = episodio;
  this->calificacion = "SC";
  this->extra = this->serie+","+this->episodio+","+this->calificacion;
};

string Capitulo::getTipo() {
  return this->tipo;
};