#include "disease.h"
#include "physics.h"
#include <iomanip>

int main() {
    auto aliens = alien::create(5);
    photon light{550.0f, 1.0f};
    phonon sound{2.0f, 1.0f};
    neutrino nu{1.0f, 0.5f};
    odoron scent{5.0f, 1.0f};

    for (const auto& a : aliens) {
        std::cout << a.representation();
        for (const auto& org : a.anatomy.organs) {
            if (auto ey = dynamic_cast<eye*>(org.get())) {
                auto signal = ey->see(light);
                std::cout << "Vision: " << signal[0] << ", " << signal[1] << '\n';
            }
            if (auto ea = dynamic_cast<ear*>(org.get())) {
                auto audio = ea->hear(sound);
                std::cout << "Audio: " << audio[0] << ", " << audio[1] << '\n';
            }
            if (auto an = dynamic_cast<antenna*>(org.get())) {
                auto n = an->detect(nu);
                std::cout << "Neutrino: " << n[0] << ", " << n[1] << '\n';
            }
            if (auto no = dynamic_cast<nose*>(org.get())) {
                auto smell = no->smell(scent);
                std::cout << "Smell: " << smell[0] << ", " << smell[1] << '\n';
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
