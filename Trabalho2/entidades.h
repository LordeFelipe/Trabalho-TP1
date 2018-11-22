#ifndef ENTIDADES_H_
#define ENTIDADES_H_

#include "dominios_hotel.h"
#include "dominios_usuario.h"
#include <list>
#include <iterator>


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

        Classe que armazena as caracteristicas necessárias para definir a entidade da conta corrente.
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

/*! \class Usuario
        \brief Classe que define a entitade do tipo Usuario.

        Classe que armazena as caracteristicas necessárias para definir a entidade do usuário.
        Contém um objeto para os tipo Nome, Identificador e Senha.
*/
class Usuario{

    private:

        // Elementos que compoem a classe?
        Nome nome; /*!< Objeto da classe Nome. Armazena o nome do cliente. */
        Identificador identificador; /*!< Objeto da classe Identificador. Armazena o identificador de usuário. */
        Senha senha; /*!< Objeto da classe Senha. Armazena a senha do usuário. */
        Cartao *cartao = NULL; /*!< Objeto da entidade Cartao. Armazena as informações do cartão de crédito do usuário. */
        ContaCorrente *conta = NULL; /*!< Objeto da entidade ContaCorrente. Armazena as informações da conta corrente do usuário. */

    public:

        // Metodos de acesso ao nome:

        /*! \fn void SetNome(const Nome &nome)
            \brief Seta o objeto passado como o nome do usuário.

            \param nome Objeto do tipo Nome a ser setado.
        */
        void SetNome(const Nome &nome){
            this->nome = nome;
        }

        /*! \fn Nome GetNome()
            \brief Retorna o objeto do nome do usuário.

            \return Objeto do tipo Nome.
        */
        Nome GetNome() const {
            return nome;
        }

        // Metodos de acesso a agencia da conta:

        /*! \fn void Identificador(const Identificador &identificador)
            \brief Seta o objeto passado como o identificador do usuário.

            \param identificador Objeto do tipo Identificador a ser setado.
        */
        void SetIdentificador(const Identificador &identificador){
            this->identificador = identificador;
        }

        /*! \fn Identificador GetIdentificador()
            \brief Retorna o objeto do identificador de usuário armazenado.

            \return Objeto do tipo Identificador.
        */
        Identificador GetIdentificador() const {
            return identificador;
        }

        // Metodos de acesso à senha:

        /*! \fn void SetSenha(const Senha &senha)
            \brief Seta o objeto passado como a senha do usuário.

            \param banco Objeto do tipo Senha a ser setado.
        */
        void SetSenha(const Senha &senha){
            this->senha = senha;
        }

        /*! \fn Senha GetSenha()
            \brief Retorna o objeto da senha armazenada.

            \return Objeto do tipo Senha.
        */
        Senha GetSenha() const {
            return senha;
        }

        // Metodos de acesso ao cartão:

        /*! \fn void SetCartao(const Cartao &cartao)
            \brief Seta o objeto passado como o cartão do usuário.

            \param cartao Objeto do tipo Cartao a ser setado.
        */
        void SetCartao(Cartao *cartao){
            this->cartao = cartao;
        }

        /*! \fn Cartao GetCartao()
            \brief Retorna o objeto do cartao armazenado.

            \return Objeto do tipo Cartao.
        */
        Cartao* GetCartao() const {
            return cartao;
        }

        bool VerificarCartao();

        // Metodos de acesso à conta corrente:

        /*! \fn void SetConta(const ContaCorrente &conta)
            \brief Seta o objeto passado como a conta corrente do usuário.

            \param conta Objeto do tipo ContaCorrente a ser setado.
        */
        void SetConta(ContaCorrente *conta){
            this->conta = conta;
        }

        /*! \fn ContaCorrente GetConta()
            \brief Retorna o objeto da conta armazenada.

            \return Objeto do tipo ContaCorrente.
        */
        ContaCorrente* GetConta() const {
            return conta;
        }

        bool VerificarConta();
};

/*! \class Reserva
        \brief Classe que define a reserva de uma acomodação

        Essa classe armazena as informacões sobre a reserva de uma acomodação.
        Nela se inclui a data da reserva, se está disponível ou não, e o usuário que efetuou a reserva (se houver).
        Contém objetos para a data de início e fim da reserva, e um ponteiro para o usuario da reserva.
*/
class Reserva
{
    private:

