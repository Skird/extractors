#ifndef EXTRACTORS_LHLEXTRACTOR_H
#define EXTRACTORS_LHLEXTRACTOR_H


#include "ISeededExtractor.h"

class LHLExtractor : public ISeededExtractor {
public:
    explicit LHLExtractor(uint32_t n, uint32_t k, double eps);

    uint32_t getInputLength() const override;
    uint32_t getSeedLen() const override;
    uint32_t getOutputLen() const override;
    double getMinEntropy() const override;
    double getError() const override;
    Bitstring extract(const WeakSource &input, const Bitstring &seed) const override;
private:
    uint32_t n_, k_, m_;
    double error_;
};


#endif //EXTRACTORS_LHLEXTRACTOR_H
