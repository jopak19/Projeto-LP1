#include "anfibio.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

Anfibio::Anfibio(string codigo, 
                string peso, 
                string altura, 
                short idade, 
                string especie,
                string periodoDeMudadepele,
                int temperaturaDoAmbiente,
                bool perigoso = false):
                Animal(codigo, peso, altura, idade, especie, perigoso),
                periodoDeMudaDePele(periodoDeMudadepele), temperaturaDoAmbiente(temperaturaDoAmbiente){
    setClasse();
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Azul;
    }
}

//getters e setters
string Anfibio::getPeriodoDeMudadepele() const{
    return this->periodoDeMudaDePele;
}

void Anfibio::setPeriodoDeMudadepele(string periodo){
    this->periodoDeMudaDePele = periodo;
}

int Anfibio::getTemperaturaDoAmbiente() const{
    return this->temperaturaDoAmbiente;
}

void Anfibio::setTemperaturaDoAmbiente(int temperatura){
    this->temperaturaDoAmbiente = temperatura;
}

void Anfibio::setClasse(){
    this->classe = "anfibio";
}

//como anfibio será exibido
string Anfibio::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    dados = "codigo: " + this->getCodigo() + " Peso: " + this->getPeso() + " Altura: "+this->getAltura() + " Especie: " + this->getEspecie() + " Perigoso: "  + perigo + 
    " Muda de Pele: " + this->getPeriodoDeMudadepele() + " Temperatura do Ambiente: " + to_string(this->getTemperaturaDoAmbiente());
    return dados;
};