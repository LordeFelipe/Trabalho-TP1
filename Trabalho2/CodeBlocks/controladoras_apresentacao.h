#ifndef CONTROLADORAS_APRESENTACAO_H_
#define CONTROLADORAS_APRESENTACAO_H_

#include "dominios_hotel.h"
#include "dominios_usuario.h"
#include "entidades.h"
#include "interfaces.h"
#include <list>
#include <iterator>
#include "dominios_usuario.h"
#include "controladoras_servico.h"

using namespace std;

//Classe controladora da apresentação do usuário--------------------------
class CntrAprUsuario:public IAprUsuario {

private:
    // Referencia para o servidor
    IServUsuario *cntr_serv_usuario;
public:
    //Método de ligação de camadas
    void SetCntrAprUsuario(IServUsuario*);

    //Métodos que lidam com a manipulação do usuário na lista
    bool CadastrarUsuario() throw(runtime_error);
    Usuario* AutenticarUsuario() throw(runtime_error);
    bool RemoverUsuario(Usuario *usuario, IAprAcomodacao* cntr_apr_aco) throw (invalid_argument);

    //Métodos que adicionam informação ao objeto usuário
    bool CadastrarConta(Usuario *usuario) throw(runtime_error);
    bool CadastrarCartao(Usuario *usuario) throw(runtime_error);
};

// Método que faz a ligação entre a camada de apresentação e a de serviço
void inline CntrAprUsuario::SetCntrAprUsuario(IServUsuario *cntr_serv_usuario){
    this->cntr_serv_usuario = cntr_serv_usuario;
}

//Classe controladora da apresentação da acomodacao--------------------------
class CntrAprAcomodacao:public IAprAcomodacao {

private:
    // Referencia para o servidor
    IServAcomodacao *cntr_serv_acomodacao;
public:
    //Método de ligação de camadas
    void SetCntrAprAcomodacao(IServAcomodacao *cntr_serv_acomodacao);

    //Métodos que lidam com adicionar e remover acomodações da lista
    bool CadastrarAcomodacao(Usuario* usuario) throw(runtime_error);
    bool DescadastrarAcomodacao(Usuario* usuario) throw(runtime_error);

    //Metodos que lidam com o cadastro e descadastro de disponibilidades em acomodações
    bool CadastrarDisponibilidade(Usuario* usuario) throw(runtime_error);
    bool DescadastrarDisponibilidade(Usuario *usuario) throw(runtime_error);

    //Métodos que lidam com o cadastro e descadastro de reservas nas acomodaões
    bool CadastrarReserva(Usuario* usuario) throw(runtime_error);
    bool DescadastrarReserva(Usuario *usuario) throw(runtime_error);

    //Métodos que fazem buscas por reservas ou acomodações do usuário desejado
    bool BuscarAcomodacoesUsuario(Usuario* usuario);
    bool BuscarReservasUsuario(Usuario* usuario);
};

// Método que faz a ligação entre a camada de apresentação e a de serviço
void inline CntrAprAcomodacao::SetCntrAprAcomodacao(IServAcomodacao *cntr_serv_acomodacao){
    this->cntr_serv_acomodacao = cntr_serv_acomodacao;
}

//Classe Controladora na navegação inicial-------------------------------------
class CntrNavegacaoInicial:public INavegacaoInicial{
        //Constantes para identificar a opção escolhida.
        static const unsigned int NUMERO_OPCOES = 2;
        static const unsigned int OPCAO_ENCERRAR = 0;
        static const unsigned int OPCAO_REGISTRAR_USUARIO = 1;
        static const unsigned int OPCAO_LOGAR_USUARIO = 2;

        void apresentarOpcoes();
public:
       CntrNavegacaoInicial(){}
       void executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco);
};

//Classe Controladora na navegação principal-------------------------------------
class CntrNavegacaoPrincipal:public INavegacaoPrincipal{
        //Constantes para identificar a opção escolhida.
        static const unsigned int NUMERO_OPCOES = 3;
        static const unsigned int OPCAO_DESLOGAR = 0;
        static const unsigned int OPCAO_ACOMODACAO = 1;
        static const unsigned int OPCAO_RESERVA = 2;
        static const unsigned int OPCAO_EXCLUIR_USUARIO = 3;

        void apresentarOpcoes();
public:
       CntrNavegacaoPrincipal(){}
       void executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco, Usuario* usuario);
};

//Classe Controladora na navegação da Acomodacao-------------------------------------
class CntrNavegacaoAcomodacao:public INavegacaoAcomodacao{
        //Constantes para identificar a opção escolhida.
        static const unsigned int NUMERO_OPCOES = 4;
        static const unsigned int OPCAO_VOLTAR = 0;
        static const unsigned int OPCAO_CADASTRAR_ACOMODACAO = 1;
        static const unsigned int OPCAO_DESCADASTRAR_ACOMODACAO = 2;
        static const unsigned int OPCAO_CADASTRAR_DISPONIBILIDADE = 3;
        static const unsigned int OPCAO_DESCADASTRAR_DISPONIBILIDADE = 4;

        void apresentarOpcoes();
public:
       CntrNavegacaoAcomodacao(){}
       void executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco, Usuario* usuario);
};

//Classe Controladora na navegação das Reservas-------------------------------------
class CntrNavegacaoReserva:public INavegacaoReserva{
        //Constantes para identificar a opção escolhida.
        static const unsigned int NUMERO_OPCOES = 2;
        static const unsigned int OPCAO_VOLTAR = 0;
        static const unsigned int OPCAO_FAZER_RESERVA = 1;
        static const unsigned int OPCAO_DESFAZER_RESERVA = 2;

        void apresentarOpcoes();
public:
       CntrNavegacaoReserva(){}
       void executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco, Usuario* usuario);
};

#endif
