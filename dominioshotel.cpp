#include "dominioshotel.h"

//Métodos do objeto CapacidadeDeAcomodacao
void CapacidadeDeAcomodacao::validar(int capacidade) throw (invalid_argument){

    if(capacidade > LIMITE_SUP || capacidade < LIMITE_INF){
        throw invalid_argument("Argumento invalido.");
    }
}

void CapacidadeDeAcomodacao::SetCapacidadeDeAcomodacao(int capacidade) throw (invalid_argument){

    validar(capacidade);
    this->capacidade = capacidade;
}

//Métodos do objeto Diaria
void Diaria::validar(float diaria) throw (invalid_argument){

    if(diaria > LIMITE_SUP || diaria < LIMITE_INF){
        throw invalid_argument("Argumento invalido.");
    }
}

void Diaria::SetDiaria(float capacidade) throw (invalid_argument){

    validar(diaria);
    this->diaria = diaria;
}

//Métodos do objeto Data
void Data::validar(int dia, int mes, int ano) throw (invalid_argument){

    //Verificação do valor do ano
    if(ano > ANO_LIMITE_SUP || ano < ANO_LIMITE_INF){
        throw invalid_argument("O Ano contêm um argumento invalido.");
    }

    //Verificão do valor do mes
    if(mes > MES_LIMITE_SUP || mes < MES_LIMITE_INF){
        throw invalid_argument("O Mês contêm um argumento invalido.");
    }

    //Verificão do valor do mes
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        if(dia > DIA_LIMITE_SUP1 || dia < DIA_LIMITE_INF){
            throw invalid_argument("O Dia contêm um argumento fora do intervalo [1,31]");
        }
    }
    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        if(dia > DIA_LIMITE_SUP2 || dia < DIA_LIMITE_INF){
            throw invalid_argument("O Dia contêm um argumento fora do intervalo [1,30]");
        }
    }
    //Fevereiro com ano bisexto
    else if(mes == 2 && ano%4 == 0){
        if(dia > DIA_LIMITE_SUP3 || dia < DIA_LIMITE_INF){
            throw invalid_argument("O Dia contêm um argumento fora do intervalo [1,29]");
        }
    }
    else if(mes == 2 && ano%4 != 0){
        if(dia > DIA_LIMITE_SUP4 || dia < DIA_LIMITE_INF){
            throw invalid_argument("O Dia contêm um argumento fora do intervalo [1,28]");
        }
    }
}

void Data::SetData(int dia, int mes, int ano) throw (invalid_argument){

    validar(dia, mes, ano);
    this->dia = dia;
    this->mes = mes;
    this->mes = mes;
}

//Métodos do objeto Data
void Estado::validar(string estado) throw (invalid_argument){

    if(estado != "AC" && estado != "AL" && estado != "AP" && estado != "AM" && estado != "BA");
    else if(estado != "CE" && estado !="DF" && estado != "ES" && estado !="GO" && estado != "MA");
    else if(estado != "MT" && estado !="MS" && estado != "MG" && estado !="PA" && estado != "PB");
    else if(estado != "PR" && estado !="PE" && estado != "PI" && estado !="RJ" && estado != "RN");
    else if(estado != "RS" && estado !="RO" && estado != "RR" && estado !="SC" && estado != "SP");
    else if(estado != "SE" && estado !="TO");
    else{
        throw invalid_argument("Argumento invalido.");
    }

}

void Estado::SetEstado(string estado) throw (invalid_argument){

    validar(estado);
    this->estado = estado;
}
//Métodos do objeto Data

