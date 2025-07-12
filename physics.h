#ifndef PHYSICS_H
#define PHYSICS_H

#include <string>
#include <vector>

struct particle {
    std::string name;
    float mass{}; // in MeV/c^2, simplified
    float charge{}; // in elementary charge units
    particle(std::string n = "", float m = 0.0f, float q = 0.0f)
        : name(std::move(n)), mass(m), charge(q) {}
};

struct photon : particle {
    float wavelength{}; // in nanometers
    float intensity{};
    photon(float wl = 550.0f, float inten = 1.0f)
        : particle("Photon", 0.0f, 0.0f), wavelength(wl), intensity(inten) {}
};

struct phonon : particle {
    float frequency{}; // in kHz
    float amplitude{};
    phonon(float freq = 1.0f, float amp = 1.0f)
        : particle("Phonon", 0.0f, 0.0f), frequency(freq), amplitude(amp) {}
};

struct electron : particle {
    electron() : particle("Electron", 0.511f, -1.0f) {}
};

struct proton : particle {
    proton() : particle("Proton", 938.27f, 1.0f) {}
};

struct neutron : particle {
    neutron() : particle("Neutron", 939.57f, 0.0f) {}
};

struct boson : particle {
    boson(std::string n = "Boson", float m = 0.0f)
        : particle(std::move(n), m, 0.0f) {}
};

struct quark : particle {
    std::string flavor;
    quark(std::string flav = "up", float m = 2.2f, float charge = 2.0f/3.0f)
        : particle("Quark", m, charge), flavor(std::move(flav)) {}
};

struct neutrino : particle {
    float energy{}; // in MeV
    float flux{};
    neutrino(float e = 1.0f, float f = 1.0f)
        : particle("Neutrino", 0.0f, 0.0f), energy(e), flux(f) {}
};

#endif // PHYSICS_H
