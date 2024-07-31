#ifndef QREGISTER_H
#define QREGISTER_H

#include "VirtualQubit.h"
#include <vector>
#include <memory>

class QRegister {
    std::vector<std::shared_ptr<VirtualQubit>> qubits;

public:
    QRegister(int numQubits);
    void applyHadamardToAll();
    std::vector<int> measureAll();
    // Future methods for simulating operations within a Hilbert space could be added here
};

#endif // QREGISTER_H
