#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

class Animal {

	private:

		string codigo;
		string peso;
		string altura;
		short idade;
		string especie;

	public:

		Animal(string codigo, string peso, string altura, short idade, string especie);
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