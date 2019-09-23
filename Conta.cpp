#include "Conta.h"
#include "Cliente.h"
#include <iostream>
#include <string>

using namespace std;

Conta::Conta(Conta *contas, static int clientes, string CPF, string conta, string data, float saldo)
{
    //ctor
    if (is_valid_conta(conta, num_contas)) {
        cpf = CPF;
        num_conta = conta;
        saldo_atual = saldo;
        data_abertura = data;
        clientes++;
    }
    else
        cout << "CPF ou conta invalidos." << '\n';
}

Conta::~Conta()
{
    //dtor
}

int is_valid_conta(string conta, static int contas)
{
    int flag = 1;
    for (int i = 0; i < contas; i++) {
        if (conta.compare(conta contas_vet[i].num_conta))
            flag = 0;
    }
    if (flag)
        return 1;
    return 0;
}
