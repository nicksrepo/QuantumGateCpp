#include "QuantumVM.h"

void QuantumVM::loadQubits(const std::vector<VirtualQubit>& qubits) {
    this->qubits = qubits;
}

unsigned int QuantumVM::calculateAddress() {
    unsigned int address = 0;
    for (auto& qubit : qubits) {
        // Measure each qubit and use its state to influence the address calculation
        address = (address << 1) | qubit.measure();
    }
    return address;
}
