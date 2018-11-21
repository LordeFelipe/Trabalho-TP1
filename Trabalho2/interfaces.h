#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios_hotel.h"
#include "dominios_usuario.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

// Declarações adiantadas.
class IServUsuario;

class IAprUsuario{

public:

    // Métodos que solicitam serviços relacionados ao usuário da camada de serviço
    virtual bool CadastrarUsuario() throw(runtime_error) = 0;
    virtual Usuario* AutenticarUsuario() throw(runtime_error) = 0;
    virtual bool CadastrarConta(Usuario *usuario) = 0;
    virtual bool CadastrarCartao(Usuario *usuario) = 0;
    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.
    virtual void SetCntrAprUsuario(IServUsuario*) = 0;
    // Método destrutor virtual.
    virtual ~IAprUsuario(){}

};

class IServUsuario{
public:

    // Métodos que realizam um serviço relacionado ao usuário para a camada de apresentação
    virtual list<Usuario>::iterator BuscarUsuario(Identificador identificador) = 0;
    virtual bool AdicionarUsuario(Identificador identificador, Senha senha, Nome nome) = 0;
    virtual void RemoverUsuario(Usuario &usuario) throw (invalid_argument) = 0;
    virtual Usuario* AutenticarUsuario(Identificador &id, Senha &senha) = 0;
    virtual bool AdicionarConta(Usuario *usuario, ContaCorrente conta) = 0;
    virtual bool AdicionarCartao(Usuario *usuario, Cartao cartao) = 0;
    // Método destrutor virtual.
    virtual ~IServUsuario(){}
};

class IServAcomodacao;

class IAprAcomodacao{

public:

    // Métodos que solicitam serviços relacionados à acomodação da camada de serviço
    virtual bool CadastrarAcomodacao(Usuario* usuario) throw(runtime_error) = 0;
    virtual bool DescadastrarAcomodacao(Usuario* usuario) throw(runtime_error) = 0;
    virtual bool CadastrarDisponibilidade(Usuario* usuario) throw(runtime_error) = 0;
    virtual bool DescadastrarDisponibilidade(Usuario *usuario) throw(runtime_error) = 0;
    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.
    virtual void SetCntrAprAcomodacao(IServAcomodacao*) = 0;
    // Método destrutor virtual.
    virtual ~IAprAcomodacao(){}

};

class IServAcomodacao{
public:

    // Métodos que realizam um serviço relacionado à acomodação para a camada de apresentação
    virtual list<Acomodacao>::iterator BuscarAcomodacao(Identificador identificador) = 0;
    virtual bool AdicionarAcomodacao(Acomodacao &acomodacao) = 0;
    virtual bool RemoverAcomodacao(Acomodacao *acomodacao) throw (invalid_argument) = 0;
    virtual int ApresentarListaAcomodacaoDoUsuario(Usuario* usuario) = 0;
    virtual Acomodacao* AcharAcomodacaoUsuarioSelecionada(Usuario* usuario, const int selecionado) = 0;
    virtual bool CadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva) = 0;
    virtual list<Reserva>::iterator BuscarReserva(Acomodacao *acomodacao, Reserva *reserva) = 0;
    virtual bool VerificarReservas(Acomodacao *acomodacao) = 0;
    virtual bool DescadastrarDisponibilidade(Acomodacao *acomodacao, Reserva *reserva) throw (invalid_argument) = 0;
    virtual int ApresentarListaDisponibiliades(Acomodacao *acomodacao) = 0;
    virtual Reserva* AcharDisponibilidadeSelecionada(Acomodacao *acomodacao, const int selecionado) = 0;
    virtual ~IServAcomodacao(){}
};

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
