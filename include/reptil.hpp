#pragma once
#include <iostream>
#include <string>
#include "animal.hpp"
using namespace std;

enum TipoDePele{
    ESCAMAS,
    CARAPACA,
    PLACADERMICA
};

class Reptil : public Animal{

    protected:

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
                    TipoDePele tipoDePele,
                    bool perigoso);

        string getPeriodoDeMudadepele() const;
        void setPeriodoDeMudadepele(string periodo);
        TipoDePele getTipoDepele() const;
        void setTipoDePele(TipoDePele tipo);

        virtual string imprimir();
        virtual void setClasse();
};
