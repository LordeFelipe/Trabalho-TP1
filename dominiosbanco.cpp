#include "dominiosbanco.h"

// Definições de métodos:

// Agencia:
void Agencia::validar(string agencia) throw (invalid_argument){
	// Lança exceção se a string tiver menos ou mais que 5 dígitos
	if(agencia.length() != N_CARAC){
		throw invalid_argument("Número de caracteres invalido.");
		return;
	}

	// Lança exceção se a string não conter apenas números
	for(int i = 0; i < N_CARAC; i++){
		if(agencia.at(i) < LIMITE_INF || agencia.at(i) > LIMITE_SUP){
			throw invalid_argument("Contem carcteres invalidos.");
			return;
		}
	}
}

void Agencia::setAgencia(string agencia) throw (invalid_argument){
	validar(agencia);
	this->agencia = agencia;
}

// Banco:
void Banco::validar(string banco) throw (invalid_argument){
	// Lança exceção se a string tiver menos ou mais que 5 dígitos
	if(banco.length() != N_CARAC){
		throw invalid_argument("Número de caracteres invalido.");
		return;
	}

	// Lança exceção se a string não conter apenas números
	for(int i = 0; i < N_CARAC; i++){
		if(banco.at(i) < LIMITE_INF || banco.at(i) > LIMITE_SUP){
			throw invalid_argument("Contem carcteres invalidos.");
			return;
		}
	}
}

void Banco::setAgencia(string banco) throw (invalid_argument){
	validar(banco);
	this->banco = banco;
}

// Conta:
void Conta::validar(string conta) throw (invalid_argument){
	// Lança exceção se a string tiver menos ou mais que 5 dígitos
	if(conta.length() != N_CARAC){
		throw invalid_argument("Número de caracteres invalido.");
		return;
	}

	// Lança exceção se a string não conter apenas números
	for(int i = 0; i < N_CARAC; i++){
		if(conta.at(i) < LIMITE_INF || conta.at(i) > LIMITE_SUP){
			throw invalid_argument("Contem carcteres invalidos.");
			return;
		}
	}
}

void Conta::setConta(string conta) throw (invalid_argument){
	validar(conta);
	this->conta = conta;
}

// Cartao:
void Cartao::validar(string cartao) throw (invalid_argument){
	// Lança exceção se a string tiver menos ou mais que 5 dígitos
	if(cartao.length() != N_CARAC){
		throw invalid_argument("Número de caracteres invalido.");
		return;
	}

	// Lança exceção se a string não conter apenas números
	for(int i = 0; i < N_CARAC; i++){
		if(cartao.at(i) < LIMITE_INF || cartao.at(i) > LIMITE_SUP){
			throw invalid_argument("Contem carcteres invalidos.");
			return;
		}
	}

	// Lança exceção caso o número do cartão seja inválido
	int nDigitos = cartao.length();
 
    int nSoma = 0, ehSegundo = false;
    for (int i = nDigitos - 1; i >= 0; i--) {
 
        int d = cartao[i] - 'a';
 
        if (ehSegundo == true)
            d = d * 2;
 
        // Nos adicionamos dois digitos para lidar
        // com casos que tem dois digitos depois de dobrar
        nSoma += d / 10;
        nSoma += d % 10;
 
        ehSegundo = !ehSegundo;
    }
    if(nSoma % 10 != 0){
    	throw invalid_argument("Numero de Cartao invalido.");
    }
}

void Cartao::setCartao(string cartao) throw (invalid_argument){
	validar(cartao);
	this->cartao = cartao;
}
