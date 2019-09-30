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
        Conta(std::string, std::string, int, int, int, float);
        ~Conta();

        //metodos get
        std::string getNum();
        std::string getCPF();
        std::string getData();
        float getSaldo();
        Lancamentos * getCabeca();
        void getLancamentos(Lancamentos *);
        void printSaldo();

        //metodos set
        void updateSaldo(float, int);

        void novoLancamento(Lancamentos *, float, int);
        static int num_contas;
        bool is_valid_data(int, int, int);

    private:
        std::string cpf;
        std::string num_conta;
        std::string data_abertura;
        float saldo_atual;
        Lancamentos * cabeca;
        int dia, mes, ano;
        void intToStr();
        bool bissexto();
};

#endif // CONTA_H
