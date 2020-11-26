#include "avenativo.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

AveNativo::AveNativo (string codigo, 
                                string peso, 
                                string altura, 
                                short idade, 
                                string especie,
                                bool aquatica,
                                bool podeVoar,
                                int marcacaoPermanente,
                                bool emExtincao,
                                Bioma biomaOrigem,
                                bool perigoso):
                                Ave(codigo, peso, altura,idade, especie, aquatica, podeVoar, perigoso),
                                Nativo(marcacaoPermanente, emExtincao, biomaOrigem){
    setClasse();
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Verde;
    }

};
void AveNativo::setClasse(){
    this->classe = "avenativo";
};

//como ave nativa será exibida
string AveNativo::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string extincao = this->getEmExtincao() ? "Sim" : "Não";
    string aqua = this->aquatica ? "aquatica" : "não Aquatica";
    string voa = this->podeVoar ? "voa" : "Não voa";
    string bioma;
    if(this->getBiomaOrigem() == AMAZONIA) bioma = "Amazonia";
    if(this->getBiomaOrigem() == CERRADO) bioma = "Cerrado";
    if(this->getBiomaOrigem() == PAMPA) bioma = "Pampa";
    if(this->getBiomaOrigem() == CAATINGA) bioma = "Caatinga";
    if(this->getBiomaOrigem() == PANTANAL) bioma = "Pantanal";
    if(this->getBiomaOrigem() == MATAATLANTICA) bioma = "Mata Atlântica";
	dados = "codigo: " + this->getCodigo() + " Peso: " + this->getPeso() + " Altura: "+this->getAltura() + " Especie: " + this->getEspecie() + " Perigoso: "  + perigo + 
    " Aquatica: " + aqua + " Pode var: " + voa + 
    " Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " Em extinção: " + extincao + " Bioma origem: " + bioma;
	return dados;
};
