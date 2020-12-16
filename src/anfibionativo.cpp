#include "anfibionativo.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

AnfibioNativo::AnfibioNativo (string codigo, 
                                string peso, 
                                string altura, 
                                short idade, 
                                string especie,
                                string periodoDeMudadepele,
                                int temperaturaDoAmbiente,
                                int marcacaoPermanente,
                                bool emExtincao,
                                Bioma biomaOrigem,
                                bool perigoso):
                                Anfibio(codigo, peso, altura,idade, especie, periodoDeMudadepele, temperaturaDoAmbiente, perigoso),
                                Nativo(marcacaoPermanente, emExtincao, biomaOrigem){
                                    setClasse();
                                };

AnfibioNativo::~AnfibioNativo(){}
void AnfibioNativo::setClasse(){
    this->classe = "anfibionativo";
};
//como anfibio nativo será exibido
string AnfibioNativo::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string extincao = this->getEmExtincao() ? "Sim" : "Não";
    string bioma;
    if(this->getBiomaOrigem() == AMAZONIA) bioma = "Amazonia";
    if(this->getBiomaOrigem() == CERRADO) bioma = "Cerrado";
    if(this->getBiomaOrigem() == PAMPA) bioma = "Pampa";
    if(this->getBiomaOrigem() == CAATINGA) bioma = "Caatinga";
    if(this->getBiomaOrigem() == PANTANAL) bioma = "Pantanal";
    if(this->getBiomaOrigem() == MATAATLANTICA) bioma = "Mata Atlântica";
	dados = "codigo: " + this->getCodigo() + " | Peso: " + this->getPeso() + " | Altura: "+this->getAltura() + " | Especie: " + this->getEspecie() + " | Perigoso: "  + perigo + 
    " | Muda de Pele: " + this->getPeriodoDeMudadepele() + " | Temperatura do Ambiente: " + to_string(this->getTemperaturaDoAmbiente()) +
    " | Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " | Em extinção: " + extincao + " | Bioma origem: " + bioma +
	" | CPF Tratador: " + this->getTratador()->getCpf() + " | CPF Veterinario: " + this->getVeterinario()->getCpf() + "\n";
    return dados;
};
