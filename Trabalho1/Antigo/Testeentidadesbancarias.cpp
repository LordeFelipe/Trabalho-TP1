#include "Testeentidadesbancarias.h"

//Métodos que testam a classe Cartao

void TUCartao::SetUp(){

    //Criação do objeto e definição do estado inicial do teste para sucesso
    cartao = new Cartao();
    estado = SUCESSO;
}

void TUCartao::TearDown(){
    delete cartao;
}

void TUCartao::TestarCenarioSucessoValidade(){
    try{
        //É setado um valor válido para a validade
        Validade validade;
        validade.SetVal(VALOR_VALIDO_VAL);
        cartao->SetValidade(validade);

        if (cartao->GetValidade().GetVal() != validade.GetVal())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUCartao::TestarCenarioSucessoNumero(){
    try{
        //É setado um valor válido para o numero do cartao
        NumeroCartao numero;
        numero.SetNumero(VALOR_VALIDO_NUMERO);
        cartao->SetNumero(numero);

        if (cartao->GetNumero().GetNumero() != numero.GetNumero())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUCartao::Run(){
    SetUp();
    TestarCenarioSucessoNumero();
    TestarCenarioSucessoValidade();
    TearDown();
    return estado;
}


//Métodos que testam a classe ContaCorrente

void TUContaCorrente::SetUp(){

    //Criação do objeto e definição do estado inicial do teste para sucesso
    conta = new ContaCorrente();
    estado = SUCESSO;
}

void TUContaCorrente::TearDown(){
    delete conta;
}

void TUContaCorrente::TestarCenarioSucessoNumero(){
    try{
        //É setado um valor válido para o numero da conta
        NumeroConta numero;
        numero.SetConta(VALOR_VALIDO_NUMERO);
        conta->SetNumero(numero);

        if (conta->GetNumero().GetConta() != numero.GetConta())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUContaCorrente::TestarCenarioSucessoAgencia(){
    try{
        //É setado um valor válido para a validade
        Agencia agencia;
        agencia.SetAgencia(VALOR_VALIDO_AGENCIA);
        conta->SetAgencia(agencia);

        if (conta->GetAgencia().GetAgencia() != agencia.GetAgencia())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUContaCorrente::TestarCenarioSucessoBanco(){
    try{
        //É setado um valor válido para a validade
        Banco banco;
        banco.SetBanco(VALOR_VALIDO_BANCO);
        conta->SetBanco(banco);

        if (conta->GetBanco().GetBanco() != banco.GetBanco())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUContaCorrente::Run(){
    SetUp();
    TestarCenarioSucessoNumero();
    TestarCenarioSucessoAgencia();
    TestarCenarioSucessoBanco();
    TearDown();
    return estado;
}
