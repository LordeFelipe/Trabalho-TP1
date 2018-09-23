#ifndef DOMINIOSHOTEL_H
#define DOMINIOSHOTEL_H

#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

// Declaração das classes

/*! \class CapacidadeDeAcomodacao
		\brief Classe do tipo CapacidadeDeAcomodacao.
		Classe que armazena a capacidade de acomodação de uma moradia e contém os métodos de manipulação desse valor.
		A capacidade tem o formato de inteiro que tem seus possíveis valores no intervalo [1,9].
*/

class CapacidadeDeAcomodacao
{
    private:

        int capacidade; /*!< Inteiro que armazena a capacidade da acomodação */

        const static int LIMITE_SUP = 9; /*!< Valor máximo da capacidade */
        const static int LIMITE_INF = 1; /*!< Valor mínimo da capacidade */

        // Método de validação
        /*! \fn void Validar(int)
            \brief Valida um inteiro para verificar se esta está no formato adequado da classe.
                Verifica se o inteiro tem seu valor entre os dois limites

            \param inteiro contendo o valor da capacidade de acomodaçao
        */
        void Validar(int) throw (invalid_argument);

    public:

        // Métodos de acesso

        /*! \fn void SetCapacidadeDeAcomodacao(int)
            \brief Verifica se o inteiro fornecido é válido e o seta no objeto

            \param inteiro contendo o valor da capacidade de acomodaçao
        */
        void SetCapacidadeDeAcomodacao(int) throw (invalid_argument);

        /*! \fn void GetCapacidadeDeAcomodacao(int)
            \brief Retorna o valor da capacidade armazenada no objeto

            \return inteiro contendo o valor da capacidade de acomodaçao
        */
        int GetCapacidadeDeAcomodacao() const{
            return capacidade;
        }
};

/*! \class Diaria
		\brief Classe do tipo Diaria.
		Classe que armazena o valor da diaria e contém os métodos de manipulação desse valor.
		A diaria tem o formato de inteiro que tem seus possíveis valores no intervalo [1,10000].
*/
class Diaria
{
    private:

        float diaria; /*!< Inteiro que armazena o valor da diária */

        const static float LIMITE_SUP = 10000; /*!< Valor máximo da diária */
        const static float LIMITE_INF = 1; /*!< Valor mínimo da diária */

        // Método de validação
        /*! \fn void Validar(float)
            \brief Valida um float para verificar se esta está no formato adequado da classe.
                Verifica se o float tem seu valor entre os dois limites.

            \param inteiro contendo o valor da diária.
        */
        void Validar(float) throw (invalid_argument);

    public:

        // Métodos de acesso

        /*! \fn void SetDiaria(int)
            \brief Verifica se o valor fornecido é válido e o seta no objeto

            \param float contendo o valor da capacidade de acomodaçao
        */
        void SetDiaria(float) throw (invalid_argument);

        /*! \fn void GetDiaria(int)
            \brief Retorna o valor da diária armazenada no objeto

            \return inteiro contendo o valor da diária
        */
        float GetDiaria() const{
            return diaria;
        }

};

/*! \class Data
		\brief Classe do tipo Data.
		Classe que armazena uma data e contém os métodos de manipulação desse valor.
		A  data tem o formato de uma string de tamanho 11 no formato dia/mes/ano onde
		o dia tem 2 caracteres, o mês 3 e o ano 4.
*/
class Data
{
    private:

        string data; /*!< String que armazena uma data */


        const static int STRING_TAMANHO = 11; /*!< Tamanho maximo da string da data */

        const static int ANO_LIMITE_SUP = 2099; /*!< Valor máximo para o ano */
        const static int ANO_LIMITE_INF = 2000; /*!< Valor mínimo para o ano */

        const static int DIA_LIMITE_SUP1 = 31;  /*!< Quantidade máxima de dias para um grupo de meses */
        const static int DIA_LIMITE_SUP2 = 30;  /*!< Quantidade máxima de dias para outro grupo de meses */
        const static int DIA_LIMITE_SUP3 = 29;  /*!< Quantidade máxima de dias de fevereiro em anos bissextos */
        const static int DIA_LIMITE_SUP4 = 28;  /*!< Quantidade máxima de dias de fevereiro em anos não bissextos */
        const static int DIA_LIMITE_INF = 1;    /*!< Quantidade mínima de dias para um grupo de meses */

