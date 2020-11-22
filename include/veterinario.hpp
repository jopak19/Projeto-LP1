#pragma once

#include "funcionario.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "animal.hpp"

using namespace std;

// Resolve problema de dependência circular
class Animal;

class Veterinario : public Funcionario {

private:

/*Atributos específicos da classe veterinario*/
	short codigoCrmv;
  

public:

	Veterinario (short cpf, string nome, string dataNascimento,
                short codigoCrmv);

    short getCodigoCrmv() const;
    void setCodigoCrmv(short codigo);
   
	friend ostream& operator<< (ostream &o, Veterinario v);	
};

