#ifndef EXTRACTORS_WEAKSOURCE_H
#define EXTRACTORS_WEAKSOURCE_H

#include <vector>
#include <cassert>
#include <cmath>

#include "utils/Bitstring.h"

class WeakSource {
public:
    WeakSource(Bitstring data, double minEntropy, double error);

    const Bitstring &getData() const;
    double getMinEntropy() const;
    double getError() const;

    std::vector<WeakSource> splitIntoBlocks(uint32_t n) const;

private:
    Bitstring data_;
    double minEntropy_;
    double error_;
};


#endif //EXTRACTORS_WEAKSOURCE_H
