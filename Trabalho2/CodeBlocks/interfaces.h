#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios_hotel.h"
#include "dominios_usuario.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

// Declarações adiantadas.
class IServUsuario;
class IAprAcomodacao;

//Interface que lida com a camada de apresentação relativa ao usuário
class IAprUsuario{

public:

    // Método por meio do qual é estabelecida ligação (link) 
    virtual void SetCntrAprUsuario(IServUsuario*) = 0;

    //Métodos que solicitam com serviços que manipulão o usuário na lista
    virtual bool CadastrarUsuario() throw(runtime_error) = 0;
    virtual Usuario* AutenticarUsuario() throw(runtime_error) = 0;
    virtual bool RemoverUsuario(Usuario *usuario, IAprAcomodacao* cntr_apr_aco) throw (invalid_argument) = 0;

    //Métodos que solicitam serviços que adicionam informação ao objeto usuário
    virtual bool CadastrarConta(Usuario *usuario) = 0;
    virtual bool CadastrarCartao(Usuario *usuario) = 0;
    
    // Método destrutor virtual.
    virtual ~IAprUsuario(){}

};

//Interface que lida com a camada de serviço relativa ao usuário
class IServUsuario{
public:

    // Métodos que realizam um serviço relacionado ao usuário para a camada de apresentação
    virtual bool AdicionarUsuario(Identificador identificador, Senha senha, Nome nome) = 0;
    virtual Usuario* AutenticarUsuario(Identificador &id, Senha &senha) = 0;
    virtual void RemoverUsuario(Usuario* usuario) throw (invalid_argument) = 0;

    // Métodos que manipulam usuários já cadastrados no sistema
    virtual bool AdicionarConta(Usuario *usuario, ContaCorrente conta) = 0;
    virtual bool AdicionarCartao(Usuario *usuario, Cartao cartao) = 0;
    virtual list<Usuario>::iterator BuscarUsuario(Identificador identificador) = 0;

    // Método destrutor virtual.
    virtual ~IServUsuario(){}
};  
class IServAcomodacao;

//Interface que lida com a camada de apresentação relativa à acomodação
class IAprAcomodacao{

public:

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.
    virtual void SetCntrAprAcomodacao(IServAcomodacao*) = 0;

    // Métodos que solicitam serviços relacionados à acomodação da camada de serviço
    virtual bool CadastrarAcomodacao(Usuario* usuario) throw(runtime_error) = 0;
    virtual bool DescadastrarAcomodacao(Usuario* usuario) throw(runtime_error) = 0;

    //Metodos que solicitam serviços que lidam com o cadastro e descadastro de disponibilidades em acomodações
    virtual bool CadastrarDisponibilidade(Usuario* usuario) throw(runtime_error) = 0;
    virtual bool DescadastrarDisponibilidade(Usuario *usuario) throw(runtime_error) = 0;

    //Métodos que solicitam serviços que lidam com o cadastro e descadastro de reservas nas acomodaões
    virtual bool CadastrarReserva(Usuario* usuario) throw(runtime_error) = 0;
    virtual bool DescadastrarReserva(Usuario *usuario) throw(runtime_error) = 0;

    //Métodos que solicitam serviços que fazem buscas por reservas ou acomodações do usuário desejado
    virtual bool BuscarAcomodacoesUsuario(Usuario* usuario) = 0;
    virtual bool BuscarReservasUsuario(Usuario* usuario) = 0;
    
    // Método destrutor virtual.
    virtual ~IAprAcomodacao(){}

};

//Interface que lida com a camada de serviço relativa à acomodação
class IServAcomodacao{
public:

    // Métodos que realizam um serviço relacionado à acomodação para a camada de apresentação
    virtual bool AdicionarAcomodacao(Acomodacao &acomodacao) = 0;
    virtual bool RemoverAcomodacao(Acomodacao *acomodacao) throw (invalid_argument) = 0;
    
    // Métodos que lidam com a disponibilização na tela das acomodações cadastradas
    virtual int ApresentarListaAcomodacoes() = 0;
    virtual int ApresentarListaAcomodacaoDoUsuario(Usuario* usuario) = 0;

    // Métodos que lidam com a pesquisa de acomodações
    virtual list<Acomodacao>::iterator BuscarAcomodacao(Identificador identificador) = 0;
    virtual bool BuscarAcomodacoesUsuario(Usuario* usuario) = 0;
    virtual Acomodacao* AcharAcomodacaoSelecionada(const int selecionado) = 0;
    virtual Acomodacao* AcharAcomodacaoUsuarioSelecionada(Usuario* usuario, const int selecionado) = 0;

    // Métodos para criação e destruição de disponibilidades
    virtual bool CadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva) = 0;
    virtual bool DescadastrarDisponibilidade(Acomodacao *acomodacao, Reserva *reserva) throw (invalid_argument) = 0;

    // Métodos responsáveis por permitir achar a disponibilidades requistada pelo usuário
    virtual int ApresentarListaDisponibiliades(Acomodacao *acomodacao) = 0;
    virtual Reserva* AcharDisponibilidadeSelecionada(Acomodacao *acomodacao, const int selecionado) = 0;

    // Métodos para fazer e desfazer reservas
    virtual bool CadastrarReserva(Reserva* reserva, Usuario* usuario) = 0;
    virtual bool DescadastrarReserva(Reserva* reserva, Usuario *usuario) = 0;

    // Métodos responsáveis por manipular as reservas do sistema
    virtual int ApresentarListaReservasUsuario(Acomodacao *acomodacao, Usuario *usuario) = 0;
    virtual list<Reserva>::iterator BuscarReserva(Acomodacao *acomodacao, Reserva *reserva) = 0;
    virtual bool BuscarReservasUsuario(Usuario* usuario)=0;
    virtual Reserva* AcharReservaSelecionada(Acomodacao *acomodacao, Usuario *usuario, const int selecionado) = 0;
    virtual bool VerificarReservas(Acomodacao *acomodacao) = 0;

    // Método destrutor virtual
    virtual ~IServAcomodacao(){}
};

//Interfaces que lidam com navegação e apresentação de menus

class INavegacaoInicial{
public:
    virtual void apresentarOpcoes() = 0;
    virtual void executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco) = 0;
};

class INavegacaoPrincipal{
public:
    virtual void apresentarOpcoes() = 0;
    virtual void executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco, Usuario* usuario) = 0;
};

class INavegacaoAcomodacao{
public:
    virtual void apresentarOpcoes() = 0;
    virtual void executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco, Usuario* usuario) = 0;
};

class INavegacaoReserva{
public:
    virtual void apresentarOpcoes() = 0;
    virtual void executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco, Usuario* usuario) = 0;
};

#endif // INTERFACES_H_INCLUDED
