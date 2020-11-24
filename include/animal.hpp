#pragma once

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <iomanip>

using std::vector;
using std::string;
using std::shared_ptr;
using std::ostream;
using std::setfill;
using std::setw;
using std::endl;

//Resolve problema de dependência circular
class Tratador;
class Veterinario;

class Animal {

	private:

		string codigo;
		string peso;
		string altura;
		short idade;
		string especie;
		shared_ptr<Veterinario> veterinario;
		shared_ptr<Tratador> tratador;

	public:

		Animal(
			string codigo, 
			string peso, 
			string altura, 
			short idade, 
			string especie,
			shared_ptr<Veterinario> veterinario,
			shared_ptr<Tratador> tratador
		);

		string getCodigo() const;
		string getPeso() const;
		string getAltura() const;
		short getIdade() const;
		string getEspecie() const;
		shared_ptr<Veterinario> getVeterinario() const;
		shared_ptr<Tratador> getTratador() const;

		void setCodigo(string codigo);
		void setPeso(string peso);
		void setAltura(string altura);
		void setIdade(short idade);
		void setEspecie(string especie);
		void alterarDados(string codigo, string peso, string altura, short idade, string especie);

		friend ostream& operator<< (ostream &o, Animal a);
};