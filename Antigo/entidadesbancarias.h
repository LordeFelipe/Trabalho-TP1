#ifndef ENTIDADES_BANCARIAS_H
#define ENTIDADES_BANCARIAS_H

#include "dominiosbanco.h"

// Definição das Classes

/*! \class Cartao
		\brief Classe que define a entitade do tipo Cartao.

		Classe que armazena as caracteristicas necessárias para definir a entidade catão de crédito.
		Contém um objeto para o tipo NumeroCartao e outro para a Validade.
*/
class Cartao{

	private:

		// Elementos que compoem a classe?
		NumeroCartao numero; /*!< Objeto da classe NumeroCartao. Armazena o número do cartão de crédito. */
		Validade validade; /*!< Objeto da classe Validade. Armazena a data de validade do cartão de crédito. */

	public:

		// Metodos de acesso ao numero do cartão:

		/*! \fn void SetNumero(const NumeroCartao &numero)
        	\brief Seta o objeto passado como o número do cartão de crédito.

        	\param numero Objeto do tipo NumeroCartao a ser setado.
		*/
		void SetNumero(const NumeroCartao &numero){
			this->numero = numero;
		}

		/*! \fn NumeroCartao GetNumero()
        	\brief Retorna o objeto do número do cartão armazenado.

        	\return Objeto do tipo NumeroCartao.
		*/
		NumeroCartao GetNumero() const {
			return numero;
		}

		// Metodos de acesso a data de validade do cartao:

		/*! \fn void SetValidade(const Validade &validade)
        	\brief Seta o objeto passado como a validade do cartão de crédito.

        	\param validade Objeto do tipo Validade a ser setado.
		*/
		void SetValidade(const Validade &validade){
			this->validade = validade;
		}

		/*! \fn Validade GetValidade()
        	\brief Retorna o objeto da data de validade do cartão armazenado.

        	\return Objeto do tipo Validade.
		*/
		Validade GetValidade() const {
			return validade;
		}
};

/*! \class ContaCorrente
		\brief Classe que define a entitade do tipo ContaCorrente.

		Classe que armazena as caracteristicas necessárias para defini a entidade da cnota corrente.
		Contém um objeto para o tipo NumeroConta, outro para a Agencia e outro para o Banco.
*/
class ContaCorrente{

	private:

		// Elementos que compoem a classe?
		NumeroConta numero; /*!< Objeto da classe NumeroConta. Armazena o número da conta corrente. */
		Agencia agencia; /*!< Objeto da classe Agencia. Armazena o número da agencia bancaria. */
		Banco banco; /*!< Objeto da classe Banco. Armazena o número do banco da conta. */

	public:

		// Metodos de acesso ao numero da conta:

		/*! \fn void SetNumero(const NumeroConta &numero)
        	\brief Seta o objeto passado como o número da conta corrente.

        	\param numero Objeto do tipo NumeroConta a ser setado.
		*/
		void SetNumero(const NumeroConta &numero){
			this->numero = numero;
		}

		/*! \fn NumeroConta GetNumero()
        	\brief Retorna o objeto do número da conta corrente.

        	\return Objeto do tipo NumeroConta.
		*/
		NumeroConta GetNumero() const {
			return numero;
		}

		// Metodos de acesso a agencia da conta:

		/*! \fn void SetAgencia(const Agencia &agencia)
        	\brief Seta o objeto passado como a agencia da conta corrente.

        	\param agencia Objeto do tipo Agencia a ser setado.
		*/
		void SetAgencia(const Agencia &agencia){
			this->agencia = agencia;
		}

		/*! \fn Agencia GetAgencia()
        	\brief Retorna o objeto da agencia da conta corrente armazenada.

        	\return Objeto do tipo Agencia.
		*/
		Agencia GetAgencia() const {
			return agencia;
		}

		// Metodos de acesso ao banco da conta:

		/*! \fn void SetBanco(const Banco &banco)
        	\brief Seta o objeto passado como o banco da conta corrente.

        	\param banco Objeto do tipo Banco a ser setado.
		*/
		void SetBanco(const Banco &banco){
			this->banco = banco;
		}

		/*! \fn Banco GetBanco()
        	\brief Retorna o objeto do banco da conta corrente armazenada.

        	\return Objeto do tipo Banco.
		*/
		Banco GetBanco() const {
			return banco;
		}
};

#endif