#ifndef DOMINIOSHOTEL_H
#define DOMINIOSHOTEL_H

#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdlib>

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

        string data;

        const static int ANO_LIMITE_SUP = 2099;
        const static int ANO_LIMITE_INF = 2000;

        const static int DIA_LIMITE_SUP1 = 31;
        const static int DIA_LIMITE_SUP2 = 30;
        const static int DIA_LIMITE_SUP3 = 29;
        const static int DIA_LIMITE_SUP4 = 28;
        const static int DIA_LIMITE_INF = 1;

        void validar(string) throw (invalid_argument);

    public:

        void SetData(string) throw (invalid_argument);

        string GetData() const{
            return data;
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
