#pragma once
#include <iostream>
#include <string>
#include "silvestre.hpp"

using namespace std;

class Exotico : public Silvestre{

    protected:

    /*Atributos específicos da classe Exotico*/
        string territorioDeOrigem;

    public:

	    Exotico (int marcacaoPermanente, bool emExtincao, string territorioDeOrigem);

        string getTerritorioDeOrigem() const;
        void setTerritorioDeOrigem(string territorio);
    	
};
