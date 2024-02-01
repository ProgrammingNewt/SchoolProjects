#ifndef POKEMONH
#define POKEMONH
#include <string>
#include "moves.h"
using namespace std;

class Pokemon {
private:

    string name;
    string type;
    int health;
    int attack;
    int defense;
    int level;

    Move moves[4];

public:
    
    Pokemon();
    
    Pokemon(string name, string type, int health, int attack, int defense, Move move1, Move move2, Move move3, Move move4);

    string getName() const;

    string getType() const;

    string getMove(int index) const;

    int getHealth() const;

    int getAttack() const;

    int getDefense() const;

    void setName(const string &name);

    void setType(const string &type);

    void setHealth(int health);

    void setAttack(int attack);

    void setDefense(int defense);

    void performMove(Pokemon &target, int moveIndex);

    void receiveDamage(int damage);

    string displayName();

    void displayHealth() const;

    void levelUp(int levels);

    void setLevel(int newLevel);

    int getLevel() const; 

    virtual void emote();
    
    
};

#endif