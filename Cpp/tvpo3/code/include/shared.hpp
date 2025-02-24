
#ifndef SHARED_HPP
#define SHARED_HPP

#include "util.hpp"

enum EncryptionMethod {
    BASE64, HEX, UNKNOWN
};

bool parseArguments(int argc, c_str* argv, char*& path, EncryptionMethod& method, bool& mode);
bool checkPath(c_str path);
bool processDir(c_str path, EncryptionMethod method, bool mode);

#endif
