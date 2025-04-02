#ifndef TRANSACTION_DATA_H
#define TRANSACTION_DATA_H

#include <string>

class TransactionData {
private:
    std::string cardNumber;
    double amount;
    std::string date;
    std::string country;

public:
    TransactionData(std::string cardNumber, double amount, std::string date, std::string country);

    std::string getCardNumber() const;
    double getAmount() const;
    std::string getDate() const;
    std::string getCountry() const;
};

#endif
