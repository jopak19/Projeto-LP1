#include "petfera.hpp"
#include "animal.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
#include <vector>
#include <string>
#include <memory>

using std::shared_ptr;
using std::string;
using std::vector;

vector<shared_ptr<Animal>> PetFera::getAnimais() const{
	return this->animais;
}

vector<shared_ptr<Tratador>> PetFera::getTratadores() const{
    return this->tratadores;
}

vector<shared_ptr<Veterinario>> PetFera::getVeterinarios() const{
    return this->veterinarios;
}

shared_ptr<Animal> PetFera::getAnimal(string codigo) const{

	for(int i = 0; i < (int) this->animais.size(); i++){

		Animal an = *this->animais.at(i);
		string codigo2 = an.getCodigo();

		if(codigo.compare(codigo2) == 0){
			return this->animais.at(i);
		}
	}
	return nullptr;
}

shared_ptr<Veterinario> PetFera::getVeterinario(string cpf) const {

	for(int i = 0; i < (int) this->veterinarios.size(); i++){
		
		Veterinario vet = *this->veterinarios.at(i);
		string cpf2 = vet.getCpf();

		if(cpf.compare(cpf2) == 0){
			return this->veterinarios.at(i);
		}
	}
	return nullptr;
}

shared_ptr<Tratador> PetFera::getTratador(string cpf) const {

	for(int i = 0; i < (int) this->tratadores.size(); i++){

		Tratador tra = *this->tratadores.at(i);
		string cpf2 = tra.getCpf();
	
		if(cpf.compare(cpf2) == 0){
			return this->tratadores.at(i);
		}
	}
	return nullptr;
}

bool PetFera::cadastrarAnimal(shared_ptr<Animal> animal){
   	this->animais.push_back(animal);
   	return true;
}

bool PetFera::cadastrarTratador(shared_ptr<Tratador> tratador){
    this->tratadores.push_back(tratador);
    return true;
}

bool PetFera::cadastrarVeterinario(shared_ptr<Veterinario> veterinario){
    this->veterinarios.push_back(veterinario);
    return true;
}

bool PetFera::realizarVenda(){
	return false;

}

bool PetFera::removerTratador(){
	return true;
}

bool PetFera::removerVeterinario(){
	return true;
}

void PetFera::editarAnimal(shared_ptr<Animal> animal){

}

void PetFera::editarTratador(shared_ptr<Tratador> tratador){

}

void PetFera::editarVeterinario(shared_ptr<Veterinario> veterinario){

}

void PetFera::listarAnimais() const{

	for(int i = 0; i < (int) this->animais.size(); i++){
		cout << *this->animais.at(i) << endl;
	}
}

void PetFera::listarTratadores() const{

	for(int i = 0; i < (int) this->tratadores.size(); i++){
		cout << *this->tratadores.at(i) << endl;
	}
}

void PetFera::listarVeterinarios() const{

	for(int i = 0; i < (int) this->veterinarios.size(); i++){
		cout << *this->veterinarios.at(i) << endl;
	}
}


