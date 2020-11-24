#include "mamifero.hpp"
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

    this->nivelSeguranca = Azul;
};

Gestacao Mamifero::getGestacao() const{
    return this->gestacao;
};
void Mamifero::setGestacao(Gestacao gestacao){
    this->gestacao = gestacao;
};
   
ostream& operator<< (ostream &o, Mamifero animal){
     /*Como o mamifero será exibido em tela*/
    string gestacao_;

    if(animal.getGestacao() == MONOTREMADO){
        gestacao_ = "monotremado";
    } else if(animal.getGestacao() == MARSUPIAL){
        gestacao_ = "marsupial";
    }else{
        gestacao_ = "placentario";
    };
    o << "Código" << setfill(' ') << setw(5) 
    << "Peso" << setfill(' ') << setw(5) 
    << "altura" << setfill(' ') << setw(5)
    << "idade" << setfill(' ') << setw(5)
    << "especie" << setfill(' ') << setw(5) 
    << "Gestação" << setfill(' ') << setw(5)  
    << endl
    << animal.getCodigo() << setfill(' ') << setw(5) 
    << animal.getPeso() << setfill(' ') << setw(5) 
    << animal.getAltura() << setfill(' ') << setw(5) 
    << animal.getIdade() << setfill(' ') << setw(5)
    << animal.getEspecie() << setfill(' ') << setw(5)
    << gestacao_ << setfill(' ') << setw(5)
    << endl;
	return o;
};	