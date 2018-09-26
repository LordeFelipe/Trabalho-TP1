#ifndef TESTESENTIDADES_H
#define TESTESENTIDADES_H

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

#endif // TESTESENTIDADES_H
