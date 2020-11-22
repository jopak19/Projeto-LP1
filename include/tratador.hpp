#pragma once

#include "funcionario.hpp"
#include "nivelseguranca.hpp"
#include "animal.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

//Resolve problemas de dependência circular
class Animal;

class Tratador : public Funcionario {

private:

	NivelSeguranca nivelSeguranca;

public:

	Tratador (short cpf, string nome, string dataNascimento, 
        NivelSeguranca nivelSeguranca);


    NivelSeguranca getNivelSeguranca();
    void setNivelSeguranca(NivelSeguranca nivel);
    
	friend ostream& operator<< (ostream &o, Tratador t);	
};

