#include <iostream>
#include <string>
#ifndef MOVEH
#define MOVEH
using namespace std;

class Move {

private:

    string moveName;
    string moveType;
    int damage;
    int index;

public:

    Move();

    Move(string moveName, string moveType, int damage, int index);
    

    string getName() const;

    string getType() const;

    int getDamage() const;

    int getIndex() const;

    void setName(const string &name);

    void setType(const string &type);

    void setDamage(int damage);

    void setIndex(int index);

};

#endif 