#include <iostream>
#include <fstream>
#include <string>
#include "Catalogo.h"
#include "Pelicula.h"
#include "Video.h"
using namespace std;

/* Referencias: 
Para el uso de fstream y la lectura de datos del .txt que use en el Catalogo.cpp segui
el video de youtube de Codigazo con link  https://www.youtube.com/watch?v=RBZidsPGkfs&t=601s&ab_channel=Codigazo
*/
int main() {
  vector<Catalogo*> catalogo;
  catalogo.push_back(new Catalogo("Simon")); 
  bool salir = false;
  
  while (salir == false) {
     //Menu - Enviar a funcion Menu()
    string decision;
    cout << "1: Mostrar todo el catalogo con calificaciones" << endl;
    cout << "2: Calificar un video" << endl;
    cout << "3: Mostrar peliculas o capitulos con una calificacion minima determinada" << endl;
    cout << "4: Mostrar peliculas o capitulos de un cierto genero" << endl;
    cout << "9: Salir" << endl;
    cin >> decision;
    //---------------------------------------------
    //Accion - Ciclo if que envia a funciones
    if (decision == "1") {
      catalogo[0]->mostrarCatalogo();
    } else if (decision == "2") {
      string id = "";
      int calificacion;
      cout << "id del video a calificar: ";
      cin >> id;
      cout << "Ingresa la calificacion del 1-5";
      cin >> calificacion;
      catalogo[0]->calificar(id,calificacion);
    } else if (decision == "3") {
      double minima = 0;
      int eleccion;
      cout << "1: Peliculas" << endl;
      cout << "2: Capitulos" << endl;
      cout << "3: Ambos" << endl;
      cin >> eleccion;
      cout << "Calificacion minima: ";
      cin >> minima;
      catalogo[0]->mostrarPorCalificacion(minima, eleccion);
    } else if (decision == "4") {
      string genero = "";
      int eleccion = 0;
      cout << "1: Peliculas" << endl;
      cout << "2: Capitulos" << endl;
      cout << "3: Ambos" << endl;
      cin >> eleccion;
      cout << "Genero - ingresalo textualmente: " << endl;
      cout << "drama " << endl;
      cout << "accion " << endl;
      cout << "misterio " << endl;
      cin >> genero;
      catalogo[0]->mostrarPorGenero(genero, eleccion);
    } else if (decision == "9") {
      salir = true;
    } else {
      cout << "Valor ingresado invalido, ingresa del 1-4 " << endl;
    }
  }
}