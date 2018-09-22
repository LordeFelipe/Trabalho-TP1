#include <iostream>
#include "dominiosbanco.h"
#include "testesbanco.h"
#include "dominioshotel.h"
#include "testesdominioshotel.h"

using namespace std;

int main(){

	TUAgencia Tagencia;

	switch(Tagencia.run()){
		case TUAgencia::SUCESSO: cout << "Agecia: Sucessso" << endl;
			break;
		case TUAgencia::FALHA: cout << "Agencia: Falha" << endl;
			break;
	}

	TUBanco Tbanco;

	switch(Tbanco.run()){
		case TUBanco::SUCESSO: cout << "Banco: Sucessso" << endl;
			break;
		case TUBanco::FALHA: cout << "Banco: Falha" << endl;
			break;
	}

	TUConta Tconta;

	switch(Tconta.run()){
		case TUConta::SUCESSO: cout << "Conta: Sucessso" << endl;
			break;
		case TUConta::FALHA: cout << "Conta: Falha" << endl;
			break;
	}

	TUCartao Tcartao;

	switch(Tcartao.run()){
		case TUCartao::SUCESSO: cout << "Cartao: Sucessso" << endl;
			break;
		case TUCartao::FALHA: cout << "Cartao: Falha" << endl;
			break;
	}
	
	TUValidade Tvalidade;

	switch(Tvalidade.run()){
		case TUValidade::SUCESSO: cout << "Validade: Sucessso" << endl;
			break;
		case TUValidade::FALHA: cout << "Validade: Falha" << endl;
			break;
	}

	TUCapacidadeDeAcomodacao Tcapacidade;

    switch(Tcapacidade.Run()){
	    case TUCapacidadeDeAcomodacao::SUCESSO: cout << "Capacidade de Acomodação: Sucesso" << endl;
	        break;
	    case TUCapacidadeDeAcomodacao::FALHA: cout << "Capacidade de Acomodação: Falha" << endl;
	        break;
    }

    TUData Tdata;

    switch(Tdata.Run()){
	    case TUData::SUCESSO: cout << "Data: Sucesso" << endl;
	        break;
	    case TUData::FALHA: cout << "Data: Falha" << endl;
	        break;
    }

    TUDiaria Tdiaria;

    switch(Tdiaria.Run()){
	    case TUDiaria::SUCESSO: cout << "Diaria: Sucesso" << endl;
	        break;
	    case TUDiaria::FALHA: cout << "Diaria: Falha" << endl;
	        break;
    }

    TUEstado Testado;

    switch(Testado.Run()){
	    case TUEstado::SUCESSO: cout << "Estado: Sucesso" << endl;
	        break;
	    case TUEstado::FALHA: cout << "Estado: Falha" << endl;
	        break;
	}

	TUTipoDeAcomodacao Tacomodacao;

    switch(Tacomodacao.Run()){
	    case TUTipoDeAcomodacao::SUCESSO: cout << "Tipo de Acomodação: Sucesso" << endl;
	        break;
	    case TUTipoDeAcomodacao::FALHA: cout << "Tipo de Acomodação: Falha" << endl;
	        break;
	}
	return 0;
}
	