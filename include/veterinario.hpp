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
	string codigoCrmv;
  

public:

	Veterinario (string cpf, string nome, string dataNascimento,
                string codigoCrmv);

    string getCodigoCrmv() const;
    void setCodigoCrmv(string codigo);
   
	friend ostream& operator<< (ostream &o, Veterinario v);	
};

