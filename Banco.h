#ifndef BANCO_H_
#define BANCO_H_

#include <iostream>
#include "Cliente.h"
#include "Conta.h"

class Banco {
public:
	Banco();
	~Banco();
	void add_cliente();
	void add_conta();
	void rmv_cliente();
	void rmv_conta();

private:
	int n, m;
	Cliente *clientes;
	Conta *contas;

};

#endif /* BANCO_H_ */
