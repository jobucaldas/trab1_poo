#ifndef BANCO_H_
#define BANCO_H_

#include <iostream>
#include "Cliente.h"
#include "Conta.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include <string>
#include <list>

/* Classe para gerir o banco. */
class Banco
{
    public:
        Banco();
        ~Banco();

        /* Adiciona/remove/altera clientes/contas. */
        void add_cliente_f();
		void add_cliente_j();

        void add_conta_p();
		void add_conta_c();

        void rmv_cliente_f(std::string);
		void rmv_cliente_j(std::string);

        void rmv_conta(std::string);

        void set_cliente_f(std::string);
		void set_cliente_j(std::string);

        /* M�todo toString */
        std::string toString() const;

        /* getters para membros static */
        static int getqtdcliente_j();
		static int getqtdcliente_f();
		static int getqtdcliente();
        static int getqtdconta_p();
		static int getqtdconta_c();
		static int getqtdconta();

        /* getters para listas */
        void get_clientes();//
        void get_contas();//
        void get_lancamento(std::string);
		void get_montante();//

        //procura uma conta para fazer lancamento
        void novoLancamento(std::string, float, int);


    private:
        /* Lista de clientes e contas, composicao de objetos */
        std::list<ContaCorrente> listaContas_c;
		std::list<ContaPoupanca> listaContas_p;
        std::list<PessoaJuridica> listaClientes_j;
		std::list<PessoaFisica> listaClientes_f;

        static int contcliente_f;
        static int contconta_c;
		static int contcliente_j;
		static int contconta_p;

        //validators conta
        bool is_valid_numConta(std::string);
        bool is_valid_data(int, int, int);

        //validators cliente
        const bool is_valid_email(std::string);//
        const bool is_valid_cpf(std::string);//
        const bool is_valid_cnpj(std::string);//

        //auxiliary functions
        bool bissexto(int);
        int buscaCliente_cpf(std::string); //
		int buscaCliente_cnpj(std::string);// //Busca um cpf de cliente cadastrado;
        int buscaContaNum_c(std::string); //
		int buscaContaNum_p(std::string); //    //Busca a conta com o numero respectivo;
};

#endif /* BANCO_H_ */
