#ifndef INTERFACERACE_H
#define INTERFACERACE_H

#include <string>

class interfaceRace {
public:
    interfaceRace() = default;
    virtual ~interfaceRace() = default;

    virtual void setDefaultAttributes() = 0;
    virtual void raceSpecialTrait() = 0;
    std::string getRaceName() const;

protected:
  std::string name;
};

#endif //INTERFACERACE_H