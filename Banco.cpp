#include "Banco.h"
#include "Cliente.h"
#include "Conta.h"
#include <string>
#include <sstream>
#include <iostream>
#include <new>
#include <stdlib.h>
#include <stdio.h>

int Banco::contcliente = 0;
int Banco::contconta = 0;

Banco::Banco() {
    contas = (listaContas *) malloc(sizeof(listaContas)); //Inicializa lista de contas.
    contas->prox = NULL;
    clientes = (listaClientes *) malloc(sizeof(listaClientes));
    clientes->prox = NULL;
}

Banco::~Banco() {

    /* Libera todas as contas */
    listaContas *aux = contas->prox;
    listaContas *remover;
    remover = (listaContas *) malloc(sizeof(listaContas));
    while (aux != NULL) {
        remover = aux;
        aux = remover->prox;
        free(remover);
        contconta--;
    }
    contas->prox = NULL;

    /* Libera todos os clientes */
    listaClientes *aux1 = clientes->prox;
    listaContas *remover1;
    remover1 = (listaContas *) malloc(sizeof(listaContas));
    while (aux != NULL) {
        remover = aux;
        aux = remover->prox;
        free(remover);
        contcliente--;
    }
    contas->prox = NULL;
}

/* Métodos */

void Banco::add_conta()
{
    //Guarda conta no fim da lista;
    listaContas *aux = this->contas;
    listaContas *novo = (listaContas *) malloc(sizeof(listaContas));
    while (aux != NULL) {
        aux = aux->prox;
    }
    //Inicializa variáveis da conta;
    std::string numero_conta, data, cpf;
    int dia, mes, ano;
    float saldo;

    std::cout << "Digite o numero da conta: " << "\n";
    std::cin >> numero_conta;

    //Cria uma conta nova(se for válido);
    if (is_valid_numConta(numero_conta)) {
        do {
            std::cout << "Digite os dados da conta: " << "\n" << "CPF (já cadastrado): ";
            std::cin >> cpf;
        } while (!buscaClientecpf(cpf));
        do {
            std::cout << "Data de abertura, no formato: 'dia mes ano': " << "\n";
            std::cin >> dia >> mes >> ano;
        } while (is_valid_data(dia, mes, ano) == false);
        data = intToStr(dia, mes, ano);

        std::cout << "Saldo inicial:" << "\n";
        std::cin >> saldo;
        novo->conta_atual = new Conta(cpf, numero_conta, data, saldo);
        this->contas->prox = novo;
        novo->prox = NULL;
        contconta++;
    }
    else
        std::cout << "Numero ja utilizado. Tente novamente." << "\n";
}

void Banco::add_cliente()
{
    /* Variáveis para cadastro de cliente */
    std::string cpf, nome, endereco, email, telefone;

    /* Avança para a última posição da lista de clientes */
    listaClientes *aux = this->clientes;
    listaClientes *novo = (listaClientes *) malloc(sizeof(listaClientes));
    while (aux != NULL) {
        aux = aux->prox;
    }
    std::cout << "Cadastrando cliente..." << std::endl << "Insira dados, CPF: ";
    std::cin >> cpf;
    if (is_valid_cpf(cpf)) {
        std::cout << "Email: ";
        std::cin >> email;
        if(is_valid_email(email)){
            std::cout << "Nome: ";
            std::getline(std::cin, nome);
            std::cout << "Telefone: ";
            std::cin >> telefone;
            std::cout << "Endereço: ";
            std::cin >> endereco;
            novo->cliente_atual = new Cliente(nome, cpf, endereco, telefone, email);
            this->clientes->prox = novo;
            novo->prox = NULL;
            contcliente++;
        } else
            std::cout << "Email inválido!!" << std::endl;
    }
    else
        std::cout << "CPF ja utilizado. Tente novamente." << "\n";
}

void Banco::rmv_cliente(listaClientes *retirar) {
    listaClientes *atual = clientes->prox, *anterior = clientes, *morta;

    while (atual != NULL && atual != retirar) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL) {
        morta = (listaClientes *) malloc (sizeof(listaClientes));
        morta = atual;
        anterior->prox = morta->prox;
        free(morta);
        contcliente--;
    }
}

void Banco::rmv_conta(listaContas *retirar) {
    listaContas *atual = contas->prox, *anterior = contas, *morta;

    while (atual != NULL && atual != retirar) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL) {
        morta = (listaContas *) malloc (sizeof(listaContas));
        morta = atual;
        anterior->prox = morta->prox;
        free(morta);
        contconta--;
    }
}
/* getters de statics */
int Banco::getqtdcliente() {
    return contcliente;
}

int Banco::getqtdconta() {
    return contconta;
}

std::string Banco::toString() const{
    std::stringstream format;
    format << "Quantidade de clientes cadastrados no banco: " << this->contcliente <<
        std::endl << "Quatidade de contas cadastradas: " << this->contconta << std::endl;
    return format.str();
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

const bool Banco::is_valid_email(std::string email){
	std::string test1 = "@", test2 = ".com";
	return (email.find(test1)!= std::string::npos && email.find(test2) != std::string::npos) ? true : false;
}

const bool Banco::is_valid_cpf(std::string cpf){
	int i, repeated = 0;
    listaClientes *aux = clientes;
    aux = aux->prox; //Pula o nó cabeça da lista;
	// Procura se há algum cpf repetido na lista;
	for(i = 0; i < Cliente::num_clients || aux != NULL; i++){
        if(aux->cliente_atual->get_cpf() == cpf){
			repeated = 1;
			break;
		}
		aux = aux->prox;
	}
	return (cpf.length() == 11 && !repeated) ? true : false;
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
/* Busca cpf na lista de clientes e retorna 1 se encontrou */
int Banco::buscaClientecpf(std::string cpf) {
    listaClientes *aux = clientes;
    while (aux != NULL && aux->cliente_atual->get_cpf() != cpf)
        aux = aux->prox;
    if (aux == NULL)
        return 0;
    return 1;
}

