#include "mamiferoexotico.hpp"
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
                                Exotico(marcacaoPermanente, emExtincao, territorioDeOrigem){};

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
    //TODO: saida dados exoticos
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