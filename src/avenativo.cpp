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

ostream& operator<< (ostream &o, AveNativo animal){
     /*Como o Ave nativo será exibido em tela*/
    o << "Código" << setfill(' ') << setw(5) 
    << "Peso" << setfill(' ') << setw(5) 
    << "altura" << setfill(' ') << setw(5)
    << "idade" << setfill(' ') << setw(5)
    << "especie" << setfill(' ') << setw(5) 
    << "aquatica" << setfill(' ') << setw(5)
    << "pode voar" << setfill(' ') << setw(5)
    //TODO: falta as especificas   
    << endl
    << animal.getCodigo() << setfill(' ') << setw(5) 
    << animal.getPeso() << setfill(' ') << setw(5) 
    << animal.getAltura() << setfill(' ') << setw(5) 
    << animal.getIdade() << setfill(' ') << setw(5)
    << animal.getEspecie() << setfill(' ') << setw(5)
    << animal.getAquatica() << setfill(' ') << setw(5)
    << animal.getPodeVoar() << setfill(' ') << setw(5) 
    << endl;
	return o;
};