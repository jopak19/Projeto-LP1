#include "mamiferoexotico.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
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
    setClasse();
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Azul;
    }

};
void MamiferoExotico::setClasse(){
    this->classe = "mamiferoexotico";
};

//como mamífero exótico será exibido
string MamiferoExotico::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string extincao = this->getEmExtincao() ? "Sim" : "Não";
    string gestacao;
    if(this->getGestacao() == PLACENTARIO) gestacao = "placentário";
    if(this->getGestacao() == MONOTREMADO) gestacao = "monotremado";
    if(this->getGestacao() == MARSUPIAL) gestacao = "marsupial";

	dados = "codigo: " + this->getCodigo() + " | Peso: " + this->getPeso() + " | Altura: "+this->getAltura() + " | Especie: " + this->getEspecie() + " | Perigoso: "  + perigo + 
    " | Gestação: " + gestacao + 
    " | Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " | Em extinção: " + extincao + " | Território origem: " + this->getTerritorioDeOrigem() +
    " | CPF Tratador: " + this->getTratador()->getCpf() + " | CPF Veterinario: " + this->getVeterinario()->getCpf() + "\n";
	return dados;
};
