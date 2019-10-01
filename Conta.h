#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <string>
#include <stdlib.h>

typedef struct lancamentos {
    float valor;
    struct lancamentos * prox;
} Lancamentos;

class Conta
{
    public:
        Conta(const std::string, const std::string, const std::string, float);
        ~Conta();

        //metodos get
        std::string getNum() const;
        std::string getCPF() const;
        std::string getData() const;
        float getSaldo();
        Lancamentos * getCabeca();
        void getLancamentos(Lancamentos *);
        void printSaldo();

        //metodos set
        void updateSaldo(float, int);

        void novoLancamento(Lancamentos *, float, int);
        static int num_contas;

    private:
        const std::string cpf;
        const std::string num_conta;
        const std::string data_abertura;
        float saldo_atual;
        Lancamentos * cabeca;
};

#endif // CONTA_H
