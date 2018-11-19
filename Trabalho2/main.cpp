#include "controladoras_apresentacao.h"
#include "controladoras_servico.h"

using namespace std;

int main(){
    CntrNavegacaoInicial cntrInicial;

    IAprUsuario* cntr_apr_usu;
    IServUsuario* cntr_serv_usu;

    cntr_apr_usu = new CntrAprUsuario();
    cntr_serv_usu = new CntrServUsuario();

    cntr_apr_usu->SetCntrAprUsuario(cntr_serv_usu);

    cntrInicial.executar(cntr_apr_usu, cntr_serv_usu);
    return 0;
}
