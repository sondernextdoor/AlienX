#pragma once
#include "cell.h"
#include "physics.h"
#include <string>
#include <vector>
#include <memory>
#include <cstddef>

struct tissue {
    std::string name;
    std::vector<cell> cells;
};

struct neural_network {
    std::vector<std::vector<float>> weights;
    int input_size{};
    int output_size{};

    neural_network(int input = 4, int output = 2) : input_size(input), output_size(output) {
        weights.resize(input_size);
        for (int i = 0; i < input_size; ++i) {
            weights[i] = random_float_array(output_size, -1.0f, 1.0f);
        }
    }

    std::vector<float> process(const std::vector<float>& inputs) {
        std::vector<float> outputs(output_size, 0.0f);
        for (int j = 0; j < output_size; ++j) {
            for (int i = 0; i < input_size && i < static_cast<int>(inputs.size()); ++i) {
                outputs[j] += inputs[i] * weights[i][j];
            }
        }
        return outputs;
    }
};

class organ {
public:
    std::string name;
    std::vector<tissue> tissues;
    virtual ~organ() = default;
};

class brain : public organ {
public:
    void* memory{};
    std::size_t capacity{};
    neural_network network;

    explicit brain(bool super_gene = false)
        : network( super_gene ? 8 : 4, super_gene ? 4 : 2 ) {
    neural_network network;

    explicit brain(bool super_gene = false)
        : network( super_gene ? 8 : 4, super_gene ? 4 : 2 ) {

    explicit brain(bool super_gene = false) {
        name = "Brain";
        capacity = super_gene ? 2048 : 1024;
        memory = ::operator new(capacity);
    }

    ~brain() override {
        ::operator delete(memory);
    }
};

class heart : public organ {
public:
    int chambers{};

    explicit heart(bool super_gene = false) {
        name = "Heart";
        chambers = super_gene ? 5 : 4;
    }
};

class muscle : public organ {
public:
    int fibers{};

    explicit muscle(bool super_gene = false) {
        name = "Muscle";
        fibers = super_gene ? 200 : 100;
    }
};

class lung : public organ {
public:
    int capacity{};

    explicit lung(bool super_gene = false) {
        name = "Lung";
        capacity = super_gene ? 2000 : 1000;
    }
};

class liver : public organ {
public:
    int detox_level{};

    explicit liver(bool super_gene = false) {
        name = "Liver";
        detox_level = super_gene ? 2 : 1;
    }
};

class kidney : public organ {
public:
    int filter_rate{};

    explicit kidney(bool super_gene = false) {
        name = "Kidney";
        filter_rate = super_gene ? 3 : 1;
    }
};

class eye : public organ {
public:
    bool night_vision{};
    neural_network network;

    explicit eye(bool super_gene = false)
        : network(2, 2) {
        name = "Eye";
        night_vision = super_gene;
    }

    std::vector<float> see(const photon& light) {
        return network.process({light.wavelength, light.intensity});
    }
};

class ear : public organ {
public:
    bool enhanced_hearing{};
    neural_network network;

    explicit ear(bool super_gene = false)
        : network(2, 2) {
        name = "Ear";
        enhanced_hearing = super_gene;
    }

    std::vector<float> hear(const phonon& sound) {
        return network.process({sound.frequency, sound.amplitude});
    }
};

class nose : public organ {
public:
    bool keen_smell{};
    neural_network network;

    explicit nose(bool super_gene = false)
        : network(2, 2) {
        name = "Nose";
        keen_smell = super_gene;
    }

    std::vector<float> smell(const odoron& scent) {
        return network.process({scent.molecule_weight, scent.concentration});

    explicit eye(bool super_gene = false) {
        name = "Eye";
        night_vision = super_gene;
    }
};

class epidermis : public organ {
public:
    bool camouflage{};

    explicit epidermis(bool super_gene = false) {
        name = "Skin";
        camouflage = super_gene;
    }
};

struct body {
    std::vector<std::shared_ptr<organ>> organs;
};

