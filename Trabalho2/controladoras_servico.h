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

    std::list<Usuario*> ListaUsuario;

public:

    Usuario* BuscarUsuario(Identificador identificador, Senha senha);
    void AdicionarUsuario(Usuario &usuario);
    void RemoverUsuario(Usuario &usuario) throw (invalid_argument);
    Usuario* AutenticarUsuario(Identificador &id, Senha &senha);


};

class CntrServAcomodacao:public IServAcomodacao{

private:

    std::list<Acomodacao*> ListaAcomodacao;

public:

    Acomodacao* BuscarAcomodacao(Identificador identificador);
    void AdicionarAcomodacao(Acomodacao &acomodacao);
    void RemoverAcomodacao(Acomodacao &acomodacao) throw (invalid_argument);
    list<Reserva>::iterator BuscarReserva(Acomodacao *acomodacao, Reserva &reserva);
    void CadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva);
    void DecadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva) throw (invalid_argument);


};

#endif
