#ifndef DOMINIOS_H_
#define DOMINIOS_H_

#include <stdexcept>
#include <string>

using namespace std;

// Declaração das classes

/*! \class Agencia
		\brief Classe do tipo Agencia.

		Classe que armazena o número da agência bancária do usuário e contém os métodos de manipulção desse valor.
		A Agencia tem o formato de uma string com 5 digitos contendo apenas números.
*/
class Agencia {

private:
	string agencia; /*!< String que armazena o número da agência bancária. */

	const static int N_CARAC = 5; /*!< Constante que armazena o número de caracteres permitido. */

	const static int LIMITE_INF = 48; /*!< Constante que armaxena o valor ascii de '0', para definir o limite inferior de caracteres permitidos. */

	const static int LIMITE_SUP = 57; /*!< Constante que armaxena o valor ascii de '9', para definir o limite superior de caracteres permitidos. */

	// Método de validação
	/*! \fn void validar(string)
        \brief Valida uma string para verificar se esta está no formato adequado da classe.

        Verifica se a string tem 5 digitos e se todos eles são números.

        \param string Variável com a string a ser validada.
	*/
	void Validar(string) throw (invalid_argument);

public:
	// Métodos de acesso
	/*! \fn void setAgencia(string)
        \brief Verifica se a string é valida e seta a string passada para a variavel 'agencia'.

        \param string Variável com a string a ser validada e setada.
	*/
	void SetAgencia(string) throw (invalid_argument);

	/*! \fn void getAgencia()
        \brief Retorna a agencia armazenada.

        \return Retorna a variavel armazenda.
	*/
	string GetAgencia() const {
		return agencia;
	}
};


/*! \class Banco
		\brief Classe do tipo Banco.

		Classe que armazena o número do banco do usuário e contém os métodos de manipulção desse valor.
		O Banco tem o formato de uma string com 3 digitos contendo apenas números.
*/
class Banco {

private:
	string banco; /*!< String que armazena o número do banco. */

	const static int N_CARAC = 3; /*!< Constante que armazena o número de caracteres permitido. */

	const static int LIMITE_INF = 48; /*!< Constante que armaxena o valor ascii de '0', para definir o limite inferior de caracteres permitidos. */

	const static int LIMITE_SUP = 57; /*!< Constante que armaxena o valor ascii de '9', para definir o limite superior de caracteres permitidos. */

	// Método de validação
	/*! \fn void validar(string)
        \brief Valida uma string para verificar se esta está no formato adequado da classe.

        Verifica se a string tem 3 digitos e se todos eles são números.

        \param string Variável com a string a ser validada.
	*/
	void Validar(string) throw (invalid_argument);

public:
	// Métodos de acesso
	/*! \fn void setBanco(string)
        \brief Verifica se a string é valida e seta a string passada para a variavel 'banco'.

        \param string Variável com a string a ser validada e setada.
	*/
	void SetBanco(string) throw (invalid_argument);

	/*! \fn void getBanco()
        \brief Retorna o banco armazenado.

        \return Retorna a variavel armazenda.
	*/
	string GetBanco() const {
		return banco;
	}
};

/*! \class Conta
		\brief Classe do tipo Conta.

		Classe que armazena o número da conta corrente do usuário e contém os métodos de manipulção desse valor.
		A Conta tem o formato de uma string com 6 digitos contendo apenas números.
*/
class Conta {

private:
	string conta; /*!< String que armazena o número da conta corrente. */

	const static int N_CARAC = 6; /*!< Constante que armazena o número de caracteres permitido. */

	const static int LIMITE_INF = 48; /*!< Constante que armaxena o valor ascii de '0', para definir o limite inferior de caracteres permitidos. */

	const static int LIMITE_SUP = 57; /*!< Constante que armaxena o valor ascii de '9', para definir o limite superior de caracteres permitidos. */

