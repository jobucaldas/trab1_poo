#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Data.h"

typedef struct lancamentos {
    float valor;
    struct lancamentos *prox;
} Lancamentos;

class Conta
{
    public:
        /* Construtor e destrutor */
        Conta(const std::string, const std::string, const Data, float);
        ~Conta();

        /* Métodos get */
        std::string getNum() const;
        std::string getCPF() const;
        std::string getData() const;
        float getSaldo();
        Lancamentos *getCabeca(); //Lista de lançamentos;
        void getLancamentos(Lancamentos *); //Extrato da conta;
        void printSaldo();

        /* Método toString */
        std::string toString() const;

        /* Métodos set */
        void updateSaldo(float, int);
        void novoLancamento(Lancamentos *, float, int);

        /* Contador para número de contas */
        static int num_contas;

    private:
        const std::string cpf;
        const std::string num_conta;
        const Data data_abertura;
        float saldo_atual;
        Lancamentos *cabeca; //Cabeça da lista de lançamentos;
};

#endif // CONTA_H