#ifndef EXTRACTORS_ISEEDEDEXTRACTOR_H
#define EXTRACTORS_ISEEDEDEXTRACTOR_H

#include "utils/WeakSource.h"

class ISeededExtractor {
public:
    /**
     * @return length of input
     */
    virtual uint32_t getInputLength() const = 0;

    /**
     * @return length of seed
     */
    virtual uint32_t getSeedLen() const = 0;

    /**
     * @return length of output
     */
    virtual uint32_t getOutputLen() const = 0;

    /**
     * @return minimal min-entropy that extractor can handle
     */
    virtual double getMinEntropy() const = 0;

    /**
     * @return statistical distance to uniform distribution
     */
    virtual double getError() const = 0;

    /**
     * Extracts from input using seed
     * @param input bitstring describing weak source sample
     * @param seed bitstring representing the seed
     * @return extracted close-to-uniform bit string
     */
    virtual Bitstring extract(const WeakSource &input, const Bitstring &seed) const = 0;

    virtual ~ISeededExtractor() = default;
};


#endif //EXTRACTORS_ISEEDEDEXTRACTOR_H
