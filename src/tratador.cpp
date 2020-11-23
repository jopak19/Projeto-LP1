#include "tratador.hpp"
#include "nivelseguranca.hpp"
#include "animal.hpp"
#include <iostream>
#include <string>
#include <iomanip>
using std::setfill;
using std::setw;

/*Método construtor*/
Tratador::Tratador(string cpf, string nome, 
 string dataNascimento, NivelSeguranca nivelSeguranca): Funcionario(cpf, nome, dataNascimento), 
 nivelSeguranca(nivelSeguranca){}

NivelSeguranca Tratador::getNivelSeguranca() const{
    return this->nivelSeguranca;
}

void Tratador::setNivelSeguranca(NivelSeguranca nivel){
    this->nivelSeguranca = nivel;
}

/*Médoto para imprimir tratador*/
ostream& operator<< (ostream &o, Tratador t){

/*Exibir o enum nível*/
    string nivel = "";
    if (t.getNivelSeguranca() == Verde){
        nivel = "Verde";

    } else if(t.getNivelSeguranca() == Vermelho){
        nivel = "Vermelho";

    } else {
        nivel = "Azul";
    }

/*Como o tratador será exibido em tela*/
    o << "Nome" << setfill(' ') << setw(15) 
    << "CPF" << setfill(' ') << setw(15) 
    << "Nível" << endl
    << t.getNome() << setfill(' ') << setw(15) 
    << t.getCpf() << setfill(' ') << setw(15) << nivel << endl;

	return o;
}
