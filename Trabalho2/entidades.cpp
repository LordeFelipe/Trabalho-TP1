#include "entidades.h"


// Implementação de metodos das classes relacionadas ao usuario:

bool Usuario::VerificarCartao(){
    if(this->GetCartao() == NULL){
        return false;
    }
    else
        return true;
}

bool Usuario::VerificarConta(){
    if(this->GetConta() == NULL){
        return false;
    }
    else
        return true;
}

// Implementação dos Metodos das Classes Relacionadas à Reserva:

void Reserva::Validar(Data &data_inicio, Data &data_termino) throw (invalid_argument){
    
    // Lança exceção se data de inicio for maior ou igual a de término
    if(data_inicio.CmpData(data_termino) != -1){
        throw invalid_argument("Periodo Invalido");
    }
}

void Reserva::SetDatas(const Data &data_inicio, const Data &data_termino){
    this->data_inicio = data_inicio;
    this->data_termino = data_termino;
}

// Implementação dos Metodos das Classes Relacionadas à Acomodação:

bool Acomodacao::AddDisponibilidade(Reserva &reserva) throw (invalid_argument){
    list<Reserva>::iterator it, local;
    Data inicio,termino;

    // Percorrer lista de reservas para encontrar aonde armazenar
    if(!this->reserva.empty()){
        for(it = this->reserva.begin(); it != this->reserva.end(); ++it){

            inicio = reserva.GetDataInicio();
            termino = reserva.GetDataTermino();
            
            // Verificar se a data de fim da reserva se encontra antes da iteracao atual da lista
            if(termino.CmpData(it->GetDataInicio()) == -1){
                local = it;
                break;
            }

            // Verificar se a data de inicio da reserva se encontra depois da iteracao atual da lista
            else if(inicio.CmpData(it->GetDataTermino()) == 1)
                local = it;

            // Lançar exceção se periodo for invalido
            else{
                throw invalid_argument("Periodo Invalido.");
		        return false;
            }
        }

        this->reserva.insert(local,reserva);
    }
    else{
        this->reserva.clear();
        this->reserva.push_front(reserva);
    }

    return true;
}

 void Acomodacao::FazReserva(const std::list<Reserva>::iterator &reserva, Usuario *usuario) throw (invalid_argument){

    // Verificar se acomodação já está reservada
    if(reserva->GetUsuario() != NULL){
        throw invalid_argument("Acomodação já resservada");
    }

    reserva->SetUsuario(usuario);
 }