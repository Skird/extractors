#ifndef EXTRACTORS_ICONDENSER_H
#define EXTRACTORS_ICONDENSER_H


#include <cstdint>
#include <utils/Bitstring.h>
#include <utils/WeakSource.h>

class ICondenser {
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
     * @return minimal min-entropy that condenser can handle
     */
    virtual double getMinEntropy() const = 0;

    /**
     * @return bound for min-entropy of output
     */
    virtual double outputMinEntropy() const = 0;

    /**
     * @return statistical distance to target distribution
     */
    virtual double getError() const = 0;

    /**
     * Applies condenser to input
     * @param input bitstring describing weak source sample
     * @param seed bitstring representing the seed
     * @return
     */
    virtual WeakSource condense(const WeakSource &input, const Bitstring &seed) const = 0;

    virtual ~ICondenser() = default;
};


#endif //EXTRACTORS_ICONDENSER_H
