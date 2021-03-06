#pragma once
#include <iostream>
#include <string>
#include "animal.hpp"

using namespace std;

class Ave : public Animal{

protected:

/*Atributos específicos da classe Ave*/
	bool aquatica;
    bool podeVoar;

public:

	Ave(string codigo, 
		string peso, 
		string altura, 
		short idade, 
		string especie,
        bool aquatica,
        bool podeVoar,
        bool perigoso);

    bool getAquatica() const;
    void setAquatica(bool aquatica);
    bool getPodeVoar() const;
    void setPodeVoar(bool podeVoar);
    virtual string imprimir();
    virtual void setClasse();
    virtual ~Ave();	
};

