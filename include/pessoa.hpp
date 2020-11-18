#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

class Pessoa {

	private:

		short cpf;
		string nome;
		string dataNascimento;
		
	public:

		Pessoa(short cpf, string nome,string dataNascimento);
		string getDataNascimento() const;
		short getCpf() const;
		string getNome() const;
		void alterarDados(short cpf, string nome, string dataNascimento);
};