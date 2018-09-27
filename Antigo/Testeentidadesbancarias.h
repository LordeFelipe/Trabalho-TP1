#ifndef TESTE_SENTIDADES_BANCARIAS_H
#define TESTE_SENTIDADES_BANCARIAS_H

#include "entidadesbancarias.h"

//Testes referentes a entidade Cartao
class TUCartao{

    private:

    Cartao* cartao;

    const string VALOR_VALIDO_VAL = "04/12";
    const string VALOR_VALIDO_NUMERO = "5555666677778884";

    //Estado do Teste
    int estado;

    //Declaração dos métodos da entidade
    void SetUp();
    void TearDown();
    void TestarCenarioSucessoValidade();
    void TestarCenarioSucessoNumero();

    public:

    const static int SUCESSO = 0;
    const static int FALHA = 1;

    int Run();
};

//Testes referentes a entidade ContaCorrente
class TUContaCorrente{

    private:

    ContaCorrente* conta;

    const string VALOR_VALIDO_NUMERO = "456328";
    const string VALOR_VALIDO_AGENCIA = "24578";
    const string VALOR_VALIDO_BANCO = "845";

    //Estado do Teste
    int estado;

    //Declaração dos métodos da entidade
    void SetUp();
    void TearDown();
    void TestarCenarioSucessoNumero();
    void TestarCenarioSucessoAgencia();
    void TestarCenarioSucessoBanco();

    public:

    const static int SUCESSO = 0;
    const static int FALHA = 1;

    int Run();
};

#endif