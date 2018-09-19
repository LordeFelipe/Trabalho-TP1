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

	return 0;
}