        //Elementos que compõem a classe
        Data data_inicio; /*!< Objeto da classe Data. Armazena qual é a data de início da reserva ou disponibilidade. */
        Data data_termino; /*!< Objeto da classe Data. Armazena qual é a data de término da reserva ou disponibilidade. */
        Usuario *usuario = NULL; /*!< Ponteiro para o usuário que efetuou a reserva. Começa como NULL indicando que não há reserva efetuada. */

        // Método de Validação
        void Validar(Data &data_inicio, Data &data_termino) throw (invalid_argument);

        public:

        // Métodos de acesso às datas de inicio e termino

        /*! \fn void SetDatas(const Data &data_inicio, const Data &data_termino)
            \brief Seta os objeto passados como a data de inicio e de termino.

            \param data_inicio Objeto do tipo Data a ser setado como data de inicio.
            \param data_termino Objeto do tipo Data a ser setado como data de termino.
        */
        void SetDatas(const Data &data_inicio, const Data &data_termino);


        /*! \fn Data GetDataInicio()
            \brief Retorna o objeto com a data de inicio armazenada.

            \return Objeto do tipo Data
        */
        Data GetDataInicio(){
            return data_inicio;
        }

        /*! \fn Data GetDataTermino()
            \brief Retorna o objeto com a data de término armazenada.

            \return Objeto do tipo Data
        */
        Data GetDataTermino(){
            return data_termino;
        }

        // Métodos de acesso ao ponteiro do usuario
        
        /*! \fn void SetUsuario(const Usuario *usuario)
            \brief Seta o ponteiro do objeto passado como o usuario filiado a reserva.

            \param usuario Ponteiro para um objeto do tipo Usuario.
        */
        void SetUsuario(Usuario *usuario){
            this->usuario = usuario;
        }

        /*! \fn Usuario* GetUsuario()
            \brief Retorna o ponteiro do usuario filiado a reserva armazenado.

            \return Ponteiro do objeto Usuario.
        */
        Usuario* GetUsuario(){
            return usuario;
        }

};

/*! \class Acomodacao
        \brief Classe que define a entitade do tipo Acomodacao.

        Classe que armazena as informações necessárias para definir uma acomodação
        Contém um objeto para os tipos Identificador, TipoDeAcomodacao, CapacidadeDeAcomodacao,
        Data, Nome, Estado e Diaria.
*/
class Acomodacao
{
    private:

        // Elementos que compoem a classe
        Identificador identificador; /*!< Objeto da classe Identificador. Armazena um identificador para a acomodação. */
        TipoDeAcomodacao tipo_de_acomodacao; /*!< Objeto da classe TipoDeAcomodacao. Armazena qual é o tipo da acomodação. */
        CapacidadeDeAcomodacao capacidade; /*!< Objeto da classe CapacidadeDeAcomodacao. Armazena qual é a capacidade da acomodação. */
        Nome cidade; /*!< Objeto da classe Nome. Armazena qual é o nome da cidade da acomodação. */
        Estado estado; /*!< Objeto da classe Estado. Armazena qual é o estado brasileiro da acaomodação. */
        Diaria diaria; /*!< Objeto da classe Diaria. Armazena qual é o valor da diária da acomodação. */
        Usuario* usuario; /*!< Objeto da classe Usuario. Armazena quem é o dono dessa acomodação. */
        std::list<Reserva> *reserva; /*!< Lista com objetos da classe Reserva indicando os períodos de disponibilidade disponíveis e de reservas efetuadas. */

    public:

        // Métodos de acesso ao identificador

        /*! \fn void SetIdentificador(const Identificador &identificador)
            \brief Seta o objeto passado como o identificador.

            \param identificador Objeto do tipo Identificador a ser setado.
        */
         void SetIdentificador(const Identificador &identificador){
            this->identificador = identificador;
        }

        /*! \fn Identificador GetIdentificador()
            \brief Retorna o objeto do identificador armazenado.

            \return Objeto do tipo Identificador.
        */
        Identificador GetIdentificador(){
            return identificador;
        }

        // Métodos de acesso ao tipo de acomodacao
        /*! \fn void SetTipoDeAcomodacao(const TipoDeAcomodacao &tipo_de_acomodacao)
            \brief Seta o objeto passado como o tipo de acomodacao.

            \param tipo_de_acomodacao Objeto do tipo TipoDeAcomodacao a ser setado.
        */
        void SetTipoDeAcomodacao(const TipoDeAcomodacao &tipo_de_acomodacao){
            this->tipo_de_acomodacao = tipo_de_acomodacao;
        }

