//
// Created by skird on 07.11.18.
//

#ifndef EXTRACTORS_BITSTRING_H
#define EXTRACTORS_BITSTRING_H

#include <string>
#include <sstream>
#include <tuple>

#include <NTL/GF2E.h>
#include "types.h"

class Bitstring : public std::string {
public:
    Bitstring() : std::string() {}
    explicit Bitstring(const NTL::GF2E &x) {
        std::stringstream tmp;
        tmp << x;
        char c{};
        tmp >> c;
        int v{};
        while (tmp >> v) {
            push_back(v + '0');
        }
    }

    explicit Bitstring(const std::string &s) : std::string(s) {}

    NTL::GF2E asGF2E() const {
        std::stringstream tmp;
        tmp << "[";
        for (uint32_t i = 0; i < size(); ++i) {
            tmp << " ";
            tmp << this->at(i);
        }
        tmp << " ]";
        NTL::GF2E res;
        tmp >> res;
        return res;
    }

    static Bitstring fromGF2E(const NTL::GF2E &value) {
        std::stringstream tmp;
        tmp << value;
        char c{};
        Bitstring result;
        while (tmp >> c) {
            if (c == '0' || c == '1') result.push_back(c);
        }
        return result;
    }

    BigInt asZZ() const {
        BigInt res(0);
        for (size_t i = 0; i < size(); ++i) {
            res = (res << 1) + uint32_t(at(i) - '0');
        }
        return res;
    }

    static Bitstring fromZZ(const BigInt &value) {
        Bitstring result;
        result.resize(NTL::NumBits(value));
        for (size_t i = 0; i < result.size(); ++i) {
            result[i] = NTL::bit(value, i);
        }
        return result;
    }

    uint32_t asUInt32() const {
        uint32_t res(0);
        for (size_t i = 0; i < size(); ++i) {
            res = (res << 1u) + uint32_t(at(i) - '0');
        }
        return res;
    }

    static Bitstring fromUInt32(uint32_t x) {
        Bitstring result;
        for (; x; x >>= 1u) {
            result.push_back('0' + (x & 1u));
        }
        return result;
    }
};

std::tuple<Bitstring, Bitstring> cutPrefix(const Bitstring &str, uint32_t s);

#endif //EXTRACTORS_BITSTRING_H
