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