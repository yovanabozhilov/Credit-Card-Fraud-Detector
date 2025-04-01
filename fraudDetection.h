#ifndef FRAUD_DETECTION_H
#define FRAUD_DETECTION_H
#include "TransactionData.h"
#include <string>

class FraudDetection {
public:
    static std::string detectFraud(const TransactionData& transaction);
};

#endif 
