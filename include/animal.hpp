#pragma once

#include <vector>
#include <string>
#include <memory>
#include "tratador.hpp"
#include "veterinario.hpp"

using std::vector;
using std::string;
using std::shared_ptr;

// Resolve problema de dependência circular
class Tratador;

class Animal {

	private:

		string codigo;
		string peso;
		string altura;
		short idade;
		string especie;
		shared_ptr<Tratador> tratador;
		shared_ptr<Veterinario> veterinario;

	public:

		Animal(
			string codigo, 
			string peso, 
			string altura, 
			short idade, 
			string especie,
			shared_ptr<Veterinario>,
			shared_ptr<Tratador>
		);

		string getCodigo() const;
		string getPeso() const;
		string getAltura() const;
		short getIdade() const;
		string getEspecie() const;

		void setCodigo(string codigo);
		void setPeso(string peso);
		void setAltura(string altura);
		void setIdade(short idade);
		void setEspecie(string especie);
		void alterarDados(string codigo, string peso, string altura, short idade, string especie);
};