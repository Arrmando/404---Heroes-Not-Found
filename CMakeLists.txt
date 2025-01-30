cmake_minimum_required(VERSION 3.14)
project(404/HeroesNotFound)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define o caminho base do projeto
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

# Inclui diretórios de cabeçalho
include_directories(
    ${CMAKE_SOURCE_DIR}/libs/cppcoro/include/cppcoro
    ${CMAKE_SOURCE_DIR}/libs/cppcoro/include
    ${CMAKE_SOURCE_DIR}/src/model/attributes/include
    ${CMAKE_SOURCE_DIR}/src/model/character/include
    ${CMAKE_SOURCE_DIR}/src/model/races/include
    ${CMAKE_SOURCE_DIR}/src/model/races/species/include
    ${CMAKE_SOURCE_DIR}/src/model/jobs/include
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/include
    ${CMAKE_SOURCE_DIR}/src/model/modifiers/include
    ${CMAKE_SOURCE_DIR}/utils/include
)

# Define diretórios de bibliotecas
link_directories(${CMAKE_SOURCE_DIR}/libs/cppcoro/build/lib)

add_definitions(-Dlinux=linux_namespace)

# Lista de arquivos fonte
set(SOURCES

    # Arquivos de utils
    ${CMAKE_SOURCE_DIR}/utils/Attributes.cpp
    ${CMAKE_SOURCE_DIR}/utils/AttributesType.cpp
    ${CMAKE_SOURCE_DIR}/utils/Classes.cpp
    ${CMAKE_SOURCE_DIR}/utils/Corroutines.cpp
    ${CMAKE_SOURCE_DIR}/utils/Job.cpp
    ${CMAKE_SOURCE_DIR}/utils/Race.cpp
    ${CMAKE_SOURCE_DIR}/utils/Species.cpp
    ${CMAKE_SOURCE_DIR}/utils/NameGenerator.cpp

    # Arquivos de races
    ${CMAKE_SOURCE_DIR}/src/model/races/RacesInterface.cpp
    ${CMAKE_SOURCE_DIR}/src/model/races/Races.cpp
    ${CMAKE_SOURCE_DIR}/src/model/races/RaceIncubator.cpp
    ${CMAKE_SOURCE_DIR}/src/model/races/species/Demihuman.cpp
    ${CMAKE_SOURCE_DIR}/src/model/races/species/Draconic.cpp
    ${CMAKE_SOURCE_DIR}/src/model/races/species/Elf.cpp
    ${CMAKE_SOURCE_DIR}/src/model/races/species/Fairy.cpp
    ${CMAKE_SOURCE_DIR}/src/model/races/species/Giant.cpp
    ${CMAKE_SOURCE_DIR}/src/model/races/species/Human.cpp
    ${CMAKE_SOURCE_DIR}/src/model/races/species/Infernal.cpp
    ${CMAKE_SOURCE_DIR}/src/model/races/species/Orc.cpp
    ${CMAKE_SOURCE_DIR}/src/model/races/species/Undead.cpp
    ${CMAKE_SOURCE_DIR}/src/model/races/species/Vampire.cpp

    # Arquivos de jobs
    ${CMAKE_SOURCE_DIR}/src/model/jobs/Jobs.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/JobsInterface.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/JobIncubator.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/Barbarian.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/Bard.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/Cleric.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/Druid.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/Mage.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/Monk.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/Necromancer.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/Paladin.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/Ranger.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/Rogue.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/Sorcerer.cpp
    ${CMAKE_SOURCE_DIR}/src/model/jobs/classes/Warrior.cpp

    # Arquivos de attributes
    ${CMAKE_SOURCE_DIR}/src/model/attributes/AttributesProcessor.cpp

    # Arquivos de modifiers
    ${CMAKE_SOURCE_DIR}/src/model/modifiers/ModifiersProcessor.cpp

    # Arquivos de character
    ${CMAKE_SOURCE_DIR}/src/model/character/TechnicalSheet.cpp
    ${CMAKE_SOURCE_DIR}/src/model/character/CharacterIncubator.cpp
    ${CMAKE_SOURCE_DIR}/src/model/character/CharacterProcessor.cpp

    # Arquivo principal do model
    ${CMAKE_SOURCE_DIR}/src/model/main.cpp
)

# Cria o executável
add_executable(HeroesNotFound ${SOURCES})

# Linka bibliotecas
target_link_libraries(HeroesNotFound PRIVATE cppcoro)