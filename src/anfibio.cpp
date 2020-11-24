#include "anfibio.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::string;

//construtor
Anfibio::Anfibio(string codigo, 
                string peso, 
                string altura, 
                short idade, 
                string especie,
                shared_ptr<Veterinario> veterinario,
                shared_ptr<Tratador> tratador,
                string periodoDeMudadepele,
                int temperaturaDoAmbiente):
                Animal(codigo, peso, altura, idade, especie, veterinario, tratador),
                periodoDeMudaDePele(periodoDeMudadepele), temperaturaDoAmbiente(temperaturaDoAmbiente){};

//getters e setters
string Anfibio::getPeriodoDeMudadepele() const{
    return this->periodoDeMudaDePele;
};
void Anfibio::setPeriodoDeMudadepele(string periodo){
    this->periodoDeMudaDePele = periodo;
};
int Anfibio::getTemperaturaDeMudaDePele() const{
    return this->temperaturaDoAmbiente;
};
void Anfibio::setTemperaturaDeMudaDePele(int temperatura){
    this->temperaturaDoAmbiente = temperatura;
};
   
ostream& operator<< (ostream &o, Anfibio animal){
     /*Como o anfibio será exibido em tela*/
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