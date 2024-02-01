/*
Lab 6
Group 1:
Charlie & Ariel

Program that has two unique pokemon fight using objects of pokmeon and move
until one of the pokemon faints, then the program ends

*/



#include "pokemon.h"
#include "moves.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(NULL));

    // normal moves objects of Move class

    Move scratch("Scratch","normal", 4, 1);
    Move tackle("Tackle", "normal", 5, 2);
    Move growl("Growl","normal",1,3);
    Move tailWhip("Tail Whip","normal",2, 4);

    // grass moves objects of Move class

    Move absorb("Absorb","grass",5, 1 );
    Move leechSeed("Leech Seed", "grass", 4, 2);
    Move vineWhip("Vine Whip", "grass", 6, 3);
    Move razorLeaf("Razor Leaf", "grass", 7, 4);

    // fire moves objects of Move class

    Move ember("Ember", "fire", 6, 1);
    Move flameWheel("Flame Wheel", "fire", 8, 2);
    Move fireSpin("Fire Spin", "fire", 10, 3);
    Move flamethrower("Flamethrower", "fire", 12, 4);

    // water moves objects of Move class

    Move waterGun("Water Gun", "water", 6, 1);
    Move bubble("Bubble", "water", 5, 2);
    Move waterPulse("Water Pulse", "water", 7, 3);
    Move surf("Surf", "water", 9, 4);
    
    // two pokemon with unique type, health and moves that will face off against eachother

    Pokemon pokemon1("poke1", "Fire", 100, 20, 20, ember, flameWheel, fireSpin, flamethrower);
    Pokemon pokemon2("poke2", "Grass", 100, 20, 20, absorb, leechSeed, vineWhip, razorLeaf);


    cout << "Pokemon 1: " << pokemon1.getName() << endl;
    cout << "-----Stats-----" << endl;
    cout << "Health: " << pokemon1.getHealth() << endl;
    cout << "Attack: " << pokemon1.getAttack() << endl;
    cout << "Defense: "<< pokemon1.getDefense() << endl;
    cout << "Available Moves: " << pokemon1.getMove(0) << ", " << pokemon1.getMove(1) << ", " << pokemon1.getMove(2) << ", " << pokemon1.getMove(3) << "!" << endl; 
    cout << endl;
    cout << endl;
    cout << "Pokemon 2: " << pokemon2.getName() << endl;
    cout << "-----Stats-----" << endl;
    cout << "Health: " << pokemon2.getHealth() << endl;
    cout << "Attack: " << pokemon2.getAttack() << endl;
    cout << "Defense: "<< pokemon2.getDefense() << endl;
    cout << "Available Moves: " << pokemon2.getMove(0) << ", " << pokemon2.getMove(1) << ", " << pokemon2.getMove(2) << ", " << pokemon2.getMove(3) << "!" << endl; 
    cout << endl;


    string winner; 

    while (pokemon1.getHealth() > 0 && pokemon2.getHealth() > 0) {
        
        int randomNum1 = 1 + rand() % 4-1;
        int randomNum2 = 1 + rand() % 4-1;

        // will attack with random move
        
        cout << pokemon1.getName() << " has " << pokemon1.getHealth() << " Health remaining!" << endl;
        cout << pokemon2.getName() << " has " << pokemon2.getHealth() << " Health remaining!" << endl;
        
        cout << endl;
        cout << pokemon1.getName() << " uses " << pokemon1.getMove(randomNum1) << " on " << pokemon2.getName() << "!" << endl;

        pokemon1.performMove(pokemon2,randomNum1);

        if(pokemon2.getHealth() > 0){

            cout << pokemon2.getName() << " uses " << pokemon2.getMove(randomNum2) << " on " << pokemon1.getName() << "!" << endl;

            pokemon2.performMove(pokemon1,randomNum2);

            if(pokemon1.getHealth() == 0){

                cout << pokemon1.getName() << " has died!" << endl;
                winner = pokemon2.getName();
            }

        }
        else if (pokemon2.getHealth() == 0){

            cout << pokemon2.getName() << " has died!" << endl;
            winner = pokemon1.getName();
        }
        
        
    }
    cout<< endl;
    cout<< endl;
    cout<< endl;

    cout << winner << " is the winner of this duel!!!" << endl;

    return 0;
}