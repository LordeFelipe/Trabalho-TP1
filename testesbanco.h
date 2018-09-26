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

	void SetUp();
	void TearDown();
	void TestarCenarioSucesso();
	void TestarCenarioFalha_QTD();
	void TestarCenarioFalha_CARAC();

public:

	// Constantes de estado:

	const static int SUCESSO = 0;
	const static int FALHA = 1;

	int Run();
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

	void SetUp();
	void TearDown();
	void TestarCenarioSucesso();
	void TestarCenarioFalha_QTD();
	void TestarCenarioFalha_CARAC();

public:

	// Constantes de estado:

	const static int SUCESSO = 0;
	const static int FALHA = 1;

	int Run();
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

	void SetUp();
	void TearDown();
	void TestarCenarioSucesso();
	void TestarCenarioFalha_QTD();
	void TestarCenarioFalha_CARAC();

public:

	// Constantes de estado:

	const static int SUCESSO = 0;
	const static int FALHA = 1;

	int Run();
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

	void SetUp();
	void TearDown();
	void TestarCenarioSucesso();
	void TestarCenarioFalha_QTD();
	void TestarCenarioFalha_CARAC();
	void TestarCenarioFalha_NUM();

public:

	// Constantes de estado:

	const static int SUCESSO = 0;
	const static int FALHA = 1;

	int Run();
};

// Testes da classe Cartao:
class TUValidade {

private:

	// Definição dos valores válidos e inválidos:

	const string VALOR_VALIDO = "12/88";
	const string VALOR_INVALIDO_SEPARADOR = "12.88";
	const string VALOR_INVALIDO_MES = "23/88";
	const string VALOR_INVALIDO_ANO = "12/aa";
	const string VALOR_INVALIDO_QTD = "12/788";


	// Ponteiro para o objeto a ser testado:

	Validade *data;

	// Estado do teste:

	int estado;

	// Declaraçãoo de métodos:

	void SetUp();
	void TearDown();
	void TestarCenarioSucesso();
	void TestarCenarioFalha_QTD();
	void TestarCenarioFalha_MES();
	void TestarCenarioFalha_ANO();
	void TestarCenarioFalha_SEPARADOR();

public:

	// Constantes de estado:

	const static int SUCESSO = 0;
	const static int FALHA = 1;

	int Run();
};

// Testes da classe Nome:
class TUNome {

private:

	// Definição dos valores válidos e inválidos:

	const string VALOR_VALIDO = "Andre M. Valle";
	const string VALOR_INVALIDO_TAM = "Andre Macedo Prado Valle";
	const string VALOR_INVALIDO_CARAC = "1209389784";
	const string VALOR_INVALIDO_PONTO = "Andre . Valle";
	const string VALOR_INVALIDO_ESPACO = "Andre  Valle";


	// Ponteiro para o objeto a ser testado:

	Nome *nome;

	// Estado do teste:

	int estado;

	// Declaraçãoo de métodos:

	void SetUp();
	void TearDown();
	void TestarCenarioSucesso();
	void TestarCenarioFalha_TAM();
	void TestarCenarioFalha_CARAC();
	void TestarCenarioFalha_PONTO();
	void TestarCenarioFalha_ESPACO();

public:

	// Constantes de estado:

	const static int SUCESSO = 0;
	const static int FALHA = 1;

	int Run();
};

// Testes da classe Senha:
class TUSenha {

private:

	// Definição dos valores válidos e inválidos:

	const string VALOR_VALIDO = "1aA#%!&$";
	const string VALOR_INVALIDO_TAM = "1aA#%!&";
	const string VALOR_INVALIDO_CARAC = "1aA#%!&*";
	const string VALOR_INVALIDO_REPETIDO = "1aA#%!&a";
	const string VALOR_INVALIDO_FALTA = "1aa1aa1a";


	// Ponteiro para o objeto a ser testado:

	Senha *senha;

	// Estado do teste:

	int estado;

	// Declaraçãoo de métodos:

	void SetUp();
	void TearDown();
	void TestarCenarioSucesso();
	void TestarCenarioFalha_TAM();
	void TestarCenarioFalha_CARAC();
	void TestarCenarioFalha_REPETIDO();
	void TestarCenarioFalha_FALTA();

public:

	// Constantes de estado:

	const static int SUCESSO = 0;
	const static int FALHA = 1;

	int Run();
};

#endif
