#include "QuantumGate.h"
#include "VirtualQubit.h"
#include <vector>
#include <iostream>
#include "QRegister.h"

class EntropyGenerator
{
public:
    static std::vector<int> generateBits(int numberOfBits, int batchSize)
    {
        std::vector<int> bits;
        bits.reserve(numberOfBits); // Pre-allocate memory for efficiency

        // Calculate the number of batches needed
        int batches = numberOfBits / batchSize + (numberOfBits % batchSize != 0);

        for (int i = 0; i < batches; ++i)
        {
            std::vector<VirtualQubit> qubits;
            // Prepare a batch of qubits in superposition
            for (int j = 0; j < batchSize && (i * batchSize + j) < numberOfBits; ++j)
            {
                qubits.emplace_back();                  // Default constructor
                QuantumGate::applyHGate(qubits.back()); // This assumes QuantumGate::applyHGate adjusts the qubit state accordingly
            }

            // Measure qubits in the batch and collect bits
            for (auto &qubit : qubits)
            {
                int bit = qubit.measure(); // Measure qubit
                bits.push_back(bit);
            }
        }

        return bits;
    }
};

int main()
{
     VirtualQubit control1, control2, target;

    // Example: Setting control qubits to |1> to ensure the target is flipped
    control1.flip(); // Assuming qubits start in |0>, flip them to |1>
    control2.flip();

     QRegister qRegister(3); // Create a quantum register with 3 qubits

    // Apply a Hadamard gate to all qubits, putting them into superposition
    qRegister.applyHadamardToAll();

    // Measure all qubits in the register
    auto measurements = qRegister.measureAll();


    // Apply the Toffoli gate
    QuantumGate::applyToffoliGate(control1, control2, target);

    // The target qubit's state would be flipped only if both controls are |1>
    std::cout << "Target qubit state after Toffoli gate: " << target.measure() << std::endl;

    
    int numberOfBits = 100; // Desired number of bits
    int batchSize = 160;     // Number of qubits to process in each batch

    auto bits = EntropyGenerator::generateBits(numberOfBits, batchSize); // Generate bits with batching

    std::cout << "Generated Bits: ";
    for (auto bit : bits)
    {
        std::cout << bit;
    }
    std::cout << std::endl;

    return 0;
}