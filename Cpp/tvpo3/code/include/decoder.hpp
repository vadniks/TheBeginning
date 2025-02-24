
#ifndef DECODER_HPP
#define DECODER_HPP

#include "util.hpp"
#include "shared.hpp"

[[nodiscard]] c_str decode(c_str message, EncryptionMethod method);

#endif
