#include "controladoras_servico.h"
#include <iostream>
using namespace std;

//Métodos da classe CntrServUsuario----------------------------------------

// ----Métodos que lidam com os usuarios----

// Método que adiciona o usuario com as informações passadas dentro da lista de usuários
bool CntrServUsuario::AdicionarUsuario(Identificador identificador, Senha senha, Nome nome){

    // Criar entidade do usuario
    Usuario usuario;
    usuario.SetIdentificador(identificador);
    usuario.SetSenha(senha);
    usuario.SetNome(nome);
    usuario.SetCartao(NULL);
    usuario.SetConta(NULL);

    //Caso seja encontrado um usuário igual ao q se deseja registrar, retorna false
    list<Usuario>::iterator usuario_repetido = this->BuscarUsuario(identificador);
    if(usuario_repetido != this->ListaUsuario.end()){
        return false;
    }

    // Adicionar usuario na lista
    this->ListaUsuario.push_front(usuario);
    return true;
}

// Método que autentica um identificador e uma senha passados com o banco de dados do sistema
Usuario* CntrServUsuario::AutenticarUsuario(Identificador &id, Senha &senha){
    //Achar usuario na lista
    list<Usuario>::iterator usuario = this->BuscarUsuario(id);

    // Retornar NULL caso usuario nao exista
    if(usuario == this->ListaUsuario.end()){
        return NULL;
    }
    // Retornar NULL caso senha não bata com a cadastrada
    else if(usuario->GetSenha().GetSenha() != senha.GetSenha()){
        return NULL;
    }
    // Retorna usuario caso contrário
    else{
        return &(*usuario);
    }
}

// Método que busca um usuário na lista pelo seu identificador
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

// Método que remove um usuário da lista de usuários cadastrados
void CntrServUsuario::RemoverUsuario(Usuario* usuario) throw (invalid_argument){

    list<Usuario>::iterator usuario_aux = BuscarUsuario(usuario->GetIdentificador());
    if(usuario_aux != this->ListaUsuario.end()){
        // Apagar usuário da lista
        this->ListaUsuario.erase(usuario_aux);
    }
    else{
        // Caso o usuario nao seja encontrado
        throw invalid_argument("Usuário inexistente.");
        return;
    }
}

// Método que associa uma conta a um usuário
bool CntrServUsuario::AdicionarConta(Usuario *usuario, ContaCorrente conta){

    list<Usuario>::iterator it = this->BuscarUsuario(usuario->GetIdentificador());
    if(it == this->ListaUsuario.end()){
        return false;
    }

    it->SetConta(&conta);
    return true;
}

// Método que associa um cartao a um usuário
bool CntrServUsuario::AdicionarCartao(Usuario *usuario, Cartao cartao){

    list<Usuario>::iterator it = this->BuscarUsuario(usuario->GetIdentificador());
    if(it == this->ListaUsuario.end()){
        return false;
    }

    it->SetCartao(&cartao);
    return true;
}

//Métodos da classe CntrServAcomodacao----------------------------------------

// ----Métodos que lidam com as acomodações----

// Método que adiciona uma acomodação a lista de acomodações do sistema
bool CntrServAcomodacao::AdicionarAcomodacao(Acomodacao &acomodacao){
    if(this->BuscarAcomodacao(acomodacao.GetIdentificador()) == this->ListaAcomodacao.end()){
        this->ListaAcomodacao.push_front(acomodacao);
        return true;
    }
    else
        // Se acomodação com o identificador passado já existe, não permitir a inserção
        return false;
}

// Método que remove uma acomodação cadastrada da lista
bool CntrServAcomodacao::RemoverAcomodacao(Acomodacao *acomodacao) throw (invalid_argument){
    list<Acomodacao>::iterator acomodacao_aux = BuscarAcomodacao(acomodacao->GetIdentificador());
    // Retornar falso caso a acomodacao nao exista
    if(acomodacao_aux == this->ListaAcomodacao.end()){
        throw invalid_argument("Usuário inexistente.");
        return false;
    }
    // Retornar falso caso houver reservas efetuadas na acomodação
    if(this->VerificarReservas(acomodacao) == false){
        return false;
    }
    else{
        // Deletar lista de reservas da acomodacao
        acomodacao_aux->GetReserva()->clear();
        acomodacao_aux->ExcluirListaReserva();
        // Deletar acomodação
        this->ListaAcomodacao.erase(acomodacao_aux);
    }

    return true;

}

// Método que imprime na tela todas as acomodações cadastradas no sistema
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

