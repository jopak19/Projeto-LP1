#pragma once
#include <iostream>
#include <string>
#include "animal.hpp"

using namespace std;

class Ave : public Animal{

private:

/*Atributos específicos da classe Ave*/
	bool aquatica;
    bool podeVoar;

public:

	Ave(string codigo, 
		string peso, 
		string altura, 
		short idade, 
		string especie,
		shared_ptr<Veterinario> veterinario,
		shared_ptr<Tratador> tratador,
        bool aquatica,
        bool podeVoar);

    bool getAquatica() const;
    void setAquatica(bool aquatica);
    bool getPodeVoar() const;
    void setPodeVoar(bool podeVoar);
   
	friend ostream& operator<< (ostream &o, Ave animal);	
};

