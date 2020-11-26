#include "anfibioexotico.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
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
                                Exotico(marcacaoPermanente, emExtincao, territorioDeOrigem){
                                    setClasse();
                                };

void AnfibioExotico::setClasse(){
    this->classe = "anfibioexotico";
};
//como anfibio exotico será exibido
string AnfibioExotico::imprimir(){
    string dados;
    string perigo = this->getPerigoso() ? "Sim" : "Não";
    string extincao = this->getEmExtincao() ? "Sim" : "Não";
	dados = "codigo: " + this->getCodigo() + " | Peso: " + this->getPeso() + " | Altura: "+this->getAltura() + " | Especie: " + this->getEspecie() + " | Perigoso: "  + perigo + 
    " | Muda de Pele: " + this->getPeriodoDeMudadepele() + " | Temperatura do Ambiente: " + to_string(this->getTemperaturaDoAmbiente()) +
    " | Marcação Permanente: " + to_string(this->getMarcacaoPermanente()) + " | Em extinção: " + extincao + " | Território origem: " + this->getTerritorioDeOrigem() +
    " | CPF Tratador: " + this->getTratador()->getCpf() + " | CPF Veterinario: " + this->getVeterinario()->getCpf() + "\n";
	return dados;
};
