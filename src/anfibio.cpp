#include "anfibio.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

//construtor
Anfibio::Anfibio(string codigo, 
                string peso, 
                string altura, 
                short idade, 
                string especie,
                string periodoDeMudadepele,
                int temperaturaDoAmbiente):
                Animal(codigo, peso, altura, idade, especie),
                periodoDeMudaDePele(periodoDeMudadepele), temperaturaDoAmbiente(temperaturaDoAmbiente){

    this->nivelSeguranca = Verde;
};

//getters e setters
string Anfibio::getPeriodoDeMudadepele() const{
    return this->periodoDeMudaDePele;
};
void Anfibio::setPeriodoDeMudadepele(string periodo){
    this->periodoDeMudaDePele = periodo;
};
int Anfibio::getTemperaturaDeMudaDePele() const{
    return this->temperaturaDoAmbiente;
};
void Anfibio::setTemperaturaDeMudaDePele(int temperatura){
    this->temperaturaDoAmbiente = temperatura;
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
    << animal.getTemperaturaDeMudaDePele() << setfill(' ') << setw(5) 
    << endl;
	return o;
};