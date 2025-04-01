#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "fraudDetection.h"
#include "rateLimiter.h"
#include "TransactionData.h"
#include "TransactionLogger.h"
#include "helperFunctions.h"

int main() {
    // Initialize Rate Limiter
    RateLimiter rateLimiter(10, 60);

    // User inputs
    std::string cardNumber;
    double amount;

    std::cout << "Enter Card Number: ";
    std::cin >> cardNumber;
    std::cout << "Enter Transaction Amount: ";
    std::cin >> amount;

    // Automatically get the user country and current date
    std::string country = getUserCountry();
    std::string currentDate = getCurrentDate();

    // Create transaction object
    TransactionData transaction(cardNumber, amount, currentDate, country);

    std::string maskedCard = maskCardNumber(cardNumber);

    // Display transaction details
    std::cout << "\n========================================" << std::endl;
    std::cout << "           TRANSACTION DETAILS          " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "🔒 Card: " << maskedCard << std::endl;
    std::cout << "📅 Date of Transaction:  " << transaction.getDate() << std::endl;
    std::cout << "🌍 Transaction made from: " << transaction.getCountry() << std::endl;
    std::cout << "💰 Transaction amount:    " << std::fixed << std::setprecision(2) << transaction.getAmount() << std::endl;

    // Check rate limit
    if (rateLimiter.isAllowed()) {
        std::cout << "\n🚀 Processing Transaction..." << std::endl;

        // Detect fraud
        std::string result = FraudDetection::detectFraud(transaction);

        // Display fraud result
        std::cout << "⚠️  Fraud Detection Result: " << result << std::endl;

        // Log the transaction
        logTransaction(transaction, result);
    } else {
        std::cout << "❌ Rate limit exceeded. Please try again later." << std::endl;
    }

    std::cout << "========================================\n" << std::endl;
    return 0;
}