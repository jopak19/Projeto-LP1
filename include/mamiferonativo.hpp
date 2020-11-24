#pragma once
#include "mamifero.hpp"
#include "nativo.hpp"

class MamiferoNativo: public Mamifero, public Nativo{
    private: 
        MamiferoNativo (string codigo, 
                        string peso, 
                        string altura, 
                        short idade, 
                        string especie,
                        Gestacao gestacao,
                        int marcacaoPermanente,
                        bool emExtincao,
                        Bioma biomaOrigem,
                        bool perigoso);
    public:
        friend ostream& operator<< (ostream &o, MamiferoNativo animal);	
};