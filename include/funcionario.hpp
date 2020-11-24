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

		string cpf;
		string nome;
		string dataNascimento;
		vector<shared_ptr<Animal>> animaisTratados;
    	int quantidadeAnimaisTratados;
		
	public:

		Funcionario(string cpf, string nome,string dataNascimento);
		string getDataNascimento() const;
		string getCpf() const;
		string getNome() const;

		void adicionarAnimalTratado(shared_ptr<Animal> animal);
    	bool removerAnimalTratado(string codigoAnimal);
    	int getQuantidadeAnimaisTratados() const;
    	vector<shared_ptr<Animal>> getAnimaisTratados() const;

    	// TODO Sobrescrever esse método nas classes derivadas
		void alterarDados(string cpf, string nome, string dataNascimento);
};
