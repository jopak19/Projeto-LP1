#include "anfibioexotico.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

AnfibioExotico::AnfibioExotico (string codigo, 
                                string peso, 
                                string altura, 
                                short idade, 
                                string especie,
                                string periodoDeMudadepele,
                                int temperaturaDoAmbiente,
                                int marcacaoPermanente,
                                bool emExtincao,
                                string territorioDeOrigem,
                                bool perigoso):
                                Anfibio(codigo, peso, altura,idade, especie, periodoDeMudadepele, temperaturaDoAmbiente, perigoso),
                                Exotico(marcacaoPermanente, emExtincao, territorioDeOrigem){};

string AnfibioExotico::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string extincao = this->getEmExtincao() ? "Sim" : "Não";
	dados = "codigo: " + this->getCodigo() + " Peso: " + this->getPeso() + " Altura: "+this->getAltura() + " Especie: " + this->getEspecie() + " Perigoso: "  + perigo + 
    " Muda de Pele: " + this->getPeriodoDeMudadepele() + " Temperatura do Ambiente: " + to_string(this->getTemperaturaDoAmbiente()) +
    " Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " Em extinção: " + extincao + " Território origem: " + this->getTerritorioDeOrigem();
	return dados;
};

ostream& operator<< (ostream &o, AnfibioExotico animal){
     /*Como o anfibio exotico será exibido em tela*/
    o << "Código" << setfill(' ') << setw(5) 
    << "Peso" << setfill(' ') << setw(5) 
    << "altura" << setfill(' ') << setw(5)
    << "idade" << setfill(' ') << setw(5)
    << "especie" << setfill(' ') << setw(5) 
    << "Muda de pele" << setfill(' ') << setw(5)
    << "Temperatura do ambiente" << setfill(' ') << setw(5)
    //TODO: falta as especificas   
    << endl
    << animal.getCodigo() << setfill(' ') << setw(5) 
    << animal.getPeso() << setfill(' ') << setw(5) 
    << animal.getAltura() << setfill(' ') << setw(5) 
    << animal.getIdade() << setfill(' ') << setw(5)
    << animal.getEspecie() << setfill(' ') << setw(5)
    << animal.getPeriodoDeMudadepele() << setfill(' ') << setw(5)
    << animal.getTemperaturaDoAmbiente() << setfill(' ') << setw(5) 
    << endl;
	return o;
};