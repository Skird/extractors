#include <utility>

#include "WeakSource.h"

WeakSource::WeakSource(Bitstring data, double minEntropy, double error)
    : data_(std::move(data)), minEntropy_(minEntropy), error_(error) {

}

const Bitstring &WeakSource::getData() const {
    return data_;
}

double WeakSource::getMinEntropy() const {
    return minEntropy_;
}

double WeakSource::getError() const {
    return error_;
}

std::vector<WeakSource> WeakSource::splitIntoBlocks(uint32_t n) const {
    assert(n > 0);
    double defect = data_.size() - minEntropy_;
    uint32_t sz = data_.size() / n;
    std::vector<WeakSource> result;
    for (uint32_t i = 0; i < n; ++i) {
        uint32_t csz = sz + (i < data_.size() % sz ? 1 : 0);
        Bitstring part(data_.substr(i * sz, csz));
        result.emplace_back(part, sz - defect - log2(1 / error_), error_);
    }
    return result;
}
