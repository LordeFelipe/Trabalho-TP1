#ifndef TESTES_ENTIDADES_H_
#define TESTES_ENTIDADES_H_

#include "entidades.h"

//Testes referentes ao tipo CapacidadeDeAcomodação
class TUAcomodacao
{
    private:

    Acomodacao* acomodacao;

    const static int VALOR_VALIDO_CAPACIDADE = 5;
    const static float VALOR_VALIDO_DIARIA = 250;
    const string VALOR_VALIDO_DATA = "29/fev/2004";
    const string VALOR_VALIDO_ESTADO = "TO";
    const string VALOR_VALIDO_TIPO_ACOMODACAO = "Flat";
    const string VALOR_VALIDO_CIDADE = "Brasilia";
    const string VALOR_VALIDO_IDENTIFICADOR = "joaos";

    //Estado do Teste
    int estado;

    //Declaração dos métodos
    void SetUp();
    void TearDown();
    void TestarCenarioSucessoIdentificador();
    void TestarCenarioSucessoTipoAcomodacao();
    void TestarCenarioSucessoCapacidade();
    void TestarCenarioSucessoDataInicio();
    void TestarCenarioSucessoDataTermino();
    void TestarCenarioSucessoCidade();
    void TestarCenarioSucessoEstado();
    void TestarCenarioSucessoDiaria();

    public:

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

    int Run();
};

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

//Testes referentes a entidade Usuario
class TUUsuario{

    private:

    Usuario* usuario;

    const string VALOR_VALIDO_IDENTIFICADOR = "joaos";
    const string VALOR_VALIDO_NOME = "Andre M. Valle";
    const string VALOR_VALIDO_SENHA = "1aA#%!&$";

    //Estado do Teste
    int estado;

    //Declaração dos métodos da entidade
    void SetUp();
    void TearDown();
    void TestarCenarioSucessoIdentificador();
    void TestarCenarioSucessoNome();
    void TestarCenarioSucessoSenha();

    public:

    const static int SUCESSO = 0;
    const static int FALHA = 1;

    int Run();
};

#endif // TESTES_ENTIDADES_H_