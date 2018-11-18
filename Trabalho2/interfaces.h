#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios_hotel.h"
#include "dominios_usuario.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

// Declarações adiantadas.
class IServUsuario;

class INavegacao{
public:
    virtual void apresentarOpcoes() = 0;
    virtual void executar() = 0;
};

class IAprUsuario{

public:

    // Método por meio do qual é solicitado o serviço.
    virtual bool CadastrarUsuario() throw(runtime_error) = 0;
    virtual Usuario* AutenticarUsuario() throw(runtime_error) = 0;
    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.
    virtual void SetCntrAprUsuario(IServUsuario*) = 0;
    // Método destrutor virtual.
    virtual ~IAprUsuario(){}

};

class IServUsuario{
public:
    virtual Usuario* BuscarUsuario(Identificador identificador, Senha senha) = 0;
    virtual bool AdicionarUsuario(Identificador identificador, Senha senha) = 0;
    virtual void RemoverUsuario(Usuario &usuario) throw (invalid_argument) = 0;
    virtual Usuario* AutenticarUsuario(Identificador &id, Senha &senha) = 0;
    virtual ~IServUsuario(){}
};

class IServAcomodacao{
public:
    virtual Acomodacao* BuscarAcomodacao(Identificador identificador) = 0;
    virtual void AdicionarAcomodacao(Acomodacao &acomodacao) = 0;
    virtual void RemoverAcomodacao(Acomodacao &acomodacao) throw (invalid_argument) = 0;
    virtual ~IServAcomodacao(){}
};


#endif // INTERFACES_H_INCLUDED
