#pragma once
#include "reptil.hpp"
#include "exotico.hpp"

class ReptilExotico: public Reptil, public Exotico{
    public: 
        ReptilExotico (string codigo, 
                        string peso, 
                        string altura, 
                        short idade, 
                        string especie,
                        string periodoDeMudadepele,
                        TipoDePele tipoDePele,
                        int marcacaoPermanente,
                        bool emExtincao,
                        string territorioDeOrigem,
                        bool perigoso);
    public:
        friend ostream& operator<< (ostream &o, ReptilExotico animal);	
};