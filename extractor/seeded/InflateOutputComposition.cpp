#include <utility>

#include "InflateOutputComposition.h"

InflateOutputComposition::InflateOutputComposition(
    std::shared_ptr<ISeededExtractor> e1,
    std::shared_ptr<ISeededExtractor> e2,
    uint32_t s)
    : first_(std::move(e1)), second_(std::move(e2)), s_(s) {
    assert(e1->getInputLength() == e2->getInputLength());
    assert(e2->getMinEntropy() <= e1->getMinEntropy() - e1->getOutputLen() - s);
}

uint32_t InflateOutputComposition::getInputLength() const {
    return first_->getInputLength();
}

uint32_t InflateOutputComposition::getSeedLen() const {
    return first_->getSeedLen() + second_->getSeedLen();
}

uint32_t InflateOutputComposition::getOutputLen() const {
    return first_->getOutputLen() + second_->getOutputLen();
}

double InflateOutputComposition::getError() const {
    return (1. / (1. - pow(2, -s_))) * (first_->getError() + second_->getError());
}

Bitstring InflateOutputComposition::extract(const WeakSource &input, const Bitstring &seed) const {
    Bitstring s1(seed.substr(0, first_->getSeedLen()));
    Bitstring s2(seed.substr(first_->getSeedLen(), second_->getSeedLen()));
    return Bitstring(first_->extract(input, s1) + second_->extract(input, s2));
}

