#ifndef _TRATADOR_
#define _TRATADOR_ 
#include "pessoa.hpp"
#include <iostream>
#include <string>

using namespace std;

enum Nivel {
    Verde,
    Vermelho,
    Azul
};

class Tratador : public Pessoa {
private:

/*Atributos específicos da classe tratador*/
	Nivel nivel_seguranca;
    int animais_tratados;

public:

/*Metodo contrutor*/
	Tratador (short cpf, string nome, string dataNascimento, Nivel nivel_seguranca, int animais_tratados);

/*Metodos gets e sets específicos de tratador*/
    int getAnimais_tratados();
    Nivel getNivel_seguranca();

    void setAnimais_tratados(int animais);
    void setNivel_seguranca(Nivel nivel);
    
    
/*Imprimir um tratador*/
	friend ostream& operator<< (ostream &o, Tratador t);	
};

#endif
