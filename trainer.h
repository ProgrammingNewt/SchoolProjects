
#ifndef TRAINER_H
#define TRAINER_H

#include "pokemon.h"
#include <string>

class Trainer {
private:
    std::string trainer;
    Pokemon* team[6];
    int partySize;

public:
    Trainer(std::string trainerName);
    std::string getName();
    void addPokeToParty(Pokemon* poke);
    int getPartySize();
    void decrementPartySize();
    Pokemon getPokeX(int pokemonPos);
};

#endif
