#include "controladoras_apresentacao.h"
#include "controladoras_servico.h"

using namespace std;

int main(){
    CntrNavegacaoInicial cntrInicial;

    IAprUsuario* cntr_apr_usu;
    IAprAcomodacao* cntr_apr_aco;
    IServUsuario* cntr_serv_usu;
    IServAcomodacao* cntr_serv_aco;

    // Inicializar controladoras
    cntr_apr_usu = new CntrAprUsuario();
    cntr_apr_aco = new CntrAprAcomodacao();
    cntr_serv_usu = new CntrServUsuario();
    cntr_serv_aco = new CntrServAcomodacao();

    // Estabelecer ligações entre controladoras de serviço e apresentação
    cntr_apr_usu->SetCntrAprUsuario(cntr_serv_usu);
    cntr_apr_aco->SetCntrAprAcomodacao(cntr_serv_aco);

    // Chamar função que executa o sistema, a partir da parte de apresentação inicial
    cntrInicial.executar(cntr_apr_usu, cntr_apr_aco);

    // Deletar controladoras
    delete cntr_apr_aco;
    delete cntr_serv_aco;
    delete cntr_apr_usu;
    delete cntr_serv_usu;

    return 0;
}
