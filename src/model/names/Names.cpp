#include <iostream>
#include <vector>
#include <string>
#include <random>

int main() {
    // List of names and species
    
    std::vector<std::pair<std::string, std::vector<std::string>>> species = {
        {"Demihuman", {"Yimi Claws", "Hoya Fangs", "Mihra Paw", "Tadrel Vox", "Horver Razor", "Derrick Aquos", "Marie Sting", "Vim Tegri"}},
        {"Draconic", {"Trodhri", "Sriasho", "Trukthax", "Sthealdroz", "Medgut", "Iasniash", "Naergosoz", "Sthiokthilaz", "Holecdo", "Ozisthu"}},
        {"Elf", {"Horith Wysajeon", "Eldrin Aena", "Artin Kristris", "Aire Craphyra", "Nuovis Zumlamin", "Merellien Dordithas", "Larrel Ianxidor", "Navarre Trisdi", "Katar Vara", "Kelvhan Phirel"}},
        {"Fairy", {"Florian Betterforest", "Snow Littleclove", "Flint Petalboots", "Pyro Tangleheart", "Oregano Rosewort", "Passiflora Maplebird", "Magpie Nevercliff", "Belladonna Plumwort", "Magnolia Toadtwist", "Black Rose Lily"}},
        {"Giant", {"Kubor", "Xikmohr", "Gromnus", "Wrandhor", "Ogrog", "Bezsar", "Flulith", "Aribos", "Zoskos", "Wubos"}},
        {"Human", {"Arthur Tech Lead", "Armando Welder", "Elias Mammoth", "Guilherme Corinthians", "Gustavo Vulcan", "Rafael of The Seven Lakes", "Maria Tailor", "Beatrice Lemon Tree", "Annie Silver"}},
        {"Orc", {"Zoz Hellsmile", "Kuz Keendrums", "Brohli Doommask", "Thahlzem Wolfdrums", "Mon Cravenrunner", "Gewda Deathband", "Sarty Sharpwatch", "Shasa Firefall", "Ula Broadstorm", "Tegerza Warpwish"}},
        {"Undead", {"Aubrey Doomdemise", "Emlyn Freebirth", "Alvaro Freecrime", "Jeff Nightspark", "Matthew Aridrunner", "Leonarda Melling", "Dale Riley", "Kristina Hogan", "Ambre Nicholai", "Lorraine Blakemore"}},
        {"Vampire", {"Ishmael, The Vampire", "Thaddeus, The Vampire", "Obediah, The Vampire", "Sin, The Vampire", "Barnabas, The Vampire", "Cassandra, The Vampire", "Carmilla, The Vampire", "Lyllith, The Vampire", "Kiara, The Vampire", "Tempesta, The Vampire"}},
        {"Infernal", {"Ralgalad", "Zogloth", "Thogdruth", "Koth'tis", "Sug'thaxon", "Zallmumoth", "Gorzon", "Bongrin", "Thostren", "Thogdral"}}
    };


    // Search species on the list
    bool founded = false;
    std::vector<std::string> choosedNames;
    for (const auto& specie : species) {
        if (specie.first == choosedSpecie) {
            choosedNames = specie.second;
            founded = true;
            break;
        }
    }



    // Giveway random name
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, choosedNames.size() - 1);

    int randomIndex = dis(gen);
    std::cout << "Creature name: " << choosedNames[randomIndex] << std::endl;

    return 0;
}
