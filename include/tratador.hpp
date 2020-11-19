#pragma once

#include "pessoa.hpp"
#include "nivelseguranca.hpp"
#include "animal.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Resolve problema de dependência circular
class Animal;

class Tratador : public Pessoa {

private:

/*Atributos específicos da classe tratador*/
	NivelSeguranca nivelSeguranca;
    int quantidadeAnimaisTratados;
    vector<shared_ptr<Animal>> animaisTratados;


public:

/*Metodo contrutor*/
	Tratador (short cpf, string nome, string dataNascimento, 
        NivelSeguranca nivelSeguranca);

/*Metodos gets e sets específicos de tratador*/
    int getQuantidadeAnimaisTratados();
    NivelSeguranca getNivelSeguranca();

    void adicionarAnimalTratado(Animal* animal);
    void setNivelSeguranca(NivelSeguranca nivel);
    vector<shared_ptr<Animal>> getAnimaisTratados();
    
/*Imprimir um tratador*/
	friend ostream& operator<< (ostream &o, Tratador t);	
};

