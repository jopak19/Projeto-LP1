#pragma once
#include "silvestre.hpp"

enum Bioma{
    AMAZONIA,
    CAATINGA,
    PAMPA,
    CERRADO,
    PANTANAL,
    MATAATLANTICA
};

class Nativo : public Silvestre{

protected:

/*Atributos específicos da classe Nativo*/
    Bioma biomaOrigem;

public:

	Nativo (int marcacaoPermanente, bool perigoso, bool emExtincao, Bioma biomaOrigem);

    Bioma getBiomaOrigem() const;
    void setBiomaOrigem(Bioma bioma);
    	
};

