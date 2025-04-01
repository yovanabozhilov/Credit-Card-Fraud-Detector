#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

// Define AES key and IV (must be the same in both encryption and decryption)
extern const unsigned char AES_KEY[16];
extern const unsigned char AES_IV[16];

// Function prototypes
std::string encryptData(const std::string& data);
std::string decryptData(const std::string& encryptedHex);

#endif // ENCRYPTION_H