#pragma once
#include "anfibio.hpp"
#include "exotico.hpp"

class AnfibioExotico: public Anfibio, public Exotico{
    private: 
        AnfibioExotico (string codigo, 
                        string peso, 
                        string altura, 
                        short idade, 
                        string especie,
                        string periodoDeMudadepele,
                        int temperaturaDoAmbiente,
                        int marcacaoPermanente,
                        bool emExtincao,
                        string territorioDeOrigem,
                        bool perigoso);
    public:
        friend ostream& operator<< (ostream &o, AnfibioExotico animal);	
};