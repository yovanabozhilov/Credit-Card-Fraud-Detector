#include "TransactionLogger.h"
#include "encryption.h"
#include "decryption.h"
#include <iostream>
#include <fstream>
#include <string>

void logTransaction(const TransactionData& transaction, const std::string& result) {

    std::string encryptedCard = encryptData(transaction.getCardNumber());
    // std::string decryptedData = decryptData(encryptedCard);

    std::ofstream logFile("transaction_log.txt", std::ios_base::app);
    logFile << "Encrypted Card Number: " << encryptedCard
            << ", Country: " << transaction.getCountry()
            << ", Amount: " << transaction.getAmount()
            << ", Date: " << transaction.getDate()
            << ", Result: " << result << std::endl;
           // << ", Decrypted Card Number: " << decryptedData << std::endl;
}