        // Método de validação
        /*! \fn void Validar(string)
            \brief Valida uma string para verificar se esta está no formato adequado da classe.
                Verifica se a string tem tamanho 11 e também os dias, meses e anos estão nos formatos
                corretos(2 numeros para o dia, 3 caracteres para o mês e 4 para o ano)

            \param string contendo a data
        */
        void Validar(string) throw (invalid_argument);

    public:

        // Métodos de acesso

        /*! \fn void SetData(string)
            \brief Verifica se a string fornecida é válida e o seta no objeto

            \param string contendo a data
        */
        void SetData(string) throw (invalid_argument);

        /*! \fn void GetCData(int)
            \brief Retorna a data armazenada no objeto

            \return string contendo a data
        */
        string GetData() const{
            return data;
        }
};

/*! \class Estado
		\brief Classe do tipo Estado
		Classe que armazena um estado e contém os métodos de manipulação desse valor.
		O estado tem o formato de string de 2 caracteres cujos possíveis valores são as siglas dos estados brasileiros
*/
class Estado
{
    private:

        string estado; /*!< String que armazena o estado */

        // Método de validação
        /*! \fn void Validar(string)
            \brief Valida uma string para verificar se esta está no formato adequado da classe.
                Verifica se a string é equivalente à sigla de um dos estados brasileiros

            \param string contendo a sigla de um estado
        */
        void Validar(string) throw (invalid_argument);

    public:

        // Métodos de acesso

        /*! \fn void SetEstado(string)
            \brief Verifica se a string fornecida é válida e a seta no objeto

            \param string contendo a sigla de um estado
        */
        void SetEstado(string) throw (invalid_argument);

        /*! \fn void GetEstado(int)
            \brief Retorna a sigla do estado

            \return string contendo o estado
        */
        string GetEstado() const{
            return estado;
        }

};

/*! \class TipoDeAcomodacao
		\brief Classe do tipo TipoDeAcomodacao
		Classe que armazena o tipo de acomodação e contém os métodos de manipulação desse valor.
		A capacidade tem o formato de string e tem como seus possíveis valores as seguintes
		strings: "Flat", "Casa" ou "Apartamento".
*/
class TipoDeAcomodacao
{
    private:

        string acomodacao; /*!< String que armazena o tipo de acomodação */

        // Método de validação
        /*! \fn void Validar(int)
            \brief Valida uma string para verificar se esta está no formato adequado da classe.
                Verifica se a string é uma das 3 strings aceitáveis

            \param string contendo o tipo de acomodaçao
        */
        void Validar(string) throw (invalid_argument);

    public:

        // Métodos de acesso

        /*! \fn void SetTipoDeAcomodacao(string)
            \brief Verifica se a string fornecida é válida e a seta no objeto

            \param string contendo o valor do tipo de acomodaçao
        */
        void SetTipoDeAcomodacao(string) throw (invalid_argument);

        /*! \fn void GetTipoDeAcomodacao(int)
            \brief Retorna o tipo de acomodação armazenado no objeto

            \return string contendo o tipo de acomodação
        */
        string GetTipoDeAcomodacao() const{
            return acomodacao;
        }
};

/*! \class Identificador
		\brief Classe do tipo Identificador.
		Classe que armazena o identificador e contém os métodos de manipulação desse valor.
		A identificador tem o formato de string de 5 caracteres e contém apenas letras minúsculas.
*/
class Identificador
{
    private:

        string identificador; /*!< string que armazena o identificador */

        const static int N_CARAC = 5; /*!< Inteiro que armazena o tamanho máximo da string do identificador */
        const static char LIMITE_SUP = 'z'; /*!< Caractere limite superior para string de acordo com a tabela ASCII */
        const static char LIMITE_INF = 'a'; /*!< Caractere limite inferior para string de acordo com a tabela ASCII */

        // Método de validação
        /*! \fn void Validar(string)
            \brief Valida uma string para verificar se esta está no formato adequado da classe.
                Verifica se a string tem tamanho 5 e se é composta apenas por letras minúsculas

            \param string contendo o identificador
        */
        void Validar(string) throw (invalid_argument);

    public:

        // Métodos de acesso

        /*! \fn void SetIdentificador(string)
            \brief Verifica se a string fornecida é válida e a seta no objeto

            \param String contendo o identificador
        */
        void SetIdentificador(string) throw (invalid_argument);

        /*! \fn void GetIdentificador(string)
            \brief Retorna o valor do identidicador

            \return string contendo o identificador
        */
        string GetIdentificador() const{
            return identificador;
        }
};
#endif // DOMINIOSHOTEL_H
