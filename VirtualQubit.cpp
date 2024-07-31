#include "VirtualQubit.h"
#include <random>

/*VirtualQubit::VirtualQubit() : gen(std::random_device{}()), dis(0.0, 1.0) {
    // Initialize your qubit here if necessary

    // Dynamically create superposition states
    double angle = dis(gen) * 2 * M_PI; // Random angle for superposition
    state0 = std::complex<double>(cos(angle), sin(angle));
    state1 = std::complex<double>(cos(angle + M_PI / 2), sin(angle + M_PI / 2));
}*/

void VirtualQubit::applyNoise()
{
    // Apply a small random perturbation to simulate noise
    double noiseIntensity = 0.05; // Adjust based on desired noise level
    double angle = dis(gen) * 2 * M_PI;
    std::complex<double> noise(cos(angle) * noiseIntensity, sin(angle) * noiseIntensity);

    state0 += noise * state0;
    state1 += noise * state1;

    // Normalize states after noise application
    double norm = std::sqrt(std::norm(state0) + std::norm(state1));
    state0 /= norm;
    state1 /= norm;
}

void VirtualQubit::applyXGate()
{
    std::swap(state0, state1);
}

void VirtualQubit::applyHGate()
{
    if (std::norm(state0) == 1.0)
    {
        state0 = state1 = std::complex<double>(1 / sqrt(2), 0);
    }
    else if (std::norm(state1) == 1.0)
    {
        state0 = std::complex<double>(1 / sqrt(2), 0);
        state1 = std::complex<double>(-1 / sqrt(2), 0); // Adjust based on your interpretation
    }
    // Note: This is a simplification. Actual superposition involves phase.
}

void VirtualQubit::entangleWith(VirtualQubit &qubit)
{
    entangledPartner = &qubit;
    qubit.entangledPartner = this;

    // Synchronize the entangled state with a random superposition
    double angle = dis(gen) * 2 * M_PI;
    std::complex<double> entangledState0 = std::complex<double>(cos(angle), sin(angle));
    std::complex<double> entangledState1 = std::complex<double>(cos(angle + M_PI / 2), sin(angle + M_PI / 2));

    state0 = qubit.state0 = entangledState0;
    state1 = qubit.state1 = entangledState1;
}



VirtualQubit::VirtualQubit() : gen(std::random_device{}()), entangledPartner(nullptr) {
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double angle = dis(gen) * 2 * M_PI; // Random angle for superposition
    state0 = std::complex<double>(cos(angle), sin(angle));
    state1 = std::complex<double>(cos(angle + M_PI / 2), sin(angle + M_PI / 2));
}



bool VirtualQubit::isEntangled() const {
    return entangledPartner != nullptr;
}

int VirtualQubit::measure() {


    
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double probabilityState0 = std::norm(state0);
    int result = dis(gen) < probabilityState0 ? 0 : 1;
    if (entangledPartner) {
        entangledPartner->state0 = result == 0 ? std::complex<double>(1, 0) : std::complex<double>(0, 0);
        entangledPartner->state1 = result == 1 ? std::complex<double>(1, 0) : std::complex<double>(0, 0);
    }
    return result;
}

void VirtualQubit::flip() {
     
    std::swap(state0, state1); // Simplifies the flipping of the qubit's state
}