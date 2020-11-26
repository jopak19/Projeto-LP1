#pragma once
#include "mamifero.hpp"
#include "nativo.hpp"

class MamiferoNativo: public Mamifero, public Nativo{
    public: 
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
        string imprimir();
        void setClasse();
        friend ostream& operator<< (ostream &o, MamiferoNativo animal);	
};