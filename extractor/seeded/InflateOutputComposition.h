#ifndef EXTRACTORS_INFLATEOUTPUTCOMPOSITION_H
#define EXTRACTORS_INFLATEOUTPUTCOMPOSITION_H

#include <memory>
#include "ISeededExtractor.h"

class InflateOutputComposition {
public:
    InflateOutputComposition(
        std::shared_ptr<ISeededExtractor> e1,
        std::shared_ptr<ISeededExtractor> e2,
        uint32_t s
    );

    /**
     * @see ISeededExtractor with similar interface
     */
    virtual uint32_t getInputLength() const;
    virtual uint32_t getSeedLen() const;
    virtual uint32_t getOutputLen() const;
    virtual double getError() const;

    /**
     * Extracts from input using seed
     * @param input bitstring describing weak source sample
     * @param seed bitstring representing the seed
     * @return extracted close-to-uniform bit string
     */
    virtual Bitstring extract(const WeakSource &input, const Bitstring &seed) const;

    virtual ~InflateOutputComposition() = default;
private:
    std::shared_ptr<ISeededExtractor> first_, second_;
    uint32_t s_;
};


#endif //EXTRACTORS_INFLATEOUTPUTCOMPOSITION_H
