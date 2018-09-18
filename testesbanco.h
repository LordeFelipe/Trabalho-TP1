#ifndef TESTES_H_
#define TESTES_H_

#include "dominiosbanco.h"

using namespace std;

// Declarações das classes de teste:

// Testes da classe Agencia:
class TUAgencia {

private:

	// Definição dos valores válidos e inválidos:

	const string VALOR_VALIDO = "12345";
	const string VALOR_INVALIDO_QTD = "123456";
	const string VALOR_INVALIDO_CARAC = "01a23";

	// Ponteiro para o objeto a ser testado:

	Agencia *agencia;

	// Estado do teste:

	int estado;

	// Declaraçãoo de métodos:

	void setUp();
	void tearDown();
	void testarCenarioSucesso();
	void testarCenarioFalha_QTD();
	void testarCenarioFalha_CARAC();

public:

	// Constantes de estado:

	const static int SUCESSO = 0;
	const static int FALHA = 0;

	int run();
};

// Testes da classe Banco:
class TUBanco {

private:

	// Definição dos valores válidos e inválidos:

	const string VALOR_VALIDO = "123";
	const string VALOR_INVALIDO_QTD = "1234";
	const string VALOR_INVALIDO_CARAC = "01a";

	// Ponteiro para o objeto a ser testado:

	Banco *banco;

	// Estado do teste:

	int estado;

	// Declaraçãoo de métodos:

	void setUp();
	void tearDown();
	void testarCenarioSucesso();
	void testarCenarioFalha_QTD();
	void testarCenarioFalha_CARAC();

public:

	// Constantes de estado:

	const static int SUCESSO = 0;
	const static int FALHA = 0;

	int run();
};

// Testes da classe Banco:
class TUConta {

private:

	// Definição dos valores válidos e inválidos:

	const string VALOR_VALIDO = "123456";
	const string VALOR_INVALIDO_QTD = "12345";
	const string VALOR_INVALIDO_CARAC = "01a123";

	// Ponteiro para o objeto a ser testado:

	Conta *conta;

	// Estado do teste:

	int estado;

	// Declaraçãoo de métodos:

	void setUp();
	void tearDown();
	void testarCenarioSucesso();
	void testarCenarioFalha_QTD();
	void testarCenarioFalha_CARAC();

public:

	// Constantes de estado:

	const static int SUCESSO = 0;
	const static int FALHA = 0;

	int run();
};

// Testes da classe Cartao:
class TUCartao {

private:

	// Definição dos valores válidos e inválidos:

	const string VALOR_VALIDO = "4012001037141112";
	const string VALOR_INVALIDO_QTD = "123456";
	const string VALOR_INVALIDO_CARAC = "0123123e123e123r";
	const string VALOR_INVALIDO_NUM = "4012001037141111";


	// Ponteiro para o objeto a ser testado:

	Cartao *cartao;

	// Estado do teste:

	int estado;

	// Declaraçãoo de métodos:

	void setUp();
	void tearDown();
	void testarCenarioSucesso();
	void testarCenarioFalha_QTD();
	void testarCenarioFalha_CARAC();
	void testarCenarioFalha_NUM();

public:

	// Constantes de estado:

	const static int SUCESSO = 0;
	const static int FALHA = 0;

	int run();
};

#endif
