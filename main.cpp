#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Conta.h"
#include "Cliente.h"
#include "Banco.h"

using namespace std;

int main()
{
    int aux, opNum; //atua como opção
    string num_conta;
    Banco banco;
    float valor;

    do {
        cout << "O que deseja fazer?" << '\n'
             << "1- Adicionar um cliente" << '\n'
             << "2- Ver os clientes cadastrados" << '\n'
             << "3- Adicionar uma conta" << '\n'
             << "4- Fazer um lancamento" << '\n'
             << "5- Ver os lancamentos de uma conta" << '\n'
             << "6- Ver todas as contas" << '\n'
             << "7- Ver total de clientes e de contas" << '\n'
             << "8- Ver montante total do banco" << '\n'
             << "0- Sair" << '\n';
        cin >> opNum;
        cout << '\n';
        switch (opNum) {
            case (1): {
                banco.add_cliente();
                cout << '\n';
                break;
            }
            case (2): {
                banco.get_clientes();
                if (banco.getqtdcliente() == 0) {
                    cout << "Nenhum cliente cadastrado. Deseja cadastrar um novo? (1- sim | 0- nao)" << '\n';
                    cin >> aux;
                    if (aux)
                        banco.add_cliente();
                }
                cout << '\n';
                break;
            }
            case (3): {
                banco.add_conta();
                cout << '\n';
                break;
            }
            case (4): {
                cout << "Digite o numero da conta:" << '\n';
                cin >> num_conta;
                cout << "Digite o tipo de lancamento: (1- credito | 2- debito)" << '\n';
                cin >> aux;
                cout << "Digite o valor do lancamento:" << '\n';
                cin >> valor;
                banco.novoLancamento(num_conta, valor, aux);
                cout << '\n';
                break;
            }
            case (5): {
                cout << "Digite o numero da conta:" << '\n';
                cin >> num_conta;
                banco.get_lancamento(num_conta);
                cout << '\n';
                break;
            }
            case (6): {
                banco.get_contas();
                cout << '\n';
                break;
            }
            case (7): {
                cout << banco.toString() << '\n';
                break;
            }
            case (8): {
                banco.get_montante();
                cout << '\n';
                break;
            }
            case (0):
                break;
            default:
                cout << "Opcao nao disponivel. Tente novamente." << "\n\n";
        }
    } while (opNum);
    return 0;
}
