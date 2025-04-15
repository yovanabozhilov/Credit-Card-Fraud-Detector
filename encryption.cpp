#include "encryption.h"
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

std::string byteArrayToHex(const unsigned char* data, size_t length) {
    std::stringstream ss;
    for (size_t i = 0; i < length; ++i)
        ss << std::setw(2) << std::setfill('0') << std::hex << (int)data[i];
    return ss.str();
}

std::string encryptData(const std::string& data) {
    const unsigned char AES_KEY[16] = {
        's','e','c','r','e','t','1','2','3','4','5','6','7','8','9','0'
    };

    unsigned char iv[16];
    if (RAND_bytes(iv, sizeof(iv)) != 1) {
        std::cerr << "Failed to generate IV.\n";
        return "";
    }

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return "";

    if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, AES_KEY, iv) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    std::vector<unsigned char> encryptedData(data.size() + EVP_MAX_BLOCK_LENGTH);
    int outLen = 0;

    if (EVP_EncryptUpdate(ctx, encryptedData.data(), &outLen,
                          reinterpret_cast<const unsigned char*>(data.c_str()), data.length()) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    int finalLen = 0;
    EVP_EncryptFinal_ex(ctx, encryptedData.data() + outLen, &finalLen);
    outLen += finalLen;

    EVP_CIPHER_CTX_free(ctx);

    std::vector<unsigned char> finalOutput;
    finalOutput.insert(finalOutput.end(), iv, iv + 16); 
    finalOutput.insert(finalOutput.end(), encryptedData.begin(), encryptedData.begin() + outLen); 

    return byteArrayToHex(finalOutput.data(), finalOutput.size());
}
