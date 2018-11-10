#ifndef ENTIDADES_H
#define ENTIDADES_H

#include "dominioshotel.h"
#include "dominiosbanco.h"
#include "dominiosusuario.h"

class Acomodacao
{
    private:

        Identificador identificador;
        TipoDeAcomodacao tipo_de_acomodacao;
        CapacidadeDeAcomodacao capacidade;
        Data data_inicio;
        Data data_termino;
        Nome cidade;
        Estado estado;
        Diaria diaria;

    public:

        // Métodos de acesso ao identificador
         void SetIdentificador(const Identificador &identificador){
            this->identificador = identificador;
        }

        Identificador GetIdentificador(){
            return identificador;
        }

        // Métodos de acesso ao tipo de acomodacao
        void SetTipoDeAcomodacao(const TipoDeAcomodacao &tipo_de_acomodacao){
            this->tipo_de_acomodacao = tipo_de_acomodacao;
        }

        TipoDeAcomodacao GetTipoDeAcomodacao(){
            return tipo_de_acomodacao;
        }

        // Métodos de acesso à capacidade de acomodação
        void SetCapacidaDeAcomodacao(const CapacidadeDeAcomodacao &capacidade){
            this->capacidade = capacidade;
        }

        CapacidadeDeAcomodacao GetCapacidadeDeAcomodacao(){
            return capacidade;
        }

        // Métodos de acesso à data de início
        void SetDataInicio(const Data &data_inicio){
            this->data_inicio = data_inicio;
        }

        Data GetDataInicio(){
            return data_inicio;
        }

        // Métodos de acesso à data de término
        void SetDataTermino(const Data &data_termino){
            this->data_termino = data_termino;
        }

        Data GetDataTermino(){
            return data_termino;
        }

        // Métodos de acesso à cidade
        void SetCidade(const Nome &cidade){
            this->cidade = cidade;
        }

        Nome GetCidade(){
            return cidade;
        }

        // Métodos de acesso ao estado
        void SetEstado(const Estado &estado){
            this->estado = estado;
        }

        Estado GetEstado(){
            return estado;
        }

        // Métodos de acesso à diária
        void SetDiaria(const Diaria &diaria){
            this->diaria = diaria;
        }

        Diaria GetDiaria(){
            return diaria;
        }
};

#endif // ENTIDADES_H
