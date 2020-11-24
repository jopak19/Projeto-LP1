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
                    string periodoDeMudadepele,
                    TipoDePele tipoDePele);

        string getPeriodoDeMudadepele() const;
        void setPeriodoDeMudadepele(string periodo);
        TipoDePele getTipoDepele() const;
        void setTipoDePele(TipoDePele tipo);
    
        friend ostream& operator<< (ostream &o, Reptil animal);	
};
