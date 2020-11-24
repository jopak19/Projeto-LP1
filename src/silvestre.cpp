#include "silvestre.hpp"

Silvestre::Silvestre(int marcacaoPermanente,
                    bool perigoso,
                    bool emExtincao):
                    marcacaoPermanente(marcacaoPermanente),perigoso(perigoso),emExtincao(emExtincao){};

int Silvestre::getMarcacaoPermanente() const{
    return this->marcacaoPermanente;
};
void Silvestre::setMarcacaoPermanente(int marcacao){
    this->marcacaoPermanente = marcacao;
};
bool Silvestre::getPerigoso() const{
    return this->perigoso;
};
void Silvestre::setPerigoso(bool perigoso){
    this->perigoso = perigoso;
};
bool Silvestre::getEmExtincao() const{
    return this->emExtincao;
};
void Silvestre::setEmExtincao(bool emExtincao){
    this->emExtincao = emExtincao;
};