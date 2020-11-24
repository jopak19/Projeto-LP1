#include "nativo.hpp"

Nativo::Nativo (int marcacaoPermanente, bool emExtincao, Bioma biomaOrigem):
                Silvestre(marcacaoPermanente, emExtincao),
                biomaOrigem(biomaOrigem){};


Bioma Nativo::getBiomaOrigem() const{
    return this->biomaOrigem;
};
void Nativo::setBiomaOrigem(Bioma bioma){
    this->biomaOrigem = bioma;
};