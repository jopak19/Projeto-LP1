#pragma once
#include "pessoa.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Veterinario : public Pessoa {

private:

/*Atributos específicos da classe veterinario*/
	short codigoCrmv;
    int animaisTratados; //duvida se ficara aqui ou outra classe para relacionar !!!

public:

/*Metodo contrutor*/
	Veterinario (short cpf, string nome, string dataNascimento, short codigoCrmv, int animaisTratados);

/*Metodos gets e sets específicos do veterinario*/
    int getAnimaisTratados() const;
    void setAnimaisTratados(int animais);
    short getCodigoCrmv() const;
    void setCodigoCrmv(short codigo);

    
    
/*Imprimir um veterinario*/
	friend ostream& operator<< (ostream &o, Veterinario v);	
};

