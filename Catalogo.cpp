#include "Catalogo.h"
#include "Pelicula.h"
#include "Capitulo.h"
#include <fstream>

Catalogo::Catalogo(string plataforma){
  this->plataforma = plataforma;
  string linea;
    ifstream archivo("videos.txt");
    while (getline(archivo,linea)) {
      if (linea[0] == 112 || linea[0] == 80) {
        this->videos.push_back(new Pelicula(linea));
      } else if (linea[0] == 99 || linea[0] == 67) {
        this->videos.push_back(new Capitulo(linea));
      }
    }
    archivo.close();
};
Catalogo::Catalogo():Catalogo("netflix"){};

void Catalogo::mostrarCatalogo(){
   for (int i=0; i < this->videos.size(); i++) {
     cout << *this->videos[i] << endl;
   }
};
void Catalogo::calificar(string id, int calificacion) {
  for (int i=0; i < this->videos.size(); i++) {
      if (this->videos[i]->getId() == id) {
        this->videos[i]->calificar(calificacion);
      }
  }
};
  
void Catalogo::mostrarPorCalificacion(int minima, int eleccion){
  string tipo = "";
  if (eleccion == 1) {
    tipo = "p";
  } else if (eleccion == 2) {
    tipo = "c";
  } else if (eleccion == 3) {
    tipo = "all";
  }
  for (int i=0; i < this->videos.size(); i++) {
    if (this->videos[i]->getCalificacionNum() > minima && tipo == "all") {
      cout << this->videos[i]->toStringReduced() << endl;
    } else if (this->videos[i]->getCalificacionNum() > minima && this->videos[i]->getTipo() == tipo) {
      cout << this->videos[i]->toStringReduced() << endl;
    } 
  }
};


void Catalogo::mostrarPorGenero(string genero, int eleccion){
  string tipo = "";
  if (eleccion == 1) {
    tipo = "p";
  } else if (eleccion == 2) {
    tipo = "c";
  } else if (eleccion == 3) {
    tipo = "all";
  }
  for (int i=0; i < this->videos.size(); i++) {
    string genero1 = this->videos[i]->getGenero();
    string genero2 = genero1;
    genero2.erase(genero2.size() - 1);
    if (genero == genero1 || genero == genero2 && tipo == "all") {
      cout << this->videos[i]->toStringReduced() << endl;
    } else if (genero == genero1 || genero == genero2 && this->videos[i]->getTipo() == tipo) {
      cout << this->videos[i]->toStringReduced() << endl;
    } 
  }
};