#ifndef TRANSACTION_LOGGER_H
#define TRANSACTION_LOGGER_H

#include "TransactionData.h"  // Include the TransactionData class

// Function to log the transaction result to a file
void logTransaction(const TransactionData& transaction, const std::string& result);

#endif
