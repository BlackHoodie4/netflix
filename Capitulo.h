#pragma once
#include "Video.h"

class Capitulo:public Video {
  protected:
    string tipo;
    string serie;
    string episodio;
  public:
    Capitulo(string video);
    string getTipo();
};