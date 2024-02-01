#ifndef WATERPIKACHUH
#define WATERPIKACHUH

#include "pokemon.h"

class WaterPikachu : public Pokemon {
private:
    
    string evolution;
    string ability;       

public:
    WaterPikachu(const string &name, int level); 

    string getEvolution() const;
    void setEvolution(const string &newEvolution);

    string getAbility() const;
    void setAbility(const string &newAbility);

    WaterPikachu evolve();

    void emote() override;
};

#endif