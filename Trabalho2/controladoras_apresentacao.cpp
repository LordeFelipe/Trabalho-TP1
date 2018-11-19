
#include "controladoras_apresentacao.h"
#include <iostream>
using namespace std;

//Métodos da classe de apresentação de usuário---------------------------------------

bool CntrAprUsuario::CadastrarUsuario() throw(runtime_error){

    bool resultado;
    Identificador identificador;
    Senha senha;
    Nome nome;
    string entrada_id, entrada_senha, entrada_nome;

    // Solicitar dados
    while(true){
        try{
            cout << "Crie um identificador com 5 digitos contendo apenas letras minusculas." << endl;
            cout << "Digite seu Identificador: ";
            cin >> entrada_id;
            identificador.SetIdentificador(entrada_id);
            cout << "Crie uma senha com 8 digitos contendo ao menos uma letra minuscula, uma maiscula, um numero e um digito (! # $ % &)." << endl;
            cout << "Digite sua Senha: ";
            cin >> entrada_senha;
            senha.SetSenha(entrada_senha);
            cout << "Crie um nome com 15 digitos." << endl;
            cout << "Digite seu Nome: ";
            cin >> entrada_nome;
            nome.SetNome(entrada_nome);
            break;
        }
        catch (const invalid_argument &exp){
            cout << endl << "Dado em formato incorreto.\n" << endl;
            return false;
        }
    }

    //Informar resultado da autenticação
    resultado = this->cntr_serv_usuario->AdicionarUsuario(identificador, senha, nome);

    if(resultado == false){
        cout << endl << "Erro: Usuário já existe" << endl;
        return false;
    }
    else{
        cout << endl << "Usuário registrado com sucesso" << endl;
        return true;
    }
}

Usuario* CntrAprUsuario::AutenticarUsuario() throw(runtime_error){

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
            cout << endl << "Dado em formato incorreto.\n" << endl;
        }
    }

    // Solicitar autenticação.
    usuario = this->cntr_serv_usuario->AutenticarUsuario(identificador, senha);

    // Informar resultado da autenticação.
    if(usuario == NULL){
        cout << endl << "Falha na autenticacao." << endl;
    }
    return usuario;
}

bool CntrAprUsuario::CadastrarConta(Usuario *usuario) throw(runtime_error){

    bool resultado;
    NumeroConta numero;
    Agencia agencia;
    Banco banco;
    string entrada_num, entrada_agencia, entrada_banco;

    // Solicitar dados
    while(true){
        try{
            cout << "Digite o numero da conta corrente com 6 digitos." << endl;
            cout << "Digite o Numero da sua Conta: ";
            cin >> entrada_num;
            numero.SetConta(entrada_num);
            cout << "Crie o numero da sua agencia com 5 digitos." << endl;
            cout << "Digite sua Agencia: ";
            cin >> entrada_agencia;
            agencia.SetAgencia(entrada_agencia);
            cout << "Crie o numero do seu banco com 3 digitos." << endl;
            cout << "Digite seu Banco: ";
            cin >> entrada_banco;
            banco.SetBanco(entrada_banco);
            break;
        }
        catch (const invalid_argument &exp){
            cout << endl << "Dado em formato incorreto.\n" << endl;
            return false;
        }
    }

    //Criar Conta
    ContaCorrente conta;
    conta.SetAgencia(agencia);
    conta.SetBanco(banco);
    conta.SetNumero(numero);

    //Informar resultado da criacao
    resultado = this->cntr_serv_usuario->AdicionarConta(usuario, conta);

    if(resultado == false){
        cout << endl << "Nao foi possivel cadastrar a conta.\n" << endl;
        return false;
    }
    else{
        cout << endl << "Conta Cadastrada com Sucesso.\n" << endl;
        return true;
    }
}

bool CntrAprUsuario::CadastrarCartao(Usuario *usuario) throw(runtime_error){

    bool resultado;
    NumeroCartao numero;
    Validade val;
    string entrada_num, entrada_val;

    // Solicitar dados
    while(true){
        try{
            cout << "Digite um numero valido de cartao com 16 digitos." << endl;
            cout << "Digite o Numero do seu Cartao: ";
            cin >> entrada_num;
            numero.SetNumero(entrada_num);
            cout << "Digite a validade do seu cartao no formato MM/AA." << endl;
            cout << "Digite a Validade do Cartao: ";
            cin >> entrada_val;
            val.SetVal(entrada_val);
            break;
        }
        catch (const invalid_argument &exp){
            cout << endl << "Dado em formato incorreto.\n" << endl;
            return false;
        }
    }

    //Criar Conta
    Cartao cartao;
    cartao.SetValidade(val);
    cartao.SetNumero(numero);

    //Informar resultado da criacao
    resultado = this->cntr_serv_usuario->AdicionarCartao(usuario, cartao);

    if(resultado == false){
        cout << endl << "Nao foi possivel cadastrar o cartao.\n" << endl;
        return false;
    }
    else{
        cout << endl << "Cartao Cadastrado com Sucesso.\n" << endl;
        return true;
    }
}

