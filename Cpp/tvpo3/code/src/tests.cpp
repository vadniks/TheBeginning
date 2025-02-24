
/*
git clone googletest
cd googletest && mkdir build && cd build
cmake ..
make
*/

#pragma ide diagnostic ignored "cert-err58-cpp"

#include <gtest/gtest.h>
#include <cstring>
#include "../include/coder.hpp"
#include "../include/decoder.hpp"

#define TEST_GROUP tests
#define EXPECT_STR_EQ(x, y) EXPECT_EQ(strcmp(x, y), 0)

c_str TEST_DIR = "/home/admin/Downloads/test";
auto METHOD = EncryptionMethod::BASE64;

TEST(TEST_GROUP, checkParameters_should_return_true) {
    c_int argc = 4;
    c_str argv[argc] = {"programItself", TEST_DIR, BASE64_S, "0"};

    char* path = 0;
    EncryptionMethod method;
    bool mode = false;

    EXPECT_TRUE(parseArguments(argc, argv, path, method, mode));
    EXPECT_STR_EQ(TEST_DIR, path);
    EXPECT_TRUE(method == EncryptionMethod::BASE64);
    EXPECT_TRUE(!mode);
}

TEST(TEST_GROUP, checkPath_shoud_return_true)
{ EXPECT_TRUE(checkPath(TEST_DIR)); }

TEST(TEST_GROUP, checkPath_shoud_return_false)
{ EXPECT_FALSE(checkPath("/home/admin/Downloads/testa")); }

TEST(TEST_GROUP, encode_base64_result_should_match_predefined)
{ EXPECT_STR_EQ("dGVzdA==", encode("test", EncryptionMethod::BASE64)); }

TEST(TEST_GROUP, encode_hex_result_should_match_predefined)
{ EXPECT_STR_EQ("74657374", encode("test", EncryptionMethod::HEX)); }

TEST(TEST_GROUP, decode_base64_result_should_match_predefined)
{ EXPECT_STR_EQ("test", decode("dGVzdA==", EncryptionMethod::BASE64)); }

TEST(TEST_GROUP, decode_hex_result_should_match_predefined)
{ EXPECT_STR_EQ("test", decode("74657374", EncryptionMethod::HEX)); }
