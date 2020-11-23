#include "nativo.hpp"

Nativo::Nativo (int marcacaoPermanente):
                marcacaoPermanente(marcacaoPermanente){};

int Nativo::getMarcacaoPermanente() const{
    return this->marcacaoPermanente;
};
void Nativo::setMarcacaoPermanente(int marcacao){
    this->marcacaoPermanente = marcacao;
}