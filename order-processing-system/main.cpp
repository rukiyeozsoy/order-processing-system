#include <vector>

#include "PaymentMethod.h"
#include "CreditCardPayment.h"
#include "PaypalPayment.h"

using namespace std;

/*
 *  Senaryo
 *  Bir sipariş işleme sistemi geliştiriyorsun.
 *  Uygulama hangi ödeme yönteminin kullanıldığını bilmemeli.
 *
 *  Gereksinimler
 *  Abstraction
 *      PaymentMethod adında abstract base class
 *      pay(double amount) pure virtual
 *      Destructor virtual
 *  Inheritance & Polymorphism
 *      CreditCardPayment
 *      PaypalPayment
 *      Her biri pay() fonksiyonunu kendi mantığıyla implemente etsin
 *  Encapsulation
 *      Kart numarası / email private
 *      Setter / getter veya constructor ile erişilsin
 *  Modern C++
 *      new / delete YASAK
 *      std::unique_ptr kullanılacak
 *  STL Algorithms
 *      Siparişler:
 *          struct Order {
 *              int id;
 *              double amount;
 *          };
 *      Sipariş listesi:
 *          std::vector<Order> orders;
 *      Yapılacaklar:
 *          En az bir sipariş 1000’den büyük mü? → std::any_of
 *          Toplam sipariş tutarını hesapla → std::accumulate
 *          500’den küçük siparişleri sil → erase-remove_if
 *  Application Code
 *      void processOrders(
 *          const std::vector<Order>& orders,
 *          const PaymentMethod& paymentMethod);
 *      Base class referansı kullanılmalı
 *      pay(totalAmount) çağrılmalı
 */

struct Order {
    int id;
    double amount;
};

void processOrder(std::vector<Order>& orders,
                   const PaymentMethod& paymentMethod) {

    bool v = std::any_of(orders.begin(),orders.end(), [](const Order& o){
        return o.amount < 1000;
    });
    if(v==false)
        qDebug()<<"1000'den küçük";

    double totalAmount = std::accumulate(
        orders.begin(), orders.end(), 0.0,
        [](double sum, const Order& o) {
            return sum + o.amount;
        });

    qDebug()<<"Toplam sipariş tutarı:" <<totalAmount;

    orders.erase(
        std::remove_if(
            orders.begin(), orders.end(),
            [](const Order& o) {
                return o.amount < 500;
            }),
        orders.end()
        );

    paymentMethod.pay(totalAmount);
}

int main()
{
    std::unique_ptr<CreditCardPayment> card = make_unique<CreditCardPayment>("1234");
    std::unique_ptr<PaypalPayment> email = make_unique<PaypalPayment>("test");

    std::vector<Order> orders = {
        {1, 4000},
        {2, 1200},
        {3, 800},
        {4, 200}
    };

    processOrder(orders, *card);
    processOrder(orders, *email); // Kod akışında 500'den küçük değerleri sildiği için silinen değer kadar eksi çıkabilir
    processOrder(orders, *card);

    return 0;
}
