#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Data.h"

class Conta
{
    public:
        /* Construtor e destrutor */
            Conta(const std::string, const std::string, const Data, float);
        ~Conta();

        /* M�todos get */
        std::string getNum() const;
        std::string getCPF() const;
        Data getData() const;
        float getSaldo();
        void getLancamentos(); //Extrato da conta;
        void printSaldo();
        std::vector<float> getVector();
        /* Metodo toString */
        std::string toString() const;

        /* Metodos set */
        void updateSaldo(float, int);
        void novoLancamento(float, int);

        /* Contador para numero de contas */
        static int num_contas;

    private:
        std::vector<float> lancamentos;
        
        const std::string cpf;
        const std::string num_conta;
        const Data dataAbertura;
        float saldo_atual;
};

#endif // CONTA_H
