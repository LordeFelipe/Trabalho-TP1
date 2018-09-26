#ifndef DOMINIOSUSUARIO_H
#define DOMINIOSUSUARIO_H

#include <stdexcept>
#include <string>

using namespace std;

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

/*! \class Nome
		\brief Classe do tipo Nome.

		Classe que armazena uma string com o nome do usuário e contém os métodos de manipulção desse valor.
		O nome tem o formato de uma string com no máximo 15 digitos, contendo ao menos uma letra, sem espaços seguidos e com todos os pontos sucedendo letras.
*/
class Nome {

private:
	string nome; /*!< String que armazena o nome do usuário. */

	const static int N_CARAC = 15; /*!< Constante que armazena o número máximo de caracteres permitido. */

	const static int LIMITE_INF_MAI = 'A'; /*!< Constante que armaxena o valor ascii de 'A', para definir o limite inferior de letras maiusculas permitidas. */

	const static int LIMITE_SUP_MAI = 'Z'; /*!< Constante que armaxena o valor ascii de 'Z', para definir o limite superior de letras maiusculas permitidas. */

	const static int LIMITE_INF_MIN = 'a'; /*!< Constante que armaxena o valor ascii de 'a', para definir o limite inferior de letras minusculas permitidas. */

	const static int LIMITE_SUP_MIN = 'z'; /*!< Constante que armaxena o valor ascii de 'z', para definir o limite superior de letras minusculas permitidas. */

	const static int PONTO = '.'; /*!< Constante que armazena o valor ASCII do caractere ponto. */

	const static int ESPACO = ' '; /*!< Constante que armazena o valor ASCII do caractere espaco. */

	const static int VERDADEIRO = 0; /*!< Constante que armazena o valor 0 representando a verdade de uma varivael. */

	const static int FALSO = 1; /*!< Constante que armazena o valor 1 representando a falsidade de uma varivael. */

	// Método de validação
	/*! \fn void validar(string)
        \brief Valida uma string para verificar se esta está no formato adequado da classe.

        Verifica se a string tem 15 digitos, se tem ao menos uma letra, se não há espaços seguidos, se todos os pontos sucedem letras
        e se não há caracteres inválidos.

        \param string Variável com a string a ser validada.
	*/
	void Validar(string) throw (invalid_argument);

public:
	// Métodos de acesso
	/*! \fn void setNome(string)
        \brief Verifica se a string é valida e seta a string passada para a variavel 'nome'.

        \param string Variável com a string a ser validada e setada.
	*/
	void SetNome(string) throw (invalid_argument);

	/*! \fn void getNome()
        \brief Retorna o nome armazenado.

        \return Retorna a variavel armazenda.
	*/
	string GetNome() const {
		return nome;
	}
};


/*! \class Senha
		\brief Classe do tipo Senha.

		Classe que armazena uma string com a senha do usuário e contém os métodos de manipulção desse valor.
		A senha tem o formato de uma string com 8 digitos, contendo ao menos uma letra maiuscula, minuscula, um número e um digito(! # $ % &) e sem caracteres repetidos.
*/
class Senha {

private:
	string senha; /*!< String que armazena o nome do usuário. */

	const static int N_CARAC = 8; /*!< Constante que armazena o número de caracteres permitido. */

	const static int LIMITE_INF_MAI = 'A'; /*!< Constante que armaxena o valor ascii de 'A', para definir o limite inferior de letras maiusculas permitidas. */

	const static int LIMITE_SUP_MAI = 'Z'; /*!< Constante que armaxena o valor ascii de 'Z', para definir o limite superior de letras maiusculas permitidas. */

	const static int LIMITE_INF_MIN = 'a'; /*!< Constante que armaxena o valor ascii de 'a', para definir o limite inferior de letras minusculas permitidas. */

	const static int LIMITE_SUP_MIN = 'z'; /*!< Constante que armaxena o valor ascii de 'z', para definir o limite superior de letras minusculas permitidas. */

	const static int LIMITE_INF_NUM = '0'; /*!< Constante que armaxena o valor ascii de '0', para definir o limite inferior de caracteres numéricos permitidos. */

	const static int LIMITE_SUP_NUM = '9'; /*!< Constante que armaxena o valor ascii de '9', para definir o limite superior de caracteres numériocs permitidos. */

	const static int EXCLAMACAO = '!'; /*!< Constante que armazena o valor ASCII do caractere de exclamação. */

	const static int CERQUILHA = '#'; /*!< Constante que armazena o valor ASCII do caractere cerquilha. */

	const static int CIFRAO = '$'; /*!< Constante que armazena o valor ASCII do caractere cifrao. */

	const static int PORCENTAGEM = '%'; /*!< Constante que armazena o valor ASCII do caractere de porcentagem. */

	const static int EITZA = '&'; /*!< Constante que armazena o valor ASCII do caractere eitza. */

	const static int VERDADEIRO = 0; /*!< Constante que armazena o valor 0 representando a verdade de uma varivael. */

	const static int FALSO = 1; /*!< Constante que armazena o valor 1 representando a falsidade de uma varivael. */

	// Método de validação
	/*! \fn void validar(string)
        \brief Valida uma string para verificar se esta está no formato adequado da classe.

        Verifica se a string tem 8 digitos, se tem ao menos uma letra maiuscula, minuscula, um número e um digito(! # $ % &),
        se não há caracteres inválidos e se não há caracteres repetidos.

        \param string Variável com a string a ser validada.
	*/
	void Validar(string) throw (invalid_argument);

public:
	// Métodos de acesso
	/*! \fn void setSenha(string)
        \brief Verifica se a string é valida e seta a string passada para a variavel 'senha'.

        \param string Variável com a string a ser validada e setada.
	*/
	void SetSenha(string) throw (invalid_argument);

	/*! \fn void getSenha()
        \brief Retorna a senha armazenada.

        \return Retorna a variavel armazenda.
	*/
	string GetSenha() const {
		return senha;
	}
};
#endif // DOMINIOSUSUARIO_H
