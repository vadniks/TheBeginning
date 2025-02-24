
#pragma ide diagnostic ignored "modernize-use-bool-literals"
#pragma ide diagnostic ignored "modernize-use-nullptr"

#include <cstring>
#include <cstdio>
#include <sys/stat.h>
#include <dirent.h>
#include "../include/shared.hpp"
#include "../include/coder.hpp"
#include "../include/decoder.hpp"

bool parseArguments(int argc, c_str* argv, char*& path, EncryptionMethod& method, bool& mode) {
    if (argc != ARGUMENT_COUNT or !argv or path) return false;

    c_uint size = strlen(argv[1]);
    path = new char[size];
    strcpy(path, argv[1]);

    method = !strcmp(BASE64_S, argv[2])
        ? EncryptionMethod::BASE64
        : !strcmp(HEX_S, argv[2])
            ? EncryptionMethod::HEX
            : EncryptionMethod::UNKNOWN;

    mode = !strcmp("1", argv[3]);

    return method != EncryptionMethod::UNKNOWN;
}

bool checkPath(c_str path) {
    if (!path) return 0;
    struct stat info {};
    return !stat(path, &info) and info.st_mode & S_IFDIR;
}

bool processFile(c_str path, EncryptionMethod method, bool mode) {
    if (!path) return 0;

    FILE* file = fopen(path, "r");
    if (!file) return 0;

    char* content = new char[BUFFER_SIZE];
    unsigned size = 0;
    for (
        int $char = 0;
        $char != EOF;
        content[size++] = static_cast<char>($char = fgetc(file))
    );

    content[--size] = '\0';

    c_str altered = !mode ? encode(content, method) : decode(content, method);
    c_uint alteredSize = strlen(altered);

    freopen(path, "w", file);
    for (unsigned i = 0; i < alteredSize; fputc(altered[i++], file));
    fclose(file);
    return 1;
}

bool processDir(c_str path, EncryptionMethod method, bool mode) {
    if (!path or !checkPath(path)) return 0;

    DIR* dir;
    struct dirent* ent;
    if (!(dir = opendir(path))) return 0;

    while ((ent = readdir(dir))) {
        if (!strcmp(ent->d_name, ".") or !strcmp(ent->d_name, "..")) continue;
        char file[strlen(path) + 1 + strlen(ent->d_name)];
        if (sprintf(file, "%s/%s", path, ent->d_name) <= 0) break;
        if (!processFile(file, method, mode)) break;
    }
    closedir(dir);
    return 1;
}
