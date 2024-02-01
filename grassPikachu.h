#ifndef GRASSPIKACHUH
#define GRASSPIKACHUH

#include "pokemon.h"

class GrassPikachu : public Pokemon {
private:
    
    string evolution;
    string ability;        // Taunt text

public:
    GrassPikachu(const string &name, int level); 

    string getEvolution() const;
    void setEvolution(const string &newEvolution);

    string getAbility() const;
    void setAbility(const string &newAbility);

    GrassPikachu evolve();

    void emote() override;
};

#endif