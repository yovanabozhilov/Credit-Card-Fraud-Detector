#include "fraudDetection.h"
#include "TransactionData.h"
#include "TransactionLogger.h"
#include <iostream>
#include <vector>
#include <unordered_set>

std::string FraudDetection::detectFraud(const TransactionData& transaction) {
    std::string country = transaction.getCountry();  // Get the country from the transaction
    double amount = transaction.getAmount();  // Get the amount from the transaction

    std::string fraudReason = "";

    // Check if the country is suspicious
    if (country != "BG") {
        fraudReason += "Suspicious country";
    } 

    // Check if the amount exceeds the threshold
    if (amount > 18000) {
        if (!fraudReason.empty()) fraudReason += " & "; // Add separator if there's already a fraud reason
        fraudReason += "Amount exceeds threshold";
    }

    // If there is any fraud reason, return it
    if (!fraudReason.empty()) {
        return "Fraudulent: " + fraudReason;
    }

    return "Legitimate";
}

