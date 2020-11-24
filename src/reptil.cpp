#include "reptil.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

//construtor
Reptil::Reptil(string codigo, 
                string peso, 
                string altura, 
                short idade, 
                string especie,
                string periodoDeMudadepele,
                TipoDePele tipoDePele):
                Animal(codigo, peso, altura, idade, especie),
                periodoDeMudaDePele(periodoDeMudadepele), tipoDePele(tipoDePele){

    this->nivelSeguranca = Verde;

};

//getters e setters
string Reptil::getPeriodoDeMudadepele() const{
    return this->periodoDeMudaDePele;
};
void Reptil::setPeriodoDeMudadepele(string periodo){
    this->periodoDeMudaDePele = periodo;
};
TipoDePele Reptil::getTipoDepele() const{
    return this->tipoDePele;
};
void Reptil::setTipoDePele(TipoDePele tipo){
    this->tipoDePele = tipo;
};
   
ostream& operator<< (ostream &o, Reptil animal){
     /*Como o Reptil será exibido em tela*/
    string tipoPele;

    if(animal.getTipoDepele() == CARAPACA){
        tipoPele = "carapaça";
    } else if(animal.getTipoDepele() == ESCAMAS){
        tipoPele = "escamas";
    }else{
        tipoPele = "placa dérmica";
    };
    o << "Código" << setfill(' ') << setw(5) 
    << "Peso" << setfill(' ') << setw(5) 
    << "altura" << setfill(' ') << setw(5)
    << "idade" << setfill(' ') << setw(5)
    << "especie" << setfill(' ') << setw(5) 
    << "Muda de pele" << setfill(' ') << setw(5)
    << "Tipo de pele" << setfill(' ') << setw(5)  
    << endl
    << animal.getCodigo() << setfill(' ') << setw(5) 
    << animal.getPeso() << setfill(' ') << setw(5) 
    << animal.getAltura() << setfill(' ') << setw(5) 
    << animal.getIdade() << setfill(' ') << setw(5)
    << animal.getEspecie() << setfill(' ') << setw(5)
    << animal.getPeriodoDeMudadepele() << setfill(' ') << setw(5)
    << tipoPele << setfill(' ') << setw(5) 
    << endl;
	return o;
};