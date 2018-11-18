#ifndef CONTROLADORAS_APRESENTACAO_H_
#define CONTROLADORAS_APRESENTACAO_H_

#include "dominios_hotel.h"
#include "dominios_usuario.h"
#include "entidades.h"
#include "interfaces.h"
#include <list>
#include <iterator>
#include "dominios_usuario.h"
#include "controladoras_servico.h"

using namespace std;

//Classe Controladora na navegação-------------------------------------
class CntrNavegacaoInicial:public INavegacao{
        //Constantes para identificar a opção escolhida.
        static const unsigned int NUMERO_OPCOES = 2;
        static const unsigned int OPCAO_ENCERRAR = 0;
        static const unsigned int OPCAO_REGISTRAR_USUARIO = 1;
        static const unsigned int OPCAO_LOGAR_USUARIO = 2;

        void apresentarOpcoes();
public:
       CntrNavegacaoInicial(){}
       void executar();
};

//Classe controladora da apresentação do usuário--------------------------
class CntrAprUsuario:public IAprUsuario {

private:
    // Referencia para o servidor
    IAprUsuario *cntr_apr_usuario;
public:
    bool CadastrarUsuario(CntrServUsuario* cntr_serv_usu) throw(runtime_error);
    Usuario* AutenticarUsuario(CntrServUsuario* cntr_serv_usu) throw(runtime_error);
    void SetCntrAprUsuario(IAprUsuario*);
};

void inline CntrAprUsuario::SetCntrAprUsuario(IAprUsuario *cntr_apr_usuario){
    this->cntr_apr_usuario = cntr_apr_usuario;
}

#endif
