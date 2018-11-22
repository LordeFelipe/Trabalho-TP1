
#include "controladoras_apresentacao.h"
#include <iostream>

using namespace std;

//Métodos da classe de apresentação de usuário------------------------------------------------

//Método Responsável por cadastrar o usuário informado na entrada
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
            cin.ignore();
            getline(cin,entrada_nome);
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

// Método responsável por verificar se o usuário de entrada está cadastrado 
Usuario* CntrAprUsuario::AutenticarUsuario() throw(runtime_error){

    Usuario* usuario;
    Identificador identificador;
    Senha senha;
    string entrada_id, entrada_senha;

    //Solicitar dados
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

//Método responsável por verificar se é possível remover um usuário e então excluí-lo
bool CntrAprUsuario::RemoverUsuario(Usuario* usuario, IAprAcomodacao* cntr_apr_aco) throw (invalid_argument){

    //Verificando se existem acomodações cadastradas
    bool resultado = cntr_apr_aco->BuscarAcomodacoesUsuario(usuario);
    if(resultado == true){
        cout << endl << "Erro: Usuário possui acomodação cadastrada" << endl << endl;
        return false;
    }

    //Verificando se o usuário tem alguma reserva em seu nome
    resultado = cntr_apr_aco->BuscarReservasUsuario(usuario);
    if(resultado == true){
        cout << endl << "Erro: Usuário possui reserva cadastrada" << endl << endl;
        return false;
    }

    this->cntr_serv_usuario->RemoverUsuario(usuario);
    //O retorno é true quando a exclusão é um sucesso
    return true;
}

//Método que adciona uma conta bancária a um determinado usuário
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

//Método que adciona um cartão de crédito a um determinado usuário
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

//Método que recebe as informações de uma acomodação pelo usuário e a cadastra
bool CntrAprAcomodacao::CadastrarAcomodacao(Usuario* usuario) throw(runtime_error){

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
            cin.ignore();
            getline(cin,entrada_cidade);
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
    acomodacao.SetUsuario(usuario);
    acomodacao.SetCapacidaDeAcomodacao(capacidade);
    acomodacao.SetCidade(cidade);
    acomodacao.SetDiaria(diaria);
    acomodacao.SetEstado(estado);
    acomodacao.SetIdentificador(identificador);
    acomodacao.SetTipoDeAcomodacao(tipo);
    acomodacao.IniciarReserva();


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

//Método que exclui a acomodação de um usuário que é solicitada
bool CntrAprAcomodacao::DescadastrarAcomodacao(Usuario* usuario) throw(runtime_error){

    //Pegando o número de acomodações que o usuário tem cadastrado
    int max = this->cntr_serv_acomodacao->ApresentarListaAcomodacaoDoUsuario(usuario);
    
    if(max < 0){
        return false;
    }

    int selecionar = -1;

    while(selecionar < 0 || selecionar > max){
        cout << "Digite o número da acomodacao que voce deseja descadastrar:" << endl;
        cin >> selecionar;
    }

    //Adquirindo acomodação desejada
    Acomodacao* acomodacao = this->cntr_serv_acomodacao->AcharAcomodacaoUsuarioSelecionada(usuario, selecionar);

    //Caso em que esta acomodação tem reservas 
    if(this->cntr_serv_acomodacao->VerificarReservas(acomodacao) == false){
        cout << "\nNao e possivel descadastrar acomodacoes com reservas ativas." << endl;
        return false;
    }

    bool resultado = this->cntr_serv_acomodacao->RemoverAcomodacao(acomodacao);

    if(resultado == true){
        cout << "\nAcomodacao Descadastrada com Sucesso." << endl;
        return true;
    }
    else{
        cout << "\nVerifique se nao ha reservas feitas antes de descadastrar essa acomodacao." << endl;
        return false;
    }

}

//Método responsável por apresentar as acomodações e registrar uma disponibilidade nela
bool CntrAprAcomodacao::CadastrarDisponibilidade(Usuario* usuario) throw(runtime_error){
    
    //Pegando o número de acomodações que o usuário tem cadastrado e apresentando a lista delas
    int max = this->cntr_serv_acomodacao->ApresentarListaAcomodacaoDoUsuario(usuario);
    
    if(max < 0){
        return false;
    }

    int selecionar = -1;

    while(selecionar < 0 || selecionar > max){
        cout << "Digite o número da acomodacao que voce deseja adicionar uma disponibilidade:" << endl;
        cin >> selecionar;
    }

    //Adquirindo acomodação desejada
    Acomodacao* acomodacao = this->cntr_serv_acomodacao->AcharAcomodacaoUsuarioSelecionada(usuario, selecionar);

    Data inicio, fim;
    string entrada_inicio, entrada_fim;

    //Coletando os dados da disponibilidade
    while(true){
        try{
            cout << "Digite as datas de disponibilidade no formato DD/MMM/AAAA." << endl;
            cout << "MMM é: jan, fev, mar, abr, mai, jun, jul, ago, set, out, nov ou dez." << endl;
            cout << "Digite a data de inicio da disponibilidade: ";
            cin >> entrada_inicio;
            inicio.SetData(entrada_inicio);
            cout << "Digite a data de termino da disponibilidade: ";
            cin >> entrada_fim;
            fim.SetData(entrada_fim);
            break;
        }
        catch (const invalid_argument &exp){
            cout << endl << "Dado em formato incorreto.\n" << endl;
            return false;
        }
    }

    //Setando as informações coletadas na reserva
    Reserva reserva;
    reserva.SetDatas(inicio, fim);
    reserva.SetUsuario(NULL);

    bool resultado = this->cntr_serv_acomodacao->CadastrarDisponibilidade(acomodacao, reserva);

    if(resultado == true){
        cout << "\nDisponibilidade Cadastrada com Sucesso." << endl;
    }
    else{
        cout << "\nPeriodo de disponibilidade conflita com outro existente." << endl;
    }

    return true;

}

//Método responsável por apresentar as acomodações para que o usuário possa remover uma de suas disponibilidades
bool CntrAprAcomodacao::DescadastrarDisponibilidade(Usuario *usuario) throw(runtime_error){

    //Pegando o número de acomodações que o usuário tem cadastrado e apresentando a lista delas
    int max = this->cntr_serv_acomodacao->ApresentarListaAcomodacoes();
    
    if(max < 0){
        return false;
    }

    int selecionar = -1;

    while(selecionar < 0 || selecionar > max){
        cout << "Digite o número da acomodacao que voce deseja descadastrar uma disponibilidade:" << endl;
        cin >> selecionar;
    }

    //Adquirindo acomodação desejada
    Acomodacao* acomodacao = this->cntr_serv_acomodacao->AcharAcomodacaoUsuarioSelecionada(usuario, selecionar);

    //Pegando o número de disponibilidades de uma acomodação e apresentando a lista delas
    max = this->cntr_serv_acomodacao->ApresentarListaDisponibiliades(acomodacao);

    if(max < 0){
        return false;
    }

    selecionar = -1;

    while(selecionar < 0 || selecionar > max){
        cout << "Digite o número da disponibilidade que voce deseja descadastrar:" << endl;
        cin >> selecionar;
    }

    //Adquirindo reserva desejada
    Reserva *reserva = this->cntr_serv_acomodacao->AcharDisponibilidadeSelecionada(acomodacao, selecionar);

    bool resultado = this->cntr_serv_acomodacao->DescadastrarDisponibilidade(acomodacao, reserva);

    if(resultado == true){
        cout << "\nDisponibilidade Descadastrada com Sucesso." << endl;
    }
    else   
        cout << "\nDisponibilidade Inexistente ou Reservada." << endl;

    return true;

}

//Método responsável por apresentar as acomodações e efetuar uma reserva nela
bool CntrAprAcomodacao::CadastrarReserva(Usuario* usuario) throw(runtime_error){

    //Pegando o número de acomodações tem cadastrado e apresentando a lista delas
    int max = this->cntr_serv_acomodacao->ApresentarListaAcomodacoes();
    
    if(max < 0){
        return false;
    }

    int selecionar = -1;

    while(selecionar < 0 || selecionar > max){
        cout << "Digite o número da acomodacao que você deseja se reservar:" << endl;
        cin >> selecionar;
    }

    //Adquirindo acomodação desejada
    Acomodacao* acomodacao = this->cntr_serv_acomodacao->AcharAcomodacaoSelecionada(selecionar);

    //Vericando se o usuário está tentando reservar uma acomodação o qual ele é dono
    if(acomodacao->GetUsuario() == usuario){
        cout << "\nNão é possível reservar uma acomodação que você é dono!" << endl;        
        return false;
    }

    //Pegando o número de disponibilidades de uma acomodação e apresentando a lista delas
    max = this->cntr_serv_acomodacao->ApresentarListaDisponibiliades(acomodacao);

    if(max < 0){
        return false;
    }

    selecionar = -1;

    while(selecionar < 0 || selecionar > max){
        cout << "Digite o número do período que você deseja se reservar:" << endl;
        cin >> selecionar;
    }

    //Adquirindo reserva desejada
    Reserva *reserva = this->cntr_serv_acomodacao->AcharDisponibilidadeSelecionada(acomodacao, selecionar);

    bool resultado =  this->cntr_serv_acomodacao->CadastrarReserva(reserva, usuario);

    if(resultado == true){
        cout << endl <<"Reserva registrada com sucesso." << endl;
        return true;
    }
    else{
        cout << endl <<"Disponibilidade já está reservada." << endl;
        return false;
    }
}

//Método responsável por excluir uma reserva feita previamente pelo usuário
bool CntrAprAcomodacao::DescadastrarReserva(Usuario *usuario) throw(runtime_error){

    //Pegando o número de acomodações cadastradas e apresentando a lista delas
     int max = this->cntr_serv_acomodacao->ApresentarListaAcomodacoes();
     
     if(max < 0){
         return false;
     }

     int selecionar = -1;

     while(selecionar < 0 || selecionar > max){
         cout << "Digite o número da acomodacao onde sua reserva está efetuada:" << endl;
         cin >> selecionar;
     }

     //Adquirindo acomododação desejada
     Acomodacao* acomodacao = this->cntr_serv_acomodacao->AcharAcomodacaoSelecionada(selecionar);

     if(acomodacao->GetUsuario() == usuario){

         cout << "\nNão ha reservas suas em uma acomodação que você é dono!" << endl;        
         return false;
     }

     //Pegando o número de reservas cadastradas e apresentando a lista delas
     max = this->cntr_serv_acomodacao->ApresentarListaReservasUsuario(acomodacao, usuario);

     if(max < 0){
         cout << "\nNao ha reservas suas nessa acomodacao." << endl;
         return false;
     }

     selecionar = -1;

     while(selecionar < 0 || selecionar > max){
         cout << "Digite o número da reserva que você deseja descadastrar:" << endl;
         cin >> selecionar;
     }

     //Adquirindo reserva desejada
     Reserva *reserva = this->cntr_serv_acomodacao->AcharReservaSelecionada(acomodacao, usuario, selecionar);

     bool resultado =  this->cntr_serv_acomodacao->DescadastrarReserva(reserva, usuario);

     if(resultado == true){
         cout << endl <<"\nReserva descadastrada com sucesso." << endl;
         return true;
     }
     else{
         cout << endl <<"\nUsuario nao e o dono da reserva." << endl;
         return false;
     }
 }

//Método responsável por checar se um usuário tem uma acomodação cadastrada
bool CntrAprAcomodacao::BuscarAcomodacoesUsuario(Usuario* usuario){
    this->cntr_serv_acomodacao->BuscarAcomodacoesUsuario(usuario);
}

//Método responsável por checar se um usuário tem uma reserva cadastrada
bool CntrAprAcomodacao::BuscarReservasUsuario(Usuario* usuario){
    this->cntr_serv_acomodacao->BuscarReservasUsuario(usuario);   
}

//Métodos da classe CntrNavegacaoInicial----------------------------------------------

//Método que apresenta as opções do menu inicial
void CntrNavegacaoInicial::apresentarOpcoes(){
    cout << "--- Servicos disponiveis ---" << endl << endl;
    cout << "0 - Encerrar." << endl;
    cout << "1 - Registrar Usuário." << endl;
    cout << "2 - Logar no Sistema." << endl;
}

//Método que apresenta o menu inicial
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

//Método que apresenta as opções do menu principal
void CntrNavegacaoPrincipal::apresentarOpcoes(){
    cout << "--- Servicos disponiveis ---" << endl << endl;
    cout << "0 - Deslogar." << endl;
    cout << "1 - Opcoes de Acomodacoes." << endl;
    cout << "2 - Opcoes de Reserva." << endl;
    cout << "3 - Excluir Usuario." << endl;
}

//Método que apresenta o menu principal
void CntrNavegacaoPrincipal::executar(IAprUsuario* cntr_apr_usu, IAprAcomodacao* cntr_apr_aco, Usuario* usuario){
        unsigned int escolha;
        bool resultado;

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
                                //Chamando a próxima interface de texto
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
                                //Chamando a proxima interface de texto
                                cntrRes.executar(cntr_apr_usu, cntr_apr_aco, usuario);
                            }
                            break;
                        case OPCAO_EXCLUIR_USUARIO:
                            cout << "\n";
                            resultado = cntr_apr_usu->RemoverUsuario(usuario, cntr_apr_aco);
                            if(resultado == true){
                                //Retornando à interface de texto inicial
                                return;
                            }

                            break;
                        case OPCAO_DESLOGAR :
                            return;
                    }
                }
        }
}

