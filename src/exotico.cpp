#include "exotico.hpp"


Exotico::Exotico(int marcacaoPermanente, bool perigoso, bool emExtincao, string territorioDeOrigem):
                Silvestre(marcacaoPermanente, perigoso, emExtincao),
                territorioDeOrigem(territorioDeOrigem){};

string Exotico::getTerritorioDeOrigem() const{
    return this->territorioDeOrigem;
};
void Exotico::setTerritorioDeOrigem(string territorio){
    this->territorioDeOrigem = territorio;
};