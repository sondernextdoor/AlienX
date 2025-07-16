#include "alien.h"
#include <sstream>
#include <iomanip>

void alien::design(alien& newborn) {
    int species_choice = random_integer(0,1);
    if (species_choice == 0) {
        newborn = grey();
    } else {
        newborn = reptilian();
    }

    cell base = cell::base_cell(newborn.chromosome_count, newborn.standard_sequence);
    newborn.cells.assign(100, base);

    newborn.height = random_float(std::get<0>(newborn.height_range), std::get<1>(newborn.height_range));
    newborn.weight = random_float(std::get<0>(newborn.weight_range), std::get<1>(newborn.weight_range));
    newborn.health = 100.0f;
    newborn.strength = 10.0f;
    newborn.intelligence = 100.0f;

    newborn.anatomy.organs.push_back(std::make_shared<brain>());
    newborn.anatomy.organs.push_back(std::make_shared<heart>());
    newborn.anatomy.organs.push_back(std::make_shared<muscle>());
    newborn.anatomy.organs.push_back(std::make_shared<lung>());
    newborn.anatomy.organs.push_back(std::make_shared<liver>());
    newborn.anatomy.organs.push_back(std::make_shared<kidney>());
    newborn.anatomy.organs.push_back(std::make_shared<eye>());
    newborn.anatomy.organs.push_back(std::make_shared<ear>());
    newborn.anatomy.organs.push_back(std::make_shared<nose>());
    newborn.anatomy.organs.push_back(std::make_shared<epidermis>());

    const auto& dna = newborn.cells[0].nucleus_data.chromosome[0].dna;
    newborn.dna_sequence = dna.HE1.allele1 + dna.HE1.allele2 + dna.HE1.allele3 + dna.HE1.allele4 +
                           dna.ST1.allele1 + dna.ST1.allele2 + dna.ST1.allele3 + dna.ST1.allele4 +
                           dna.IN1.allele1 + dna.IN1.allele2 + dna.IN1.allele3 + dna.IN1.allele4 +
                           dna.AP1.allele1 + dna.AP1.allele2 + dna.AP1.allele3 + dna.AP1.allele4;
    newborn.color = newborn.calculate_color();
}

alien alien::create() {
    alien a;
    a.design(a);
    return a;
}

int alien::super_gene_carrier(alien subject) {
    for (const auto& org : subject.anatomy.organs) {
        if (auto br = dynamic_cast<brain*>(org.get()); br && br->capacity > 1024) return 999;
        if (auto hr = dynamic_cast<heart*>(org.get()); hr && hr->chambers > 4) return 333;
        if (auto ki = dynamic_cast<kidney*>(org.get()); ki && ki->filter_rate > 1) return 222;
        if (auto li = dynamic_cast<liver*>(org.get()); li && li->detox_level > 1) return 111;
        if (auto ey = dynamic_cast<eye*>(org.get()); ey && ey->night_vision) return 888;
        if (auto ea = dynamic_cast<ear*>(org.get()); ea && ea->enhanced_hearing) return 666;
        if (auto an = dynamic_cast<antenna*>(org.get()); an && an->neutrino_sensor) return 1111;
        if (auto no = dynamic_cast<nose*>(org.get()); no && no->keen_smell) return 0;
        if (auto sk = dynamic_cast<epidermis*>(org.get()); sk && sk->camouflage) return 555;
    }
    return 0;
}

std::string alien::calculate_color() {
    const auto& allele = cells[0].nucleus_data.chromosome[0].dna.AP1.allele1;
    if (allele == "T") return "Green";
    if (allele == "A") return "Grey";
    if (allele == "C") return "Red";
    if (allele == "G") return "Black";
    if (allele == "X") return "Translucent";
    return "Unknown";
}

vector<alien> alien::create(int count) {
    vector<alien> out;
    for(int i=0;i<count;++i) {
        out.push_back(create());
    }
    return out;
}

alien::alien() = default;

std::string alien::representation() const {
    std::ostringstream os;
    os << "  .-.\n";
    os << " (o o)  Species: " << species << "\n";
    os << " | O |  Color: " << color << "\n";
    os << " |   |  H:" << std::fixed << std::setprecision(1) << height
       << " W:" << weight << "\n";
    os << " '---'\n";
    return os.str();
}

