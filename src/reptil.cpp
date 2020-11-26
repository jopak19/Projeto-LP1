#include "reptil.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

//construtor
Reptil::Reptil(string codigo, 
                string peso, 
                string altura, 
                short idade, 
                string especie,
                string periodoDeMudadepele,
                TipoDePele tipoDePele,
                bool perigoso = false):
                Animal(codigo, peso, altura, idade, especie, perigoso),
                periodoDeMudaDePele(periodoDeMudadepele), tipoDePele(tipoDePele){
    setClasse();
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Azul;
    }
};

//getters e setters
string Reptil::getPeriodoDeMudadepele() const{
    return this->periodoDeMudaDePele;
};
void Reptil::setPeriodoDeMudadepele(string periodo){
    this->periodoDeMudaDePele = periodo;
};
TipoDePele Reptil::getTipoDepele() const{
    return this->tipoDePele;
};
void Reptil::setTipoDePele(TipoDePele tipo){
    this->tipoDePele = tipo;
};
void Reptil::setClasse(){
    this->classe = "reptil";
};

//como reptil será exibido
string Reptil::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string tipoPele;
    if(this->getTipoDepele() == CARAPACA) tipoPele = "Carapaça";
    if(this->getTipoDepele() == ESCAMAS) tipoPele = "Escamas";
    if(this->getTipoDepele() == PLACADERMICA) tipoPele = "Placa dérmica";
	dados = "codigo: " + this->getCodigo() + " Peso: " + this->getPeso() + " Altura: "+this->getAltura() + " Especie: " + this->getEspecie() + " Perigoso: "  + perigo + 
    " Muda de Pele: " + this->getPeriodoDeMudadepele() + " Tipo de Pele: " + tipoPele;
	return dados;
};
