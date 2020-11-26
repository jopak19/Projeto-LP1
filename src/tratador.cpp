#include "tratador.hpp"


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
    o << "Nome" << setfill(' ') << setw(20) 
    << "CPF" << setfill(' ') << setw(20) 
    << "Nível" << endl
    << t.getNome() << setfill(' ') << setw(20) 
    << t.getCpf() << setfill(' ') << setw(20) << nivel << endl;

	return o;
}
