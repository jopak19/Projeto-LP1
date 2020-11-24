#include "nativo.hpp"

Nativo::Nativo (int marcacaoPermanente, bool perigoso, bool emExtincao, Bioma biomaOrigem):
                Silvestre(marcacaoPermanente, perigoso, emExtincao),
                biomaOrigem(biomaOrigem){};


Bioma Nativo::getBiomaOrigem() const{
    return this->biomaOrigem;
};
void Nativo::setBiomaOrigem(Bioma bioma){
    this->biomaOrigem = bioma;
};