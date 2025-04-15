#include "decryption.h"
#include <openssl/evp.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

std::vector<unsigned char> hexToByteArray(const std::string& hex) {
    std::vector<unsigned char> bytes;
    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        unsigned char byte = static_cast<unsigned char>(std::stoi(byteString, nullptr, 16));
        bytes.push_back(byte);
    }
    return bytes;
}

std::string decryptData(const std::string& encryptedHex) {
    const unsigned char AES_KEY[16] = {
        's','e','c','r','e','t','1','2','3','4','5','6','7','8','9','0'
    };

    std::vector<unsigned char> encryptedBytes = hexToByteArray(encryptedHex);

    if (encryptedBytes.size() <= 16) return "";

    unsigned char iv[16];
    std::copy(encryptedBytes.begin(), encryptedBytes.begin() + 16, iv);

    std::vector<unsigned char> ciphertext(encryptedBytes.begin() + 16, encryptedBytes.end());

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return "";

    if (EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, AES_KEY, iv) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    std::vector<unsigned char> decrypted(ciphertext.size());
    int outLen;

    if (EVP_DecryptUpdate(ctx, decrypted.data(), &outLen,
                          ciphertext.data(), ciphertext.size()) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    int finalLen = 0;
    EVP_DecryptFinal_ex(ctx, decrypted.data() + outLen, &finalLen);
    outLen += finalLen;

    EVP_CIPHER_CTX_free(ctx);

    return std::string(reinterpret_cast<char*>(decrypted.data()), outLen);
}
