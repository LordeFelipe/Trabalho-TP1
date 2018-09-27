#include <iostream>
#include "testesbanco.h"

// Definição dos métodos:

// Testes para a classe Agência:
void TUAgencia::SetUp(){
	agencia = new Agencia();
	estado = SUCESSO;
}

void TUAgencia::TearDown(){
	delete agencia;
}

void TUAgencia::TestarCenarioSucesso(){
	try{
		agencia->SetAgencia(VALOR_VALIDO);
		if(agencia->GetAgencia() != VALOR_VALIDO)
			estado = FALHA;
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUAgencia::TestarCenarioFalha_QTD(){
	try{
		agencia->SetAgencia(VALOR_INVALIDO_QTD);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUAgencia::TestarCenarioFalha_CARAC(){
	try{
		agencia->SetAgencia(VALOR_INVALIDO_CARAC);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUAgencia::Run(){
	SetUp();
	TestarCenarioSucesso();
    TestarCenarioFalha_QTD();
    TestarCenarioFalha_CARAC();
    TearDown();

    return estado;
}

// Testes para a classe Banco:
void TUBanco::SetUp(){
	banco = new Banco();
	estado = SUCESSO;
}

void TUBanco::TearDown(){
	delete banco;
}

void TUBanco::TestarCenarioSucesso(){
	try{
		banco->SetBanco(VALOR_VALIDO);
		if(banco->GetBanco() != VALOR_VALIDO)
			estado = FALHA;
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUBanco::TestarCenarioFalha_QTD(){
	try{
		banco->SetBanco(VALOR_INVALIDO_QTD);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUBanco::TestarCenarioFalha_CARAC(){
	try{
		banco->SetBanco(VALOR_INVALIDO_CARAC);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUBanco::Run(){
	SetUp();
	TestarCenarioSucesso();
    TestarCenarioFalha_QTD();
    TestarCenarioFalha_CARAC();
    TearDown();

    return estado;
}

// Testes para a classe Conta:
void TUConta::SetUp(){
	conta = new NumeroConta();
	estado = SUCESSO;
}

void TUConta::TearDown(){
	delete conta;
}

void TUConta::TestarCenarioSucesso(){
	try{
		conta->SetConta(VALOR_VALIDO);
		if(conta->GetConta() != VALOR_VALIDO)
			estado = FALHA;
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUConta::TestarCenarioFalha_QTD(){
	try{
		conta->SetConta(VALOR_INVALIDO_QTD);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUConta::TestarCenarioFalha_CARAC(){
	try{
		conta->SetConta(VALOR_INVALIDO_CARAC);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUConta::Run(){
	SetUp();
	TestarCenarioSucesso();
    TestarCenarioFalha_QTD();
    TestarCenarioFalha_CARAC();
    TearDown();

    return estado;
}

// Testes para a classe Cartao:
void TUNumeroCartao::SetUp(){
	cartao = new NumeroCartao();
	estado = SUCESSO;
}

void TUNumeroCartao::TearDown(){
	delete cartao;
}

void TUNumeroCartao::TestarCenarioSucesso(){
	try{
		cartao->SetNumero(VALOR_VALIDO);
		if(cartao->GetNumero() != VALOR_VALIDO)
			estado = FALHA;
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUNumeroCartao::TestarCenarioFalha_QTD(){
	try{
		cartao->SetNumero(VALOR_INVALIDO_QTD);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUNumeroCartao::TestarCenarioFalha_CARAC(){
	try{
		cartao->SetNumero(VALOR_INVALIDO_CARAC);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUNumeroCartao::TestarCenarioFalha_NUM(){
	try{
		cartao->SetNumero(VALOR_INVALIDO_NUM);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUNumeroCartao::Run(){
	SetUp();
	TestarCenarioSucesso();
    TestarCenarioFalha_QTD();
    TestarCenarioFalha_CARAC();
    TestarCenarioFalha_NUM();
    TearDown();

    return estado;
}

// Testes para a classe Validade:
void TUValidade::SetUp(){
	data = new Validade();
	estado = SUCESSO;
}

void TUValidade::TearDown(){
	delete data;
}

void TUValidade::TestarCenarioSucesso(){
	try{
		data->SetVal(VALOR_VALIDO);
		if(data->GetVal() != VALOR_VALIDO){
			estado = FALHA;
		}
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUValidade::TestarCenarioFalha_QTD(){
	try{
		data->SetVal(VALOR_INVALIDO_QTD);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUValidade::TestarCenarioFalha_SEPARADOR(){
	try{
		data->SetVal(VALOR_INVALIDO_SEPARADOR);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUValidade::TestarCenarioFalha_MES(){
	try{
		data->SetVal(VALOR_INVALIDO_MES);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUValidade::TestarCenarioFalha_ANO(){
	try{
		data->SetVal(VALOR_INVALIDO_ANO);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUValidade::Run(){
	SetUp();
	TestarCenarioSucesso();
    TestarCenarioFalha_QTD();
    TestarCenarioFalha_SEPARADOR();
    TestarCenarioFalha_MES();
    TestarCenarioFalha_ANO();
    TearDown();

    return estado;
}
