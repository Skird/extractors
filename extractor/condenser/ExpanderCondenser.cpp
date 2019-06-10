#include "ExpanderCondenser.h"

uint32_t ExpanderCondenser::getInputLength() const {
    return expander_->getLogLSize();
}

uint32_t ExpanderCondenser::getSeedLen() const {
    return expander_->getLogDegree();
}

uint32_t ExpanderCondenser::getOutputLen() const {
    return expander_->getLogRSize();
}

double ExpanderCondenser::getMinEntropy() const {
    NTL::RRPush push;
    NTL::RR::SetPrecision(20);
    NTL::RR x = NTL::to_RR(expander_->getExpansionSize()), ln2;
    NTL::log(x, x);
    NTL::log(ln2, NTL::RR(2));
    double res;
    NTL::conv(res, x / ln2);
    return res;
}

double ExpanderCondenser::getError() const {
    NTL::RRPush push;
    NTL::RR::SetPrecision(20);
    auto x = NTL::to_RR(1) - NTL::to_RR(expander_->getExpansionFactor()) / NTL::to_RR(expander_->getDegree());
    double res;
    NTL::conv(res, x);
    return res;
}

double ExpanderCondenser::outputMinEntropy() const {
    return getMinEntropy() + getSeedLen();
}

WeakSource ExpanderCondenser::condense(const WeakSource &input, const Bitstring &seed) const {
    return WeakSource(expander_->getEdge(input.getData(), seed), outputMinEntropy(), getError());
}
