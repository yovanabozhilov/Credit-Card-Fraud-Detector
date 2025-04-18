#include "TransactionData.h"

TransactionData::TransactionData(std::string cardNumber, double amount, std::string date, std::string country)
    : cardNumber(cardNumber), amount(amount), date(date), country(country) {}

std::string TransactionData::getCardNumber() const { return cardNumber; }
double TransactionData::getAmount() const { return amount; }
std::string TransactionData::getDate() const { return date; }
std::string TransactionData::getCountry() const { return country; }
