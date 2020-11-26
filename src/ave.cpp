#include "ave.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

Ave::Ave(string codigo, 
		string peso, 
		string altura, 
		short idade, 
		string especie,
        bool aquatica,
        bool podeVoar,
        bool perigoso = false): Animal(codigo, peso, altura, idade, especie, perigoso),
        aquatica(aquatica), podeVoar(podeVoar){
        setClasse();
        if(perigoso){
            this->nivelSeguranca = Vermelho;

        } else {
            this->nivelSeguranca = Verde;
        }
};
void Ave::setClasse(){
    this->classe = "ave";
};
bool Ave::getAquatica() const{
    return this->aquatica;
};
void Ave::setAquatica(bool aquatica){
    this->aquatica = aquatica;
};
bool Ave::getPodeVoar() const{
    return this->podeVoar;
};
void Ave::setPodeVoar(bool podeVoar){
    this->podeVoar = podeVoar;
};
string Ave::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string aqua = this->aquatica ? "aquatica" : "não Aquatica";
    string voa = this->podeVoar ? "voa" : "Não voa";
	dados = "codigo: " + this->getCodigo() + " Peso: " + this->getPeso() + " Altura: "+this->getAltura() + " Especie: " + this->getEspecie() + " Perigoso: "  + perigo + 
    " Aquatica: " + aqua + " Pode var: " + voa;
	return dados;
};
ostream& operator<< (ostream &o, Ave animal){
    /*Como a ave será exibido em tela*/
    o << "Código" << setfill(' ') << setw(5) 
    << "Peso" << setfill(' ') << setw(5) 
    << "altura" << setfill(' ') << setw(5)
    << "idade" << setfill(' ') << setw(5)
    << "especie" << setfill(' ') << setw(5)  
    << endl
    << animal.getCodigo() << setfill(' ') << setw(5) 
    << animal.getPeso() << setfill(' ') << setw(5) 
    << animal.getAltura() << setfill(' ') << setw(5) 
    << animal.getIdade() << setfill(' ') << setw(5)
    << animal.getEspecie() << setfill(' ') << setw(5) 
    << endl;
	return o;
};