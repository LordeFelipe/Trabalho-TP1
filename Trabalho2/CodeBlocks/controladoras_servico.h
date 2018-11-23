#ifndef CONTROLADORAS_SERVICO_H_
#define CONTROLADORAS_SERVICO_H_

#include "dominios_hotel.h"
#include "dominios_usuario.h"
#include "entidades.h"
#include "interfaces.h"
#include <list>
#include <iterator>

using namespace std;


//Classe controladora dos serviços da classe do usuário--------------------------
class CntrServUsuario:public IServUsuario {

private:
    // Lista com os usuários cadastrados no sistema - Container do Usuário
    std::list<Usuario> ListaUsuario;

public:
    // Métodos que manipulam os usuários na lista
    bool AdicionarUsuario(Identificador identificador, Senha senha, Nome nome);
    Usuario* AutenticarUsuario(Identificador &id, Senha &senha);
    list<Usuario>::iterator BuscarUsuario(Identificador identificador);
    void RemoverUsuario(Usuario* usuario) throw (invalid_argument);

    // Métodos que modificam os objetos dos usuários
    bool AdicionarConta(Usuario *usuario, ContaCorrente conta);
    bool AdicionarCartao(Usuario *usuario, Cartao cartao);

};

class CntrServAcomodacao:public IServAcomodacao {

private:
    // Lista com as acomodações cadastradas no sistema - Container da Acomodação
    std::list<Acomodacao> ListaAcomodacao;

public:
    // Métodos que manipulam as acomodações na lista
    bool AdicionarAcomodacao(Acomodacao &acomodacao);
    bool RemoverAcomodacao(Acomodacao *acomodacao) throw (invalid_argument);

    // Métodos que lidam com a disponibilização na tela das acomodações cadastradas
    int ApresentarListaAcomodacoes();
    int ApresentarListaAcomodacaoDoUsuario(Usuario* usuario);
    
    // Métodos que lidam com a pesquisa de acomodações
    list<Acomodacao>::iterator BuscarAcomodacao(Identificador identificador);
    bool BuscarAcomodacoesUsuario(Usuario* usuario);
    Acomodacao* AcharAcomodacaoSelecionada(const int selecionado);
    Acomodacao* AcharAcomodacaoUsuarioSelecionada(Usuario* usuario, const int selecionado);

    // Métodos para criação e destruição de disponibilidades
    bool CadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva);
    bool DescadastrarDisponibilidade(Acomodacao *acomodacao, Reserva *reserva) throw (invalid_argument);
    
    // Métodos responsáveis por permitir achar a disponibilidades requistada pelo usuário
    int ApresentarListaDisponibiliades(Acomodacao *acomodacao);
    Reserva* AcharDisponibilidadeSelecionada(Acomodacao *acomodacao, const int selecionado);

    // Métodos para fazer e desfazer reservas
    bool CadastrarReserva(Reserva* reserva, Usuario* usuario);
    bool DescadastrarReserva(Reserva* reserva, Usuario *usuario);

    // Métodos responsáveis por manipular as reservas do sistema
    int ApresentarListaReservasUsuario(Acomodacao *acomodacao, Usuario *usuario);
    list<Reserva>::iterator BuscarReserva(Acomodacao *acomodacao, Reserva *reserva);
    bool BuscarReservasUsuario(Usuario* usuario);
    Reserva* AcharReservaSelecionada(Acomodacao *acomodacao, Usuario *usuario, const int selecionado);
    bool VerificarReservas(Acomodacao *acomodacao);

};

#endif
