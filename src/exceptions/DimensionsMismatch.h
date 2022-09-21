#ifndef DIMENSIONSMISMATCH_H
#define DIMENSIONSMISMATCH_H

#include <string>

class DimensionsMismatch {
public:
    DimensionsMismatch() {}
    std::string what() {
        return "Dimensions don't match\n";
    }
};

#endif // DIMENSIONSMISMATCH_H
