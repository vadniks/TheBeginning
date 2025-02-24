
#pragma ide diagnostic ignored "modernize-use-nullptr"

#include <cryptopp/base64.h>
#include <cryptopp/hex.h>
#include "../include/coder.hpp"

namespace coder {

c_str base64(c_str message) {
    if (!message) return 0;

    CryptoPP::Base64Encoder encoder;
    encoder.Put(reinterpret_cast<byte const*>(message), strlen(message));
    encoder.MessageEnd();

    char* encoded;
    unsigned long size = encoder.MaxRetrievable();
    if (size) {
        encoded = static_cast<char*>(calloc(size, sizeof(char)));
        encoder.Get(reinterpret_cast<byte*>(encoded), size);
    }
    encoded[size - 1] = '\0';
    return encoded;
}

c_str hex(c_str message) {
    if (!message) return 0;

    CryptoPP::HexEncoder encoder;
    encoder.Put(reinterpret_cast<byte const*>(message), strlen(message));
    encoder.MessageEnd();

    char* encoded;
    unsigned long size = encoder.MaxRetrievable();
    if (size) {
        encoded = static_cast<char*>(calloc(size, sizeof(char)));
        encoder.Get(reinterpret_cast<byte*>(encoded), size);
    }
    encoded[size] = '\0';
    return encoded;
}

}

c_str encode(c_str message, EncryptionMethod method) { return !message ? 0 :
    method == EncryptionMethod::BASE64
        ? coder::base64(message)
        : method == EncryptionMethod::HEX
            ? coder::hex(message)
            : 0; }
