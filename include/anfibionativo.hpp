#pragma once
#include "anfibio.hpp"
#include "nativo.hpp"

class AnfibioNativo: public Anfibio, public Nativo{
    private: 
        AnfibioNativo (string codigo, 
                        string peso, 
                        string altura, 
                        short idade, 
                        string especie,
                        string periodoDeMudadepele,
                        int temperaturaDoAmbiente,
                        int marcacaoPermanente,
                        bool emExtincao,
                        Bioma biomaOrigem,
                        bool perigoso);
    public:
        friend ostream& operator<< (ostream &o, AnfibioNativo animal);	
};