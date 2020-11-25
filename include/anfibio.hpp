#pragma once
#include <iostream>
#include <string>
#include "animal.hpp"

using namespace std;

class Anfibio : public Animal{

protected:

/*Atributos específicos da classe Anfibio*/
    string periodoDeMudaDePele;
    int temperaturaDoAmbiente;
public:

	Anfibio(string codigo, 
            string peso, 
            string altura, 
            short idade, 
            string especie,
            string periodoDeMudadepele,
            int temperaturaDoAmbiente,
            bool perigoso);

    string getPeriodoDeMudadepele() const;
    void setPeriodoDeMudadepele(string periodo);
    int getTemperaturaDoAmbiente() const;
    void setTemperaturaDoAmbiente(int temperatura);
    virtual string imprimir();
	friend ostream& operator<< (ostream &o, Anfibio animal);	
};
