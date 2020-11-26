#include "reptilexotico.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

ReptilExotico::ReptilExotico (  string codigo, 
                                string peso, 
                                string altura, 
                                short idade, 
                                string especie,
                                string periodoDeMudadepele,
                                TipoDePele tipoDePele,
                                int marcacaoPermanente,
                                bool emExtincao,
                                string territorioDeOrigem,
                                bool perigoso):
                                Reptil(codigo, peso, altura,idade, especie, periodoDeMudadepele, tipoDePele, perigoso),
                                Exotico(marcacaoPermanente, emExtincao, territorioDeOrigem){
    setClasse();
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Azul;
    }
};
void ReptilExotico::setClasse(){
    this->classe = "reptilexotico";
};

//como reptil exótico será exibido
string ReptilExotico::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string extincao = this->getEmExtincao() ? "Sim" : "Não";
    string tipoPele;
    if(this->getTipoDepele() == CARAPACA) tipoPele = "Carapaça";
    if(this->getTipoDepele() == ESCAMAS) tipoPele = "Escamas";
    if(this->getTipoDepele() == PLACADERMICA) tipoPele = "Placa dérmica";
	dados = "codigo: " + this->getCodigo() + " | Peso: " + this->getPeso() + " | Altura: "+this->getAltura() + " | Especie: " + this->getEspecie() + " | Perigoso: "  + perigo + 
    " | Muda de Pele: " + this->getPeriodoDeMudadepele() + " | Tipo de Pele: " + tipoPele +
    " | Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " | Em extinção: " + extincao + " | Território origem: " + this->getTerritorioDeOrigem() +
    " | CPF Tratador: " + this->getTratador()->getCpf() + " | CPF Veterinario: " + this->getVeterinario()->getCpf() + "\n";
	return dados;
};
