#include "silvestre.hpp"

Silvestre::Silvestre(int marcacaoPermanente,
                    bool emExtincao):
                    marcacaoPermanente(marcacaoPermanente),emExtincao(emExtincao){};

int Silvestre::getMarcacaoPermanente() const{
    return this->marcacaoPermanente;
};
void Silvestre::setMarcacaoPermanente(int marcacao){
    this->marcacaoPermanente = marcacao;
};

bool Silvestre::getEmExtincao() const{
    return this->emExtincao;
};
void Silvestre::setEmExtincao(bool emExtincao){
    this->emExtincao = emExtincao;
};