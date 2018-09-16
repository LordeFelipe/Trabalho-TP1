#include "testesdominioshotel.h"


//Métodos que testam a classe CapacidadeDeAcomodacao

void TUCapacidadeDeAcomodacao::SetUp(){

    //Criação do objeto capacidade e definição do estado inicial do teste para sucesso
    capacidade = new CapacidadeDeAcomodacao();
    estado = SUCESSO;
}

void TUCapacidadeDeAcomodacao::TearDown(){
    delete capacidade;
}

void TUCapacidadeDeAcomodacao::TestarCenarioSucesso(){
    try{
        //O valor da capacidade é setado para um valor válido para passar no teste
        capacidade->SetCapacidadeDeAcomodacao(VALOR_VALIDO);
        if (capacidade->GetCapacidadeDeAcomodacao() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUCapacidadeDeAcomodacao::TestarCenarioFalha(){
    try{
        //O valor da capacidade é setado para um valor inválido para falhar no teste
        capacidade->SetCapacidadeDeAcomodacao(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUCapacidadeDeAcomodacao::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

//Métodos que testam a Diaria

void TUDiaria::SetUp(){

    //Criação do objeto diaria e definição do estado inicial do teste para sucesso
    diaria = new Diaria();
    estado = SUCESSO;
}

void TUDiaria::TearDown(){
    delete diaria;
}

void TUDiaria::TestarCenarioSucesso(){
    try{
        //O valor da diaria é setado para um valor válido para passar no teste
        diaria->SetDiaria(VALOR_VALIDO);
        if (diaria->GetDiaria() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUDiaria::TestarCenarioFalha(){
    try{
        //O valor da diaria é setado para um valor inválido para falhar no teste
        diaria->SetDiaria(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUDiaria::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

//Métodos que testam a Data

void TUData::SetUp(){

    //Criação do objeto data e definição do estado inicial do teste para sucesso
    data = new Data();
    estado = SUCESSO;
}

void TUData::TearDown(){
    delete data;
}

void TUData::TestarCenarioSucesso(){
    try{
        //O valor da data é setado para um valor válido para passar no teste
        data->SetData(VALOR_VALIDO_DIA, VALOR_VALIDO_MES, VALOR_VALIDO_ANO);
        if (data->GetDataDia() != VALOR_VALIDO_DIA || data->GetDataMes() != VALOR_VALIDO_MES || data->GetDataAno() != VALOR_VALIDO_ANO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUData::TestarCenarioFalha(){
    try{
        //O valor da data é setado para um valor inválido para falhar no teste
        data->SetData(VALOR_INVALIDO_DIA, VALOR_INVALIDO_MES, VALOR_INVALIDO_ANO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUData::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}
