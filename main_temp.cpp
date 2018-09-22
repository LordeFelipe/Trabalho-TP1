#include <iostream>
#include "dominiosbanco.h"
#include "testesbanco.h"

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
	    case TUCapacidadeDeAcomodacao::SUCESSO: cout << "SUCESSO";
	        break;
	    case TUCapacidadeDeAcomodacao::FALHA: cout << "SUCESSO";
	        break;
    }

    TUData Tdata;

    switch(Tdata.Run()){
	    case TUData::SUCESSO: cout << "SUCESSO";
	        break;
	    case TUData::FALHA: cout << "SUCESSO";
	        break;
    }

    TUDiaria Tdiaria;

    switch(Tdiaria.Run()){
	    case TUDiaria::SUCESSO: cout << "SUCESSO";
	        break;
	    case TUDiaria::FALHA: cout << "SUCESSO";
	        break;
    }

    TUEstado Testado;

    switch(Testado.Run()){
	    case TUEstado::SUCESSO: cout << "SUCESSO";
	        break;
	    case TUEstado::FALHA: cout << "SUCESSO";
	        break;

	return 0;
}