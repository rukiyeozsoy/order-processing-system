TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle

SOURCES += \
        CreditCardPayment.cpp \
        PaymentMethod.cpp \
        PaypalPayment.cpp \
        main.cpp

HEADERS += \
    CreditCardPayment.h \
    PaymentMethod.h \
    PaypalPayment.h
