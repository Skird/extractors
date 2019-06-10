#include <NTL/GF2E.h>
#include <NTL/GF2XFactoring.h>

#include "LHLExtractor.h"

uint32_t LHLExtractor::getInputLength() const {
    return n_;
}

uint32_t LHLExtractor::getSeedLen() const {
    return n_;
}

uint32_t LHLExtractor::getOutputLen() const {
    return m_;
}

double LHLExtractor::getMinEntropy() const {
    return k_;
}

double LHLExtractor::getError() const {
    return error_;
}

Bitstring LHLExtractor::extract(const WeakSource &input, const Bitstring &seed) const {
    assert(input.getMinEntropy() >= k_);
    assert(seed.size() == n_);
    NTL::GF2EPush push;
    NTL::GF2E::init(NTL::BuildSparseIrred_GF2X(n_));
    auto x = input.getData().asGF2E();
    auto y = seed.asGF2E();
    return Bitstring((Bitstring(x) + Bitstring(y)).substr(0, m_));
}

LHLExtractor::LHLExtractor(uint32_t n, uint32_t k, double eps): n_(n), k_(k), error_(eps) {
    m_ = ceil(k_ + n_ - 2 * log2(1. / error_));
}
