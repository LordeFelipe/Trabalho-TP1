#include "testesbanco.h"

// Definição dos métodos:

// Testes para a classe Agência:
void TUAgencia::setUp(){
	agencia = new Agencia();
	estado = SUCESSO;
}

void TUAgencia::tearDown(){
	delete agencia;
}

void TUAgencia::testarCenarioSucesso(){
	try{
		agencia->setAgencia(VALOR_VALIDO);
		if(agencia->getAgencia() != VALOR_VALIDO)
			estado = FALHA;
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUAgencia::testarCenarioFalha_QTD(){
	try{
		agencia->setAgencia(VALOR_INVALIDO_QTD);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUAgencia::testarCenarioFalha_CARAC(){
	try{
		agencia->setAgencia(VALOR_INVALIDO_CARAC);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUAgencia::run(){
	setUp();
	testarCenarioSucesso();
    testarCenarioFalha_QTD();
    testarCenarioFalha_CARAC();
    tearDown();

    return estado;
}

// Testes para a classe Banco:
void TUBanco::setUp(){
	banco = new Banco();
	estado = SUCESSO;
}

void TUBanco::tearDown(){
	delete banco;
}

void TUBanco::testarCenarioSucesso(){
	try{
		banco->setBanco(VALOR_VALIDO);
		if(banco->getBanco() != VALOR_VALIDO)
			estado = FALHA;
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUBanco::testarCenarioFalha_QTD(){
	try{
		banco->setBanco(VALOR_INVALIDO_QTD);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUBanco::testarCenarioFalha_CARAC(){
	try{
		banco->setBanco(VALOR_INVALIDO_CARAC);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUBanco::run(){
	setUp();
	testarCenarioSucesso();
    testarCenarioFalha_QTD();
    testarCenarioFalha_CARAC();
    tearDown();

    return estado;
}

// Testes para a classe Conta:
void TUConta::setUp(){
	conta = new Conta();
	estado = SUCESSO;
}

void TUConta::tearDown(){
	delete conta;
}

void TUConta::testarCenarioSucesso(){
	try{
		conta->setConta(VALOR_VALIDO);
		if(conta->getConta() != VALOR_VALIDO)
			estado = FALHA;
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUConta::testarCenarioFalha_QTD(){
	try{
		conta->setConta(VALOR_INVALIDO_QTD);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUConta::testarCenarioFalha_CARAC(){
	try{
		conta->setConta(VALOR_INVALIDO_CARAC);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUConta::run(){
	setUp();
	testarCenarioSucesso();
    testarCenarioFalha_QTD();
    testarCenarioFalha_CARAC();
    tearDown();

    return estado;
}

// Testes para a classe Cartao:
void TUCartao::setUp(){
	cartao = new Cartao();
	estado = SUCESSO;
}

void TUCartao::tearDown(){
	delete cartao;
}

void TUCartao::testarCenarioSucesso(){
	try{
		cartao->setCartao(VALOR_VALIDO);
		if(cartao->getCartao() != VALOR_VALIDO)
			estado = FALHA;
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUCartao::testarCenarioFalha_QTD(){
	try{
		cartao->setCartao(VALOR_INVALIDO_QTD);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUCartao::testarCenarioFalha_CARAC(){
	try{
		cartao->setCartao(VALOR_INVALIDO_CARAC);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUCartao::testarCenarioFalha_NUM(){
	try{
		cartao->setCartao(VALOR_INVALIDO_NUM);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUCartao::run(){
	setUp();
	testarCenarioSucesso();
    testarCenarioFalha_QTD();
    testarCenarioFalha_CARAC();
    testarCenarioFalha_NUM();
    tearDown();

    return estado;
}
