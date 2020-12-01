#include "veterinario.hpp"
#include <iostream>
#include <string>
#include <iomanip>
using std::setfill;
using std::setw;

/*Método construtor*/

Veterinario::Veterinario(string cpf, string nome, string dataNascimento, string codigoCrmv): 
            Funcionario(cpf, nome, dataNascimento), codigoCrmv(codigoCrmv){}

string Veterinario::getCodigoCrmv() const{
    return this->codigoCrmv;
}

void Veterinario::setCodigoCrmv(string codigo){
    this->codigoCrmv = codigo;
}

/*Médoto para imprimir Veterinario*/
ostream& 
operator<< (ostream &o, Veterinario v){

/*Como o Veterinario será exibido em tela*/
    o << "Nome: " << v.getNome() 
    << " | CPF: " << v.getCpf()
    << " | CRMV: " << v.getCodigoCrmv() << endl;
	return o;
}
