#include "mamiferonativo.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

MamiferoNativo::MamiferoNativo (string codigo, 
                                string peso, 
                                string altura, 
                                short idade, 
                                string especie,
                                Gestacao gestacao,
                                int marcacaoPermanente,
                                bool emExtincao,
                                Bioma biomaOrigem,
                                bool perigoso):
                                Mamifero(codigo, peso, altura,idade, especie, gestacao, perigoso),
                                Nativo(marcacaoPermanente, emExtincao, biomaOrigem){
    
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Azul;
    }

};

string MamiferoNativo::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string extincao = this->getEmExtincao() ? "Sim" : "Não";
    string gestacao;
    if(this->getGestacao() == PLACENTARIO) gestacao = "placentário";
    if(this->getGestacao() == MONOTREMADO) gestacao = "monotremado";
    if(this->getGestacao() == MARSUPIAL) gestacao = "marsupial";
    string bioma;
    if(this->getBiomaOrigem() == AMAZONIA) bioma = "Amazonia";
    if(this->getBiomaOrigem() == CERRADO) bioma = "Cerrado";
    if(this->getBiomaOrigem() == PAMPA) bioma = "Pampa";
    if(this->getBiomaOrigem() == CAATINGA) bioma = "Caatinga";
    if(this->getBiomaOrigem() == PANTANAL) bioma = "Pantanal";

	dados = "codigo: " + this->getCodigo() + " Peso: " + this->getPeso() + " Altura: "+this->getAltura() + " Especie: " + this->getEspecie() + " Perigoso: "  + perigo + 
    " Gestação: " + gestacao + 
    " Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " Em extinção: " + extincao + " Bioma origem: " + bioma;
	return dados;
};

ostream& operator<< (ostream &o, MamiferoNativo animal){
     /*Como o mamifero será exibido em tela*/
    string gestacao_;

    if(animal.getGestacao() == MONOTREMADO){
        gestacao_ = "monotremado";
    } else if(animal.getGestacao() == MARSUPIAL){
        gestacao_ = "marsupial";
    }else{
        gestacao_ = "placentario";
    };
    o << "Código" << setfill(' ') << setw(5) 
    << "Peso" << setfill(' ') << setw(5) 
    << "altura" << setfill(' ') << setw(5)
    << "idade" << setfill(' ') << setw(5)
    << "especie" << setfill(' ') << setw(5) 
    << "Gestação" << setfill(' ') << setw(5)  
    //TODO: saida dados nativos
    << endl
    << animal.getCodigo() << setfill(' ') << setw(5) 
    << animal.getPeso() << setfill(' ') << setw(5) 
    << animal.getAltura() << setfill(' ') << setw(5) 
    << animal.getIdade() << setfill(' ') << setw(5)
    << animal.getEspecie() << setfill(' ') << setw(5)
    << gestacao_ << setfill(' ') << setw(5)
    << endl;
	return o;
};