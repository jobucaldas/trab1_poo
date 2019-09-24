#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <string>

class Cliente {
public:
	// Constructors
	Cliente(Cliente*, int*, std::string, std::string, std::string, std::string, std::string);
	~Cliente();

	// Setters
	int set_cliente(std::string, std::string, std::string, std::string, std::string);
	int set_email(std::string);
	void set_telefone(std::string);

	// Getters
	const std::string get_nome();
	const std::string get_cpf();
	const std::string get_endereco();
	const std::string get_telefone();
	const std::string get_email();

private:
	// Variables
	std::string nome;
	std::string cpf;
	std::string endereco;
	std::string telefone;
	std::string email;
	static int n;
	Cliente* clientes;

	// Private Setters
	int set_cpf(std::string);
	void set_nome(std::string);
	void set_endereco(std::string);

	// Validators
	const bool is_valid_email(std::string);
	const bool is_valid_cpf(std::string);
};

#endif /* CLIENTE_H_ */
