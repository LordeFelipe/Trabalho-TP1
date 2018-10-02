#include "testes_entidades.h"

//Métodos que testam a classe Acomodacao

void TUAcomodacao::SetUp(){

    //Criação do objeto capacidade e definição do estado inicial do teste para sucesso
    acomodacao = new Acomodacao();
    estado = SUCESSO;
}

void TUAcomodacao::TearDown(){
    delete acomodacao;
}

void TUAcomodacao::TestarCenarioSucessoIdentificador(){
    try{
        //É setado um valor válido para o identificador contido na acomodacao
        Identificador identificador;
        identificador.SetIdentificador(VALOR_VALIDO_IDENTIFICADOR);
        acomodacao->SetIdentificador(identificador);

        if (acomodacao->GetIdentificador().GetIdentificador() != identificador.GetIdentificador())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUAcomodacao::TestarCenarioSucessoTipoAcomodacao(){
    try{
        //É setado um valor válido para o tipo de acomodação contido na acomodacao
        TipoDeAcomodacao tipo_de_acomodacao;
        tipo_de_acomodacao.SetTipoDeAcomodacao(VALOR_VALIDO_TIPO_ACOMODACAO);
        acomodacao->SetTipoDeAcomodacao(tipo_de_acomodacao);

        if (acomodacao->GetTipoDeAcomodacao().GetTipoDeAcomodacao() != tipo_de_acomodacao.GetTipoDeAcomodacao())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}


void TUAcomodacao::TestarCenarioSucessoCapacidade(){
    try{
        //É setado um valor válido para a capacidade contida na acomodacao
        CapacidadeDeAcomodacao capacidade;
        capacidade.SetCapacidadeDeAcomodacao(VALOR_VALIDO_CAPACIDADE);
        acomodacao->SetCapacidaDeAcomodacao(capacidade);

        if (acomodacao->GetCapacidadeDeAcomodacao().GetCapacidadeDeAcomodacao() != capacidade.GetCapacidadeDeAcomodacao())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUAcomodacao::TestarCenarioSucessoDataInicio(){
    try{
        //É setado um valor válido para a data de inicio contida na acomodacao
        Data data_inicio;
        data_inicio.SetData(VALOR_VALIDO_DATA);
        acomodacao->SetDataInicio(data_inicio);

        if (acomodacao->GetDataInicio().GetData() != data_inicio.GetData())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUAcomodacao::TestarCenarioSucessoDataTermino(){
    try{
        //É setado um valor válido para a data de término contida na acomodacao
        Data data_termino;
        data_termino.SetData(VALOR_VALIDO_DATA);
        acomodacao->SetDataTermino(data_termino);

        if (acomodacao->GetDataTermino().GetData() != data_termino.GetData())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUAcomodacao::TestarCenarioSucessoCidade(){
    try{
        //É setado um valor válido para a cidade contida na acomodacao
        Nome cidade;
        cidade.SetNome(VALOR_VALIDO_CIDADE);
        acomodacao->SetCidade(cidade);

        if (acomodacao->GetCidade().GetNome() != cidade.GetNome())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUAcomodacao::TestarCenarioSucessoEstado(){
    try{
        //É setado um valor válido para o estado contido na acomodacao
        Estado estado_brasileiro;
        estado_brasileiro.SetEstado(VALOR_VALIDO_CIDADE);
        acomodacao->SetEstado(estado_brasileiro);

        if (acomodacao->GetEstado().GetEstado() != estado_brasileiro.GetEstado())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUAcomodacao::TestarCenarioSucessoDiaria(){
    try{
        //É setado um valor válido para a diaria contida na acomodacao
        Diaria diaria;
        diaria.SetDiaria(VALOR_VALIDO_DIARIA);
        acomodacao->SetDiaria(diaria);

        if (acomodacao->GetDiaria().GetDiaria() != diaria.GetDiaria())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUAcomodacao::Run(){
    SetUp();
    TestarCenarioSucessoIdentificador();
    TestarCenarioSucessoTipoAcomodacao();
    TestarCenarioSucessoCapacidade();
    TestarCenarioSucessoDataInicio();
    TestarCenarioSucessoDataTermino();
    TestarCenarioSucessoCidade();
    TestarCenarioSucessoEstado();
    TestarCenarioSucessoDiaria();
    TearDown();
    return estado;
}

//Métodos que testam a classe Cartao

void TUCartao::SetUp(){

    //Criação do objeto e definição do estado inicial do teste para sucesso
    cartao = new Cartao();
    estado = SUCESSO;
}

void TUCartao::TearDown(){
    delete cartao;
}

void TUCartao::TestarCenarioSucessoValidade(){
    try{
        //É setado um valor válido para a validade
        Validade validade;
        validade.SetVal(VALOR_VALIDO_VAL);
        cartao->SetValidade(validade);

        if (cartao->GetValidade().GetVal() != validade.GetVal())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUCartao::TestarCenarioSucessoNumero(){
    try{
        //É setado um valor válido para o numero do cartao
        NumeroCartao numero;
        numero.SetNumero(VALOR_VALIDO_NUMERO);
        cartao->SetNumero(numero);

        if (cartao->GetNumero().GetNumero() != numero.GetNumero())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUCartao::Run(){
    SetUp();
    TestarCenarioSucessoNumero();
    TestarCenarioSucessoValidade();
    TearDown();
    return estado;
}


//Métodos que testam a classe ContaCorrente

void TUContaCorrente::SetUp(){

    //Criação do objeto e definição do estado inicial do teste para sucesso
    conta = new ContaCorrente();
    estado = SUCESSO;
}

void TUContaCorrente::TearDown(){
    delete conta;
}

void TUContaCorrente::TestarCenarioSucessoNumero(){
    try{
        //É setado um valor válido para o numero da conta
        NumeroConta numero;
        numero.SetConta(VALOR_VALIDO_NUMERO);
        conta->SetNumero(numero);

        if (conta->GetNumero().GetConta() != numero.GetConta())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUContaCorrente::TestarCenarioSucessoAgencia(){
    try{
        //É setado um valor válido para a validade
        Agencia agencia;
        agencia.SetAgencia(VALOR_VALIDO_AGENCIA);
        conta->SetAgencia(agencia);

        if (conta->GetAgencia().GetAgencia() != agencia.GetAgencia())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUContaCorrente::TestarCenarioSucessoBanco(){
    try{
        //É setado um valor válido para a validade
        Banco banco;
        banco.SetBanco(VALOR_VALIDO_BANCO);
        conta->SetBanco(banco);

        if (conta->GetBanco().GetBanco() != banco.GetBanco())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUContaCorrente::Run(){
    SetUp();
    TestarCenarioSucessoNumero();
    TestarCenarioSucessoAgencia();
    TestarCenarioSucessoBanco();
    TearDown();
    return estado;
}

//Métodos que testam a classe Usuario

void TUUsuario::SetUp(){

    //Criação do objeto e definição do estado inicial do teste para sucesso
    usuario = new Usuario();
    estado = SUCESSO;
}

void TUUsuario::TearDown(){
    delete usuario;
}

void TUUsuario::TestarCenarioSucessoIdentificador(){
    try{
        //É setado um valor válido para o identificador
        Identificador identificador;
        identificador.SetIdentificador(VALOR_VALIDO_SENHA);
        usuario->SetIdentificador(identificador);

        if (usuario->GetIdentificador().GetIdentificador() != identificador.GetIdentificador())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUUsuario::TestarCenarioSucessoNome(){
    try{
        //É setado um valor válido para a validade
        Nome nome;
        nome.SetNome(VALOR_VALIDO_NOME);
        usuario->SetNome(nome);

        if (usuario->GetNome().GetNome() != nome.GetNome())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUUsuario::TestarCenarioSucessoSenha(){
    try{
        //É setado um valor válido para a senha
        Senha senha;
        senha.SetSenha(VALOR_VALIDO_SENHA);
        usuario->SetSenha(senha);

        if (usuario->GetSenha().GetSenha() != senha.GetSenha())
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUUsuario::Run(){
    SetUp();
    TestarCenarioSucessoIdentificador();
    TestarCenarioSucessoNome();
    TestarCenarioSucessoSenha();
    TearDown();
    return estado;
}
