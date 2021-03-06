#pragma once
#include "ave.hpp"
#include "exotico.hpp"

class AveExotico: public Ave, public Exotico{
    public: 
        AveExotico (string codigo, 
                    string peso, 
                    string altura, 
                    short idade, 
                    string especie,
                    bool aquatica,
                    bool podeVoar,
                    int marcacaoPermanente,
                    bool emExtincao,
                    string territorioDeOrigem,
                    bool perigoso);
    public:
        string imprimir();
        void setClasse();
        virtual ~AveExotico();
};