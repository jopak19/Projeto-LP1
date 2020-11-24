#pragma once
#include <iostream>
#include <string>
#include "animal.hpp"

using namespace std;

class Anfibio : public Animal{

private:

/*Atributos específicos da classe Anfibio*/
    string periodoDeMudaDePele;
    int temperaturaDoAmbiente;
public:

	Anfibio(string codigo, 
            string peso, 
            string altura, 
            short idade, 
            string especie,
            shared_ptr<Veterinario> veterinario,
            shared_ptr<Tratador> tratador,
            string periodoDeMudadepele,
            int temperaturaDoAmbiente);

    string getPeriodoDeMudadepele() const;
    void setPeriodoDeMudadepele(string periodo);
    int getTemperaturaDeMudaDePele() const;
    void setTemperaturaDeMudaDePele(int temperatura);
   
	friend ostream& operator<< (ostream &o, Anfibio animal);	
};
