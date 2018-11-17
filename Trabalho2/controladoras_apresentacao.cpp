#include "controladoras_apresentacao.h"

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