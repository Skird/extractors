#include <vector>
#include <cassert>
#include "PVExpander.h"

namespace {

NTL::GF2EX powmod(NTL::GF2EX x, NTL::ZZ p, const NTL::GF2EX &mod) {
    NTL::GF2EX res(1);
    for (; !NTL::IsZero(p); p >>= 1) {
        if (NTL::IsOdd(p)) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

}

BigInt PVExpander::getLSize() const {
    BigInt sz{};
    NTL::power(sz, q, n);
    return sz;  // q^n
}

uint32_t PVExpander::getLogLSize() const {
    return log_q * n;
}

BigInt PVExpander::getRSize() const {
    BigInt sz{};
    NTL::power(sz, q, m + 1);
    return sz;  // q^(m+1)
}

uint32_t PVExpander::getLogRSize() const {
    return log_q * (m + 1);
}

BigInt PVExpander::getExpansionFactor() const {
    return q - (n - 1) * (h - 1) * m;
}

BigInt PVExpander::getExpansionSize() const {
    BigInt sz{};
    NTL::power(sz, h, m);
    return sz;
}

BigInt PVExpander::getDegree() const {
    return q;
}

uint32_t PVExpander::getLogDegree() const {
    return log_q;
}

Bitstring PVExpander::getEdge(const Bitstring &leftLabel, const Bitstring &edgeLabel) const {
    assert(leftLabel.size() == getLogLSize());
    assert(edgeLabel.size() == getLogDegree());
    NTL::GF2EPush push{};
    NTL::GF2E::init(P);

    NTL::GF2EX f{};
    f.SetLength(n);
    NTL::GF2E converted = edgeLabel.asGF2E();
    for (uint32_t i = 0; i < leftLabel.size(); i += log_q) {
        Bitstring(leftLabel.substr(i, log_q)).asGF2E();
    }

    Bitstring result;
    result += edgeLabel;
    for (uint32_t it = 0; it <= m; ++it) {
        NTL::GF2E cur;
        NTL::eval(cur, f, converted);
        result += Bitstring::fromGF2E(cur);
        f = powmod(f, h, E);
    }
    return result;
}

PVExpander::PVExpander(uint32_t log_q, const NTL::GF2X &field_p, NTL::GF2EX e, uint32_t n, uint32_t m, const NTL::ZZ &h)
    : log_q(log_q), n(n), m(m), h(h), q(NTL::power_ZZ(2, log_q)), P(field_p), E(std::move(e)) {
}
