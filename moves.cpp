#include "moves.h"
#include <iostream>
#include <string>
using namespace std;


Move::Move() {

    moveName = "default";
    moveType = "Normal";
    damage = 1;
    

}
Move::Move(string nameVal, string typeVal, int damageVal, int indexVal) {

    moveName = nameVal;
    moveType = typeVal;
    damage = damageVal;
    index = indexVal;

}


string Move::getName() const {

    return moveName;

}

string Move::getType() const {

    return moveType;

}

int Move::getDamage() const {

    return damage;

}

int Move::getIndex() const {

    return index;

}

void Move::setName(const string &nameVal) {

    moveName = nameVal;
}

void Move::setType(const string &typeVal) {


    moveType = typeVal;
}

void Move::setDamage(int damageVal) {

    damage = damageVal;
}

void Move::setIndex(int indexVal){

    index = indexVal;

}