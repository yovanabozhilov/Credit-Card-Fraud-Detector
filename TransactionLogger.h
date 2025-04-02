#ifndef TRANSACTION_LOGGER_H
#define TRANSACTION_LOGGER_H

#include "TransactionData.h"  

void logTransaction(const TransactionData& transaction, const std::string& result);

#endif
