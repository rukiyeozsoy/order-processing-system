#include "PaypalPayment.h"

PaypalPayment::PaypalPayment(const std::string &email)
    : email(email) {
}

void PaypalPayment::pay(double amount) const
{
    qDebug()<<"PaypalPayment:" << amount;
}
