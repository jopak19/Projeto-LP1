#include "exotico.hpp"

Exotico::Exotico(int marcacaoPermanente, string territorioDeOrigem):
                marcacaoPermanente(marcacaoPermanente), territorioDeOrigem(territorioDeOrigem){};

int Exotico::getMarcacaoPermanente() const{
    return this->marcacaoPermanente;
};
void Exotico::setMarcacaoPermanente(int marcacao){
    this->marcacaoPermanente = marcacao;
}
string Exotico::getTerritorioDeOrigem() const{
    return this->territorioDeOrigem;
};
void Exotico::setTerritorioDeOrigem(string territorio){
    this->territorioDeOrigem = territorio;
};