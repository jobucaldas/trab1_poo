#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <string>

class Cliente {
public:
	// Constructors
	Cliente();
	~Cliente();

	// Setters
	void set_cliente(std::string, std::string, std::string, std::string, std::string);
	void set_email(std::string);
	void set_telefone(std::string);

	// Getters
	const void get_nome(std::string);
	const void get_cpf(std::string);
	const void get_endereco(std::string);
	const void get_telefone(std::string);
	const void get_email(std::string);

private:
	// Variables
	std::string nome;
	std::string cpf;
	std::string endereco;
	std::string telefone;
	std::string email;

	// Private Setters
	void set_nome(std::string);
	void set_cpf(std::string);
	void set_endereco(std::string);

	// Validators
	const bool is_valid_email(std::string);
	const bool is_valid_cpf();
};

#endif /* CLIENTE_H_ */
