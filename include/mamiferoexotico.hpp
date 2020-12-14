#pragma once
#include "mamifero.hpp"
#include "exotico.hpp"

class MamiferoExotico: public Mamifero, public Exotico{
    public: 
        MamiferoExotico (string codigo, 
                        string peso, 
                        string altura, 
                        short idade, 
                        string especie,
                        Gestacao gestacao,
                        int marcacaoPermanente,
                        bool emExtincao,
                        string territorioDeOrigem,
                        bool perigoso);
    public:
        string imprimir();
        void setClasse();	
        virtual ~MamiferoExotico();
};