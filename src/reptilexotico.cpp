#include "reptilexotico.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

ReptilExotico::ReptilExotico (  string codigo, 
                                string peso, 
                                string altura, 
                                short idade, 
                                string especie,
                                string periodoDeMudadepele,
                                TipoDePele tipoDePele,
                                int marcacaoPermanente,
                                bool emExtincao,
                                string territorioDeOrigem,
                                bool perigoso):
                                Reptil(codigo, peso, altura,idade, especie, periodoDeMudadepele, tipoDePele, perigoso),
                                Exotico(marcacaoPermanente, emExtincao, territorioDeOrigem){
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Azul;
    }
};

string ReptilExotico::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string extincao = this->getEmExtincao() ? "Sim" : "Não";
    string tipoPele;
    if(this->getTipoDepele() == CARAPACA) tipoPele = "Carapaça";
    if(this->getTipoDepele() == ESCAMAS) tipoPele = "Escamas";
    if(this->getTipoDepele() == PLACADERMICA) tipoPele = "Placa dérmica";
	dados = "codigo: " + this->getCodigo() + " Peso: " + this->getPeso() + " Altura: "+this->getAltura() + " Especie: " + this->getEspecie() + " Perigoso: "  + perigo + 
    " Muda de Pele: " + this->getPeriodoDeMudadepele() + " Tipo de Pele: " + tipoPele +
    " Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " Em extinção: " + extincao + " Território origem: " + this->getTerritorioDeOrigem();
;
	return dados;
};

ostream& operator<< (ostream &o, ReptilExotico animal){
     /*Como o Reptil exotico será exibido em tela*/
    o << "Código" << setfill(' ') << setw(5) 
    << "Peso" << setfill(' ') << setw(5) 
    << "altura" << setfill(' ') << setw(5)
    << "idade" << setfill(' ') << setw(5)
    << "especie" << setfill(' ') << setw(5) 
    << "Muda de pele" << setfill(' ') << setw(5)
    << "Temperatura do ambiente" << setfill(' ') << setw(5)
    //TODO: falta as especificas   
    << endl
    << animal.getCodigo() << setfill(' ') << setw(5) 
    << animal.getPeso() << setfill(' ') << setw(5) 
    << animal.getAltura() << setfill(' ') << setw(5) 
    << animal.getIdade() << setfill(' ') << setw(5)
    << animal.getEspecie() << setfill(' ') << setw(5)
    << animal.getPeriodoDeMudadepele() << setfill(' ') << setw(5)
    << animal.getTipoDepele() << setfill(' ') << setw(5) 
    << endl;
	return o;
};