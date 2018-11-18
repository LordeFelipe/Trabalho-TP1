
#include "controladoras_apresentacao.h"
#include <iostream>
using namespace std;

//Métodos da classe CntrNavegacaoInicial----------------------------------------

void CntrNavegacaoInicial::apresentarOpcoes(){
    cout << "--- Servicos disponiveis ---" << endl << endl;
    cout << "0 - Encerrar." << endl;
    cout << "1 - Registrar Usuário." << endl;
    cout << "2 - Logar no Sistema." << endl;
}

void CntrNavegacaoInicial::executar(){
        unsigned int escolha;
        CntrServUsuario* cntr_serv_usu = new CntrServUsuario;
        CntrAprUsuario* cntr_apr_usu = new CntrAprUsuario;
        Usuario* usuario;

        while (true) {
                escolha = -1;
                while(escolha == -1 || escolha > NUMERO_OPCOES){
                    apresentarOpcoes();
                    cout << "Escolha a opcao : ";
                    cin >> escolha;
                    switch (escolha) {
                        case OPCAO_REGISTRAR_USUARIO:
                            cntr_apr_usu->CadastrarUsuario(cntr_serv_usu);
                            break;
                        case OPCAO_LOGAR_USUARIO:
                            usuario = cntr_apr_usu->AutenticarUsuario(cntr_serv_usu);

                            //Caso seja um sucesso a autenticação
                            if(usuario != NULL){
                                cout << "Esse trabalho eh um lixo";
                                //Chama a próxima interface de texto
                            }
                            break;
                        case OPCAO_ENCERRAR :
                            return;
                    }
                }
        }
}

//Métodos da classe de apresentação de usuário---------------------------------------

bool CntrAprUsuario::CadastrarUsuario(CntrServUsuario* cntr_serv_usu) throw(runtime_error){

    bool resultado;
    Identificador identificador;
    Senha senha;
    string entrada_id, entrada_senha;

    // Solicitar dados
    while(true){
        try{
            cout << "Digite seu Identificador:";
            cin >> entrada_id;
            identificador.SetIdentificador(entrada_id);
            cout << "Digite sua Senha:";
            cin >> entrada_senha;
            senha.SetSenha(entrada_senha);
            break;
        }
        catch (const invalid_argument &exp){
            cout << endl << "Dado em formato incorreto." << endl;
            return false;
        }
    }

    //Informar resultado da autenticação
    resultado = cntr_serv_usu->AdicionarUsuario(identificador, senha);

    if(resultado == false){
        cout << endl << "Erro: Usuário já existe" << endl;
        return false;
    }
    else{
        cout << endl << "Usuário registrado com sucesso" << endl;
        return true;
    }
}

Usuario* CntrAprUsuario::AutenticarUsuario(CntrServUsuario* cntr_serv_usu) throw(runtime_error){

    Usuario* usuario;
    Identificador identificador;
    Senha senha;
    string entrada_id, entrada_senha;
    // Solicitar matricula e senha.

    while(true) {

        try {
            cout << "Digite seu identificador : ";
            cin >> entrada_id;
            identificador.SetIdentificador(entrada_id);
            cout << "Digite sua senha : ";
            cin >> entrada_senha;
            senha.SetSenha(entrada_senha);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Dado em formato incorreto." << endl;
        }
    }

    // Solicitar autenticação.
    usuario = cntr_serv_usu->AutenticarUsuario(identificador, senha);

    // Informar resultado da autenticação.
    if(usuario == NULL){
        cout << endl << "Falha na autenticacao." << endl;
    }
    return usuario;
}
