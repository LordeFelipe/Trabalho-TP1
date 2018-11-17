#include "controladoras_servico.h"

//Métodos da classe CntrServUsuario----------------------------------------

Usuario* CntrServUsuario::BuscarUsuario(Identificador identificador, Senha senha){
    list<Usuario*>::iterator it;
    Identificador identificador_aux;
    Senha senha_aux;

    if(!this->ListaUsuario.empty()){
        for(it = this->ListaUsuario.begin(); it != this->ListaUsuario.end(); ++it){

            identificador_aux = (*it)->GetIdentificador();
            senha_aux = (*it)->GetSenha();

            if(identificador_aux.GetIdentificador() == identificador.GetIdentificador()){
                if(senha_aux.GetSenha() == senha.GetSenha()){
                    // O retorno aqui é o endereço do usuário que foi encontrado
                    return *it;
                }
            }
        }
    }
    // Lista está vazia ou não achou o usuário
    return NULL;
}


void CntrServUsuario::AdicionarUsuario(Usuario &usuario){
    this->ListaUsuario.push_front(&usuario);
}

void CntrServUsuario::RemoverUsuario(Usuario &usuario) throw (invalid_argument){
    Usuario* usuario_aux = BuscarUsuario(usuario.GetIdentificador(), usuario.GetSenha());
    if(usuario_aux != NULL){
        this->ListaUsuario.remove(usuario_aux);
    }
    else{
        throw invalid_argument("Usuário inexistente.");
        return;
    }

}

//Métodos da classe CntrServAcomodacao----------------------------------------

Acomodacao* CntrServAcomodacao::BuscarAcomodacao(Identificador identificador){
    list<Acomodacao*>::iterator it;
    Identificador identificador_aux;

    if(!this->ListaAcomodacao.empty()){
        for(it = this->ListaAcomodacao.begin(); it != this->ListaAcomodacao.end(); ++it){

            identificador_aux = (*it)->GetIdentificador();

            if(identificador_aux.GetIdentificador() == identificador.GetIdentificador()){
                return *it;
                
            }
        }
    }
    // Lista está vazia ou não achou o usuário
    return NULL;
}


void CntrServAcomodacao::AdicionarAcomodacao(Acomodacao &acomodacao){
    this->ListaAcomodacao.push_front(&acomodacao);
}

void CntrServAcomodacao::RemoverAcomodacao(Acomodacao &acomodacao) throw (invalid_argument){
    Acomodacao* acomodacao_aux = BuscarAcomodacao(acomodacao.GetIdentificador());
    if(acomodacao_aux != NULL){
        this->ListaAcomodacao.remove(acomodacao_aux);
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