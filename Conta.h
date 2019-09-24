#ifndef CONTA_H
#define CONTA_H
#include <string>

class Conta
{
    public:
        Conta(Conta *, int, std::string, std::string, int, int, int float);
        ~Conta();
        int is_valid_conta(std::string, Conta *, int);

        //metodos get
        std::string getNum();
        std::string getCPF();
        std::string getData();
        float getSaldo();

        //metodos set
        void setSaldo(float);

        static int num_contas;

        bool is_valid_data();
        

    protected:

    private:
        std::string cpf;
        std::string num_conta;
        std::string data_abertura;
        float saldo_atual;
        int dia, mes, ano;
        void inttostr();
        bool bissexto();
};

#endif // CONTA_H
