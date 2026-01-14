#ifndef PAYMENTMETHOD_H
#define PAYMENTMETHOD_H

#include <QDebug>

class PaymentMethod
{
public:
    PaymentMethod();
    virtual ~PaymentMethod() = default;

    virtual void pay(double amount) const = 0;
};

#endif // PAYMENTMETHOD_H
