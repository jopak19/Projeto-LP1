#include "petfera.hpp"
#include "animal.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
#include <vector>
#include <string>
#include <memory>

using namespace std;

vector<shared_ptr<Animal>> PetFera::getAnimais() const{
	return this->animais;
}

vector<shared_ptr<Tratador>> PetFera::getTratadores() const{
    return this->tratadores;
}

vector<shared_ptr<Veterinario>> PetFera::getVeterinarios() const{
    return this->veterinarios;
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

/*
bool PetFera::realizarVenda(){

}

bool PetFera::removerTratador(){

}

bool PetFera::removerVeterinario(){

}
*/

void PetFera::editarAnimal(shared_ptr<Animal> animal){

}

void PetFera::editarTratador(shared_ptr<Tratador> tratador){

}

void PetFera::editarVeterinario(shared_ptr<Veterinario> veterinario){

}

void PetFera::listarAnimais() const{

}

void PetFera::listarTratadores() const{

}

void PetFera::listarVeterinarios() const{

}