#ifndef NORMALPIKACHUH
#define NORMALPIKACHUH

#include "pokemon.h"

class NormalPikachu : public Pokemon {
private:
    
    string evolution;
    string ability;       

public:
    NormalPikachu(const string &name, int level); 

    string getEvolution() const;
    void setEvolution(const string &newEvolution);

    string getAbility() const;
    void setAbility(const string &newAbility);

    NormalPikachu evolve();
};

#endif
