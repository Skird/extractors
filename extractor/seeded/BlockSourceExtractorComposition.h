#ifndef EXTRACTORS_BLOCKSOURCEEXTRACTORCOMPOSITION_H
#define EXTRACTORS_BLOCKSOURCEEXTRACTORCOMPOSITION_H

#include <vector>
#include <memory>
#include <cassert>

#include "utils/Bitstring.h"
#include "ISeededExtractor.h"

class BlockSourceExtractorComposition {
public:
    template<typename InputIterator>
    BlockSourceExtractorComposition(InputIterator from, InputIterator to);

    /**
     * @see ISeededExtractor with similar interface
     */
    virtual uint32_t getInputLength() const;
    virtual uint32_t getSeedLen() const;
    virtual uint32_t getOutputLen() const;
    virtual double getError() const;

    /**
     * Applies extractor composition to block-source using seed
     * @param input vector of weak sources, s.t. each is not conditioned on previous
     * @param seed bit string representing seed
     * @return extracted close-to-uniform bits
     */
    virtual Bitstring extract(const std::vector<WeakSource> &input, const Bitstring &seed) const;

private:
    std::vector<std::shared_ptr<ISeededExtractor> > ext_;
    uint32_t inputLen_, seedLen_, outputLen_;
    double error_;
};


#endif //EXTRACTORS_BLOCKSOURCEEXTRACTORCOMPOSITION_H
