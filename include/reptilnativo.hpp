#pragma once
#include "reptil.hpp"
#include "nativo.hpp"

class ReptilNativo: public Reptil, public Nativo{
    private: 
        ReptilNativo   (string codigo, 
                        string peso, 
                        string altura, 
                        short idade, 
                        string especie,
                        string periodoDeMudadepele,
                        TipoDePele tipoDePele,
                        int marcacaoPermanente,
                        bool emExtincao,
                        Bioma biomaOrigem,
                        bool perigoso);
    public:
        friend ostream& operator<< (ostream &o, ReptilNativo animal);	
};