#include "Banco.h"
#include "Cliente.h"
#include "Conta.h"
#include <string>
#include <sstream>
#include <iostream>
#include <new>
#include <iomanip>
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
    listaClientes *remover1;
    remover1 = (listaClientes *) malloc(sizeof(listaClientes));
    while (aux1 != NULL) {
        remover1 = aux1;
        aux1 = remover1->prox;
        free(remover1);
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
    while (aux->prox != NULL) {
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
            std::cout << "Digite os dados da conta: " << "\n" << "CPF (ja cadastrado): ";
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
        aux->prox = novo;
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
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    std::cout << "Cadastrando cliente..." << std::endl << "Insira dados:" << '\n' << "CPF: ";
	do {
		std::cin >> cpf;
		if (!is_valid_cpf(cpf))
			std::cout << "CPF invalido ou ja utilizado. Tente novamente." << '\n';
	} while (!is_valid_cpf(cpf));
	//std::cout << cpf<<std::endl;
	std::cout << "Nome: ";
	scanf("\n");
    std::getline(std::cin, nome);
    //std::cout << email << std::endl;
	std::cout << "Email: ";
	do {
		std::cin >> email;
		if (!is_valid_email(email))
			std::cout << "Email invalido!! Tente novamente" << std::endl;
	} while (!is_valid_email(email));
	//std::cout << nome<<std::endl;
    std::cout << "Telefone: ";
	scanf("\n");
    std::cin >> telefone;
	//std::cout << telefone<<std::endl;
    std::cout << "Endereco: ";
	scanf("\n");
	std::getline(std::cin, endereco);
	//std::cout << endereco<<std::endl;
    novo->cliente_atual = new Cliente(nome, cpf, endereco, telefone, email);
    aux->prox = novo;
    novo->prox = NULL;
    contcliente++;

}

void Banco::get_clientes()
{
    listaClientes *aux = this->clientes->prox;
    while (aux != NULL) {
        std::cout << aux->cliente_atual->toString() << "\n";
        aux = aux->prox;
    }
}

void Banco::set_cliente(std::string busca)
{
    int numPassos = buscaClientecpf(busca);
    listaClientes * aux = this->clientes;
    for (int i = 0; i < numPassos; i++)
        aux = aux->prox;
    std::string nome, endereco, telefone, email;
    std::cout << "Digite os dados do cliente: " << '\n'
              << "Nome: ";
    scanf("\n");
    std::getline(std::cin, nome);
    do {
        std::cout << "Email: ";
        std::cin >> email;
        if (is_valid_email(email) == false)
            std::cout << "Email invalido." << '\n';
    } while (is_valid_email(email) == false);
    std::cout << "Telefone: ";
    std::cin >> telefone;
    std::cout << "Endereco: ";
    scanf("\n");
    std::getline(std::cin, endereco);
    aux->cliente_atual->set_cliente(nome, busca, endereco, telefone, email);
}

void Banco::get_contas()
{
    listaContas *aux = this->contas->prox;
    while (aux != NULL) {
        std::cout << aux->conta_atual->toString() << "\n";
        aux = aux->prox;
    }
}

void Banco::rmv_cliente(std::string retirar) {
    listaClientes *atual = clientes->prox, *anterior = clientes, *morta;

    while (atual != NULL && atual->cliente_atual->get_cpf().compare(retirar) != 0) {
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

void Banco::rmv_conta(std::string retirar) {
    listaContas *atual = contas->prox, *anterior = contas, *morta;

    while (atual != NULL && atual->conta_atual->getNum().compare(retirar) != 0) {
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

//remove as contas vinculadas a um cliente
void Banco::rmv_conta_cpf(std::string retirar) {
    listaContas *atual = contas->prox, *anterior = contas, *morta;
    int flag;
    while (atual != NULL) {
        flag = 0;
        if (atual->conta_atual->getCPF().compare(retirar) == 0 && atual != NULL) {
            morta = (listaContas *) malloc (sizeof(listaContas));
            morta = atual;
            anterior->prox = morta->prox;
            free(morta);
            contconta--;
            atual = anterior->prox;
            flag = 1;
        }
        //verifica se ja excluiu uma conta
        if (!flag) {
            anterior = atual;
            atual = atual->prox;
        }
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
        std::endl << "Quantidade de contas cadastradas: " << this->contconta << std::endl;
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
    return false;
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
	for(i = 0; i < Cliente::num_clientes || aux != NULL; i++){
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
    int i = 0;
    listaClientes *aux = clientes->prox; //pula o nó cabeça da lista
    //procura se o cpf inserido está cadastrado
	while (aux != NULL && aux->cliente_atual->get_cpf().compare(cpf) != 0) {
		aux = aux->prox;
		i++;
	}
    if (aux == NULL) {
        std::cout << "CPF nao encontrado." << '\n';
        return 0;
    }
    return (i+1);
}

int Banco::buscaContaNum(std::string numeroBusca) {
    listaContas * aux = contas->prox;
    int i = 0;
    while (aux != NULL && aux->conta_atual->getNum().compare(numeroBusca) != 0) {
        aux = aux->prox;
        i++;
    }
    if (aux == NULL) {
        std::cout << "Conta nao encontrada." << '\n';
        return 0;
    }
    //retorna o numero de passos, a partir do inicio, até encontrar a conta
    //com o numero em questão
    return (i+1);
}

void Banco::novoLancamento(std::string numeroBusca, float valor, int operacao)
{
    listaContas * aux = this->contas;
    for (int i = 0; i < this->buscaContaNum(numeroBusca); i++) {
        aux = aux->prox;
    }
    aux->conta_atual->novoLancamento(aux->conta_atual->getCabeca(), valor, operacao);
}

void Banco::get_lancamento(std::string numeroBusca) {
    listaContas * aux = this->contas;
    int numeroIteracoes = this->buscaContaNum(numeroBusca);
    for (int i = 0; i < numeroIteracoes; i++) {
        aux = aux->prox;
    }
    if (aux != contas)
        aux->conta_atual->getLancamentos(aux->conta_atual->getCabeca());
}

void Banco::get_montante()
{
    listaContas * aux = contas->prox;
    float montante = 0;
    while (aux != NULL) {
        montante += aux->conta_atual->getSaldo();
        aux = aux->prox;
    }
    std::cout << "Montante do banco: " << std::fixed << std::setprecision(2) << montante << '\n';
}
