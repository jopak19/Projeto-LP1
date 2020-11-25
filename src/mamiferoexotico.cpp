#include "mamiferoexotico.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

MamiferoExotico::MamiferoExotico (string codigo, 
                                string peso, 
                                string altura, 
                                short idade, 
                                string especie,
                                Gestacao gestacao,
                                int marcacaoPermanente,
                                bool emExtincao,
                                string territorioDeOrigem,
                                bool perigoso):
                                Mamifero(codigo, peso, altura,idade, especie, gestacao, perigoso),
                                Exotico(marcacaoPermanente, emExtincao, territorioDeOrigem){
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Azul;
    }

};
string MamiferoExotico::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string extincao = this->getEmExtincao() ? "Sim" : "Não";
    string gestacao;
    if(this->getGestacao() == PLACENTARIO) gestacao = "placentário";
    if(this->getGestacao() == MONOTREMADO) gestacao = "monotremado";
    if(this->getGestacao() == MARSUPIAL) gestacao = "marsupial";

	dados = "codigo: " + this->getCodigo() + " Peso: " + this->getPeso() + " Altura: "+this->getAltura() + " Especie: " + this->getEspecie() + " Perigoso: "  + perigo + 
    " Gestação: " + gestacao + 
    " Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " Em extinção: " + extincao + " Território origem: " + this->getTerritorioDeOrigem();
	return dados;
};

ostream& operator<< (ostream &o, MamiferoExotico animal){
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
    //TODO: saida dados exoticos
    << endl
    << animal.getCodigo() << setfill(' ') << setw(5) 
    << animal.getCodigo() << setfill(' ') << setw(5) 
    << animal.getPeso() << setfill(' ') << setw(5) 
    << animal.getAltura() << setfill(' ') << setw(5) 
    << animal.getIdade() << setfill(' ') << setw(5)
    << animal.getEspecie() << setfill(' ') << setw(5)
    << gestacao_ << setfill(' ') << setw(5)
    << endl;
	return o;
};