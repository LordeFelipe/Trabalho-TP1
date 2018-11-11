#ifndef CONTROLADORAS_H_
#define CONTROLADORAS_H_

#include "dominios_hotel.h"
#include "dominios_usuario.h"
#include "entidades.h"

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

#endif