#include "dominios_usuario.h"

// Implementação dos Metodos das Classes Relacionadas ao Hotel:

//Métodos do objeto Identificador
void Identificador::Validar(string identificador) throw (invalid_argument){

    // Lança exceção se o número de caracteres for diferente do esperado
    if(identificador.length() != N_CARAC){
        throw invalid_argument("Argumento invalido.");
    }

    // Lança exceção se os caracteres não forem todos minúsculos
    for(int i = 0; i < identificador.length(); i++){
        if(identificador[i] > LIMITE_SUP || identificador[i] < LIMITE_INF){
            throw invalid_argument("Argumento invalido.");
        }
    }
}

void Identificador::SetIdentificador(string identificador) throw (invalid_argument){

    Validar(identificador);
    this->identificador = identificador;
}

// Métodos do Objeto Nome:
void Nome::Validar(string nome) throw (invalid_argument){
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
	for(unsigned int i = 0; i < nome.length(); i++){
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

void Nome::SetNome(string nome) throw (invalid_argument){
	Validar(nome);
	this->nome = nome;
}

// Métodos do Objeto Senha:
void Senha::Validar(string senha) throw (invalid_argument){
	// Lança exceção se a string tiver mais ou menos que 8 dígitos
	if(senha.length() != N_CARAC){
		throw invalid_argument("Número de caracteres invalido.");
		return;
	}

	// Variável para verificar se há letras maiusculas na senha
	int HaMaiusculas = FALSO;

	// Variável para verificar se há letras minusculas na senha
	int HaMinusculas = FALSO;

	// Variável para verificar se há numeros na senha
	int HaNumeros = FALSO;

	// Variável para verificar se há numeros na senha
	int HaSimbolos = FALSO;

	// Loop para verificar a string senha
	for(unsigned int i = 0; i < senha.length(); i++){
		// Verificar se é letra maiuscula
		if(senha.at(i) >= LIMITE_INF_MAI && senha.at(i) <= LIMITE_SUP_MAI){
			HaMaiusculas = VERDADEIRO;
		}

		// Verificar se é letra minuscula
		else if(senha.at(i) >= LIMITE_INF_MIN && senha.at(i) <= LIMITE_SUP_MIN){
			HaMinusculas = VERDADEIRO;
		}

		// Verificar se é numero
		else if(senha.at(i) >= LIMITE_INF_NUM && senha.at(i) <= LIMITE_SUP_NUM){
			HaNumeros = VERDADEIRO;
		}

		// Verificar se é digito
		else if(senha.at(i) == EXCLAMACAO || senha.at(i) == CERQUILHA || senha.at(i) == CIFRAO
			|| senha.at(i) == PORCENTAGEM || senha.at(i) == EITZA){

			HaSimbolos = VERDADEIRO;
		}

		// Lancar escecao caso seja um caractere invalido
		else{
			throw invalid_argument("Caractere invalido.");
			return;
		}

		// Verificar se há algum caractere repetido
		for(unsigned int j = 0; j < i; j++){
			if(senha.at(i) == senha.at(j)){
				throw invalid_argument("Caractere repetido.");
				return;
			}
		}
	}

	// Lançar exceção se não tiver ao menos uma letra maiuscula, minuscula, numero e digito na senha
	if(HaMaiusculas == FALSO || HaMinusculas == FALSO || HaNumeros == FALSO || HaSimbolos == FALSO){
		throw invalid_argument("A senha deve conter uma letra minuscula, maiuscula, um numero e um digito.");
		return;
	}
}

void Senha::SetSenha(string senha) throw (invalid_argument){
	Validar(senha);
	this->senha = senha;
}

// Métodos do Objeto Agencia:
void Agencia::Validar(string agencia) throw (invalid_argument){
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

void Agencia::SetAgencia(string agencia) throw (invalid_argument){
	Validar(agencia);
	this->agencia = agencia;
}

// Métodos do Objeto Banco:
void Banco::Validar(string banco) throw (invalid_argument){
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

void Banco::SetBanco(string banco) throw (invalid_argument){
	Validar(banco);
	this->banco = banco;
}

// Métodos do Objeto NumeroConta:
void NumeroConta::Validar(string conta) throw (invalid_argument){
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

void NumeroConta::SetConta(string conta) throw (invalid_argument){
	Validar(conta);
	this->numero = conta;
}

// Métodos do Objeto NumeroCartao:
void NumeroCartao::Validar(string cartao) throw (invalid_argument){
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

void NumeroCartao::SetNumero(string cartao) throw (invalid_argument){
	Validar(cartao);
	this->numero = cartao;
}

// Métodos do Objeto Validade:
void Validade::Validar(string data) throw (invalid_argument){
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

void Validade::SetVal(string data) throw (invalid_argument){
	Validar(data);
	this->data = data;
}