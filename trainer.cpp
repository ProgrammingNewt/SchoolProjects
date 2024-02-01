
#include "trainer.h"

Trainer::Trainer(std::string trainerName) : trainer(trainerName), partySize(0) {
    for (int i = 0; i < 6; ++i) {
        team[i] = nullptr;
    }
}

std::string Trainer::getName() {
    return trainer;
}

void Trainer::addPokeToParty(Pokemon* poke) {
    if (partySize < 6) {
        team[partySize] = poke;
        ++partySize;
    }
}
void Trainer::decrementPartySize(){partySize--;}
int Trainer::getPartySize() {
    return partySize;
}

Pokemon Trainer::getPokeX(int pokemonPos) {
    if (pokemonPos >= 0 && pokemonPos < partySize) {
        return *team[pokemonPos];
    }

}
