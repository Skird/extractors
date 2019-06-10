#include "BlockSourceExtractorComposition.h"


uint32_t BlockSourceExtractorComposition::getInputLength() const {
    return inputLen_;
}

uint32_t BlockSourceExtractorComposition::getSeedLen() const {
    return seedLen_;
}

uint32_t BlockSourceExtractorComposition::getOutputLen() const {
    return outputLen_;
}

double BlockSourceExtractorComposition::getError() const {
    return error_;
}

Bitstring BlockSourceExtractorComposition::extract(const std::vector<WeakSource> &input, const Bitstring &seed) const {
    Bitstring currentRnd = seed;
    Bitstring output;
    for (int i = ext_.size() - 1; i >= 0; --i) {
        assert(ext_[i]->getSeedLen() == seed.size());
        assert(ext_[i]->getInputLength() == input[i].getData().size());
        auto newRnd = ext_[i]->extract(input[i], currentRnd);
        assert(newRnd.size() == ext_[i]->getOutputLen());

        auto nextSeedLen = i == 0 ? 0u : ext_[i - 1]->getSeedLen();
        auto [pref, suff] = cutPrefix(newRnd, nextSeedLen);
        output += suff;
        currentRnd = pref;
    }
    assert(output.size() == outputLen_);
    return output;
}

template <typename InputIterator>
BlockSourceExtractorComposition::BlockSourceExtractorComposition(InputIterator from, InputIterator to) : ext_(from, to) {
    inputLen_ = 0;
    seedLen_ = 0;
    outputLen_ = 0;
    error_ = 0;
    for (const auto &ext : ext_) {
        inputLen_ += ext->getInputLength();
        outputLen_ += ext->getOutputLen() - seedLen_;
        seedLen_ = ext->getSeedLen();
        error_ += ext->getError();
    }
}
