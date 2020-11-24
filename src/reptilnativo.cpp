#include "reptilnativo.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

ReptilNativo::ReptilNativo(string codigo, 
                            string peso, 
                            string altura, 
                            short idade, 
                            string especie,
                            string periodoDeMudadepele,
                            TipoDePele tipoDePele,
                            int marcacaoPermanente,
                            bool emExtincao,
                            Bioma biomaOrigem,
                            bool perigoso):
                            Reptil(codigo, peso, altura,idade, especie, periodoDeMudadepele, tipoDePele, perigoso),
                            Nativo(marcacaoPermanente, emExtincao, biomaOrigem){
    if(perigoso){
        this->nivelSeguranca = Vermelho;

    } else {
        this->nivelSeguranca = Azul;
    }

};
                                
ostream& operator<< (ostream &o, ReptilNativo animal){
     /*Como o Reptil nativo será exibido em tela*/
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
    << animal.getTipoDepele() << setfill(' ') << setw(5) 
    << endl;
	return o;
};