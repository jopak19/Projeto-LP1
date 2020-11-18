#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

class Pessoa {

	public:
		short getIdade();
		short getCpf();
		string getNome();

	private:
		string nome;
		short idade;
		short cpf;

};