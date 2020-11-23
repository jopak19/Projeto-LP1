#pragma once
#include <iostream>
#include <string>
#include "animal.hpp"
using namespace std;

enum TipoDePele{
    ESCAMAS,
    CARAPAÇA,
    PLACADERMICA
};

class Reptil : public Animal{

    private:

    /*Atributos específicos da classe Reptil*/
        string periodoDeMudaDePele;
        TipoDePele tipoDePele;
    public:

        Reptil (   string codigo, 
                    string peso, 
                    string altura, 
                    short idade, 
                    string especie,
                    shared_ptr<Veterinario>,
                    shared_ptr<Tratador>,
                    string periodoDeMudadepele,
                    int temperaturaDoAmbiente);

        string getPeriodoDeMudadepele() const;
        void setPeriodoDeMudadepele(string periodo);
        int getTemperaturaDoAmbiente() const;
        void setTemperaturaDoAmbiente(int temperatura);
    
        friend ostream& operator<< (ostream &o, Reptil animal);	
};
