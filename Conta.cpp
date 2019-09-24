#include "Conta.h"
#include "Cliente.h"
#include <iostream>
#include <string>

Conta::Conta(Conta * contas_vet, int clientes, std::string CPF, std::string conta, int dia, int mes, int ano float saldo)
{
    //ctor
    if (is_valid_conta(conta, contas_vet, clientes)) {
        cpf = CPF;
        num_conta = conta;
        saldo_atual = saldo;
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
        inttostr();
        if (is_valid_data == false)
            std::cout << "Data inválida";
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

void Conta::inttostr() {
    std::stringstream change;
    std::string aux1, aux2, aux3;
    change << this->dia;
    change >> aux1;
    change << this->mes;
    change >> aux2;
    change << this->ano;
    change >> aux3;
    this->data_abertura = aux1 + "/" + aux2 + "/" + aux3;
}

bool bissexto () {
    if ((ano % 400 == 0 || ano % 100 != 0) && ano % 4 == 0)
        return true;
    return false;
}

bool Conta::is_valid_data() {
    if (this->mes < 1 || this->mes > 12){
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
