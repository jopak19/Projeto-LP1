#include "aveexotico.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

AveExotico::AveExotico (string codigo, 
                        string peso, 
                        string altura, 
                        short idade, 
                        string especie,
                        bool aquatica,
                        bool podeVoar,
                        int marcacaoPermanente,
                        bool emExtincao,
                        string territorioDeOrigem,
                        bool perigoso):
                        Ave(codigo, peso, altura,idade, especie, aquatica, podeVoar, perigoso),
                        Exotico(marcacaoPermanente, emExtincao, territorioDeOrigem){
    setClasse();
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Verde;
    }

};
void AveExotico::setClasse(){
    this->classe = "aveexotico";
};
string AveExotico::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string extincao = this->getEmExtincao() ? "Sim" : "Não";
    string aqua = this->aquatica ? "aquatica" : "não Aquatica";
    string voa = this->podeVoar ? "voa" : "Não voa";
	dados = "codigo: " + this->getCodigo() + " Peso: " + this->getPeso() + " Altura: "+this->getAltura() + " Especie: " + this->getEspecie() + " Perigoso: "  + perigo + 
    " Aquatica: " + aqua + " Pode var: " + voa + 
    " Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " Em extinção: " + extincao + " Território origem: " + this->getTerritorioDeOrigem();;
	return dados;
};
ostream& operator<< (ostream &o, AveExotico animal){
     /*Como o Ave exotico será exibido em tela*/
    o << "Código" << setfill(' ') << setw(5) 
    << "Peso" << setfill(' ') << setw(5) 
    << "altura" << setfill(' ') << setw(5)
    << "idade" << setfill(' ') << setw(5)
    << "especie" << setfill(' ') << setw(5) 
    << "aquatica" << setfill(' ') << setw(5)
    << "pode voar" << setfill(' ') << setw(5)
    //TODO: falta as especificas   
    << endl
    << animal.getCodigo() << setfill(' ') << setw(5) 
    << animal.getPeso() << setfill(' ') << setw(5) 
    << animal.getAltura() << setfill(' ') << setw(5) 
    << animal.getIdade() << setfill(' ') << setw(5)
    << animal.getEspecie() << setfill(' ') << setw(5)
    << animal.getAquatica() << setfill(' ') << setw(5)
    << animal.getPodeVoar() << setfill(' ') << setw(5) 
    << endl;
	return o;
};