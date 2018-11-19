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

    // Método por meio do qual é solicitado o serviço.
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
    virtual list<Usuario>::iterator BuscarUsuario(Identificador identificador) = 0;
    virtual bool AdicionarUsuario(Identificador identificador, Senha senha, Nome nome) = 0;
    virtual void RemoverUsuario(Usuario &usuario) throw (invalid_argument) = 0;
    virtual Usuario* AutenticarUsuario(Identificador &id, Senha &senha) = 0;
    virtual bool AdicionarConta(Usuario *usuario, ContaCorrente conta) = 0;
    virtual bool AdicionarCartao(Usuario *usuario, Cartao cartao) = 0;
    virtual ~IServUsuario(){}
};

class IServAcomodacao{
public:
    virtual Acomodacao* BuscarAcomodacao(Identificador identificador) = 0;
    virtual void AdicionarAcomodacao(Acomodacao &acomodacao) = 0;
    virtual void RemoverAcomodacao(Acomodacao &acomodacao) throw (invalid_argument) = 0;
    virtual ~IServAcomodacao(){}
};

class INavegacaoInicial{
public:
    virtual void apresentarOpcoes() = 0;
    virtual void executar(IAprUsuario* cntr_apr_usu, IServUsuario* cntr_serv_usu) = 0;
};

class INavegacaoPrincipal{
public:
    virtual void apresentarOpcoes() = 0;
    virtual void executar(IAprUsuario* cntr_apr_usu, IServUsuario* cntr_serv_usu, Usuario* usuario) = 0;
};

class INavegacaoAcomodacao{
public:
    virtual void apresentarOpcoes() = 0;
    virtual void executar(IAprUsuario* cntr_apr_usu, IServUsuario* cntr_serv_usu, Usuario* usuario) = 0;
};

class INavegacaoReserva{
public:
    virtual void apresentarOpcoes() = 0;
    virtual void executar(IAprUsuario* cntr_apr_usu, IServUsuario* cntr_serv_usu, Usuario* usuario) = 0;
};

#endif // INTERFACES_H_INCLUDED