        /*! \fn TipoDeAcomodacao GetTipoDeAcomodacao()
            \brief Retorna o objeto do tipo de acomodacao armazenado.

            \return Objeto do tipo TipoDeAcomodacao.
        */
        TipoDeAcomodacao GetTipoDeAcomodacao(){
            return tipo_de_acomodacao;
        }

        // Métodos de acesso à capacidade de acomodação

        /*! \fn void SetCapacidaDeAcomodacao(const CapacidadeDeAcomodacao &capacidade)
            \brief Seta o objeto passado como a capacidade de acomodacao.

            \param capacidade Objeto do tipo CapacidadeDeAcomodacao a ser setado.
        */
        void SetCapacidaDeAcomodacao(const CapacidadeDeAcomodacao &capacidade){
            this->capacidade = capacidade;
        }

        /*! \fn CapacidadeDeAcomodacao GetCapacidadeDeAcomodacao()
            \brief Retorna o objeto com a capacidade de acomodacao armazenada.

            \return Objeto do tipo CapacidadeDeAcomodacao.
        */
        CapacidadeDeAcomodacao GetCapacidadeDeAcomodacao(){
            return capacidade;
        }

        // Métodos de acesso à cidade

        /*! \fn void SetCidade(const Nome &cidade)
            \brief Seta o objeto passado como o nome da cidade.

            \param cidade Objeto do tipo Nome a ser setado.
        */
        void SetCidade(const Nome &cidade){
            this->cidade = cidade;
        }

        /*! \fn Nome GetCidade()
            \brief Retorna o objeto com o nome da cidade armazenado.

            \return Objeto do tipo Nome
        */
        Nome GetCidade(){
            return cidade;
        }

        // Métodos de acesso ao estado

        /*! \fn void SetEstado(const Estado &estado)
            \brief Seta o objeto passado como o estado.

            \param estado Objeto do tipo Estado a ser setado.
        */
        void SetEstado(const Estado &estado){
            this->estado = estado;
        }

        /*! \fn Estado GetEstado()
            \brief Retorna o objeto com o estado armazenado.

            \return Objeto do tipo Estado
        */
        Estado GetEstado(){
            return estado;
        }

        // Métodos de acesso à diária

        /*! \fn void SetDiaria(const Diaria &diaria)
            \brief Seta o objeto passado como a diária.

            \param diaria Objeto do tipo Diaria a ser setado.
        */
        void SetDiaria(const Diaria &diaria){
            this->diaria = diaria;
        }

        /*! \fn GetDiaria()
            \brief Retorna o objeto com a diaria armazenada.

            \return Objeto do tipo Diaria
        */
        Diaria GetDiaria(){
            return diaria;
        }

        // Métodos de acesso à lista de reservas

        /*! \fn void AddDisponibilidade(const Reserva &reserva) throw (invalid_argument)
            \brief Adiciona a disponibilidade na lista de reservas.

            \param reserva Objeto do tipo Reserva a ser adicionado.
        */
        bool AddDisponibilidade(Reserva &reserva) throw (invalid_argument);

        /*! \fn void FazReserva(const std::list<Reserva>::iterator &reserva, const Usuario *usuario);
            \brief Reserva uma acomodação da lista de reservas para um usuario.

            \param reserva Elemento da lista com a reserva a ser feita.
            \param usuario Ponteiro para o usuario a ser vinculado a reserva.
        */
        void FazReserva(const std::list<Reserva>::iterator &reserva, Usuario *usuario) throw (invalid_argument);

        /*! \fn GetReserva()
            \brief Retorna a lista de reservas.

            \return Objeto do tipo std::list<Reserva>
        */
        std::list<Reserva> *GetReserva(){
            return reserva;
        }

        /*! \fn SetUsuario(Usuario* usuario)
            \brief Adiciona um usuário à acomodação

            \param usuario ponteiro para o dono da acomodação
        */
        void SetUsuario(Usuario* usuario){
            this->usuario = usuario;
        }

        /*! \fn GetUsuario()
            \brief Retorna o dono da acomodacao

            \return Objeto do tipo *Usuario
        */

        Usuario* GetUsuario(){
            return usuario; 
        }

        void IniciarReserva(){
            this->reserva = new list<Reserva>; 
        }

        void ExcluirListaReserva(){
            delete this->reserva;
        }
};

#endif // ENTIDADES_H_
