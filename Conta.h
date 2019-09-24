#ifndef CONTA_H
#define CONTA_H
#include <string>

using namespace std;

class Conta
{
    public:
        Conta(Conta *, int, string, string, string, float);
        ~Conta();
        int is_valid_conta(string, Conta *, int);
        string getNum(Conta);
        static int num_contas;
    protected:

    private:
        string cpf;
        string num_conta;
        string data_abertura;
        float saldo_atual;
};

#endif // CONTA_H
