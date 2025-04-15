#include "encryption.h"
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

const unsigned char AES_KEY[16] = { 's', 'e', 'c', 'r', 'e', 't', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
const unsigned char AES_IV[16] = { 'i', 'n', 'i', 't', 'v', 'e', 'c', 't', 'o', 'r', '1', '2', '3', '4', '5', '6' };

std::string byteArrayToHex(const unsigned char* data, size_t length) {
    std::stringstream ss;
    for (size_t i = 0; i < length; ++i)
        ss << std::setw(2) << std::setfill('0') << std::hex << (int)data[i];
    return ss.str();
}

std::string encryptData(const std::string& data) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return "";

    if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, AES_KEY, AES_IV) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    int paddedLength = data.length() + (16 - (data.length() % 16));
    std::vector<unsigned char> encryptedData(paddedLength);
    int outLen;

    if (EVP_EncryptUpdate(ctx, encryptedData.data(), &outLen, (unsigned char*)data.c_str(), data.length()) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    int finalLen = 0;
    EVP_EncryptFinal_ex(ctx, encryptedData.data() + outLen, &finalLen);
    outLen += finalLen;

    EVP_CIPHER_CTX_free(ctx);
    return byteArrayToHex(encryptedData.data(), outLen);
}
