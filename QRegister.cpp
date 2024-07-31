#include "QRegister.h"
#include "QuantumGate.h"

QRegister::QRegister(int numQubits) {
    for (int i = 0; i < numQubits; ++i) {
        qubits.push_back(std::make_shared<VirtualQubit>());
    }
}

void QRegister::applyHadamardToAll() {
    for (auto& qubit : qubits) {
        QuantumGate::applyHGate(*qubit);
    }
}

std::vector<int> QRegister::measureAll() {
    std::vector<int> measurements;
    for (auto& qubit : qubits) {
        measurements.push_back(qubit->measure());
    }
    return measurements;
}
