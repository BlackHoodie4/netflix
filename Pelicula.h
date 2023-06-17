#pragma once
#include "Video.h"

class Pelicula:public Video {
  protected:
    string tipo;
  public:
    Pelicula(string video);
    string getTipo();
};