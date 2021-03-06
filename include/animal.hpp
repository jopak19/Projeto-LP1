#pragma once

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <iomanip>
#include "nivelseguranca.hpp"

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

	protected:

		string codigo;
		string peso;
		string altura;
		short idade;
		string especie;
		shared_ptr<Veterinario> veterinario;
		shared_ptr<Tratador> tratador;
		NivelSeguranca nivelSeguranca;
		bool perigoso;
		string classe;

	public:

		Animal(
			string codigo, 
			string peso, 
			string altura, 
			short idade, 
			string especie,
			bool perigoso
		);
		string getClasse() const;
		bool getPerigoso() const;
		void setPerigoso(bool perigoso);
		string getCodigo() const;
		string getPeso() const;
		string getAltura() const;
		short getIdade() const;
		string getEspecie() const;
		shared_ptr<Veterinario> getVeterinario() const;
		shared_ptr<Tratador> getTratador() const;
		NivelSeguranca getNivelSeguranca() const;
		bool setVeterinario(shared_ptr<Veterinario> veterinario);
		bool setTratador(shared_ptr<Tratador> tratador);
		void setCodigo(string codigo);
		void setPeso(string peso);
		void setAltura(string altura);
		void setIdade(short idade);
		void setEspecie(string especie);
		void alterarDados(string codigo, string peso, string altura, short idade, string especie);
		virtual string imprimir();
		virtual ~Animal();

		friend ostream& operator<< (ostream &o, shared_ptr<Animal> a);
};