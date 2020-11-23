#pragma once
#include <iostream>
#include <string>

using namespace std;

class Exotico{

    private:

    /*Atributos específicos da classe Exotico*/
	    int marcacaoPermanente;
        string territorioDeOrigem;

    public:

	    Exotico (int marcacaoPermanente, string territorioDeOrigem);

        int getMarcacaoPermanente() const;
        void setMarcacaoPermanente(int marcacao);
        string getTerritorioDeOrigem() const;
        void setTerritorioDeOrigem(string territorio);
    	
};
