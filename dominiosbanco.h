#ifndef DOMINIOS_H_
#define DOMINIOS_H_

#include <stdexcept>
#include <string>

using namespace std;

// Declaração das classes

class Agencia {

private:
	string agencia;

	const static int N_CARAC = 5;

	const static int LIMITE_INF = 48;

	const static int LIMITE_SUP = 57;

	// Método de validação
	void validar(string) throw (invalid_argument);

public:
	// Métodos de acesso
	void setAgencia(string) throw (invalid_argument);

	string getAgencia() const {
		return agencia;
	}
};

class Banco {

private:
	string banco;

	const static int N_CARAC = 3;

	const static int LIMITE_INF = 48;

	const static int LIMITE_SUP = 57;

	// Método de validação
	void validar(string) throw (invalid_argument);

public:
	// Métodos de acesso
	void setBanco(string) throw (invalid_argument);

	string getBanco() const {
		return banco;
	}
};

class Conta {

private:
	string conta;

	const static int N_CARAC = 6;

	const static int LIMITE_INF = 48;

	const static int LIMITE_SUP = 57;

	// Método de validação
	void validar(string) throw (invalid_argument);

public:
	// Métodos de acesso
	void setConta(string) throw (invalid_argument);

	string getConta() const {
		return conta;
	}
};

class Cartao {

private:
	string cartao;

	const static int N_CARAC = 16;

	const static int LIMITE_INF = 48;

	const static int LIMITE_SUP = 57;

	// Método de validação
	void validar(string) throw (invalid_argument);

public:
	// Métodos de acesso
	void setCartao(string) throw (invalid_argument);

	string getCartao() const {
		return cartao;
	}
};


#endif