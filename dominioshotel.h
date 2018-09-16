#ifndef DOMINIOSHOTEL_H
#define DOMINIOSHOTEL_H

#include <stdexcept>
#include <string>

using namespace std;

class CapacidadeDeAcomodacao
{
    private:

        int capacidade;

        const static int LIMITE_SUP = 1;
        const static int LIMITE_INF = 9;

        void validar(int) throw (invalid_argument);

    public:

        void SetCapacidadeDeAcomodacao(int) throw (invalid_argument);

        int GetCapacidadeDeAcomodacao() const{
            return capacidade;
        }

};

class Diaria
{
    private:

        float diaria;

        const static float LIMITE_SUP = 10000;
        const static float LIMITE_INF = 1;

        void validar(float) throw (invalid_argument);

    public:

        void SetDiaria(float) throw (invalid_argument);

        float GetDiaria() const{
            return diaria;
        }

};

class Data
{
    private:

        int dia;
        int mes;
        int ano;

        const static int ANO_LIMITE_SUP = 2099;
        const static int ANO_LIMITE_INF = 2000;

        const static int MES_LIMITE_SUP = 12;
        const static int MES_LIMITE_INF = 1;

        const static int DIA_LIMITE_SUP1 = 31;
        const static int DIA_LIMITE_SUP2 = 30;
        const static int DIA_LIMITE_SUP3 = 29;
        const static int DIA_LIMITE_SUP4 = 28;
        const static int DIA_LIMITE_INF = 1;

        void validar(int, int, int) throw (invalid_argument);

    public:

        void SetData(int, int, int) throw (invalid_argument);

        int GetDataDia() const{
            return dia;
        }
        int GetDataMes() const{
            return mes;
        }
        int GetDataAno() const{
            return ano;
        }

};

class Estado
{
    private:

        string estado;

        void validar(string) throw (invalid_argument);

    public:

        void SetEstado(string) throw (invalid_argument);

        string GetEstado() const{
            return estado;
        }

};
#endif // DOMINIOSHOTEL_H
