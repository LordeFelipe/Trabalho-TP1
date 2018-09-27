#ifndef ENTIDADES_BANCARIAS_H
#define ENTIDADES_BANCARIAS_H

#include "dominiosbanco.h"

// Definição das Classes

class Cartao{

	private:

		// Elementos que compoem a classe?
		NumeroCartao numero;
		Validade validade;

	public:

		// Metodos de acesso ao numero do cartão:
		void SetNumero(const NumeroCartao &numero){
			this->numero = numero;
		}

		NumeroCartao GetNumero() const {
			return numero;
		}

		// Metodos de acesso a data de validade do cartao:
		void SetValidade(const Validade &validade){
			this->validade = validade;
		}

		Validade GetValidade() const {
			return validade;
		}
};

class ContaCorrente{

	private:

		// Elementos que compoem a classe?
		NumeroConta numero;
		Agencia agencia;
		Banco banco;

	public:

		// Metodos de acesso ao numero da conta:
		void SetNumero(const NumeroConta &numero){
			this->numero = numero;
		}

		NumeroConta GetNumero() const {
			return numero;
		}

		// Metodos de acesso a agencia da conta:
		void SetAgencia(const Agencia &agencia){
			this->agencia = agencia;
		}

		Agencia GetAgencia() const {
			return agencia;
		}

		// Metodos de acesso ao banco da conta:
		void SetBanco(const Banco &banco){
			this->banco = banco;
		}

		Banco GetBanco() const {
			return banco;
		}
};

#endif