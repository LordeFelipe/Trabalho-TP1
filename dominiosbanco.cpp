#include <iostream>
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
	// Lança exceção se a string tiver menos ou mais que 3 dígitos
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

void Banco::setBanco(string banco) throw (invalid_argument){
	validar(banco);
	this->banco = banco;
}

// Conta:
void Conta::validar(string conta) throw (invalid_argument){
	// Lança exceção se a string tiver menos ou mais que 6 dígitos
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
	// Lança exceção se a string tiver menos ou mais que 16 dígitos
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

// Validade:
void Validade::validar(string data) throw (invalid_argument){
	// Lança exceção se a string tiver menos ou mais que 5 dígitos
	if(data.length() != N_CARAC){
		throw invalid_argument("Número de caracteres invalido.");
		return;
	}

	// Lança exceção se o caractere do meio não for '/'
	if(data.at(2) != '/'){
		throw invalid_argument("Falta de caractere '/' para separar mes e ano");
		return;
	}

	// Lança exceção se o ano não conter apenas números
	for(int i = 3; i < N_CARAC; i++){
		if(data.at(i) < LIMITE_INF || data.at(i) > LIMITE_SUP){
			throw invalid_argument("Contem carcteres invalidos no ano.");
			return;
		}
	}

	// Lança exceção para meses inválidos
	if(data.at(0) == '0'){
		if(data.at(1) < '1' || data.at(1) > '9'){
			throw invalid_argument("Mes Invalido.");
			return;
		}
	}
	else if(data.at(0) == '1'){
		if(data.at(1) < '0' || data.at(1) > '2'){
			throw invalid_argument("Mes Invalido.");
			return;
		}
	}
	else{
		throw invalid_argument("Mes Invalido.");
		return;
	}
}

void Validade::setVal(string data) throw (invalid_argument){
	validar(data);
	this->data = data;
}

// Nome:
void Nome::validar(string nome) throw (invalid_argument){
	// Lança exceção se a string tiver mais que 15 dígitos
	if(nome.length() > N_CARAC){
		throw invalid_argument("Número de caracteres invalido.");
		return;
	}

	// Variavel para verificar se caractere anterior é letra
	int AnteriorEhLetra = FALSO; 

	// Variável para verificar se há letras no nome
	int HaLetras = FALSO;

	// Loop para verificar a string nome
	for(int i = 0; i < nome.length(); i++){
		// Verificar se é letra
		if((nome.at(i) >= LIMITE_INF_MAI && nome.at(i) <= LIMITE_SUP_MAI) ||
			(nome.at(i) >= LIMITE_INF_MIN && nome.at(i) <= LIMITE_SUP_MIN)){
			
			HaLetras = VERDADEIRO;
			AnteriorEhLetra = VERDADEIRO;
		}

		// Verificar se é ponto
		else if(nome.at(i) == PONTO){
			// Lançar excecao se não for precedido por letra
			if(AnteriorEhLetra == FALSO){
				throw invalid_argument("Ponto nao precedido por letra.");
				return;
			}
			else
				AnteriorEhLetra = FALSO;
		}

		// Verificar se ha espaços seguidos
		else if(nome.at(i) == ESPACO){
			// Lançar exceçao se houver espacos seguidos
			if(i != 0){
				if(nome.at(i-1) == ESPACO){
					throw invalid_argument("Espacos seguidos.");
					return;
				}
			}

			AnteriorEhLetra = FALSO;
		}

		// Lançar exceçao se for um caractere inválido
		else{
			throw invalid_argument("Caractere invalido.");
			return;
		}
	}

	// Lançar exceção se não tiver letras no nome
	if(HaLetras == FALSO){
		throw invalid_argument("Nao ha letras.");
		return;
	}
}

void Nome::setNome(string nome) throw (invalid_argument){
	validar(nome);
	this->nome = nome;
}