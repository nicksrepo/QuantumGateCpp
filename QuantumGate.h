#ifndef QUANTUMGATE_H
#define QUANTUMGATE_H

#include "VirtualQubit.h"

class QuantumGate {
public:
    static void applyXGate(VirtualQubit& qubit);
    static void applyHGate(VirtualQubit& qubit);
    static void applyZGate(VirtualQubit& qubit);
    static void applyCNOTGate(VirtualQubit& controlQubit, VirtualQubit& targetQubit);
    static void applyToffoliGate(VirtualQubit& control1, VirtualQubit& control2, VirtualQubit& target);
    // Add more gates as needed
};

#endif // QUANTUMGATE_H
