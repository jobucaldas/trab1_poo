#include "Banco.h"
#include "Cliente.h"
#include "Conta.h"
#include <string>
#include <iostream>
#include <new>

Banco::Banco(int n) {
    contas = (listaContas *) malloc(sizeof(listaContas));
    contas->prox = NULL;
}

Banco::~Banco() {

}

//metodos de lista//

void Banco::add_cliente()
{
    listaContas *aux = this->contas;
    listaContas * novo = (listaContas *) malloc(sizeof(listaContas));
    while (aux != NULL) {
        aux = aux->prox;
    }
    std::string numero_conta, rg;
    int dia, mes, ano;
    float saldo;
    std::cout << "Digite o numero da conta:" << '\n';
    std::cin >> numero_conta;

    if (is_valid_numConta(numero_conta)) {
        std::cout << "Digite os dados da conta:" << '\n'
              << "RG:" << '\n';
        std::cin >> rg;
        std::cout << "Data de abertura, no formato: 'dia mes ano':" << '\n';
        std::cin >> dia >> mes >> ano;
        std::cout << "Saldo inicial:" << '\n';
        std::cin >> saldo;
        novo->conta_atual = new Conta(rg, numero_conta, dia, mes, ano, saldo);
        this->contas->prox = novo;
        novo->prox = NULL;
    }
    else
        std::cout << "Numero ja utilizado. Tente novamente." << '\n';
}

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