//Métodos da classe de apresentação da acomodacao-------------------------------------

bool CntrAprAcomodacao::CadastrarAcomodacao() throw(runtime_error){

    bool resultado;
    Identificador identificador;
    TipoDeAcomodacao tipo; 
    CapacidadeDeAcomodacao capacidade; 
    Nome cidade;
    Estado estado; 
    Diaria diaria;
    string entrada_id, entrada_tipo, entrada_cidade, entrada_estado;
    int entrada_cap;
    float entrada_diaria;

    // Solicitar dados
    while(true){
        try{
            cout << "Crie um identificador com 5 digitos contendo apenas letras minusculas." << endl;
            cout << "Digite o Identificador: ";
            cin >> entrada_id;
            identificador.SetIdentificador(entrada_id);
            cout << "Digite o Tipo de Acomodacao (Apartamento, Casa ou Flat)." << endl;
            cin >> entrada_tipo;
            tipo.SetTipoDeAcomodacao(entrada_tipo);
            cout << "Digite sua Cidade com 15 digitos." << endl;
            cin >> entrada_cidade;
            cidade.SetNome(entrada_cidade);
            cout << "Digite seu Estado (AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE, PI, RJ, RN, RS, RO, RR, SC, SP, SE ou TO)." << endl;
            cin >> entrada_estado;
            estado.SetEstado(entrada_estado);
            cout << "Digite a Diaria da Acomodacao (Valor de 1 a 10000 Reais)." << endl;
            cin >> entrada_diaria;
            diaria.SetDiaria(entrada_diaria);
            cout << "Digite a Capacidade da Acomodacao (Valor inteiro de 1 a 9)." << endl;
            cin >> entrada_cap;
            capacidade.SetCapacidadeDeAcomodacao(entrada_cap);
            break;
        }
        catch (const invalid_argument &exp){
            cout << endl << "Dado em formato incorreto.\n" << endl;
            return false;
        }
    }

    //Criar Objeto para a Acomodacao
    Acomodacao acomodacao;
    acomodacao.SetCapacidaDeAcomodacao(capacidade);
    acomodacao.SetCidade(cidade);
    acomodacao.SetDiaria(diaria);
    acomodacao.SetEstado(estado);
    acomodacao.SetIdentificador(identificador);
    acomodacao.SetTipoDeAcomodacao(tipo);

    //Informar resultado da inserção
    resultado = this->cntr_serv_acomodacao->AdicionarAcomodacao(acomodacao);

    if(resultado == false){
        cout << endl << "Erro: Acomodacao com esse identificador já existe" << endl;
        return false;
    }
    else{
        cout << endl << "Acomodacao registrada com sucesso" << endl;
        return true;
    }
}


//Métodos da classe CntrNavegacaoInicial----------------------------------------------

void CntrNavegacaoInicial::apresentarOpcoes(){
    cout << "--- Servicos disponiveis ---" << endl << endl;
    cout << "0 - Encerrar." << endl;
    cout << "1 - Registrar Usuário." << endl;
    cout << "2 - Logar no Sistema." << endl;
}

void CntrNavegacaoInicial::executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco){
        CntrNavegacaoPrincipal cntrPrinc;
        
        unsigned int escolha;

        Usuario* usuario;

        while (true) {
                escolha = -1;
                while(escolha == -1 || escolha > NUMERO_OPCOES){
                    apresentarOpcoes();
                    cout << "Escolha a opcao : ";
                    cin >> escolha;
                    switch (escolha) {
                        case OPCAO_REGISTRAR_USUARIO:
                            cntr_apr_usu->CadastrarUsuario();
                            cout << "\n";
                            break;
                        case OPCAO_LOGAR_USUARIO:
                            usuario = cntr_apr_usu->AutenticarUsuario();

                            //Caso seja um sucesso a autenticação
                            if(usuario != NULL){
                                cout << "\nUsuario Autenticado com Sucesso.\n" << endl;
                                //Chama a próxima interface de texto
                                cntrPrinc.executar(cntr_apr_usu, cntr_apr_aco, usuario);
                                usuario = NULL;
                                cout << "\n";
                            }
                            break;
                        case OPCAO_ENCERRAR :
                            return;
                    }
                }
        }
}

