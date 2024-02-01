#include "waterPikachu.h"


WaterPikachu::WaterPikachu(const string &name, int level) 
: Pokemon(name, "Grass", 100, 20, 20,
          Move("Water-Absorb", "Water", 5, 1),
          Move("Hydro-pump", "Water", 4, 2),
          Move("Water Cannon", "Water", 6, 3),
          Move("surf", "Water", 7, 4)),

  
  evolution("Tsunami!"),

  ability("Get ready for a wave of destruction!") {  
    setName(name);
    setLevel(level); 
}


string WaterPikachu::getEvolution() const {
    return evolution;
}

void WaterPikachu::setEvolution(const string &newEvolution) {
    evolution = newEvolution;
}

string WaterPikachu::getAbility() const {
    return ability;
}

void WaterPikachu::setAbility(const string &newAbility) {
    ability = newAbility;
}

WaterPikachu WaterPikachu::evolve() {
     

    WaterPikachu evolvedPikachu(*this);
    
    evolvedPikachu.setName(evolution); 


    evolvedPikachu.setHealth(getHealth() * 1.2);

    evolvedPikachu.setAttack(getAttack() * 1.2);

    evolvedPikachu.setDefense(getDefense() * 1.2);

    cout << getName() << " HAS EVOLVED from all that fighting!!!";
    
    return evolvedPikachu;

   
}

void WaterPikachu::emote() {

    cout << "I am a Water type pokemon I make splashes!!" << endl;
}