#include <iostream>
#include <stdlib.h>
#include <new>

#include "Conta.h"
#include "Cliente.h"
#include "Banco.h"

using namespace std;

int main()
{
    Banco banco;
    banco.add_conta();
    banco.add_conta();
    banco.add_conta();
    std::cout << Conta::num_contas;
    return 0;
}
