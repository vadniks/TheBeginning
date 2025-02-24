
#pragma ide diagnostic ignored "modernize-use-nullptr"

#include <cryptopp/base64.h>
#include <cryptopp/hex.h>
#include "../include/decoder.hpp"

namespace decoder {

c_str base64(c_str message) {
    if (!message) return 0;

    CryptoPP::Base64Decoder decoder;
    decoder.Put(reinterpret_cast<byte const*>(message), strlen(message));
    decoder.MessageEnd();

    char* decoded;
    unsigned long size = decoder.MaxRetrievable();
    if (size and size <= SIZE_MAX) {
        decoded = static_cast<char*>(calloc(size, sizeof(char)));
        decoder.Get(reinterpret_cast<byte*>(decoded), size);
    }
    decoded[size] = '\0';
    return decoded;
}

c_str hex(c_str message) {
    if (!message) return 0;

    CryptoPP::HexDecoder decoder;
    decoder.Put(reinterpret_cast<byte const*>(message), strlen(message));
    decoder.MessageEnd();

    char* decoded;
    unsigned long size = decoder.MaxRetrievable();
    if (size and size <= SIZE_MAX) {
        decoded = static_cast<char*>(calloc(size, sizeof(char)));
        decoder.Get(reinterpret_cast<byte*>(decoded), size);
    }
    decoded[size] = '\0';
    return decoded;
}

}

c_str decode(c_str message, EncryptionMethod method) { return !message ? 0 :
    method == EncryptionMethod::BASE64
        ? decoder::base64(message)
        : method == EncryptionMethod::HEX
            ? decoder::hex(message)
            : 0; }