//Métodos da classe CntrNavegacaoPrincipal--------------------------------------------

void CntrNavegacaoPrincipal::apresentarOpcoes(){
    cout << "--- Servicos disponiveis ---" << endl << endl;
    cout << "0 - Deslogar." << endl;
    cout << "1 - Opcoes de Acomodacoes." << endl;
    cout << "2 - Opcoes de Reserva." << endl;
    cout << "3 - Excluir Usuario." << endl;
}

void CntrNavegacaoPrincipal::executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco, Usuario* usuario){
        unsigned int escolha;

        CntrNavegacaoAcomodacao cntrAco;
        CntrNavegacaoReserva cntrRes;

        while (true) {
                escolha = -1;
                while(escolha == -1 || escolha > NUMERO_OPCOES){
                    apresentarOpcoes();
                    cout << "Escolha a opcao : ";
                    cin >> escolha;
                    switch (escolha) {
                        case OPCAO_ACOMODACAO:
                            if(usuario->GetConta() == NULL){
                                cout << "\nConta Corrente nao encontrada. Cadastre uma agora.\n" << endl;
                                cntr_apr_usu->CadastrarConta(usuario);
                            }
                            if(usuario->GetConta() != NULL){
                                cout << "\n";
                                cntrAco.executar(cntr_apr_usu, cntr_apr_aco, usuario);
                            }
                            break;
                        case OPCAO_RESERVA:
                            if(usuario->GetCartao() == NULL){
                                cout << "\nCartao nao encontrado. Cadastre um agora.\n" << endl;
                                cntr_apr_usu->CadastrarCartao(usuario);
                            }
                            if(usuario->GetCartao() != NULL){
                                cout << "\n";
                                cntrRes.executar(cntr_apr_usu, cntr_apr_aco, usuario);
                            }
                            break;
                        case OPCAO_EXCLUIR_USUARIO:
                            break;
                        case OPCAO_DESLOGAR :
                            return;
                    }
                }
        }
}

//Métodos da classe CntrNavegacaoAcomodacao--------------------------------------------

void CntrNavegacaoAcomodacao::apresentarOpcoes(){
    cout << "--- Servicos disponiveis ---" << endl << endl;
    cout << "0 - Voltar ao Menu Principal." << endl;
    cout << "1 - Cadastrar Acomodacao." << endl;
    cout << "2 - Decadastar Acomodacao." << endl;
    cout << "3 - Cadastar Disponibilidade." << endl;
    cout << "4 - Decadastar Disponibilidade." << endl;
}

void CntrNavegacaoAcomodacao::executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco, Usuario* usuario){
        unsigned int escolha;

        while (true) {
                escolha = -1;
                while(escolha == -1 || escolha > NUMERO_OPCOES){
                    apresentarOpcoes();
                    cout << "Escolha a opcao : ";
                    cin >> escolha;
                    switch (escolha) {
                        case OPCAO_CADASTRAR_ACOMODACAO:
                            cntr_apr_aco->CadastrarAcomodacao();
                            cout << "\n";
                            break;
                        case OPCAO_DECADASTRAR_ACOMODACAO:
                            break;
                        case OPCAO_CADASTRAR_DISPONIBILIDADE:
                            break;
                        case OPCAO_DECADASTRAR_DISPONIBILIDADE:
                            break;
                        case OPCAO_VOLTAR :
                            cout << "\n";  
                            return;
                    }
                }
        }
}

//Métodos da classe CntrNavegacaoReserva------------------------------------------------

void CntrNavegacaoReserva::apresentarOpcoes(){
    cout << "--- Servicos disponiveis ---" << endl << endl;
    cout << "0 - Voltar ao Menu Principal." << endl;
    cout << "1 - Fazer Reserva." << endl;
    cout << "2 - Cancelar Reserva." << endl;
}

void CntrNavegacaoReserva::executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco, Usuario* usuario){
        unsigned int escolha;

        while (true) {
                escolha = -1;
                while(escolha == -1 || escolha > NUMERO_OPCOES){
                    apresentarOpcoes();
                    cout << "Escolha a opcao : ";
                    cin >> escolha;
                    switch (escolha) {
                        case OPCAO_FAZER_RESERVA:
                            break;
                        case OPCAO_DESFAZER_RESERVA:
                            break;
                        case OPCAO_VOLTAR :
                            cout << "\n";
                            return;
                    }
                }
        }
}