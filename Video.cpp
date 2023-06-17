#include "Video.h"

Video::Video(string video) {
  int comas = 0;
  string id = "";
  string nombre = "";
  string duracion = "";
  string genero = "";
  for (char caracter : video) {
        if (caracter == 44) {
          comas++;
        } else if (comas == 0) {
          //Solo brinca
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
  this->id = id;
  this->nombre = nombre;
  this->duracion = duracion;
  this->genero = genero;
  this->calificacion = "SC";
  this->extra = this->calificacion;
  
};
Video::Video():Video("p,20191245,The Lion King,118,drama"){};

void Video::calificar(int calificacion) {
  this->calificaciones.push_back(calificacion);
  string caliString = "";
  if (this->calificaciones.size() == 0) {
    caliString = "SC";
  } else {
    double suma = 0;
    for (int i=0; i < this->calificaciones.size(); i++) {
      suma = suma + this->calificaciones[i];  
    }
    caliString = to_string(suma/(this->calificaciones.size()));
  }
  this->calificacion = caliString;
};
string Video::getId() {
  return this->id;
};

string Video::getCalificacion() {
  return this->calificacion;
}
double Video::getCalificacionNum() {
  if (this->calificaciones.size() == 0) {
    return 0.0;
  } else {
    double suma = 0;
    for (int i=0; i < this->calificaciones.size(); i++) {
      suma = suma + this->calificaciones[i];  
    }
    return suma/(this->calificaciones.size());
  }
};

string Video::getGenero() {
  return this->genero;
};

string Video::toStringReduced() {
  return this->id +","+ this->nombre + "," + this->getCalificacion();
};