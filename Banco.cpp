#include "Banco.h"
#include "Cliente.h"
#include "Conta.h"
#include <string>
#include <sstream>
#include <iostream>
#include <new>

Banco::Banco() {
    contas = (listaContas *) malloc(sizeof(listaContas));
    contas->prox = NULL;
    contas->conta_atual = 0;
}

Banco::~Banco() {
    listaContas * aux = contas;
    listaContas * remover;
    while (aux != NULL) {
        remover = aux;
        delete remover;
        aux = aux->prox;
    }
}

//list methods//

void Banco::add_conta()
{
    listaContas *aux = this->contas;
    listaContas * novo = (listaContas *) malloc(sizeof(listaContas));
    while (aux != NULL) {
        aux = aux->prox;
    }
    std::string numero_conta, rg, data;
    int dia, mes, ano;
    float saldo;
    std::cout << "Digite o numero da conta:" << '\n';
    std::cin >> numero_conta;

    if (is_valid_numConta(numero_conta)) {
        std::cout << "Digite os dados da conta:" << '\n'
              << "RG:" << '\n';
        std::cin >> rg;
        do {
            std::cout << "Data de abertura, no formato: 'dia mes ano':" << '\n';
            std::cin >> dia >> mes >> ano;
        } while (is_valid_data(dia, mes, ano) == false);
        data = intToStr(dia, mes, ano);

        std::cout << "Saldo inicial:" << '\n';
        std::cin >> saldo;
        novo->conta_atual = new Conta(rg, numero_conta, data, saldo);
        this->contas->prox = novo;
        novo->prox = NULL;
    }
    else
        std::cout << "Numero ja utilizado. Tente novamente." << '\n';
}

void Banco::add_cliente()
{
    listaClientes * aux = this->clientes;
    listaClientes * novo = (listaClientes *) malloc(sizeof(listaClientes));
    while (aux != NULL) {
        aux = aux->prox;
    }
    //IMPLEMENTAR
    /*if (is_valid_cpf(numero_cpf)) {
        novo->cliente_atual = new Cliente(clientes, n, nome, cpf, endereco, telefone, emailo);
        this->clientes->prox = novo;
        novo->prox = NULL;
    }
    else
        std::cout << "CPF ja utilizado. Tente novamente." << '\n';
    */
}

//validators//

bool Banco::is_valid_numConta(std::string numero)
{
    listaContas *aux = this->contas->prox;
    while (aux != NULL) {
        if (aux->conta_atual->getNum().compare(numero) == 0)
            return false;
        aux = aux->prox;
    }
    return true;
}

bool Banco::is_valid_data(int dia, int mes, int ano) {
    if (mes < 1 || mes > 12){
        return false;
    }
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return (dia > 0 && dia < 32) ? true : false;
        case 4: case 6: case 9: case 11:
            return (dia > 0 && dia < 31) ? true : false;
        case 2:
            if (bissexto(ano)) {
                return (dia > 0 && dia < 30) ? true : false;
            }
            return (dia > 0 && dia < 29) ? true : false;
    }
}

//auxiliary functions//
std::string Banco::intToStr(int dia, int mes, int ano) {
    std::stringstream change;
    std::string aux;
    change << dia << "/" << mes << "/" << ano;
    change >> aux;
    return aux;
}

bool Banco::bissexto (int ano) {
    if ((ano % 400 == 0 || ano % 100 != 0) && ano % 4 == 0)
        return true;
    return false;
}
