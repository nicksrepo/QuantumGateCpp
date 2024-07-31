#ifndef VIRTUALQUBIT_H
#define VIRTUALQUBIT_H

#include <complex>
#include <random>

/*
class VirtualQubit {
private:
    std::complex<double> state0; // Probability amplitude for |0>
    std::complex<double> state1; // Probability amplitude for |1>
    std::mt19937 gen; // Mersenne Twister random number generator
    VirtualQubit* entangledPartner = nullptr; // Pointer to an entangled partner, if any

public:
    VirtualQubit();
    void entangleWith(VirtualQubit& qubit);
    bool isEntangled() const;
    int measure();
};
*/

class VirtualQubit {
private:
   
    std::mt19937 gen; // Mersenne Twister random number generator
    std::uniform_real_distribution<> dis; // Uniform distribution

    VirtualQubit* entangledPartner = nullptr; // Pointer to an entangled partner, if any
    

public:
 std::complex<double> state0; // Probability amplitude for |0>
    std::complex<double> state1; // Probability amplitude for |1>
    VirtualQubit();
        VirtualQubit(const std::complex<double>& initialState0, const std::complex<double>& initialState1);


    // No need for VirtualQubit:: prefix inside class declaration
    void applyNoise();
    void entangleWith(VirtualQubit& qubit);
    bool isEntangled() const;
    void flip();

    int measure();
    void applyXGate();
    void applyHGate();
};

#endif // VIRTUALQUBIT_H
