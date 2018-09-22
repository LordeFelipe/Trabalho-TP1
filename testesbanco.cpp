#include <iostream>
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

// Testes para a classe Validade:
void TUValidade::setUp(){
	data = new Validade();
	estado = SUCESSO;
}

void TUValidade::tearDown(){
	delete data;
}

void TUValidade::testarCenarioSucesso(){
	try{
		data->setVal(VALOR_VALIDO);
		if(data->getVal() != VALOR_VALIDO){
			estado = FALHA;
		}
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUValidade::testarCenarioFalha_QTD(){
	try{
		data->setVal(VALOR_INVALIDO_QTD);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUValidade::testarCenarioFalha_SEPARADOR(){
	try{
		data->setVal(VALOR_INVALIDO_SEPARADOR);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUValidade::testarCenarioFalha_MES(){
	try{
		data->setVal(VALOR_INVALIDO_MES);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUValidade::testarCenarioFalha_ANO(){
	try{
		data->setVal(VALOR_INVALIDO_ANO);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUValidade::run(){
	setUp();
	testarCenarioSucesso();
    testarCenarioFalha_QTD();
    testarCenarioFalha_SEPARADOR();
    testarCenarioFalha_MES();
    testarCenarioFalha_ANO();
    tearDown();

    return estado;
}

// Testes para a classe Nome:
void TUNome::setUp(){
	nome = new Nome();
	estado = SUCESSO;
}

void TUNome::tearDown(){
	delete nome;
}

void TUNome::testarCenarioSucesso(){
	try{
		nome->setNome(VALOR_VALIDO);
		if(nome->getNome() != VALOR_VALIDO){
			estado = FALHA;
		}
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUNome::testarCenarioFalha_TAM(){
	try{
		nome->setNome(VALOR_INVALIDO_TAM);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUNome::testarCenarioFalha_CARAC(){
	try{
		nome->setNome(VALOR_INVALIDO_CARAC);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUNome::testarCenarioFalha_PONTO(){
	try{
		nome->setNome(VALOR_INVALIDO_PONTO);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUNome::testarCenarioFalha_ESPACO(){
	try{
		nome->setNome(VALOR_INVALIDO_ESPACO);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUNome::run(){
	setUp();
	testarCenarioSucesso();
	testarCenarioFalha_TAM();
	testarCenarioFalha_CARAC();
	testarCenarioFalha_PONTO();
	testarCenarioFalha_ESPACO();
    tearDown();

    return estado;
}