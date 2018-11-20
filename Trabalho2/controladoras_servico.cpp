#include "controladoras_servico.h"
#include <iostream>
using namespace std;

//Métodos da classe CntrServUsuario----------------------------------------

list<Usuario>::iterator CntrServUsuario::BuscarUsuario(Identificador identificador){
    list<Usuario>::iterator it;
    Identificador identificador_aux;
    Senha senha_aux;

    if(!this->ListaUsuario.empty()){
        for(it = this->ListaUsuario.begin(); it != this->ListaUsuario.end(); ++it){

            identificador_aux = it->GetIdentificador();
            senha_aux = it->GetSenha();

            if(identificador_aux.GetIdentificador() == identificador.GetIdentificador()){
                // O retorno aqui é o endereço do usuário que foi encontrado
                return it;
            }
        }
    }
    // Lista está vazia ou não achou o usuário
    return this->ListaUsuario.end();
}


bool CntrServUsuario::AdicionarUsuario(Identificador identificador, Senha senha, Nome nome){

    Usuario usuario;
    usuario.SetIdentificador(identificador);
    usuario.SetSenha(senha);
    usuario.SetNome(nome);
    //Caso seja ecnontrado um usuário igual ao q se deseja registrar, retorna false
    list<Usuario>::iterator usuario_repetido = this->BuscarUsuario(identificador);
    if(usuario_repetido != this->ListaUsuario.end()){
        return false;
    }

    this->ListaUsuario.push_front(usuario);
    return true;
}

bool CntrServUsuario::AdicionarConta(Usuario *usuario, ContaCorrente conta){

    list<Usuario>::iterator it = this->BuscarUsuario(usuario->GetIdentificador());
    if(it == this->ListaUsuario.end()){
        return false;
    }

    it->SetConta(&conta);
    return true;
}

bool CntrServUsuario::AdicionarCartao(Usuario *usuario, Cartao cartao){

    list<Usuario>::iterator it = this->BuscarUsuario(usuario->GetIdentificador());
    if(it == this->ListaUsuario.end()){
        return false;
    }

    it->SetCartao(&cartao);
    return true;
}

void CntrServUsuario::RemoverUsuario(Usuario &usuario) throw (invalid_argument){
    list<Usuario>::iterator usuario_aux = BuscarUsuario(usuario.GetIdentificador());
    if(usuario_aux != this->ListaUsuario.end()){
        this->ListaUsuario.erase(usuario_aux);
    }
    else{
        throw invalid_argument("Usuário inexistente.");
        return;
    }

}

Usuario* CntrServUsuario::AutenticarUsuario(Identificador &id, Senha &senha){
    list<Usuario>::iterator usuario = this->BuscarUsuario(id);

    if(usuario == this->ListaUsuario.end()){
        return NULL;
    }
    else if(usuario->GetSenha().GetSenha() != senha.GetSenha()){
        return NULL;
    }
    else{
        return &(*usuario);
    }
}
//Métodos da classe CntrServAcomodacao----------------------------------------

list<Acomodacao>::iterator CntrServAcomodacao::BuscarAcomodacao(Identificador identificador){
    list<Acomodacao>::iterator it;
    Identificador identificador_aux;

    if(!this->ListaAcomodacao.empty()){
        for(it = this->ListaAcomodacao.begin(); it != this->ListaAcomodacao.end(); ++it){

            identificador_aux = it->GetIdentificador();

            if(identificador_aux.GetIdentificador() == identificador.GetIdentificador()){
                return it;

            }
        }
    }
    // Lista está vazia ou não achou o usuário
    return this->ListaAcomodacao.end();
}


bool CntrServAcomodacao::AdicionarAcomodacao(Acomodacao &acomodacao){
    if(this->BuscarAcomodacao(acomodacao.GetIdentificador()) == this->ListaAcomodacao.end()){
        this->ListaAcomodacao.push_front(acomodacao);
        return true;
    }
    else
        return false;
}

void CntrServAcomodacao::RemoverAcomodacao(Acomodacao &acomodacao) throw (invalid_argument){
    list<Acomodacao>::iterator acomodacao_aux = BuscarAcomodacao(acomodacao.GetIdentificador());
    if(acomodacao_aux != this->ListaAcomodacao.end()){
        this->ListaAcomodacao.erase(acomodacao_aux);
    }
    else{
        throw invalid_argument("Usuário inexistente.");
        return;
    }

}

void CntrServAcomodacao::CadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva){
    list<Reserva> listReserva = acomodacao->GetReserva();

    listReserva.push_front(reserva);
}

list<Reserva>::iterator CntrServAcomodacao::BuscarReserva(Acomodacao *acomodacao, Reserva &reserva){
    list<Reserva> listReserva = acomodacao->GetReserva();
    list<Reserva>::iterator it;

    for(it = listReserva.begin(); it != listReserva.end(); ++it){
        if(it->GetDataInicio().GetData() == reserva.GetDataInicio().GetData()){
            if(it->GetDataTermino().GetData() == reserva.GetDataTermino().GetData()){
                if(it->GetUsuario() == reserva.GetUsuario()){
                    return it;
                }
            }
        }
    }

    // Lista vazia ou reserva não encontrada
    return listReserva.end();
}

void CntrServAcomodacao::DecadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva) throw (invalid_argument){
    list<Reserva>::iterator local = this->BuscarReserva(acomodacao, reserva);

    if(local == acomodacao->GetReserva().end()){
        throw invalid_argument("Disponibilidade Inexstente");
        return;
    }

    if(local->GetUsuario() != NULL){
        throw invalid_argument("Acomodacao alugada para esse periodo");
        return;
    }

    acomodacao->GetReserva().erase(local);
}

void CntrServAcomodacao::ApresentarListaAcomodacaoDoUsuario(Usuario* usuario){
    list<Acomodacao>::iterator it;
    if(!this->ListaAcomodacao.empty()){
        for(it = this->ListaAcomodacao.begin(); it != this->ListaAcomodacao.end(); ++it){
            if(it->GetUsuario() == usuario){
                cout << "Identificador:" << it->GetIdentificador().GetIdentificador() << endl;
                cout << "Tipo de Acomodação:" << it->GetTipoDeAcomodacao().GetTipoDeAcomodacao() << endl;
                cout << "Capacidade de Acomodacao:" << it->GetCapacidadeDeAcomodacao().GetCapacidadeDeAcomodacao() << endl;
                cout << "Cidade:" << it->GetCidade().GetNome() << endl;
                cout << "Estado:" << it->GetEstado().GetEstado() << endl;
                cout << "Valor da diária:" << it->GetDiaria().GetDiaria() << endl << endl;
            }

        }
    }
    else{
        cout << "Não há acomodações cadastradas" << endl;
    }
    // Lista está vazia ou não achou o usuário
    return;


}
