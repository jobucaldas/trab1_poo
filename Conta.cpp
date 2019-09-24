#include "Conta.h"
#include "Cliente.h"
#include <iostream>
#include <string>

using namespace std;

Conta::Conta(Conta * contas_vet, int clientes, string CPF, string conta, string data, float saldo)
{
    //ctor
    if (is_valid_conta(conta, contas_vet, clientes)) {
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

string Conta::getNum(Conta)
{
    return this->num_conta;
}

int Conta::is_valid_conta(string conta, Conta * contas_vet, int contas)
{
    int flag = 1;
    for (int i = 0; i < contas; i++) {
        if (conta.compare(getNum(contas_vet[i])))
            flag = 0;
    }
    if (flag)
        return 1;
    return 0;
}
