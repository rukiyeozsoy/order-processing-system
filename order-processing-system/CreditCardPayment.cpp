#include "CreditCardPayment.h"

CreditCardPayment::CreditCardPayment(const std::string &cardNumber)
    : cardNumber(cardNumber) {}

void CreditCardPayment::pay(double amount) const
{
    qDebug()<<"CreditCardPayment:" << amount;
}
