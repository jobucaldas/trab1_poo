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

typedef struct clientes {
    Cliente *cliente_atual;
    struct clientes *prox;
} listaClientes;

class Banco
{
    public:
        Banco();
        ~Banco();
        void add_cliente();
        void add_conta();
        void rmv_cliente();
        void rmv_conta();

    private:
        int n, m;
        listaClientes *clientes;
        listaContas *contas;

        //validators//
        bool is_valid_numConta(std::string);
        bool is_valid_data(int, int, int);

        //auxiliary functions
        std::string intToStr(int, int, int);
        bool bissexto(int);
};

#endif /* BANCO_H_ */
