# include "tratador.hpp"
#include <iostream>
#include <string>
#include <iomanip>
using std::setfill;
using std::setw;

/*Método construtor*/

Tratador::Tratador(short cpf, string nome, string dataNascimento, Nivel nivelSeguranca, int animaisTratados): Pessoa(cpf, nome, dataNascimento), nivelSeguranca(nivelSeguranca),animaisTratados(0){}


/*Gets e sets*/
int Tratador::getAnimaisTratados(){
    return this->animaisTratados;
}

Nivel Tratador::getNivelSeguranca(){
    return this->nivelSeguranca;
}

void Tratador::setAnimaisTratados(int animais){
    this->animaisTratados = animais;
}

void Tratador::setNivelSeguranca(Nivel nivel){
    this->nivelSeguranca = nivel;
}


/*Médoto para imprimir tratador*/
ostream& 
operator<< (ostream &o, Tratador t){

/*Exibir o enum nível*/
    string nivel = "";
    if (t.getNivelSeguranca() == 0){
        nivel = "Verde";

    } else if(t.getNivelSeguranca() == 1){
        nivel = "Vermelho";

    } else {
        nivel = "Azul";
    }

/*Como o tratador será exibido em tela*/
o << setfill(' ') << setw(30) << t.getNome()
		<< setfill(' ') << setw(15) << t.getCpf()
		<< setfill(' ') << nivel;
	return o;
}
