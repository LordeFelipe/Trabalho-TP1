#include "Testes_Dominios_Hotel.h"


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
        data->SetData(VALOR_VALIDO);
        if (data->GetData() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUData::TestarCenarioFalha(){
    try{
        //O valor da data é setado para um valor inválido para falhar no teste
        data->SetData(VALOR_INVALIDO);
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

//Métodos que testam o Estado

void TUEstado::SetUp(){

    //Criação do objeto estado e definição do estado inicial do teste para sucesso
    estado = new Estado();
    estado_teste = SUCESSO;
}

void TUEstado::TearDown(){
    delete estado;
}

void TUEstado::TestarCenarioSucesso(){
    try{
        //É setado um estado vaĺido para passsar no teste
        estado->SetEstado(VALOR_VALIDO);
        if (estado->GetEstado() != VALOR_VALIDO)
            estado_teste = FALHA;
    }
    catch(invalid_argument excecao){
        estado_teste = FALHA;
    }
}

void TUEstado::TestarCenarioFalha(){
    try{
        //É setado um estado inválido para falhar no teste
        estado->SetEstado(VALOR_INVALIDO);
        estado_teste = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUEstado::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado_teste;
}

//Métodos que testam o Estado

void TUTipoDeAcomodacao::SetUp(){

    //Criação do objeto acomodacao e definição do estado inicial do teste para sucesso
    acomodacao = new TipoDeAcomodacao();
    estado_teste = SUCESSO;
}

void TUTipoDeAcomodacao::TearDown(){
    delete acomodacao;
}

void TUTipoDeAcomodacao::TestarCenarioSucesso(){
    try{
        //É setado um tipo de acomodação vaĺido para passsar no teste
        acomodacao->SetTipoDeAcomodacao(VALOR_VALIDO);
        if (acomodacao->GetTipoDeAcomodacao() != VALOR_VALIDO)
            estado_teste = FALHA;
    }
    catch(invalid_argument excecao){
        estado_teste = FALHA;
    }
}

void TUTipoDeAcomodacao::TestarCenarioFalha(){
    try{
        //É setado um tipo de acomodação inválido para falhar no teste
        acomodacao->SetTipoDeAcomodacao(VALOR_INVALIDO);
        estado_teste = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUTipoDeAcomodacao::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado_teste;
}