#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios_hotel.h"
#include "dominios_usuario.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

// Declarações adiantadas.

class ILNAutenticacao;

// Declaração de interface para serviço de autenticação na camada de apresentação.

class IUAutenticacao {
public:

    // Método por meio do qual é solicitado o serviço.

    virtual ResultadoAutenticacao autenticar() throw(runtime_error) = 0;

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.

    virtual void setCntrLNAutenticacao(ILNAutenticacao *) = 0;

    // Método destrutor virtual.

    virtual ~IUAutenticacao(){}
};

// Declaração de interface para serviço de autenticação na camada de serviço.

class ILNAutenticacao {
public:

    // Método por meio do qual é solicitado o serviço.

    virtual Resultado autenticar(const Identificador&, const Senha&) throw(runtime_error)= 0;

    // Método destrutor virtual.

    virtual ~ILNAutenticacao(){}
};

class IServUsuario{
public:
    virtual Usuario* BuscarUsuario(Identificador identificador, Senha senha) = 0;
    virtual void AdicionarUsuario(Usuario &usuario) = 0;
    virtual void RemoverUsuario(Usuario &usuario) throw (invalid_argument) = 0;


};

class IServAcomodacao{
public:
    virtual Acomodacao* BuscarAcomodacao(Identificador identificador) = 0;
    virtual void AdicionarAcomodacao(Acomodacao &acomodacao) = 0;
    virtual void RemoverAcomodacao(Acomodacao &acomodacao) throw (invalid_argument) = 0;


};


#endif // INTERFACES_H_INCLUDED
