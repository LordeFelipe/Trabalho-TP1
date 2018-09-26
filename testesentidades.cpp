#include "testesentidades.h"

//Métodos que testam a classe Acomodacao

void TUAcomodacao::SetUp(){

    //Criação do objeto capacidade e definição do estado inicial do teste para sucesso
    acomodacao = new Acomodacao();
    estado = SUCESSO;
}

void TUAcomodacao::TearDown(){
    delete acomodacao;
}

void TUAcomodacao::TestarCenarioSucessoIdentificador(){
    try{
        //É setado um valor válido para o identificador contido na acomodacao
        Identificador identificador;
        identificador.SetIdentificador(VALOR_VALIDO_IDENTIFICADOR);
        acomodacao->SetIdentificador(identificador);

        if (acomodacao->GetIdentificador().GetIdentificador() != identificador.GetIdentificador())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUAcomodacao::TestarCenarioSucessoTipoAcomodacao(){
    try{
        //É setado um valor válido para o tipo de acomodação contido na acomodacao
        TipoDeAcomodacao tipo_de_acomodacao;
        tipo_de_acomodacao.SetTipoDeAcomodacao(VALOR_VALIDO_TIPO_ACOMODACAO);
        acomodacao->SetTipoDeAcomodacao(tipo_de_acomodacao);

        if (acomodacao->GetTipoDeAcomodacao().GetTipoDeAcomodacao() != tipo_de_acomodacao.GetTipoDeAcomodacao())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}


void TUAcomodacao::TestarCenarioSucessoCapacidade(){
    try{
        //É setado um valor válido para a capacidade contida na acomodacao
        CapacidadeDeAcomodacao capacidade;
        capacidade.SetCapacidadeDeAcomodacao(VALOR_VALIDO_CAPACIDADE);
        acomodacao->SetCapacidaDeAcomodacao(capacidade);

        if (acomodacao->GetCapacidadeDeAcomodacao().GetCapacidadeDeAcomodacao() != capacidade.GetCapacidadeDeAcomodacao())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUAcomodacao::TestarCenarioSucessoDataInicio(){
    try{
        //É setado um valor válido para a data de inicio contida na acomodacao
        Data data_inicio;
        data_inicio.SetData(VALOR_VALIDO_DATA);
        acomodacao->SetDataInicio(data_inicio);

        if (acomodacao->GetDataInicio().GetData() != data_inicio.GetData())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUAcomodacao::TestarCenarioSucessoDataTermino(){
    try{
        //É setado um valor válido para a data de término contida na acomodacao
        Data data_termino;
        data_termino.SetData(VALOR_VALIDO_DATA);
        acomodacao->SetDataTermino(data_termino);

        if (acomodacao->GetDataTermino().GetData() != data_termino.GetData())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUAcomodacao::TestarCenarioSucessoCidade(){
    try{
        //É setado um valor válido para a cidade contida na acomodacao
        Nome cidade;
        cidade.SetNome(VALOR_VALIDO_CIDADE);
        acomodacao->SetCidade(cidade);

        if (acomodacao->GetCidade().GetNome() != cidade.GetNome())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUAcomodacao::TestarCenarioSucessoEstado(){
    try{
        //É setado um valor válido para o estado contido na acomodacao
        Estado estado_brasileiro;
        estado_brasileiro.SetEstado(VALOR_VALIDO_CIDADE);
        acomodacao->SetEstado(estado_brasileiro);

        if (acomodacao->GetEstado().GetEstado() != estado_brasileiro.GetEstado())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUAcomodacao::TestarCenarioSucessoDiaria(){
    try{
        //É setado um valor válido para a diaria contida na acomodacao
        Diaria diaria;
        diaria.SetDiaria(VALOR_VALIDO_DIARIA);
        acomodacao->SetDiaria(diaria);

        if (acomodacao->GetDiaria().GetDiaria() != diaria.GetDiaria())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}


int TUAcomodacao::Run(){
    SetUp();
    TestarCenarioSucessoIdentificador();
    TestarCenarioSucessoTipoAcomodacao();
    TestarCenarioSucessoCapacidade();
    TestarCenarioSucessoDataInicio();
    TestarCenarioSucessoDataTermino();
    TestarCenarioSucessoCidade();
    TestarCenarioSucessoEstado();
    TestarCenarioSucessoDiaria();
    TearDown();
    return estado;
}
