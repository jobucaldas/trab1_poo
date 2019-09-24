#include "Conta.h"
#include "Cliente.h"
#include <iostream>
#include <string>

Conta::Conta(Conta * contas_vet, int clientes, std::string CPF, std::string conta, std::string data, float saldo)
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
        std::cout << "CPF ou conta invalidos." << '\n';
}

Conta::~Conta()
{
    //dtor
}

//Metodos get//////////////////////
std::string Conta::getNum()
{
    return this->num_conta;
}

std::string Conta::getCPF()
{
    return this->cpf;
}

std::string Conta::getData()
{
    return this->data_abertura;
}

float Conta::getSaldo()
{
    return this->saldo_atual;
}

//Metodos set///////////////////////
void Conta::setSaldo(float novoSaldo)
{
    this->saldo_atual = novoSaldo;
}

////////////////////////////////////

int Conta::is_valid_conta(std::string conta, Conta * contas_vet, int contas)
{
    int flag = 1;
    for (int i = 0; i < contas; i++) {
        if ( conta.compare( contas_vet[i].getNum() ) )
            flag = 0;
    }
    if (flag)
        return 1;
    return 0;
}
