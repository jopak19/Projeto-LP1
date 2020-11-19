# include "animal.hpp"
# include "veterinario.hpp"
# include "tratador.hpp"

Animal::Animal(string codigo, string peso, 
	string altura, short idade, string especie, 
	shared_ptr<Veterinario> veterinario, shared_ptr<Tratador> tratador):
	codigo(codigo), peso(peso), altura(altura), 
	idade(idade), especie(especie), veterinario(veterinario), tratador(tratador){
}

string Animal::getCodigo() const {
	return this->codigo;
}

string Animal::getPeso() const {
	return this->peso;
}

string Animal::getAltura() const {
	return this->altura;
}

short Animal::getIdade() const {
	return this->idade;
}

string Animal::getEspecie() const {
	return this->especie;
}

void Animal::setCodigo(string codigo){
	this->codigo = codigo;
}

void Animal::setPeso(string peso){
	this->peso = peso;
}

void Animal::setAltura(string altura){
	this->altura = altura;
}

void Animal::setIdade(short idade){
	this->idade = idade;
}

void Animal::setEspecie(string especie){
	this->especie = especie;
}

void Animal::alterarDados(string codigo, string peso, string altura, short idade, string especie){

	this->codigo = codigo;
	this->peso = peso;
	this->altura = altura;
	this->idade = idade;
	this->especie = especie;

	/*Teria como fazer algo similar em C++ para 
	não precisar necessáriamente alterar todos os valores?*/

	/*
	if(codigo != NULL)
		this->codigo = codigo;

	if(peso != NULL)
		this->peso = peso;

	if(altura != NULL)
		this->altura = altura;

	if(idade != NULL)
		this->idade = idade;

	if(especie != NULL)
		this->especie = especie;
	*/
}