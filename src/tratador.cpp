# include "tratador.hpp"
#include <iostream>
#include <string>
#include <iomanip>
using std::setfill;
using std::setw;

/*Método construtor*/

Tratador::Tratador(short cpf, string nome, string dataNascimento, Nivel nivel_seguranca, int animais_tratados): Pessoa(cpf, nome, dataNascimento), nivel_seguranca(nivel_seguranca),animais_tratados(0){}



/*Gets e sets*/
int Tratador::getAnimais_tratados(){
    return this->animais_tratados;
}
Nivel Tratador::getNivel_seguranca(){
    return this->nivel_seguranca;
}

void Tratador::setAnimais_tratados(int animais){
    this->animais_tratados = animais;
}
void Tratador::setNivel_seguranca(Nivel nivel){
    this->nivel_seguranca = nivel;
}


/*Médoto para imprimir tratador*/
ostream& 
operator<< (ostream &o, Tratador t){

/*Exibir o enum nível*/
    string nivel = "";
    if (t.getNivel_seguranca() == 0){
        nivel = "Verde";
    }else if(t.getNivel_seguranca() == 1){
        nivel = "Vermelho";
    }else{
        nivel = "Azul";
    }

/*Como o tratador será exibido em tela*/
o << setfill(' ') << setw(30) << t.getNome()
		<< setfill(' ') << setw(15) << t.getCpf()
		<< setfill(' ') << nivel;
	return o;
}
