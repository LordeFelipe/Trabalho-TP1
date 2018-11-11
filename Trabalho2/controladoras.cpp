#include controladoras.h

//Métodos da classe CntrIUAutenticacao

ResultadoAutenticacao autenticar() throw(runtime_error){

    ResultadoAutenticacao resultadoAutenticacao;
    Resultado resultado;
    Identificador identificador;
    Senha senha;
    int entrada;

    // SOlicitar dados

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

    // INCOMPLETO
}