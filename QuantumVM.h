#ifndef QUANTUMVM_H
#define QUANTUMVM_H

#include "VirtualQubit.h"
#include <vector>

class QuantumVM {
private:
    std::vector<VirtualQubit> qubits;

public:
    void loadQubits(const std::vector<VirtualQubit>& qubits);
    unsigned int calculateAddress();
};

#endif // QUANTUMVM_H
