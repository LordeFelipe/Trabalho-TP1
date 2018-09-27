#ifndef TESTES_DOMINIOS_HOTEL_H_
#define TESTES_DOMINIOS_HOTEL_H_

#include <string>
#include <stdexcept>
#include "Dominios_Hotel.h"

using namespace std;

//Testes referentes ao tipo CapacidadeDeAcomodação
class TUCapacidadeDeAcomodacao
{
    private:

    const static int VALOR_VALIDO = 5;
    const static int VALOR_INVALIDO = 15;

    CapacidadeDeAcomodacao* capacidade;

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

//Testes referentes ao objeto Diaria
class TUDiaria
{
    private:

    const static float VALOR_VALIDO = 250;
    const static float VALOR_INVALIDO = 12000;

    Diaria* diaria;

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

//Testes referentes ao objeto Data
class TUData
{
    private:

    const string VALOR_VALIDO = "29/fev/2004";
    const string VALOR_INVALIDO = "31/jan/1999";

    Data* data;

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

//Testes referentes ao objeto Estado
class TUEstado
{
    private:

    const string VALOR_VALIDO = "TO";
    const string VALOR_INVALIDO = "AA";

    Estado* estado;

    //Estado do Teste
    int estado_teste;

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

//Testes referentes ao objeto TipoDeAcomodacao
class TUTipoDeAcomodacao
{
    private:

    const string VALOR_VALIDO = "Flat";
    const string VALOR_INVALIDO = "Castelo Medieval";


    TipoDeAcomodacao* acomodacao;

    //Estado do Teste
    int estado_teste;

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

#endif // TESTES_DOMINIOS_HOTEL_H_