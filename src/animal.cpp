#include "animal.hpp"

Animal::Animal(string codigo, string peso, 
	string altura, short idade, string especie, bool perigoso):codigo(codigo), peso(peso), altura(altura), 
	idade(idade), especie(especie), perigoso(perigoso){
}
Animal::~Animal(){}
//getters e setters

//atributo "classe" será definido no construtor de cada classe derivada, por um metódo virtual
string Animal::getClasse() const{
	return this->classe;
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

shared_ptr<Veterinario> Animal::getVeterinario() const {
	return this->veterinario;
}

shared_ptr<Tratador> Animal::getTratador() const {
	return this->tratador;
}

NivelSeguranca Animal::getNivelSeguranca() const {
	return this->nivelSeguranca;
}
bool Animal::getPerigoso() const{
	return this->perigoso;
};
void Animal::setPerigoso(bool perigoso){
	this->perigoso = perigoso;
};
bool Animal::setVeterinario(shared_ptr<Veterinario> veterinario){
	this->veterinario = veterinario;
	return true;
}

bool Animal::setTratador(shared_ptr<Tratador> tratador){
	this->tratador = tratador;
	return true;
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
string Animal::imprimir(){
	
	string dados;
	return dados;
};

// caso seja usado o operador << em um animal, como ele será exibido
ostream& operator<< (ostream &o, Animal a){

	o << "Código" << setfill(' ') << setw(15) 
    << "Peso" << setfill(' ') << setw(15) 
    << "Altura" 
    << "Especie" << endl
    << a.getCodigo() << setfill(' ') << setw(15) 
    << a.getPeso() << setfill(' ') << setw(15) 
   	<< a.getAltura() << setfill(' ') << setw(15)
   	<< a.getEspecie() << setfill(' ') << setw(15)
    << endl;

	return o;
}