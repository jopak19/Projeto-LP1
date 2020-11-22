#pragma once

#include <vector>
#include <string>
#include "animal.hpp"

using std::vector;
using std::string;
using std::shared_ptr;

class Animal;
class Funcionario {

	protected:

		short cpf;
		string nome;
		string dataNascimento;
		vector<shared_ptr<Animal>> animaisTratados;
    	int quantidadeAnimaisTratados;
		
	public:

		Funcionario(short cpf, string nome,string dataNascimento);
		string getDataNascimento() const;
		short getCpf() const;
		string getNome() const;

		// TODO Sobrescrever esse método nas classes derivadas
		void alterarDados(short cpf, string nome, string dataNascimento);

		void adicionarAnimalTratado(shared_ptr<Animal> animal);
    	void removerAnimalTratado(shared_ptr<Animal> animal);
    	int getQuantidadeAnimaisTratados() const;
    	vector<shared_ptr<Animal>> getAnimaisTratados() const;
};
