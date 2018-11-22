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

void CntrServUsuario::RemoverUsuario(Usuario* usuario) throw (invalid_argument){
    list<Usuario>::iterator usuario_aux = BuscarUsuario(usuario->GetIdentificador());
    if(usuario_aux != this->ListaUsuario.end()){
        this->ListaUsuario.erase(usuario_aux);
    }
    else{
        throw invalid_argument("Usuário inexistente.");
        return;
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

bool CntrServAcomodacao::RemoverAcomodacao(Acomodacao *acomodacao) throw (invalid_argument){
    list<Acomodacao>::iterator acomodacao_aux = BuscarAcomodacao(acomodacao->GetIdentificador());
    if(acomodacao_aux == this->ListaAcomodacao.end()){
        throw invalid_argument("Usuário inexistente.");
        return false;
    }
    if(this->VerificarReservas(acomodacao) == false){
        return false;
    }
    else{
        acomodacao_aux->GetReserva()->clear();
        acomodacao_aux->ExcluirListaReserva();
        this->ListaAcomodacao.erase(acomodacao_aux);
    }

    return true;

}

bool CntrServAcomodacao::CadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva){
    try{
        acomodacao->AddDisponibilidade(reserva);
    }
    catch (const invalid_argument &exp){
        return false;
    }

    return true;
}

list<Reserva>::iterator CntrServAcomodacao::BuscarReserva(Acomodacao *acomodacao, Reserva *reserva){
    list<Reserva> *listReserva = acomodacao->GetReserva();
    list<Reserva>::iterator it;
    int i = 0;
    for(it = listReserva->begin(); i < listReserva->size(); ++it,i++){
        if(it->GetDataInicio().GetData() == reserva->GetDataInicio().GetData()){
            if(it->GetDataTermino().GetData() == reserva->GetDataTermino().GetData()){
                if(it->GetUsuario() == reserva->GetUsuario()){
                    return it;
                }
            }
        }
    }

    // Lista vazia ou reserva não encontrada
    return listReserva->end();
}

bool CntrServAcomodacao::DescadastrarDisponibilidade(Acomodacao *acomodacao, Reserva *reserva) throw (invalid_argument){
    list<Reserva>::iterator local = this->BuscarReserva(acomodacao, reserva);

    if(local == acomodacao->GetReserva()->end()){
        throw invalid_argument("Disponibilidade Inexstente");
        return false;
    }

    if(local->GetUsuario() != NULL){
        throw invalid_argument("Acomodacao alugada para esse periodo");
        return false;
    }

    acomodacao->GetReserva()->erase(local);

    return true;
}

bool CntrServAcomodacao::VerificarReservas(Acomodacao *acomodacao){
    list<Reserva>::iterator it;
    int i = 0;
    for(it = acomodacao->GetReserva()->begin(); i < acomodacao->GetReserva()->size(); ++it, i++){
        if(it->GetUsuario() != NULL){
            return false;
        }
    }
    return true;
}

int CntrServAcomodacao::ApresentarListaAcomodacaoDoUsuario(Usuario* usuario){
    list<Acomodacao>::iterator it;
    int max = -1;
    int i = 0;
    if(!this->ListaAcomodacao.empty()){
        cout <<"\nAcomodaces Cadastradas:" << endl;
        for(it = this->ListaAcomodacao.begin(); i < this->ListaAcomodacao.size(); ++it, i++){
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

int CntrServAcomodacao::ApresentarListaAcomodacoes(){
    list<Acomodacao>::iterator it;
    int max = -1;
    int i = 0;
    if(!this->ListaAcomodacao.empty()){
        cout <<"\nAcomodaces Cadastradas:" << endl;
        for(it = this->ListaAcomodacao.begin(); i < this->ListaAcomodacao.size(); ++it, i++){
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
    int j = 0;
    if(!this->ListaAcomodacao.empty()){
        for(it = this->ListaAcomodacao.begin(); j < this->ListaAcomodacao.size(); ++it,j++){
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

Acomodacao* CntrServAcomodacao::AcharAcomodacaoSelecionada(const int selecionado){
    list<Acomodacao>::iterator it;
    int i = 0;
    int j = 0;
    if(!this->ListaAcomodacao.empty()){
        for(it = this->ListaAcomodacao.begin(); j < this->ListaAcomodacao.size(); ++it,j++){
            if(i == selecionado){
                return &(*it);    
            }
            i++;
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
    int i=0;
    cout << acomodacao->GetReserva()->size() << endl;
    if(!acomodacao->GetReserva()->empty()){
        cout <<"\nDisponibilidades Livres Cadastradas:" << endl;
        for(it = acomodacao->GetReserva()->begin(); i < acomodacao->GetReserva()->size(); ++it, i++){
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
    unsigned int j = 0;
    if(!acomodacao->GetReserva()->empty()){
        for(it = acomodacao->GetReserva()->begin(); j < acomodacao->GetReserva()->size(); ++it, j++){
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

bool CntrServAcomodacao::CadastrarReserva(Reserva* reserva, Usuario* usuario){
    if(reserva->GetUsuario() == NULL){
        reserva->SetUsuario(usuario);
        return true;
    }
    else{
        return false;
    }

}

bool CntrServAcomodacao::BuscarAcomodacoesUsuario(Usuario* usuario){
    list<Acomodacao>::iterator it;
    Identificador identificador_aux;

    if(!this->ListaAcomodacao.empty()){
        for(it = this->ListaAcomodacao.begin(); it != this->ListaAcomodacao.end(); ++it){

            if(it->GetUsuario() == usuario){
                return true;
            }
        }
    }
    // Não há acomdações cadastradas nesse usuário
    return false;
}

int CntrServAcomodacao::ApresentarListaReservasUsuario(Acomodacao *acomodacao, Usuario *usuario){
     list<Reserva>::iterator it;
     int max = -1;
     int i=0;
     if(!acomodacao->GetReserva()->empty()){
         cout <<"\nReservas efetuadas:" << endl;
         for(it = acomodacao->GetReserva()->begin(); i < acomodacao->GetReserva()->size(); ++it, i++){
             if(it->GetUsuario() == usuario){
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
         cout << "Não há desse usuario efetuadas." << endl;
     }

     return max;

 }

 Reserva* CntrServAcomodacao::AcharReservaSelecionada(Acomodacao *acomodacao, Usuario *usuario, const int selecionado){
     list<Reserva>::iterator it;
     int i = 0;
     unsigned int j = 0;
     if(!acomodacao->GetReserva()->empty()){
         for(it = acomodacao->GetReserva()->begin(); j < acomodacao->GetReserva()->size(); ++it, j++){
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
         cout << "Não há disponibilidades cadastradas" << endl;
     }
     // Lista está vazia ou não achou a acomodacao
     return NULL;
 }

 bool CntrServAcomodacao::DescadastrarReserva(Reserva* reserva, Usuario *usuario){
     if(reserva->GetUsuario() == usuario){
         reserva->SetUsuario(NULL);
         return true;
     }
     else   
         return false;
 }