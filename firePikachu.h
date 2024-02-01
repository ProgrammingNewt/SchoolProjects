#ifndef FIREPIKACHUH
#define FIREPIKACHUH

#include "pokemon.h"

class FirePikachu : public Pokemon {
private:
    
    string evolution;
    string ability;

public:
    FirePikachu(const string &name, int level); 


    string getEvolution() const;

    void setEvolution(const string &newEvolution);

    FirePikachu evolve();

    string getAbility() const;      

    void setAbility(const string &newAbility); 

    void emote() override;
};

#endif 