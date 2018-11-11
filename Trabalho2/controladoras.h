#ifndef CONTROLADORAS_H_
#define CONTROLADORAS_H_

#include "dominios_hotel.h"
#include "dominios_usuario.h"
#include "entidades.h"
#include "interfaces.h"

using namespace std;

//Classe controladora do serviço de autenticação
class CntrIUAutenticacao:public IUAutenticacao {

private:

    // Referencia para o servidor
    ILNAutenticacao *cntrLNAutenticacao;

public:
    
    ResultadoAutenticacao autenticar() throw(runtime_error);

    void setCntrLNAutenticacao(ILNAutenticacao*)
}

void inline CntrIUAutenticacao::setCntrLNAutenticacao(ILNAutenticacao *cntrLNAutenticacao){
    this->cntrLNAutenticacao = cntrLNAutenticacao;
}

//Classe Controladora na navegação
class CntrNavegacao:public CntrInteracao {
        //Constantes para identificar a opção escolhida.
        static const unsigned int NUMERO_OPCOES = 6;
        static const unsigned int OPCAO_ENCERRAR = 0;
        static const unsigned int OPCAO_CADASTRAR_ACOMODACAO = 1;
        static const unsigned int OPCAO_DECADASTRAR_ACOMODACAO = 2;
        static const unsigned int OPCAO_CADASTRAR_DISPONIBILIDADE  = 3;
        static const unsigned int OPCAO_DECADASTRAR_DISPONIBILIDADE = 4;
        static const unsigned int OPCAO_CADASTRAR_RESERVA = 5;
        static const unsigned int OPCAO_DECADASTRAR_RESERVA = 6;

        void apresentarOpcoes();
public:
       CntrNavegacao(){}
       void executar();
};

#endif