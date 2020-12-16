#include "exotico.hpp"

Exotico::Exotico(int marcacaoPermanente, bool emExtincao, string territorioDeOrigem):
                Silvestre(marcacaoPermanente, emExtincao),
                territorioDeOrigem(territorioDeOrigem){};

Exotico::~Exotico(){}
//getters e setters
string Exotico::getTerritorioDeOrigem() const{
    return this->territorioDeOrigem;
}

void Exotico::setTerritorioDeOrigem(string territorio){
    this->territorioDeOrigem = territorio;
}
