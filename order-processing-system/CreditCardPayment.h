#ifndef CREDITCARDPAYMENT_H
#define CREDITCARDPAYMENT_H

#include "PaymentMethod.h"

class CreditCardPayment : public PaymentMethod
{
public:
    explicit CreditCardPayment(const std::string& cardNumber);

    void pay(double amount) const override;

private:
    std::string cardNumber;
};

#endif // CREDITCARDPAYMENT_H
