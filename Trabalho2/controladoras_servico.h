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
    int ApresentarListaAcomodacaoDoUsuario(Usuario* usuario);
    Acomodacao* AcharAcomodacaoUsuarioSelecionada(Usuario* usuario, const int selecionado);
    bool VerificarReservas(Acomodacao *acomodacao);
    bool RemoverAcomodacao(Acomodacao *acomodacao) throw (invalid_argument);
    bool CadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva);
    list<Reserva>::iterator BuscarReserva(Acomodacao *acomodacao, Reserva *reserva);
    bool DescadastrarDisponibilidade(Acomodacao *acomodacao, Reserva *reserva) throw (invalid_argument);
    int ApresentarListaDisponibiliades(Acomodacao *acomodacao);
    Reserva* AcharDisponibilidadeSelecionada(Acomodacao *acomodacao, const int selecionado);
    bool CadastrarReserva(Reserva* reserva, Usuario* usuario);
    int ApresentarListaAcomodacoes();
    Acomodacao* AcharAcomodacaoSelecionada(const int selecionado);
    int ApresentarListaReservasUsuario(Acomodacao *acomodacao, Usuario *usuario);
    Reserva* AcharReservaSelecionada(Acomodacao *acomodacao, Usuario *usuario, const int selecionado);
    bool DescadastrarReserva(Reserva* reserva, Usuario *usuario);

};

#endif
