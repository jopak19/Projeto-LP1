#pragma once
#include "anfibio.hpp"
#include "nativo.hpp"

class AnfibioNativo: public Anfibio, public Nativo{
    public: 
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
        string imprimir();
        void setClasse();
        virtual ~AnfibioNativo();	
};