#ifndef QUANTUMRANDOMNUMBERGENERATOR_H
#define QUANTUMRANDOMNUMBERGENERATOR_H

#include "VirtualQubit.h"
#include <vector>

class QuantumRandomNumberGenerator {
public:
    static std::vector<int> generateRandomBits(int numberOfBits);
};

#endif // QUANTUMRANDOMNUMBERGENERATOR_H
