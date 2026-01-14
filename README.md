# order-processing-system

Senaryo
Bir sipariş işleme sistemi geliştiriyorsun.
Uygulama hangi ödeme yönteminin kullanıldığını bilmemeli.
 
Gereksinimler
Abstraction
    PaymentMethod adında abstract base class
    pay(double amount) pure virtual
    Destructor virtual
Inheritance & Polymorphism
    CreditCardPayment
    PaypalPayment
    Her biri pay() fonksiyonunu kendi mantığıyla implemente etsin
Encapsulation
    Kart numarası / email private
    Setter / getter veya constructor ile erişilsin
Modern C++
    new / delete YASAK
    std::unique_ptr kullanılacak
STL Algorithms
    Siparişler:
        struct Order {
            int id;
            double amount;
        };
    Sipariş listesi:
        std::vector<Order> orders;
    Yapılacaklar:
        En az bir sipariş 1000’den büyük mü? → std::any_of
        Toplam sipariş tutarını hesapla → std::accumulate
        500’den küçük siparişleri sil → erase-remove_if
Application Code
    void processOrders(
        const std::vector<Order>& orders,
        const PaymentMethod& paymentMethod);
    Base class referansı kullanılmalı
    pay(totalAmount) çağrılmalı
 
