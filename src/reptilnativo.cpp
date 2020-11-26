#include "reptilnativo.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

ReptilNativo::ReptilNativo(string codigo, 
                            string peso, 
                            string altura, 
                            short idade, 
                            string especie,
                            string periodoDeMudadepele,
                            TipoDePele tipoDePele,
                            int marcacaoPermanente,
                            bool emExtincao,
                            Bioma biomaOrigem,
                            bool perigoso):
                            Reptil(codigo, peso, altura,idade, especie, periodoDeMudadepele, tipoDePele, perigoso),
                            Nativo(marcacaoPermanente, emExtincao, biomaOrigem){
      setClasse();                        
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Azul;
    }

};
void ReptilNativo::setClasse(){
    this->classe = "reptilnativo";
};

//como reptil nativo será exibido
string ReptilNativo::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string extincao = this->getEmExtincao() ? "Sim" : "Não";
    string tipoPele;
    string bioma;
    if(this->getBiomaOrigem() == AMAZONIA) bioma = "Amazonia";
    if(this->getBiomaOrigem() == CERRADO) bioma = "Cerrado";
    if(this->getBiomaOrigem() == PAMPA) bioma = "Pampa";
    if(this->getBiomaOrigem() == CAATINGA) bioma = "Caatinga";
    if(this->getBiomaOrigem() == PANTANAL) bioma = "Pantanal";

    if(this->getTipoDepele() == CARAPACA) tipoPele = "Carapaça";
    if(this->getTipoDepele() == ESCAMAS) tipoPele = "Escamas";
    if(this->getTipoDepele() == PLACADERMICA) tipoPele = "Placa dérmica";
	dados = "codigo: " + this->getCodigo() + " | Peso: " + this->getPeso() + " | Altura: "+this->getAltura() + " | Especie: " + this->getEspecie() + " | Perigoso: "  + perigo + 
    " | Muda de Pele: " + this->getPeriodoDeMudadepele() + " | Tipo de Pele: " + tipoPele +
    " | Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " | Em extinção: " + extincao + " | Bioma origem: " + bioma + 
    " | CPF Tratador: " + this->getTratador()->getCpf() + " | CPF Veterinario: " + this->getVeterinario()->getCpf() + "\n";
	return dados;
};
