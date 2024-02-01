#include "grassPikachu.h"

GrassPikachu::GrassPikachu(const string &name, int level) 
: Pokemon(name, "Grass", 100, 20, 20,
          Move("Pika-Absorb", "Water", 5, 1),
          Move("Pika-Seed", "Water", 4, 2),
          Move("Pika-Whip", "Water", 6, 3),
          Move("Pika-Leaf", "Water", 7, 4)),

  
  evolution("Tree!"),

  ability("Get ready for a leaves!") {  
    setName(name);
    setLevel(level); 
}


string GrassPikachu::getEvolution() const {
    return evolution;
}

void GrassPikachu::setEvolution(const string &newEvolution) {
    evolution = newEvolution;
}

string GrassPikachu::getAbility() const {
    return ability;
}

void GrassPikachu::setAbility(const string &newAbility) {
    ability = newAbility;
}

GrassPikachu GrassPikachu::evolve() {
     

    GrassPikachu evolvedPikachu(*this);
    
    evolvedPikachu.setName(evolution); 


    evolvedPikachu.setHealth(getHealth() * 1.2);

    evolvedPikachu.setAttack(getAttack() * 1.2);

    evolvedPikachu.setDefense(getDefense() * 1.2);

    cout << getName() << " HAS EVOLVED from all that fighting!!!";
    
    return evolvedPikachu;

   
}

void GrassPikachu::emote() {

    cout << "I am a Grass type pokemon I make throw dirt and rocks!!" << endl;
}