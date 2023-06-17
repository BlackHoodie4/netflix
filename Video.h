#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Video{
  protected:
    string tipo;
    string id;
    string nombre;
    string duracion;
    string genero;
    string resumen;
    vector<int> calificaciones;
    string calificacion;
    string extra;
  public:
    Video(string video);
    Video();
    void calificar(int calificacion);
    string getId();
    string getCalificacion();
    double getCalificacionNum();
    string getGenero();
    string toStringReduced();
    virtual string getTipo()=0;
    friend ostream& operator<<(ostream& os,const Video& v){
      os<<v.id<<","<<v.nombre<<","<<v.duracion<<","<<v.genero<<","<<v.extra;
      return os;  
    }
    
};