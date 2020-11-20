#include "veterinario.hpp"
#include <iostream>
#include <string>
#include <iomanip>
using std::setfill;
using std::setw;

/*Método construtor*/

Veterinario::Veterinario(short cpf, string nome, string dataNascimento, short codigoCrmv): 
            Pessoa(cpf, nome, dataNascimento), codigoCrmv(codigoCrmv){}


/*Gets e sets*/
int Veterinario::getQuantidadeAnimaisTratados() const{
    return this->quantidadeAnimaisTratados;
}
vector<shared_ptr<Animal>> Veterinario::getAnimaisTratados() const{
    return this->animaisTratados;
}
short Veterinario::getCodigoCrmv() const{
    return this->codigoCrmv;
}
void Veterinario::setCodigoCrmv(short codigo){
    this->codigoCrmv = codigo;
}
void Veterinario::adiconarAnimalTratado(shared_ptr<Animal> animal){
    this->animaisTratados.push_back(animal);
    this->quantidadeAnimaisTratados++;
}
void Veterinario::removeAnimalTratado(shared_ptr<Animal> animal){
     // TODO
}


/*Médoto para imprimir Veterinario*/
ostream& 
operator<< (ostream &o, Veterinario v){

/*Como o Veterinario será exibido em tela*/
o << setfill(' ') << setw(30) << v.getNome()
		<< setfill(' ') << setw(15) << v.getCpf()
		<< setfill(' ') << v.getCodigoCrmv();
	return o;
}
