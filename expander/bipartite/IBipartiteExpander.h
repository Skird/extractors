#ifndef EXTRACTORS_IBIPARTITEEXPANDER_H
#define EXTRACTORS_IBIPARTITEEXPANDER_H

#include "utils/Bitstring.h"
#include "utils/types.h"

/**
 * Represents (L, R, D, K, A)-bipartite regular expander with parts L and R and left degree D
 * Size of maximal set that can be expanded is denoted as K
 * Expansion factor is denoted as A
 * For purposes of this library size of L, R and D is assumed to be power of 2 and all vertices and edges
 * are labeled with bit strings
 */
class IBipartiteExpander {
public:
    /**
     * @return size of left part
     */
    virtual BigInt getLSize() const = 0;

    /**
     * @return bit length of labels of left part
     */
    virtual uint32_t getLogLSize() const = 0;

    /**
     * @return size of right part
     */
    virtual BigInt getRSize() const = 0;

    /**
     * @return bit length of labels of right part
     */
    virtual uint32_t getLogRSize() const = 0;

    /**
     * @return Expansion factor
     */
    virtual BigInt getExpansionFactor() const = 0;

    /**
     * @return Size of maximal set that can be expanded
     */
    virtual BigInt getExpansionSize() const = 0;

    /**
     * @return Left degree
     */
    virtual BigInt getDegree() const = 0;

    /**
     * @return Logarithm (base 2) of left degree
     */
    virtual uint32_t getLogDegree() const = 0;

    /**
     * Method for getting edge of expander
     * @param leftLabel bitstring labeling left vertex
     * @param edgeLabel bitstring labeling edge
     * @return bitstring labeling corresponding right vertex
     */
    virtual Bitstring getEdge(const Bitstring &leftLabel, const Bitstring &edgeLabel) const = 0;

    virtual ~IBipartiteExpander() = default;
};


#endif //EXTRACTORS_IBIPARTITEEXPANDER_H
