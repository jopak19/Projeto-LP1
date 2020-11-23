# include "funcionario.hpp"

Funcionario::Funcionario(string cpf, string nome, string dataNascimento):
	cpf(cpf), nome(nome), dataNascimento(dataNascimento){
}

string Funcionario::getNome() const{
	return this->nome;
}

string Funcionario::getDataNascimento() const {
	return this->dataNascimento;
}

string Funcionario::getCpf() const {
	return this->cpf;
}

void Funcionario::alterarDados(string cpf, string nome, string dataNascimento) {

	this->cpf = cpf;
	this->nome = nome;
	this->dataNascimento = nome;

	/*Teria como fazer algo similar em C++ para 
	não precisar necessáriamente alterar todos os valores?*/

	/*
	if(cpf != NULL)
		this->cpf = cpf;

	if(nome != NULL)
		this->nome = nome;

	if(dataNascimento != NULL)
		this->dataNascimento = nome;

	*/
}