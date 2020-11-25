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

    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Azul;
    }
    
};

//getters e setters
string Anfibio::getPeriodoDeMudadepele() const{
    return this->periodoDeMudaDePele;
};
void Anfibio::setPeriodoDeMudadepele(string periodo){
    this->periodoDeMudaDePele = periodo;
};
int Anfibio::getTemperaturaDoAmbiente() const{
    return this->temperaturaDoAmbiente;
};
void Anfibio::setTemperaturaDoAmbiente(int temperatura){
    this->temperaturaDoAmbiente = temperatura;
};
string Anfibio::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
	dados = "codigo: " + this->getCodigo() + " Peso: " + this->getPeso() + " Altura: "+this->getAltura() + " Especie: " + this->getEspecie() + " Perigoso: "  + perigo + 
    " Muda de Pele: " + this->getPeriodoDeMudadepele() + " Temperatura do Ambiente: " + to_string(this->getTemperaturaDoAmbiente());
	return dados;
};
ostream& operator<< (ostream &o, Anfibio animal){
     /*Como o anfibio será exibido em tela*/
    o << "Código" << setfill(' ') << setw(5) 
    << "Peso" << setfill(' ') << setw(5) 
    << "altura" << setfill(' ') << setw(5)
    << "idade" << setfill(' ') << setw(5)
    << "especie" << setfill(' ') << setw(5) 
    << "Muda de pele" << setfill(' ') << setw(5)
    << "Temperatura do ambiente" << setfill(' ') << setw(5)  
    << endl
    << animal.getCodigo() << setfill(' ') << setw(5) 
    << animal.getPeso() << setfill(' ') << setw(5) 
    << animal.getAltura() << setfill(' ') << setw(5) 
    << animal.getIdade() << setfill(' ') << setw(5)
    << animal.getEspecie() << setfill(' ') << setw(5)
    << animal.getPeriodoDeMudadepele() << setfill(' ') << setw(5)
    << animal.getTemperaturaDoAmbiente() << setfill(' ') << setw(5) 
    << endl;
	return o;
};