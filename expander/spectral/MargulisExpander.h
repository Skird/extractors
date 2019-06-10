#ifndef EXTRACTORS_MARGULISEXPANDER_H
#define EXTRACTORS_MARGULISEXPANDER_H


#include "ISpectralExpander.h"

class MargulisExpander : public ISpectralExpander {
public:
    explicit MargulisExpander(uint32_t logn);

    BigInt getSize() const override;
    uint32_t getLogSize() const override;
    double getSpectralGap() const override;
    BigInt getDegree() const override;
    uint32_t getLogDegree() const override;
    Bitstring getEdge(const Bitstring &vLabel, const Bitstring &edgeLabel) const override;
private:
    BigInt n_;
    uint32_t logn_;
};


#endif //EXTRACTORS_MARGULISEXPANDER_H
