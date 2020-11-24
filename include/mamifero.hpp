#pragma once
#include <iostream>
#include <string>
#include "animal.hpp"

using namespace std;

enum Gestacao {
    MONOTREMADO,
    MARSUPIAL,
    PLACENTARIO,

};

class Mamifero : public Animal{

private:

/*Atributos específicos da classe Mamifero*/
    Gestacao gestacao;
public:

	Mamifero (  string codigo, 
                string peso, 
                string altura, 
                short idade, 
                string especie,
                Gestacao gestacao
                );

    Gestacao getGestacao() const;
    void setGestacao(Gestacao gestacao);
   
	friend ostream& operator<< (ostream &o, Mamifero animal);	
};
