#include "veterinario.hpp"
#include <iostream>
#include <string>
#include <iomanip>
using std::setfill;
using std::setw;

/*Método construtor*/

Veterinario::Veterinario(short cpf, string nome, string dataNascimento, short codigoCrmv, int animaisTratados = 0): Pessoa(cpf, nome, dataNascimento), codigoCrmv(codigoCrmv),animaisTratados(0){}


/*Gets e sets*/
int Veterinario::getAnimaisTratados() const{
    return this->animaisTratados;
}

short Veterinario::getCodigoCrmv() const{
    return this->codigoCrmv;
}

void Veterinario::setAnimaisTratados(int animais){
    this->animaisTratados = animais;
}

void Veterinario::setCodigoCrmv(short codigo){
    this->codigoCrmv = codigo;
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