// Método que imprime na tela todas as acomodações associadas a um usuário no sistema
int CntrServAcomodacao::ApresentarListaAcomodacaoDoUsuario(Usuario* usuario){
    list<Acomodacao>::iterator it;
    int max = -1;
    int i = 0;
    if(!this->ListaAcomodacao.empty()){
        cout <<"\nAcomodaces Cadastradas:" << endl;
        for(it = this->ListaAcomodacao.begin(); i < this->ListaAcomodacao.size(); ++it, i++){
            // Verificar se acomoção pertence ao usuário
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

// Método que busca uma acomodação pelo seu identificador
list<Acomodacao>::iterator CntrServAcomodacao::BuscarAcomodacao(Identificador identificador){
    list<Acomodacao>::iterator it;
    Identificador identificador_aux;

    if(!this->ListaAcomodacao.empty()){
        for(it = this->ListaAcomodacao.begin(); it != this->ListaAcomodacao.end(); ++it){

            identificador_aux = it->GetIdentificador();

            if(identificador_aux.GetIdentificador() == identificador.GetIdentificador()){
                // Retornar posição da lista em que os identificadoes bateram
                return it;

            }
        }
    }
    // Lista está vazia ou não achou o usuário
    return this->ListaAcomodacao.end();
}

// Método que busca se há uma acomodação relacionada a um usuário no sistema
bool CntrServAcomodacao::BuscarAcomodacoesUsuario(Usuario* usuario){
    list<Acomodacao>::iterator it;

    if(!this->ListaAcomodacao.empty()){
        for(it = this->ListaAcomodacao.begin(); it != this->ListaAcomodacao.end(); ++it){
            // Se houver alguma acomodação cadastrada pelo usuario, retornar true
            if(it->GetUsuario() == usuario){
                return true;
            }
        }
    }
    // Não há acomdações cadastradas nesse usuário
    return false;
}

// Método que acha uma acomodação de acordo com o número selecionado pelo usuário do sistema
Acomodacao* CntrServAcomodacao::AcharAcomodacaoSelecionada(const int selecionado){
    list<Acomodacao>::iterator it;
    int i = 0;
    int j = 0;
    if(!this->ListaAcomodacao.empty()){
        for(it = this->ListaAcomodacao.begin(); j < this->ListaAcomodacao.size(); ++it,j++){
            // Retornar a acomodacao que bate com a posicao da lista com o numero passado
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

// Método que acha uma acomodação de um usuário de acordo com o número selecionado por este
Acomodacao* CntrServAcomodacao::AcharAcomodacaoUsuarioSelecionada(Usuario* usuario, const int selecionado){
    list<Acomodacao>::iterator it;
    int i = 0;
    int j = 0;
    if(!this->ListaAcomodacao.empty()){
        for(it = this->ListaAcomodacao.begin(); j < this->ListaAcomodacao.size(); ++it,j++){
            if(it->GetUsuario() == usuario){
                // Retornar a acomodacao do usuario que bate com a posicao da lista com o numero passado
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

// ----Métodos que lidam com os periodos de disponibilidade----

// Método que cadastra um periodo de disponibilidade a uma acomodação
bool CntrServAcomodacao::CadastrarDisponibilidade(Acomodacao *acomodacao, Reserva &reserva){
    try{
        acomodacao->AddDisponibilidade(reserva);
    }
    catch (const invalid_argument &exp){
        return false;
    }

    return true;
}

// Método que descadastra um periodo de disponibilidade de uma acomodação
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

// Método que apresenta na tela a lista de disponibilidades de uma acomodação 
int CntrServAcomodacao::ApresentarListaDisponibiliades(Acomodacao *acomodacao){
    list<Reserva>::iterator it;
    int max = -1;
    int i=0;
    cout << acomodacao->GetReserva()->size() << endl;
    if(!acomodacao->GetReserva()->empty()){
        cout <<"\nDisponibilidades Livres Cadastradas:" << endl;
        for(it = acomodacao->GetReserva()->begin(); i < acomodacao->GetReserva()->size(); ++it, i++){
            // Imprimir se não há usuario na reserva
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

// Método que retorna a disponibilidade de uma acomodação de acordo com o número selecionado pelo usuário
Reserva* CntrServAcomodacao::AcharDisponibilidadeSelecionada(Acomodacao *acomodacao, const int selecionado){
    list<Reserva>::iterator it;
    int i = 0;
    unsigned int j = 0;
    if(!acomodacao->GetReserva()->empty()){
        for(it = acomodacao->GetReserva()->begin(); j < acomodacao->GetReserva()->size(); ++it, j++){
            if(it->GetUsuario() == NULL){
                // Retornar a disponibilidade da acomodacao que bate com a posicao da lista com o numero passado
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

// ----Métodos que lidam com as reservas----

// Método que cadastra a reserva para um usuário
bool CntrServAcomodacao::CadastrarReserva(Reserva* reserva, Usuario* usuario){
    // Verificar se já há usuário com a reserva
    if(reserva->GetUsuario() == NULL){
        reserva->SetUsuario(usuario);
        return true;
    }
    else{
        return false;
    }

}

// Método que descadastra a reserva feita por um usuário
bool CntrServAcomodacao::DescadastrarReserva(Reserva* reserva, Usuario *usuario){
    // Verificar se usuário é o dono da reserva
    if(reserva->GetUsuario() == usuario){
        reserva->SetUsuario(NULL);
        return true;
    }
    else   
        return false;
}

// Método que imprime na tela as reservas efetuadas por um usuário
int CntrServAcomodacao::ApresentarListaReservasUsuario(Acomodacao *acomodacao, Usuario *usuario){
    list<Reserva>::iterator it;
    int max = -1;
    int i=0;
    if(!acomodacao->GetReserva()->empty()){
        cout <<"\nReservas efetuadas:" << endl;
        for(it = acomodacao->GetReserva()->begin(); i < acomodacao->GetReserva()->size(); ++it, i++){
            // Imprimir se areserva for do usuário
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
    // Lista está vazia ou nao ha reservas do usuario
    else{
        cout << "Não há desse usuario efetuadas." << endl;
    }

    return max;

}

// Método que busca a reserva na lista de acomodações
list<Reserva>::iterator CntrServAcomodacao::BuscarReserva(Acomodacao *acomodacao, Reserva *reserva){
    list<Reserva> *listReserva = acomodacao->GetReserva();
    list<Reserva>::iterator it;
    int i = 0;
    for(it = listReserva->begin(); i < listReserva->size(); ++it,i++){
        if(it->GetDataInicio().GetData() == reserva->GetDataInicio().GetData()){
            if(it->GetDataTermino().GetData() == reserva->GetDataTermino().GetData()){
                if(it->GetUsuario() == reserva->GetUsuario()){
                    // Retorna se achou a reserva na lista
                    return it;
                }
            }
        }
    }

    // Lista vazia ou reserva não encontrada
    return listReserva->end();
}

// Método que verifica se há reservas efetuadas por um usuário
bool CntrServAcomodacao::BuscarReservasUsuario(Usuario* usuario){
    list<Acomodacao>::iterator it_aco;
    list<Reserva>::iterator it_res;
    list<Reserva> lista;

    if(!this->ListaAcomodacao.empty()){
        for(it_aco = this->ListaAcomodacao.begin(); it_aco != this->ListaAcomodacao.end(); ++it_aco){
            lista = *it_aco->GetReserva();
            if(!lista.empty()){
                for(it_res = lista.begin(); it_res != lista.end(); ++it_res){
                    // Retorna true caso ache alguma reserva efetuada pelo usuario
                    if(it_res->GetUsuario() == usuario){
                        return true;
                    }        
            
                }
            }
        }
    }
    // Não há reservas cadastradas nesse usuário
    return false;
}

// Método que acha a reserva selecionada de uma acomodação de acordo com o número passado pelo usuário
Reserva* CntrServAcomodacao::AcharReservaSelecionada(Acomodacao *acomodacao, Usuario *usuario, const int selecionado){
    list<Reserva>::iterator it;
    int i = 0;
    unsigned int j = 0;
    if(!acomodacao->GetReserva()->empty()){
        for(it = acomodacao->GetReserva()->begin(); j < acomodacao->GetReserva()->size(); ++it, j++){
            if(it->GetUsuario() == usuario){
                if(i == selecionado){
                    // Retornar a reserva que bate com a posicao da lista com o numero passado
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

// Método que verifica se a acomodação tem alguma reserva efetuada
bool CntrServAcomodacao::VerificarReservas(Acomodacao *acomodacao){
    list<Reserva>::iterator it;
    int i = 0;
    for(it = acomodacao->GetReserva()->begin(); i < acomodacao->GetReserva()->size(); ++it, i++){
        // Retorna false caso tenha alguma reserva associada a um usuario na acomodacao
        if(it->GetUsuario() != NULL){
            return false;
        }
    }
    return true;
}
