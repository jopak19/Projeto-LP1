#pragma once

#include "pessoa.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "animal.hpp"

using namespace std;

// Resolve problema de dependência circular
class Animal;

class Veterinario : public Pessoa {

private:

/*Atributos específicos da classe veterinario*/
	short codigoCrmv;
    vector<shared_ptr<Animal>> animaisTratados;
    int quantidadeAnimaisTratados;

public:

/*Metodo contrutor*/
	Veterinario (short cpf, string nome, string dataNascimento,
                short codigoCrmv);

/*Metodos gets e sets específicos do veterinario*/
    int getQuantidadeAnimaisTratados() const;
    vector<shared_ptr<Animal>> getAnimaisTratados() const;
    short getCodigoCrmv() const;
    void setCodigoCrmv(short codigo);
    void adiconarAnimalTratado(shared_ptr<Animal> animal);
    void removeAnimalTratado(shared_ptr<Animal> animal);

/*Imprimir um veterinario*/
	friend ostream& operator<< (ostream &o, Veterinario v);	
};

