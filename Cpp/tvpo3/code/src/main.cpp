
#include <cstdlib>
#include "../include/shared.hpp"
#include "../include/util.hpp"

#if !defined(IS_TESTING)

int main(const int argc, c_str* argv) {
    char* path = 0;
    EncryptionMethod method;
    bool mode = false;

    if (!parseArguments(argc, argv, path, method, mode)) return EXIT_FAILURE;
    return processDir(path, method, mode) ? EXIT_SUCCESS : EXIT_FAILURE;
}

#endif
