#include "firePikachu.h"

FirePikachu::FirePikachu(const string &name, int level):Pokemon(name, "Fire", 100, 20, 20,
          Move("Spark Thrower", "Normal", 4, 1),
          Move("Blaze Dash", "Fire", 8, 2),
          Move("Inferno Swirl", "Fire", 10, 3),
          Move("Lightning Inferno", "Fire", 12, 4)),

  

  ability("Get ready to for some burns!!"),

  evolution("Lava Carry") {
    setLevel(level);

    setName(name);

    
}


string FirePikachu::getEvolution() const {
    return evolution;
}

void FirePikachu::setEvolution(const string &newEvolution) {
    evolution = newEvolution;
}

FirePikachu FirePikachu::evolve() {

    

    FirePikachu evolvedPikachu(*this);
    
    evolvedPikachu.setName(evolution); 
    

    evolvedPikachu.setHealth(getHealth() * 1.2);

    evolvedPikachu.setAttack(getAttack() * 1.2);

    evolvedPikachu.setDefense(getDefense() * 1.2);

    cout << getName() << " HAS EVOLVED from all that fighting!!!";

    return evolvedPikachu;


}

string FirePikachu::getAbility() const {
    return ability;
}

void FirePikachu::setAbility(const string &newAbility) {
    ability = newAbility;
}

void FirePikachu::emote() {

    cout << "I am a fire type pokemon I can burn things up!!" << endl;
}
