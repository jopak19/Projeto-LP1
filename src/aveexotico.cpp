#include "aveexotico.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include "tratador.hpp"
#include "veterinario.hpp"
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

}
AveExotico::~AveExotico(){}
void AveExotico::setClasse(){
    this->classe = "aveexotico";
}

//como uma ave exótica será exibida
string AveExotico::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string extincao = this->getEmExtincao() ? "Sim" : "Não";
    string aqua = this->aquatica ? "aquatica" : "não Aquatica";
    string voa = this->podeVoar ? "voa" : "Não voa";
    dados = "codigo: " + this->getCodigo() + " Peso: " + this->getPeso() + " Altura: "+this->getAltura() + " Especie: " + this->getEspecie() + " Perigoso: "  + perigo + 
    " Aquatica: " + aqua + " Pode var: " + voa + 
    " Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " Em extinção: " + extincao + " Território origem: " + this->getTerritorioDeOrigem() + 
    " | CPF Tratador: " + this->getTratador()->getCpf() + " | CPF Veterinario: " + this->getVeterinario()->getCpf() + "\n";
    return dados;
}