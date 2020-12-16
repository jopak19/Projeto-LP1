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

protected:

/*Atributos específicos da classe Mamifero*/
    Gestacao gestacao;
public:

	Mamifero (  string codigo, 
                string peso, 
                string altura, 
                short idade, 
                string especie,
                Gestacao gestacao,
                bool perigoso);

    Gestacao getGestacao() const;
    void setGestacao(Gestacao gestacao);
    virtual string imprimir();
    virtual void setClasse();	
    virtual ~Mamifero();
};
