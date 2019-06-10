#include "utils/Bitstring.h"

std::tuple<Bitstring, Bitstring> cutPrefix(const Bitstring &str, uint32_t s) {
    return {Bitstring(str.substr(0, s)), Bitstring(str.substr(s, str.size() - s))};
}

