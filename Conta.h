#ifndef CONTA_H
#define CONTA_H
#include <string>

using namespace std;

class Conta
{
    public:
        Conta(string, string, string, float, int);
        ~Conta();
        int is_valid_conta(string, static int);
        static int num_contas;
    protected:

    private:
        string cpf;
        string num_conta;
        string data_abertura;
        float saldo_atual;
};

#endif // CONTA_H
