#include "mamiferonativo.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
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
    setClasse();
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Azul;
    }

};
void MamiferoNativo::setClasse(){
    this->classe = "mamiferonativo";
};

//como mamífero nativo será exibido
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
    " Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " Em extinção: " + extincao + " Bioma origem: " + bioma + 
	" | CPF Tratador: " + this->getTratador()->getCpf() + " | CPF Veterinario: " + this->getVeterinario()->getCpf() + "\n";
	return dados;
};
