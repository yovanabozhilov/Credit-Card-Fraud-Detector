#include "encryption.h"
#include <openssl/evp.h>
#include <vector>
#include <iostream>

// Convert hex string back to bytes
std::vector<unsigned char> hexToByteArray(const std::string& hex) {
    std::vector<unsigned char> bytes;
    for (size_t i = 0; i < hex.length(); i += 2)
        bytes.push_back(std::stoi(hex.substr(i, 2), nullptr, 16));
    return bytes;
}

// Decrypt AES-128-CBC encrypted data
std::string decryptData(const std::string& encryptedHex) {
    std::vector<unsigned char> encryptedBytes = hexToByteArray(encryptedHex);
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return "";

    // Now AES_KEY and AES_IV are correctly linked
    if (EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, AES_KEY, AES_IV) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    std::vector<unsigned char> decryptedData(encryptedBytes.size());
    int outLen;

    if (EVP_DecryptUpdate(ctx, decryptedData.data(), &outLen, encryptedBytes.data(), encryptedBytes.size()) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    int finalLen = 0;
    EVP_DecryptFinal_ex(ctx, decryptedData.data() + outLen, &finalLen);
    outLen += finalLen;

    EVP_CIPHER_CTX_free(ctx);
    return std::string(decryptedData.begin(), decryptedData.begin() + outLen);
}
