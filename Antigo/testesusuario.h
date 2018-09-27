#ifndef TESTESUSUARIO_H
#define TESTESUSUARIO_H

#include "dominiosusuario.h"

//Testes referentes ao objeto Identificador
class TUIdentificador
{
    private:

    const string VALOR_VALIDO = "joaos";
    const string VALOR_INVALIDO = "AAAAA";


    Identificador* identificador;

    //Estado do Teste
    int estado;

    //Declaração dos métodos
    void SetUp();
    void TearDown();
    void TestarCenarioSucesso();
    void TestarCenarioFalha();

    public:

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

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


#endif // TESTESUSUARIO_H
