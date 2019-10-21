/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conta.cpp
 * Author: 769783
 * 
 * Created on 8 de outubro de 2019, 12:22
 */

#include "Conta.h"
#include "Cliente.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <sstream>

/* Contador para número de contas */
int Conta::num_contas = 0;

/* Construtor, inicia lista de lançamentos,
   inicia parametros,
   incrementa contador;  */
Conta::Conta(std::string CPF, std::string nconta,
            Data data, float saldo) : cpf(CPF),
            num_conta(nconta), data_abertura(data)
{

    this->saldo_atual = saldo;

    /* Cria lista de lançamentos deste cliente */
    this->cabeca = (Lancamentos *) malloc(sizeof(Lancamentos));
    this->cabeca->prox = NULL;

    num_contas++;

    std::cout << "Conta criada com sucesso!" << std::endl;
}

Conta::~Conta(){
    num_contas--;
}

/* Getters */
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
    return this->data_abertura.toString();
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
/* Mostra na tela histórico de lançamentos(extrato) */
void Conta::getLancamentos(Lancamentos *cabeca)
{
    Lancamentos *aux = cabeca->prox;
    while (aux != NULL) {
        std::cout << "Lancamento: " << std::fixed << std::setprecision(2)
                  << aux->valor << '\n';
        aux = aux->prox;
    }
    std::cout << "Saldo final: " << std::fixed << std::setprecision(2) << this->saldo_atual;
    std::cout << std::endl;
}

/* Métodos set */
void Conta::updateSaldo(float valor, int operacao)
{
    //operacao = 1: credito, operacao = 2: debito.
    if (operacao == 1 || (operacao == 2 && this->saldo_atual - valor >= 0)) {
        novoLancamento(this->cabeca, valor, operacao);
        this->saldo_atual = this->saldo_atual - valor;
    }
}

/* Atualiza a lista de lancamentos */

void Conta::novoLancamento(Lancamentos *head, float valor, int operacao)
{
    //operacao = 1: credito, operacao = 2: debito
    if (operacao == 1 || (operacao == 2 && this->saldo_atual - valor >= 0)) {
        this->saldo_atual -= valor;
        Lancamentos *aux = cabeca;
        Lancamentos *novo = (Lancamentos *) malloc(sizeof(Lancamentos));
        novo->valor = valor;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = NULL;
    }
}

/* toString */

std::string Conta::toString() const {
    std::stringstream format;
    format << "Apresentando dados da conta..." << std::endl
        << "Numero da conta: " << this->num_conta << std::endl
        << "CPF: " << this->cpf << std::endl << "Data de abertura: " << this->data_abertura.toString()
        << std::endl << "Saldo atual: " << std::fixed << std::setprecision(2) << this->saldo_atual << std::endl;
    return format.str();
}