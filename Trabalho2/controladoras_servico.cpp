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
    usuario.SetCartao(NULL);
    usuario.SetConta(NULL);
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

void CntrServAcomodacao::RemoverAcomodacao(Acomodacao *acomodacao) throw (invalid_argument){
    list<Acomodacao>::iterator acomodacao_aux = BuscarAcomodacao(acomodacao->GetIdentificador());
    if(acomodacao_aux != this->ListaAcomodacao.end()){
        this->ListaAcomodacao.erase(acomodacao_aux);
    }
    else{
        throw invalid_argument("Usuário inexistente.");
        return;
    }

}

void CntrServAcomodacao::CadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva){
    acomodacao->AddDisponibilidade(reserva);
}

list<Reserva>::iterator CntrServAcomodacao::BuscarReserva(Acomodacao *acomodacao, Reserva *reserva){
    list<Reserva> listReserva = acomodacao->GetReserva();
    list<Reserva>::iterator it;

    for(it = listReserva.begin(); it != listReserva.end(); ++it){
        if(it->GetDataInicio().GetData() == reserva->GetDataInicio().GetData()){
            if(it->GetDataTermino().GetData() == reserva->GetDataTermino().GetData()){
                if(it->GetUsuario() == reserva->GetUsuario()){
                    return it;
                }
            }
        }
    }

    // Lista vazia ou reserva não encontrada
    return listReserva.end();
}

void CntrServAcomodacao::DescadastrarDisponibilidade(Acomodacao *acomodacao, Reserva *reserva) throw (invalid_argument){
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

bool CntrServAcomodacao::VerificarReservas(Acomodacao *acomodacao){
    list<Reserva>::iterator it;
    for(it = acomodacao->GetReserva().begin(); it != acomodacao->GetReserva().end(); ++it){
        if(it->GetUsuario() != NULL){
            return false;
        }
    }
    return true;
}

int CntrServAcomodacao::ApresentarListaAcomodacaoDoUsuario(Usuario* usuario){
    list<Acomodacao>::iterator it;
    int max = -1;
    if(!this->ListaAcomodacao.empty()){
        cout <<"\nAcomodaces Cadastradas:" << endl;
        for(it = this->ListaAcomodacao.begin(); it != this->ListaAcomodacao.end(); ++it){
            if(it->GetUsuario() == usuario){
                max++;
                cout << "------------------------------" << endl;
                cout << "Opcao (" << max << "):" << endl;
                cout << "Identificador: " << it->GetIdentificador().GetIdentificador() << endl;
                cout << "Tipo de Acomodação: " << it->GetTipoDeAcomodacao().GetTipoDeAcomodacao() << endl;
                cout << "Capacidade de Acomodacao: " << it->GetCapacidadeDeAcomodacao().GetCapacidadeDeAcomodacao() << endl;
                cout << "Cidade: " << it->GetCidade().GetNome() << endl;
                cout << "Estado: " << it->GetEstado().GetEstado() << endl;
                cout << "Valor da diária: " << it->GetDiaria().GetDiaria() << endl << endl;
            }

        }
        cout << "------------------------------" << endl;
    }
    // Lista está vazia ou não achou o usuário
    else{
        cout << "Não há acomodações cadastradas." << endl;
    }

    return max;

}

Acomodacao* CntrServAcomodacao::AcharAcomodacaoUsuarioSelecionada(Usuario* usuario, const int selecionado){
    list<Acomodacao>::iterator it;
    int i = 0;
    if(!this->ListaAcomodacao.empty()){
        for(it = this->ListaAcomodacao.begin(); it != this->ListaAcomodacao.end(); ++it){
            if(it->GetUsuario() == usuario){
                if(i == selecionado){
                    return &(*it);
                }
                else{
                    i++;
                }
            }

        }
    }
    else{
        cout << "Não há acomodações cadastradas" << endl;
    }
    // Lista está vazia ou não achou a acomodacao
    return NULL;


}

int CntrServAcomodacao::ApresentarListaDisponibiliades(Acomodacao *acomodacao){
    list<Reserva>::iterator it;
    int max = -1;
    if(!acomodacao->GetReserva().empty()){
        cout <<"\nDisponibilidades Livres Cadastradas:" << endl;
        for(it = acomodacao->GetReserva().begin(); it != acomodacao->GetReserva().end(); ++it){
            if(it->GetUsuario() == NULL){
                max++;
                cout << "------------------------------" << endl;
                cout << "Opcao (" << max << "):" << endl;
                cout << "Data de Inicio: " << it->GetDataInicio().GetData() << endl;
                cout << "Data de Termino: " << it->GetDataTermino().GetData() << endl;
            }

        }
        cout << "------------------------------" << endl;
    }
    // Lista está vazia ou nao ha disponibilidades livres
    else{
        cout << "Não há disponibilidades livres cadastradas." << endl;
    }

    return max;

}

Reserva* CntrServAcomodacao::AcharDisponibilidadeSelecionada(Acomodacao *acomodacao, const int selecionado){
    list<Reserva>::iterator it;
    int i = 0;
    if(!acomodacao->GetReserva().empty()){
        for(it = acomodacao->GetReserva().begin(); it != acomodacao->GetReserva().end(); ++it){
            if(it->GetUsuario() == NULL){
                if(i == selecionado){
                    return &(*it);
                }
                else{
                    i++;
                }
            }

        }
    }
    else{
        cout << "Não há disponibilidades cadastradas" << endl;
    }
    // Lista está vazia ou não achou a acomodacao
    return NULL;


}
