#include "dominioshotel.h"

//Métodos do objeto CapacidadeDeAcomodacao
void CapacidadeDeAcomodacao::Validar(int capacidade) throw (invalid_argument){

    // Lança excessão caso o valor da capacidade ultrapasse um dos seus limites
    if(capacidade > LIMITE_SUP || capacidade < LIMITE_INF){
        throw invalid_argument("Argumento invalido.");

    }
}

void CapacidadeDeAcomodacao::SetCapacidadeDeAcomodacao(int capacidade) throw (invalid_argument){

    Validar(capacidade);
    this->capacidade = capacidade;
}

//Métodos do objeto Diaria
void Diaria::Validar(float diaria) throw (invalid_argument){

    // Lança excessão caso o valor da diaria ultrapasse um dos seus limites
    if(diaria > LIMITE_SUP || diaria < LIMITE_INF){
        throw invalid_argument("Argumento invalido.");
    }
}

void Diaria::SetDiaria(float diaria) throw (invalid_argument){

    Validar(diaria);
    this->diaria = diaria;
}

//Métodos do objeto Data
void Data::Validar(string data) throw (invalid_argument){

    //Lança uma exceção se a string tem valor maior que o limite
    if(data.length() != STRING_TAMANHO){
        throw invalid_argument("O Ano contêm um argumento invalido.");
    }

    string diastring = data.substr(0,2);
    int dia = atoi(diastring.c_str());

    string mes = data.substr(3,3);

    string anostring = data.substr(7,4);
    int ano = atoi(anostring.c_str());

    //Verificação do valor do ano
    if(ano > ANO_LIMITE_SUP || ano < ANO_LIMITE_INF){
        throw invalid_argument("O Ano contêm um argumento invalido.");
    }

    //Verificão do valor do mes
    if(mes != "jan" && mes != "fev" && mes != "mar" && mes != "abr" && mes != "mai" && mes != "jun" && mes != "jul" && mes != "ago" && mes != "set" && mes != "out" && mes != "nov" && mes != "dez"){
        throw invalid_argument("O Mês contêm um argumento invalido.");
    }

    //Lança exceção caso os meses a seguir tenham mais de 31 dias
    if(mes == "jan" || mes == "mar" || mes == "mai" || mes == "jul" || mes == "ago" || mes == "out" || mes == "dez"){
        if(dia > DIA_LIMITE_SUP1 || dia < DIA_LIMITE_INF){
            throw invalid_argument("O Dia contêm um argumento fora do intervalo [1,31]");
        }
    }

    //Lança exceção caso os meses a seguir tenham mais de 30 dias
    else if(mes == "abr" || mes == "jun" || mes == "set" || mes == "nov"){
        if(dia > DIA_LIMITE_SUP2 || dia < DIA_LIMITE_INF){
            throw invalid_argument("O Dia contêm um argumento fora do intervalo [1,30]");
        }
    }

    //Lança exceção caso em que fevereiro tem mais de 29 dias em anos bissextos
    else if(mes == "fev" && ano%4 == 0){
        if(dia > DIA_LIMITE_SUP3 || dia < DIA_LIMITE_INF){
            throw invalid_argument("O Dia contêm um argumento fora do intervalo [1,29]");
        }
    }

    //Lança exceção caso em que fevereiro tem mais de 28 dias em anos não bissextos
    else if(mes == "fev" && ano%4 != 0){
        if(dia > DIA_LIMITE_SUP4 || dia < DIA_LIMITE_INF){
            throw invalid_argument("O Dia contêm um argumento fora do intervalo [1,28]");
        }
    }
}

void Data::SetData(string data) throw (invalid_argument){

    Validar(data);
    this->data = data;
}

//Métodos do objeto Estado
void Estado::Validar(string estado) throw (invalid_argument){

    // Exceção é lançado caso seja fornecido um estado que não existe
    if(estado == "AC" || estado == "AL" || estado == "AP" || estado == "AM" || estado == "BA");
    else if(estado == "CE" || estado =="DF" || estado == "ES" || estado == "GO" || estado == "MA");
    else if(estado == "MT" || estado =="MS" || estado == "MG" || estado == "PA" || estado == "PB");
    else if(estado == "PR" || estado =="PE" || estado == "PI" || estado == "RJ" || estado == "RN");
    else if(estado == "RS" || estado =="RO" || estado == "RR" || estado == "SC" || estado == "SP");
    else if(estado == "SE" || estado =="TO");
    else{
        throw invalid_argument("Argumento invalido.");
    }

}

void Estado::SetEstado(string estado) throw (invalid_argument){

    Validar(estado);
    this->estado = estado;
}

//Métodos do objeto TipoDeAcomodacao
void TipoDeAcomodacao::Validar(string acomodacao) throw (invalid_argument){

    if(acomodacao != "Apartamento" && acomodacao != "Casa" && acomodacao != "Flat"){
        throw invalid_argument("Argumento invalido.");
    }
}

void TipoDeAcomodacao::SetTipoDeAcomodacao(string acomodacao) throw (invalid_argument){

    Validar(acomodacao);
    this->acomodacao = acomodacao;
}
