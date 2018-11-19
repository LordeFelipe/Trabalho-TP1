#ifndef CONTROLADORAS_SERVICO_H_
#define CONTROLADORAS_SERVICO_H_

#include "dominios_hotel.h"
#include "dominios_usuario.h"
#include "entidades.h"
#include "interfaces.h"
#include <list>
#include <iterator>

using namespace std;

class CntrServUsuario:public IServUsuario{

private:
    std::list<Usuario> ListaUsuario;

public:
    list<Usuario>::iterator BuscarUsuario(Identificador identificador);
    bool AdicionarUsuario(Identificador identificador, Senha senha, Nome nome);
    void RemoverUsuario(Usuario &usuario) throw (invalid_argument);
    bool AdicionarConta(Usuario *usuario, ContaCorrente conta);
    bool AdicionarCartao(Usuario *usuario, Cartao cartao);
    Usuario* AutenticarUsuario(Identificador &id, Senha &senha);

};

class CntrServAcomodacao:public IServAcomodacao{

private:
    std::list<Acomodacao> ListaAcomodacao;

public:
    list<Acomodacao>::iterator BuscarAcomodacao(Identificador identificador);
    bool AdicionarAcomodacao(Acomodacao &acomodacao);
    void RemoverAcomodacao(Acomodacao &acomodacao) throw (invalid_argument);
    void CadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva);
    list<Reserva>::iterator BuscarReserva(Acomodacao *acomodacao, Reserva &reserva);
    void DecadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva) throw (invalid_argument);


};

#endif
