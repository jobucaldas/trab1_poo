#ifndef BANCO_H_
#define BANCO_H_

#include <iostream>
#include "Cliente.h"
#include "Conta.h"
#include <string>

typedef struct contas {
    Conta *conta_atual;
    struct contas *prox;
} listaContas;

class Banco
{
    public:
        Banco(int);
        ~Banco();
        void add_cliente();
        void add_conta();
        void rmv_cliente();
        void rmv_conta();

    private:
        int n, m;
        Cliente *clientes;
        listaContas *contas;

        //validators//
        bool is_valid_numConta(std::string);
};

#endif /* BANCO_H_ */
