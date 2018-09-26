#include "testesusuario.h"

//Métodos que testam o Identificador

void TUIdentificador::SetUp(){

    //Criação do objeto identificador e definição do estado inicial do teste para sucesso
    identificador = new Identificador();
    estado = SUCESSO;
}

void TUIdentificador::TearDown(){
    delete identificador;
}

void TUIdentificador::TestarCenarioSucesso(){
    try{
        //O valor do identificador é setado para um valor válido para passar no teste
        identificador->SetIdentificador(VALOR_VALIDO);
        if (identificador->GetIdentificador() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUIdentificador::TestarCenarioFalha(){
    try{
        //O valor do identificador é setado para um valor inválido para falhar no teste
        identificador->SetIdentificador(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUIdentificador::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

// Testes para a classe Nome:
void TUNome::SetUp(){
	nome = new Nome();
	estado = SUCESSO;
}

void TUNome::TearDown(){
	delete nome;
}

void TUNome::TestarCenarioSucesso(){
	try{
		nome->SetNome(VALOR_VALIDO);
		if(nome->GetNome() != VALOR_VALIDO){
			estado = FALHA;
		}
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUNome::TestarCenarioFalha_TAM(){
	try{
		nome->SetNome(VALOR_INVALIDO_TAM);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUNome::TestarCenarioFalha_CARAC(){
	try{
		nome->SetNome(VALOR_INVALIDO_CARAC);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUNome::TestarCenarioFalha_PONTO(){
	try{
		nome->SetNome(VALOR_INVALIDO_PONTO);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUNome::TestarCenarioFalha_ESPACO(){
	try{
		nome->SetNome(VALOR_INVALIDO_ESPACO);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUNome::Run(){
	SetUp();
	TestarCenarioSucesso();
	TestarCenarioFalha_TAM();
	TestarCenarioFalha_CARAC();
	TestarCenarioFalha_PONTO();
	TestarCenarioFalha_ESPACO();
    TearDown();

    return estado;
}

// Testes para a classe Senha:
void TUSenha::SetUp(){
	senha = new Senha();
	estado = SUCESSO;
}

void TUSenha::TearDown(){
	delete senha;
}

void TUSenha::TestarCenarioSucesso(){
	try{
		senha->SetSenha(VALOR_VALIDO);
		if(senha->GetSenha() != VALOR_VALIDO){
			estado = FALHA;
		}
	}
	catch(invalid_argument excecao){
		estado = FALHA;
	}
}

void TUSenha::TestarCenarioFalha_TAM(){
	try{
		senha->SetSenha(VALOR_INVALIDO_TAM);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUSenha::TestarCenarioFalha_CARAC(){
	try{
		senha->SetSenha(VALOR_INVALIDO_CARAC);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUSenha::TestarCenarioFalha_REPETIDO(){
	try{
		senha->SetSenha(VALOR_INVALIDO_REPETIDO);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

void TUSenha::TestarCenarioFalha_FALTA(){
	try{
		senha->SetSenha(VALOR_INVALIDO_FALTA);
		estado = FALHA;
	}
	catch(invalid_argument excecao){
		return;
	}
}

int TUSenha::Run(){
	SetUp();
	TestarCenarioSucesso();
	TestarCenarioFalha_TAM();
	TestarCenarioFalha_CARAC();
	TestarCenarioFalha_REPETIDO();
	TestarCenarioFalha_FALTA();
    TearDown();

    return estado;
}
