#ifndef EXTRACTORS_PVEXPANDER_H
#define EXTRACTORS_PVEXPANDER_H

#include "utils/types.h"
#include "expander/bipartite/IBipartiteExpander.h"

#include <NTL/GF2X.h>
#include <NTL/GF2EX.h>

class PVExpander : public IBipartiteExpander {
public:
    /**
     * Constructs expander using Parvaresh-Vardy code
     * @param log_q base 2 logarithm of field size
     * @param field_p degree log_q irreducible polynomial over GF(2)
     * @param e degree n irreducible polynomial over GF(2^q)[X]
     * @param n parameter for left part size
     * @param m parameter for right part size
     * @param h PV <<power>> parameter
     */
    PVExpander(uint32_t log_q, const NTL::GF2X& field_p, NTL::GF2EX e, uint32_t n, uint32_t m, const BigInt& h);

    BigInt getLSize() const override;
    uint32_t getLogLSize() const override;
    BigInt getRSize() const override;
    uint32_t getLogRSize() const override;
    BigInt getExpansionFactor() const override;
    BigInt getExpansionSize() const override;
    BigInt getDegree() const override;
    uint32_t getLogDegree() const override;
    Bitstring getEdge(const Bitstring &leftLabel, const Bitstring &edgeLabel) const override;
protected:
    uint32_t log_q, n, m;
    NTL::ZZ h, q;
    NTL::GF2X P;
    NTL::GF2EX E;
};

#endif //EXTRACTORS_PVEXPANDER_H
