#include <utility>

#ifndef EXTRACTORS_EXPANDERCONDENSER_H
#define EXTRACTORS_EXPANDERCONDENSER_H

#include <memory>

#include "expander/bipartite/IBipartiteExpander.h"
#include "extractor/condenser/ICondenser.h"

class ExpanderCondenser : public ICondenser {
public:
    explicit ExpanderCondenser(std::shared_ptr<IBipartiteExpander> bipartiteExpander)
        : expander_(std::move(bipartiteExpander)) {}

    static std::shared_ptr<ExpanderCondenser>
    createCondenserFromExpander(std::shared_ptr<IBipartiteExpander> bipartiteExpander) {
        return std::make_shared<ExpanderCondenser>(bipartiteExpander);
    }

    uint32_t getInputLength() const override;
    uint32_t getSeedLen() const override;
    uint32_t getOutputLen() const override;
    double getMinEntropy() const override;
    double outputMinEntropy() const override;
    double getError() const override;
    WeakSource condense(const WeakSource &input, const Bitstring &seed) const override;

private:
    std::shared_ptr<IBipartiteExpander> expander_;
};

#endif //EXTRACTORS_EXPANDERCONDENSER_H
