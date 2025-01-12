

#ifndef interfaceRace_H
#define interfaceRace_H

#include <string>

class interfaceRace {
public:
    virtual void onStart() = 0;
    virtual void onDestroy() = 0;
    virtual void setDefaultAttributes() = 0;
    virtual void raceSpecialTrait() = 0;
    virtual std::string getRaceName() const = 0;
    virtual ~interfaceRace() {}
};

#endif //interfaceRace_H

git config --global user.name "EliasDMS"
git config --global user.email "eliasdaniel_ms@outlook.com.br"