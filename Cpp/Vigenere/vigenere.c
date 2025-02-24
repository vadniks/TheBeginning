/*!
 *  \author Vad Nik
 *  \date December 16th, 2019
 *  \brief A little crypto util using Vigenere's algorithm with extended alphabet.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* str;
typedef const char* c_str;

c_str CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-=_+~`{}[]:;\"'\\|/<>,.?";
c_str TIP = "<msg (without whitespaces)> <key> <mode (e/d/q)>";
__attribute_const__ int charsLen, msgLen, keyLen;

enum MODE {
    ENCRYPT = 'e',
    DECRYPT = 'd'
};

__attribute_pure__ str encrypt(str msg, str /*extended*/ key);
__attribute_pure__ str decrypt(str msg, str /*extended*/ key);
__attribute_pure__ int getId(char c);
__attribute_pure__ str extendKey(str msg, c_str key);

int main(int argc, str* argv)
{
    if (argc != 4) {
        puts(TIP);
        return EXIT_FAILURE;
    }

    charsLen = (int) strlen(CHARS);

    str msg, key, result;
    char mode;

    msg = argv[1];
    key = argv[2];
    mode = argv[3][0];

    msgLen = (int) strlen(msg);
    keyLen = (int) strlen(key);

    switch (mode)
    {
        case ENCRYPT:
            result = encrypt(msg, extendKey(msg, key));
            break;
        case DECRYPT:
            result = decrypt(msg, extendKey(msg, key));
            break;
        default:
            puts(TIP);
            return EXIT_FAILURE;
    }

    if (result != NULL)
        printf("%s\n", result);

    return EXIT_SUCCESS;
}

str encrypt(str msg, str key)
{
    str enc = malloc(msgLen * sizeof(char));

    int i;
    for (i = 0; i < msgLen; i++)
        enc[i] = CHARS[(getId(msg[i]) + getId(key[i])) % charsLen];
    enc[i] = '\0';

    return enc;
}

str decrypt(str msg, str key)
{
    str dec = malloc(msgLen * sizeof(char));

    int i;
    for (i = 0; i < msgLen; i++)
        dec[i] = CHARS[((getId(msg[i]) - getId(key[i])) + charsLen) % charsLen];
    dec[i] = '\0';

    return dec;
}

int getId(const char c)
{
    for (int i = 0; i < charsLen; ++i)
    {
        if (CHARS[i] == c)
            return i;
    }

    return -1;
}

str extendKey(str msg, c_str key)
{
    str newKey = malloc(strlen(msg) * sizeof(char));

    int i, j;
    for (i = 0, j = 0; i < msgLen; i++, j++)
    {
        if (j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }
    newKey[i] = '\0';

    return newKey;
}
