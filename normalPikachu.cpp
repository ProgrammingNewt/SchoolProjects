
#include "normalPikachu.h"


NormalPikachu::NormalPikachu(const string &name, int level) 
: Pokemon(name, "Normal", 100, 20, 20,
          Move("Normal Fist", "Normal", 5, 1),
          Move("Normal Slam", "Normal", 4, 2),
          Move("Normal Wave", "Normal", 6, 3),
          Move("Normal Hammer", "Normal", 7, 4)),

  
  evolution("Giant"),

  ability("Get ready for an earthquake.") {  
    setName(name);
    setLevel(level); 
}


string NormalPikachu::getEvolution() const {
    return evolution;
}

void NormalPikachu::setEvolution(const string &newEvolution) {
    evolution = newEvolution;
}

string NormalPikachu::getAbility() const {
    return ability;
}

void NormalPikachu::setAbility(const string &newAbility) {
    ability = newAbility;
}

NormalPikachu NormalPikachu::evolve() {
     

    NormalPikachu evolvedPikachu(*this);
    
    evolvedPikachu.setName(evolution); 


    evolvedPikachu.setHealth(getHealth() * 1.2);

    evolvedPikachu.setAttack(getAttack() * 1.2);

    evolvedPikachu.setDefense(getDefense() * 1.2);

    cout << getName() << " HAS EVOLVED from all that fighting!!!";
    
    return evolvedPikachu;

   
}