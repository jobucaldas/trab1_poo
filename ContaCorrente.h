#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "Conta.h"

class ContaCorrente : public Conta {
public:
    ContaCorrente();
    ~ContaCorrente();
    virtual std::string toString() const;
private:

};

#endif /* CONTACORRENTE_H */

