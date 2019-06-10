#include <cassert>
#include "MargulisExpander.h"

BigInt MargulisExpander::getSize() const {
    return n_ * n_;
}

uint32_t MargulisExpander::getLogSize() const {
    return 2 * logn_;
}

BigInt MargulisExpander::getDegree() const {
    return BigInt(8);
}

uint32_t MargulisExpander::getLogDegree() const {
    return 3;
}

Bitstring MargulisExpander::getEdge(const Bitstring &vLabel, const Bitstring &edgeLabel) const {
    assert(vLabel.size() == getLogSize());
    assert(edgeLabel.size() == getLogDegree());
    BigInt x = Bitstring(vLabel.substr(0, logn_)).asZZ();
    BigInt y = Bitstring(vLabel.substr(logn_, logn_)).asZZ();
    uint32_t d = edgeLabel.asUInt32();
    assert(0 <= d && d < 8);
    BigInt xx(0), yy(0);
    switch (d) {
        case 1:
            xx = 1; // no break
        case 0:
            xx += x + 2 * y;
            yy += y;
            break;

        case 3:
            yy = 1; // no break
        case 2:
            xx += x;
            yy += 2 * x + y;
            break;

        case 5:
            xx = -1; // no break
        case 4:
            yy += y;
            xx += x - 2 * y;
            break;

        case 7:
            yy = -1; // no break
        case 6:
            xx += x;
            yy += y - 2 * x;
            break;
        default:
            assert(false);
    }
    xx %= n_;
    yy %= n_;
    if (NTL::sign(xx) < 0) xx += n_;
    if (NTL::sign(yy) < 0) yy += n_;
    return Bitstring(Bitstring::fromZZ(xx) + Bitstring::fromZZ(yy));
}

MargulisExpander::MargulisExpander(uint32_t logn) : n_(BigInt(1) << logn), logn_(logn) {
}

double MargulisExpander::getSpectralGap() const {
    return 5 * sqrt(2) / 8;
}
