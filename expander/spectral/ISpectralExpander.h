#ifndef EXTRACTORS_ISPECTRALEXPANDER_H
#define EXTRACTORS_ISPECTRALEXPANDER_H

#include "utils/Bitstring.h"
#include "utils/types.h"

/**
 * Represents (V, D, K, A)-regular expander with vertex set V and degree D
 * Size of maximal set that can be expanded is denoted as K
 * Expansion factor is denoted as A
 * For purposes of this library size of V and D is assumed to be power of 2 and all vertices and edges
 * are labeled with bit strings
 */

class ISpectralExpander {
public:
    /**
     * @return size of expander
     */
    virtual BigInt getSize() const = 0;

    /**
     * @return bit length of labels of vertices
     */
    virtual uint32_t getLogSize() const = 0;

    /**
     * @return Expansion factor
     */
    virtual double getSpectralGap() const = 0;

    /**
     * @return Degree
     */
    virtual BigInt getDegree() const = 0;

    /**
     * @return Logarithm (base 2) of degree
     */
    virtual uint32_t getLogDegree() const = 0;

    /**
     * Method for getting edge of expander
     * @param vLabel bitstring labeling vertex
     * @param edgeLabel bitstring labeling edge
     * @return bitstring labeling corresponding vertex
     */
    virtual Bitstring getEdge(const Bitstring &vLabel, const Bitstring &edgeLabel) const = 0;

    virtual ~ISpectralExpander() = default;
};


#endif //EXTRACTORS_ISPECTRALEXPANDER_H
