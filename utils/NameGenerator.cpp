#include <string>
#include <vector>
#include <random>
#include "../utils/include/Species.hpp"
#include "NameGenerator.hpp"

NameGenerator::NameGenerator() : gen(rd()) {
    speciesNames = {
        {Species::DEMIHUMAN, {"Yimi Claws", "Hoya Fangs", "Mihra Paw", "Tadrel Vox", "Horver Razor", "Derrick Aquos", "Marie Sting", "Vim Tegri"}},
        {Species::DRACONIC, {"Trodhri", "Sriasho", "Trukthax", "Sthealdroz", "Medgut", "Iasniash", "Naergosoz", "Sthiokthilaz", "Holecdo", "Ozisthu"}},
        {Species::ELF, {"Horith Wysajeon", "Eldrin Aena", "Artin Kristris", "Aire Craphyra", "Nuovis Zumlamin", "Merellien Dordithas", "Larrel Ianxidor", "Navarre Trisdi", "Katar Vara", "Kelvhan Phirel"}},
        {Species::FAIRY, {"Florian Betterforest", "Snow Littleclove", "Flint Petalboots", "Pyro Tangleheart", "Oregano Rosewort", "Passiflora Maplebird", "Magpie Nevercliff", "Belladonna Plumwort", "Magnolia Toadtwist", "Black Rose Lily"}},
        {Species::GIANT, {"Kubor", "Xikmohr", "Gromnus", "Wrandhor", "Ogrog", "Bezsar", "Flulith", "Aribos", "Zoskos", "Wubos"}},
        {Species::HUMAN, {"Arthur Tech Lead", "Armando Welder", "Elias Mammoth", "Guilherme Corinthians", "Gustavo Vulcan", "Rafael of The Seven Lakes", "Maria Tailor", "Beatrice Lemon Tree", "Annie Silver"}},
        {Species::ORC, {"Zoz Hellsmile", "Kuz Keendrums", "Brohli Doommask", "Thahlzem Wolfdrums", "Mon Cravenrunner", "Gewda Deathband", "Sarty Sharpwatch", "Shasa Firefall", "Ula Broadstorm", "Tegerza Warpwish"}},
        {Species::UNDEAD, {"Aubrey Doomdemise", "Emlyn Freebirth", "Alvaro Freecrime", "Jeff Nightspark", "Matthew Aridrunner", "Leonarda Melling", "Dale Riley", "Kristina Hogan", "Ambre Nicholai", "Lorraine Blakemore"}},
        {Species::VAMPIRE, {"Ishmael, The Vampire", "Thaddeus, The Vampire", "Obediah, The Vampire", "Sin, The Vampire", "Barnabas, The Vampire", "Cassandra, The Vampire", "Carmilla, The Vampire", "Lyllith, The Vampire", "Kiara, The Vampire", "Tempesta, The Vampire"}},
        {Species::INFERNAL, {"Ralgalad", "Zogloth", "Thogdruth", "Koth'tis", "Sug'thaxon", "Zallmumoth", "Gorzon", "Bongrin", "Thostren", "Thogdral"}}
    };
}

std::string NameGenerator::randomName(Species type) {
    std::vector<std::string> choosedNames;

    for (const auto& species : speciesNames) {
        if (species.first == type) {
            choosedNames = species.second;
            break;
        }
    }

    std::uniform_int_distribution<> dis(0, choosedNames.size() - 1);
    int randomIndex = dis(gen);

    return choosedNames[randomIndex];
}