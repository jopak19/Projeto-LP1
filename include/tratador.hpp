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
	Nivel nivelSeguranca;
    int animaisTratados;

public:

/*Metodo contrutor*/
	Tratador (short cpf, string nome, string dataNascimento, Nivel nivelSeguranca, int animaisTratados);

/*Metodos gets e sets específicos de tratador*/
    int getAnimaisTratados();
    Nivel getNivelSeguranca();

    void setAnimaisTratados(int animais);
    void setNivelSeguranca(Nivel nivel);
    
    
/*Imprimir um tratador*/
	friend ostream& operator<< (ostream &o, Tratador t);	
};

#endif
