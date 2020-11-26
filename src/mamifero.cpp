#include "mamifero.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

Mamifero::Mamifero(string codigo, 
                   string peso, 
                   string altura, 
                   short idade, 
                   string especie,
                   Gestacao gestacao,
                   bool perigoso = false):
                   Animal(codigo, peso, altura, idade, especie, perigoso),
                   gestacao(gestacao){
    setClasse();
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Azul;
    }
};
//getters e setters
void Mamifero::setClasse(){
    this->classe = "mamifero";
};
Gestacao Mamifero::getGestacao() const{
    return this->gestacao;
};
void Mamifero::setGestacao(Gestacao gestacao){
    this->gestacao = gestacao;
};

//como mamifero será exibido
string Mamifero::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string gestacao;
    if(this->getGestacao() == PLACENTARIO) gestacao = "placentário";
    if(this->getGestacao() == MONOTREMADO) gestacao = "monotremado";
    if(this->getGestacao() == MARSUPIAL) gestacao = "marsupial";

	dados = "codigo: " + this->getCodigo() + " | Peso: " + this->getPeso() + " | Altura: "+this->getAltura() + " | Especie: " + this->getEspecie() + " | Perigoso: "  + perigo + 
    " Gestação: " + gestacao +
    " | CPF Tratador: " + this->getTratador()->getCpf() + " | CPF Veterinario: " + this->getVeterinario()->getCpf() + "\n";
	return dados;
};
  