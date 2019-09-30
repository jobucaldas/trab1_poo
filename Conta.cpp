#include "Conta.h"
#include "Cliente.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <sstream>

int Conta::num_contas = 0;

Conta::Conta(std::string CPF, std::string nconta,
            int dia, int mes, int ano, float saldo)
{
    //ctor
    if ((is_valid_data(dia, mes, ano) == true) ) {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
        intToStr();
        this->cpf = CPF;
        this->num_conta = nconta;
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
    if (is_valid_data(dia, mes, ano) == false) {
        std::cout << "Data invalida. A conta sera deletada." << '\n';
        this->~Conta();
    }
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

void Conta::intToStr() {
    std::stringstream change;
    std::string aux;
    change << this->dia << "/" << this->mes << "/" << this->ano;
    change >> aux;
    this->data_abertura = aux;
}

bool Conta::bissexto () {
    if ((ano % 400 == 0 || ano % 100 != 0) && ano % 4 == 0)
        return true;
    return false;
}

bool Conta::is_valid_data(int dia, int mes, int ano) {
    if (mes < 1 || mes > 12){
        return false;
    }
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return (dia > 0 && dia < 32) ? true : false;
        case 4: case 6: case 9: case 11:
            return (dia > 0 && dia < 31) ? true : false;
        case 2:
            if (bissexto()) {
                return (dia > 0 && dia < 30) ? true : false;
            }
            return (dia > 0 && dia < 29) ? true : false;
    }
}
