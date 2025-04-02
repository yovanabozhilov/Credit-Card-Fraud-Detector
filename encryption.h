#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

extern const unsigned char AES_KEY[16];
extern const unsigned char AES_IV[16];

std::string encryptData(const std::string& data);
std::string decryptData(const std::string& encryptedHex);

#endif 
