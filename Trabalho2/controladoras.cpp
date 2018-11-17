#include controladoras.h

//Métodos da classe CntrIUAutenticacao---------------------------------------

ResultadoAutenticacao autenticar() throw(runtime_error){

    ResultadoAutenticacao resultadoAutenticacao;
    Resultado resultado;
    Identificador identificador;
    Senha senha;
    int entrada;

    // Solicitar dados

    while(true){
        try{
            cout << "Digite seu Identificador:";
            cin >> entrada;
            identificador.SetIdentificador(entrada);
            cout << "Digite sua Senha:";
            cin >> enrada;
            senha.SetSenha(entrada);
            break;
        }
        catch (const invalid_argument &exp){
            cout << endl << "Dado em formato incorreto." << endl;
        }
    }

    // Solicitar autenticação.

    //Precisamos entender oq raios essa interface tem q fazer
    resultado = cntrLNAutenticacao->autenticar(identificador, senha);


    // Informar resultado da autenticação.

    if(resultado.getValor() == ResultadoAutenticacao::FALHA){
        cout << endl << "Falha na autenticacao." << endl;
    }

    resultadoAutenticacao.setValor(resultado.getValor());
    resultadoAutenticacao.SetIdentificador(matricula);

    return resultadoAutenticacao;
}

//Métodos da classe CntrNavegacao----------------------------------------

void CntrAluno::apresentarOpcoes(){
    cout << "--- Servicos disponiveis ---" << endl << endl;
    cout << "0 - Encerrar." << endl << endl;
    cout << "1 - Cadastrar Acomodação." << endl;
    cout << "2 - Decadastrar Acomodação." << endl;
    cout << "3 - Cadastrar Disponibilidade de Acomodação." << endl;
    cout << "4 - Decadastrar Disponibilidade de Acomodação." << endl;
    cout << "5 - Cadastrar Reserva." << endl;
    cout << "6 - Decadastrar Reserva." << endl;
}

void CntrNavegacao::executar(){
        unsigned int escolha;
        
        while (true) {
                escolha = -1;
                while(escolha == -1 || escolha > NUMERO_OPCOES){
                        apresentarOpcoes();
                        cout << "Escolha a opcao : ";
                        cin >> escolha;
                }
                switch (escolha) {
                        case OPCAO_CADASTRAR_ACOMODACAO:    
                            //Função de cadastrar acomodacao
                            break;
                        case OPCAO_DECADASTRAR_ACOMODACAO:    
                            //Função de decadastrar acomodacao
                            break;
                        case OPCAO_CADASTRAR_DISPONIBILIDADE:    
                            //Função de cadastrar disponibilidade
                            break;
                        case OPCAO_DECADASTRAR_DISPONIBILIDADE:    
                            //Função de decadastrar disponibilidade
                            break;
                        case OPCAO_CADASTRAR_RESERVA:    
                            //Função de cadastrar reserva
                            break;
                        case OPCAO_DECADASTRAR_RESERVA:    
                            //Função de decadastrar reserva
                            break;
                        case OPCAO_ENCERRAR :   return;
                }
        }
}

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