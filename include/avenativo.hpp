#pragma once
#include "ave.hpp"
#include "nativo.hpp"

class AveNativo: public Ave, public Nativo{
    private: 
        AveNativo (     string codigo, 
                        string peso, 
                        string altura, 
                        short idade, 
                        string especie,
                        bool aquatica,
                        bool podeVoar,
                        int marcacaoPermanente,
                        bool emExtincao,
                        Bioma biomaOrigem,
                        bool perigoso);
    public:
        friend ostream& operator<< (ostream &o, AveNativo animal);	
};