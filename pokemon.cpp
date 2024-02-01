#include "pokemon.h"
#include "moves.h"
#include <iostream>
#include <string>
using namespace std;


Pokemon::Pokemon(){

    name = "decault name";

    type = "nothing";

    health = 100;
    attack = 10;
    defense = 10;

}
Pokemon::Pokemon(string nameVal, string typeVal, int healthVal, int attackVal, int defenseVal, Move move1, Move move2, Move move3, Move move4){

    name = nameVal;

    type = typeVal;

    health = healthVal;

    attack = attackVal;

    defense = defenseVal;

    moves[0] = move1;
    moves[1] = move2;
    moves[2] = move3;
    moves[3] = move4;



}

string Pokemon::getMove(int index) const {

    return moves[index].getName();

}

//Move Pokemon::setMove(int index) const {

    //something here

//}



string Pokemon::getName() const {

    return name;
}

string Pokemon::getType() const {

    return type;
}

int Pokemon::getHealth() const {

    return health;
}

int Pokemon::getAttack() const {

    return attack;
}

int Pokemon::getDefense() const {

    return defense;
}

void Pokemon::setName(const string &nameVal) {

    name = nameVal;
}

void Pokemon::setType(const string &typeVal) {

    type = typeVal;
}

void Pokemon::setHealth(int healthVal) {

    health = healthVal;
}

void Pokemon::setAttack(int attackVal) {

    attack = attackVal;
}

void Pokemon::setDefense(int defenseVal) {

    defense = defenseVal;
}


void Pokemon::performMove(Pokemon &target, int moveIndex) {

    if (moveIndex < 0 || moveIndex >= 4) {

        cout << "Not valid move" << endl;

        return;
    }

    Move moveToPerform = moves[moveIndex];


    double typeEffectiveness = 1; 

    
    if (moveToPerform.getType() == "Fire" ) {

        if (target.getType() == "Grass") {

            typeEffectiveness = 2;

        } else if (target.getType() == "Fire" || target.getType() == "Water") {
            
            typeEffectiveness = 0.5;
        }
    } 
    
    else if (moveToPerform.getType() == "Grass") {

        if (target.getType() == "Water") {

            typeEffectiveness = 2;

        } 
        
        else if (target.getType() == "Grass" || target.getType() == "Fire") {

            typeEffectiveness = 0.5;
        }
    }
    else if (moveToPerform.getType() == "Water") {

        if (target.getType() == "Fire") {

            typeEffectiveness = 2;

        } 
        else if (target.getType() == "Water" || target.getType() == "Grass") {
            typeEffectiveness = 0.5;
        }
    }

    int damage = (moveToPerform.getDamage() + attack) * typeEffectiveness - target.getDefense();


    if(damage <= 0){

        damage = 0;
    }
    

    target.receiveDamage(damage);
}

void Pokemon::receiveDamage(int damage) {

    health -= damage;

    if (health < 0) {
    
        health = 0; 
    }
}

void Pokemon::displayHealth() const {

    cout << name << " - HP: " << health << endl;

}