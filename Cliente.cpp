#include "Cliente.h"

Cliente::Cliente(Cliente* clientes, int* n, std::string nome, std::string cpf, std::string endereco, std::string telefone, std::string email) {

}

Cliente::~Cliente() {

}

/* -----Validators------ */
const bool Cliente::is_valid_email(std::string email){
	std::string test1 = "@", test2 = ".com";
	return (email.find(test1)!=std::string::npos && email.find(test2)!=std::string::npos)?true:false;
}

const bool Cliente::is_valid_cpf(std::string cpf, Cliente* clientes, int n){
	int i, repeated;

	// Finds if cpf is already used
	for(i=0;i<n;i++)
		if(clientes[i].cpf.find(cpf)){
			repeated = 1;
			break;
		} else
			repeated = 0;

	return (cpf.length()==11 && repeated)?true:false;
}

/* -----Setters------ */
int Cliente::set_cliente(std::string nome, std::string cpf, std::string endereco, std::string telefone, std::string email, Cliente* clientes, int n){
	/*
	 *  - Exit Table -
	 *  1 - CPF   Error
	 *  2 - Email Error
	 */

	this->set_nome(nome);
	this->set_endereco(endereco);
	this->set_telefone(telefone);

	if(this->set_cpf(cpf, clientes, n)){
		return 1;
	}
	if(this->set_email(email)){
		return 2;
	}

	return 0;
}

void Cliente::set_nome(std::string nome){
	this->nome = nome;
}

int Cliente::set_cpf(std::string cpf, Cliente* clientes, int n){
	// Error code if given cpf is not valid
	if(!this->is_valid_cpf(cpf, clientes, n))
		return 1;

	this->cpf = cpf;
	return 0;
}

int Cliente::set_email(std::string email){
	if(!this->is_valid_email(email))
		return 1;

	this->email = email;
	return 0;
}

void Cliente::set_endereco(std::string endereco){
	this->endereco = endereco;
}

void Cliente::set_telefone(std::string telefone){
	this->telefone = telefone;
}

/* -----Getters----- */
const std::string Cliente::get_nome(){
	return this->nome;
}

const std::string Cliente::get_cpf(){
	return this->cpf;
}

const std::string Cliente::get_endereco(){
	return this->endereco;
}

const std::string Cliente::get_telefone(){
	return this->telefone;
}

const std::string Cliente::get_email(){
	return this->email;
}