	// Método de validação
	/*! \fn void validar(string)
        \brief Valida uma string para verificar se esta está no formato adequado da classe.

        Verifica se a string tem 6 digitos e se todos eles são números.

        \param string Variável com a string a ser validada.
	*/
	void Validar(string) throw (invalid_argument);

public:
	// Métodos de acesso
	/*! \fn void setConta(string)
        \brief Verifica se a string é valida e seta a string passada para a variavel 'conta'.

        \param string Variável com a string a ser validada e setada.
	*/
	void SetConta(string) throw (invalid_argument);

	/*! \fn void getConta()
        \brief Retorna a conta armazenada.

        \return Retorna a variavel armazenda.
	*/
	string GetConta() const {
		return conta;
	}
};

/*! \class Cartao
		\brief Classe do tipo Cartao.

		Classe que armazena o número do cartão de crédito do usuário e contém os métodos de manipulção desse valor.
		O Cartao tem o formato de uma string com 16 digitos, contendo apenas números, e que respeita o algoritmo de Luhn.
*/
class Cartao {

private:
	string cartao; /*!< String que armazena o número do cartão de crédito. */

	const static int N_CARAC = 16; /*!< Constante que armazena o número de caracteres permitido. */

	const static int LIMITE_INF = 48; /*!< Constante que armaxena o valor ascii de '0', para definir o limite inferior de caracteres permitidos. */

	const static int LIMITE_SUP = 57; /*!< Constante que armaxena o valor ascii de '9', para definir o limite superior de caracteres permitidos. */

	// Método de validação
	/*! \fn void validar(string)
        \brief Valida uma string para verificar se esta está no formato adequado da classe.

        Verifica se a string tem 16 digitos, se todos eles são números e se é um número válido de cartão.

        \param string Variável com a string a ser validada.
	*/
	void Validar(string) throw (invalid_argument);

public:
	// Métodos de acesso
	/*! \fn void setCartao(string)
        \brief Verifica se a string é valida e seta a string passada para a variavel 'cartao'.

        \param string Variável com a string a ser validada e setada.
	*/
	void SetCartao(string) throw (invalid_argument);

	/*! \fn void getCartao()
        \brief Retorna o cartao armazenado.

        \return Retorna a variavel armazenda.
	*/
	string GetCartao() const {
		return cartao;
	}
};

/*! \class Validade
		\brief Classe do tipo Validade.

		Classe que armazena a data de validade do cartão de crédito do usuário e contém os métodos de manipulção desse valor.
		A Validade tem o formato de uma string com 5 digitos, sendo o digito central uma '/	, os outros números e os dois primeiros um mês válido (formato MM/AA).
*/
class Validade {

private:
	string data; /*!< String que armazena a data de validade do cartão. */

	const static int N_CARAC = 5; /*!< Constante que armazena o número de caracteres permitido. */

	const static int LIMITE_INF = 48; /*!< Constante que armaxena o valor ascii de '0', para definir o limite inferior de caracteres numéricos permitidos. */

	const static int LIMITE_SUP = 57; /*!< Constante que armaxena o valor ascii de '9', para definir o limite superior de caracteres numériocs permitidos. */

	// Método de validação
	/*! \fn void validar(string)
        \brief Valida uma string para verificar se esta está no formato adequado da classe.

        Verifica se a string tem 5 digitos, se o digito do meio é o separador '/', se o restante é número e se os dois primeiros são um mês válido.

        \param string Variável com a string a ser validada.
	*/
	void Validar(string) throw (invalid_argument);

public:
	// Métodos de acesso
	/*! \fn void setVal(string)
        \brief Verifica se a string é valida e seta a string passada para a variavel 'data'.

        \param string Variável com a string a ser validada e setada.
	*/
	void SetVal(string) throw (invalid_argument);

	/*! \fn void getVal()
        \brief Retorna a data de validade armazenada.

        \return Retorna a variavel armazenda.
	*/
	string GetVal() const {
		return data;
	}
};

#endif