//Métodos da classe CntrNavegacaoAcomodacao--------------------------------------------

//Método que apresenta as opções do menu de acomodações
void CntrNavegacaoAcomodacao::apresentarOpcoes(){
    cout << "--- Servicos disponiveis ---" << endl << endl;
    cout << "0 - Voltar ao Menu Principal." << endl;
    cout << "1 - Cadastrar Acomodacao." << endl;
    cout << "2 - Descadastrar Acomodacao." << endl;
    cout << "3 - Cadastrar Disponibilidade." << endl;
    cout << "4 - Descadastrar Disponibilidade." << endl;
}

//Método que apresenta o menu de acomodações
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
                            cntr_apr_aco->CadastrarAcomodacao(usuario);
                            cout << "\n";
                            break;
                        case OPCAO_DESCADASTRAR_ACOMODACAO:
                            cntr_apr_aco->DescadastrarAcomodacao(usuario);
                            cout << "\n";
                            break;
                        case OPCAO_CADASTRAR_DISPONIBILIDADE:
                            cntr_apr_aco->CadastrarDisponibilidade(usuario);
                            cout << "\n";
                            break;
                        case OPCAO_DESCADASTRAR_DISPONIBILIDADE:
                        cntr_apr_aco->DescadastrarDisponibilidade(usuario);
                        cout << "\n";
                            break;
                        case OPCAO_VOLTAR :
                            cout << "\n";
                            return;
                    }
                }
        }
}

//Métodos da classe CntrNavegacaoReserva------------------------------------------------

//Método que apresenta as opções do menu de reservas
void CntrNavegacaoReserva::apresentarOpcoes(){
    cout << "--- Servicos disponiveis ---" << endl << endl;
    cout << "0 - Voltar ao Menu Principal." << endl;
    cout << "1 - Fazer Reserva." << endl;
    cout << "2 - Cancelar Reserva." << endl;
}

//Método que apresenta o menu de reservas
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
                            cntr_apr_aco->CadastrarReserva(usuario);
                            break;
                        case OPCAO_DESFAZER_RESERVA:
                            cntr_apr_aco->DescadastrarReserva(usuario);
                            break;
                        case OPCAO_VOLTAR :
                            cout << "\n";
                            return;
                    }
                }
        }
}
