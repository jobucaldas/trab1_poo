#include "Conta.h"
#include "Cliente.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <sstream>

int Conta::num_contas = 0;

Conta::Conta(std::string CPF, std::string nconta,
            std::string data, float saldo) : cpf(CPF),
            num_conta(nconta), data_abertura(data)
{
    //ctor
    this->saldo_atual = saldo;
    this->cabeca = (Lancamentos *) malloc(sizeof(Lancamentos));
    this->cabeca->prox = NULL;
    num_contas++;
    std::cout << "Conta criada com sucesso!" << '\n'
              << "CPF: " << this->getCPF() << '\n'
              << "Numero da conta: " << this->getNum() << '\n'
              << "Saldo: " << this->getSaldo() << '\n'
              << "Data de abertura: " << this->getData() << "\n\n";
}

Conta::~Conta()
{
    //dtor
}

//Metodos get//////////////////////
std::string Conta::getNum() const
{
    return this->num_conta;
}

std::string Conta::getCPF() const
{
    return this->cpf;
}

std::string Conta::getData() const
{
    return this->data_abertura;
}

float Conta::getSaldo()
{
    return this->saldo_atual;
}
Lancamentos * Conta::getCabeca()
{
    return this->cabeca;
}

void Conta::printSaldo()
{
    std::cout << "Saldo atual: " << std::fixed << std::setprecision(2)
              << this->getSaldo() << "\n\n";
}

void Conta::getLancamentos(Lancamentos * cabeca)
{
    Lancamentos * aux = cabeca->prox;
    while (aux != NULL) {
        std::cout << "Lancamento: " << std::fixed << std::setprecision(2)
                  << aux->valor << '\n';
        aux = aux->prox;
    }
    std::cout << '\n';
}

//Metodos set///////////////////////
void Conta::updateSaldo(float novoSaldo, int operacao)
{
    //operacao = 1: credito, operacao = 2: debito
    if (operacao == 1 || (operacao == 2 && this->saldo_atual + novoSaldo >= 0)) {
        novoLancamento(this->cabeca, novoSaldo, operacao);
        this->saldo_atual = this->saldo_atual + novoSaldo;
    }
}

////////////////////////////////////

void Conta::novoLancamento(Lancamentos * head, float saldo, int operacao)
{
    //operacao = 1: credito, operacao = 2: debito
    if (operacao == 1 || (operacao == 2 && this->saldo_atual + saldo >= 0)) {
        Lancamentos * aux = cabeca;
        Lancamentos * novo = (Lancamentos *) malloc(sizeof(Lancamentos));
        novo->valor = saldo;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}

