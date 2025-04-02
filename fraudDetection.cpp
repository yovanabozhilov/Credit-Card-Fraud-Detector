#include "fraudDetection.h"
#include "TransactionData.h"
#include "TransactionLogger.h"
#include <iostream>
#include <vector>
#include <unordered_set>

std::string FraudDetection::detectFraud(const TransactionData& transaction) {
    std::string country = transaction.getCountry();  
    double amount = transaction.getAmount();  

    std::string fraudReason = "";

    if (country != "BG") {
        fraudReason += "Suspicious country";
    } 

    if (amount > 18000) {
        if (!fraudReason.empty()) fraudReason += " & "; 
        fraudReason += "Amount exceeds threshold";
    }

    if (!fraudReason.empty()) {
        return "Fraudulent: " + fraudReason;
    }

    return "Legitimate";
}

