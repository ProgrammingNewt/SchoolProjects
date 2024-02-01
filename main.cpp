/*

Lab Group 1: Charlie & Ariel
Lab 13

Bootleg pikachu, 
added: New gameplay options : new menu added
Pokemon class uses virtual functions for code efficiency


*/


#include "pokemon.h"
#include "trainer.h"
#include "moves.h"

#include "normalPikachu.h" 
#include "waterPikachu.h" 
#include "firePikachu.h"
#include "grassPikachu.h"


#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

using namespace std;

void battle();


    // Moves
    Move scratch("Scratch","normal", 27, 1);
    Move tackle("Tackle", "normal", 27, 2);
    Move growl("Growl","normal",3,3);
    Move tailWhip("Tail Whip","normal", 42, 4);
    Move absorb("Absorb","grass",55, 1 );
    Move leechSeed("Leech Seed", "grass", 34, 2);
    Move vineWhip("Vine Whip", "grass", 56, 3);
    Move razorLeaf("Razor Leaf", "grass", 57, 4);
    Move ember("Ember", "fire", 46, 1);
    Move flameWheel("Flame Wheel", "fire", 58, 2);
    Move fireSpin("Fire Spin", "fire", 30, 3);
    Move flamethrower("Flamethrower", "fire", 3, 4);
    Move waterGun("Water Gun", "water", 56, 1);
    Move bubble("Bubble", "water", 35, 2);
    Move waterPulse("Water Pulse", "water", 27, 3);
    Move surf("Surf", "water", 49, 4);
    
    // Pokedex
    Pokemon* fireCarry1 = new FirePikachu("Fire Carry", 5);
    Pokemon* fireCarry2 = new FirePikachu("Fire Pear", 5);
    Pokemon* fireCarry3 = new FirePikachu("Fire Chu", 5);
    Pokemon* fireCarry4 = new FirePikachu("Fire Monster", 5);
    Pokemon* fireCarry5 = new FirePikachu("Fire Bro", 5);
    Pokemon* fireCarry6 = new FirePikachu("Fire Zard", 5);

    Pokemon* grassCarry1 = new GrassPikachu("Grass guy", 5);
    Pokemon* grassCarry2 = new GrassPikachu("Grass serpent", 5);
    Pokemon* grassCarry3 = new GrassPikachu("Grass man", 5);
    Pokemon* grassCarry4 = new GrassPikachu("Grass vine", 5);
    Pokemon* grassCarry5 = new GrassPikachu("Grass goat", 5);
    Pokemon* grassCarry6 = new GrassPikachu("Grass snake", 5);

    Pokemon* normalCarry1 = new NormalPikachu("Santa Man", 5);
    Pokemon* normalCarry2 = new NormalPikachu("Lapras", 5);
    Pokemon* normalCarry3 = new NormalPikachu("Snorlax", 5);
    Pokemon* normalCarry4 = new NormalPikachu("That guy", 5);
    Pokemon* normalCarry5 = new NormalPikachu("Lugia", 5);
    Pokemon* normalCarry6 = new NormalPikachu("Arcanine", 5);

    Pokemon* waterCarry1 = new WaterPikachu("Kyogre", 5);
    Pokemon* waterCarry2 = new NormalPikachu("Gyrados", 5);
    Pokemon* waterCarry3 = new NormalPikachu("Seaking", 5);
    Pokemon* waterCarry4 = new NormalPikachu("LifeguardPokemon", 5);
    Pokemon* waterCarry5 = new NormalPikachu("Water Spider", 5);
    Pokemon* watterCarry6 = new NormalPikachu("SurferPoke", 5);

    string username;

    int main(){

    cout << "Welcome to pokemon!, Enter your name: " << endl;
    cin >> username;

    int choice;
        Trainer user(username);
    user.addPokeToParty(fireCarry1);
    user.addPokeToParty(fireCarry2);
    user.addPokeToParty(fireCarry3);
    user.addPokeToParty(fireCarry4);
    user.addPokeToParty(fireCarry5);
    user.addPokeToParty(fireCarry6);

    

    Trainer ash("Ash Ketchum"); 
    ash.addPokeToParty(grassCarry6);
    ash.addPokeToParty(watterCarry6);
    ash.addPokeToParty(grassCarry4);
    ash.addPokeToParty(normalCarry5);
    ash.addPokeToParty(grassCarry2);
    ash.addPokeToParty(grassCarry1);

    cout << "test" << endl;

    do{ 

        cout << "Menu: " << endl;
        cout << "1. Battle" << endl;
        cout << "2. View crew" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;



switch(choice){
    case 1:
        battle();
        break; 

    case 2:
        cout << "--------------------" << endl;
        cout << "Trainer: " << user.getName() << endl;
        cout << "--------------------" << endl;
        cout << "Crew: " << endl;
        for(int i = 0; i < 6; i++){
            cout << "--------------------" << endl;
            Pokemon userPokemon = user.getPokeX(i);
            cout << "Pokemon " <<  i << ": " << userPokemon.getName() << endl;

        }

        break;


    case 3:
        std::cout << "Exiting the game.... Thank you for playing bootleg pokemon" << endl;
        break;

    default:
        std::cout << "Invalid choice. Please try again." << endl;
}

     }while(choice != 3);

    return 0;

    
    }

    

void battle(){

    Trainer user(username);
    user.addPokeToParty(fireCarry1);
    user.addPokeToParty(fireCarry2);
    user.addPokeToParty(fireCarry3);
    user.addPokeToParty(fireCarry4);
    user.addPokeToParty(fireCarry5);
    user.addPokeToParty(fireCarry6);

    Trainer ash("Ash Ketchum"); 
    ash.addPokeToParty(grassCarry6);
    ash.addPokeToParty(watterCarry6);
    ash.addPokeToParty(grassCarry4);
    ash.addPokeToParty(normalCarry5);
    ash.addPokeToParty(grassCarry2);
    ash.addPokeToParty(grassCarry1);


    cout << " Uh oh ! " << " Another trainer is approaching..!" << endl;
    cout << endl;
    cout << "--------------------------" << endl;
    cout << ash.getName() << " VS " << user.getName() << endl;
    cout << "    BATTLE BEGIN   " << endl;
    cout << "--------------------------" << endl;
    int levelSave1[6];
    int levelSave2[6];
while (user.getPartySize() > 0 && ash.getPartySize() > 0) {
    
    int userPoke = user.getPartySize() - 1;
    int opponentPoke = ash.getPartySize() - 1;
    Pokemon userPokemon = user.getPokeX(userPoke);
    Pokemon opponentPokemon = ash.getPokeX(opponentPoke);
    bool isDead;

    std::cout << user.getName() << "'s turn!" << endl;
    std::cout << endl;

    while (userPokemon.getHealth() > 0 && opponentPokemon.getHealth() > 0) {

        if(isDead == true){
            userPokemon.setHealth(userPokemon.getHealth() - 50);
        }else if(isDead == false){
            opponentPokemon.setHealth(opponentPokemon.getHealth() - 50);
        }
        std::cout << userPokemon.getName() << " vs " << opponentPokemon.getName() << endl;

        std::cout << "Available moves for " << userPokemon.getName() << ":" << endl;
        for (int i = 0; i < 4; ++i) {
            std::cout << i << ". " << userPokemon.getMove(i) << endl;
            std::cout << "---------------" << endl;
        }

        int selectedMove;
       std::cout << "Choose a move (0 to 3): ";
        std::cin >> selectedMove;

        if (selectedMove < 0 || selectedMove >= 4) {
            std::cout << "Invalid move, please try again." << endl;
            continue;
        }

        int randomNum2 = 0 + rand() % 3;
        userPokemon.performMove(opponentPokemon, selectedMove);
        std::cout << userPokemon.getName() << " uses " << userPokemon.getMove(selectedMove) << " on " << opponentPokemon.getName() << "!" << endl;
        std::cout << endl;
        std::cout << opponentPokemon.getName() << " has " << opponentPokemon.getHealth() << " health remaining!" << endl;
        std::cout << endl;
        userPokemon.levelUp(1);
        levelSave1[userPoke] = userPokemon.getLevel();
        

        if (opponentPokemon.getHealth() > 0) {
            std::cout << opponentPokemon.getName() << " uses " << opponentPokemon.getMove(randomNum2) << " on " << userPokemon.getName() << "!" << endl;
            std::cout << endl;
            opponentPokemon.performMove(userPokemon, randomNum2);
            std::cout << userPokemon.getName() << " has " << userPokemon.getHealth() << " health remaining!" << endl;
            std::cout << endl;
            opponentPokemon.levelUp(1);
            levelSave2[opponentPoke];


            
        } else if (opponentPokemon.getHealth() <= 0) {
            std::cout << opponentPokemon.getName() << " has fainted!" << endl;
            std::cout << endl;
            ash.decrementPartySize();
            isDead = true;
          
            
        }

                if (userPokemon.getHealth() <= 0) {
            std::cout << userPokemon.getName() << " has fainted!" << endl;
            std::cout << endl;
   
            user.decrementPartySize();
            isDead = false;
       
            
        }
    }



    std::cout << "End of battle!" << endl;

    std::cout << "---------------" << endl;
    std::cout << "Current party status:" << endl;
    std::cout << user.getName() << "'s party: " << user.getPartySize() << " Pokemon remaining" << endl;
    std::cout << ash.getName() << "'s party: " << ash.getPartySize() << " Pokemon remaining" << endl;
     std::cout << "---------------" << endl;

    // Ask if user wants to run or keep battling
     
    if(user.getPartySize() == 0){
        std::cout << " You lost! , better luck next time!" << endl;
        break;
        
    }else if(ash.getPartySize() == 0){
        std::cout << "---------------" << endl;
        std::cout << user.getName() << " Is the winner!, congrats!" << endl;
        std::cout << "---------------" << endl;
        break;
        
    }
     std::cout << "---------------" << endl;
    char run;
    std::cout << "Run? (y/n): ";
    std::cin >> run;
     std::cout << "---------------" << endl;

    if (run != 'n' && run != 'N') {

        std::cout << "Succesfully ran away!" << endl;
        std::cout << "---------------" << endl;
        break;

    }





}
   
  
    FirePikachu newfireCarry1("FireCarry", levelSave1[0]);
    FirePikachu newfireCarry2("Fire Chu", levelSave1[1]);
    FirePikachu newfireCarry3("Fire Monster", levelSave1[2]);
    FirePikachu newfireCarry4("Fire Bro", levelSave1[3]);
    FirePikachu newfireCarry5("Fire Zard", levelSave1[4]);
    FirePikachu newfireCarry6("FireCarry", levelSave1[5]);

    ash.addPokeToParty(grassCarry6);
    ash.addPokeToParty(watterCarry6);
    ash.addPokeToParty(grassCarry4);
    ash.addPokeToParty(normalCarry5);
    ash.addPokeToParty(grassCarry2);
    ash.addPokeToParty(grassCarry1);

    GrassPikachu newashCarry1("SurferPoke", levelSave2[0]);
    WaterPikachu newashCarry2("SurferPoke",levelSave2[1]);
    GrassPikachu newashCarry3("Grass vine",levelSave2[2]);
    NormalPikachu newashCarry4("Lugia",levelSave2[3]);
    GrassPikachu newashCarry5("Grass serpent", levelSave2[4]);
    GrassPikachu newashCarry6("Grass guy", levelSave2[5]);




    Pokemon& fire1 = newfireCarry1;
    Pokemon& fire2 = newfireCarry2;
    Pokemon& fire3 = newfireCarry3;
    Pokemon& fire4 = newfireCarry4;
    Pokemon& fire5 = newfireCarry5;
    Pokemon& fire6 = newfireCarry6;

    Pokemon& ash1 = newashCarry1;
    Pokemon& ash2 = newashCarry2;
    Pokemon& ash3 = newashCarry3;
    Pokemon& ash4 = newashCarry4;
    Pokemon& ash5 = newashCarry5;
    Pokemon& ash6 = newashCarry6;

    FirePikachu levelUpArray[6] = {newfireCarry1,newfireCarry2, newfireCarry3,newfireCarry4,newfireCarry5,newfireCarry6};

    Pokemon all[12] = {fire1, fire2, fire3,fire4,fire5,fire6, ash1, ash2, ash3, ash4, ash5, ash6};


for(int i = 0; i < 12; i++)
  {
    cout << "My name is " << all[i].getName() << ". I am currently level " << all[i].getLevel() << "and here is my finishing remark!" << endl;
    all[i].emote();
   
  }

for(int i = 0; i < 6; i++)
  {
  if(levelUpArray[i].getLevel() >= 6)
  {

    levelUpArray[i].evolve();
    std::cout << endl;
    std::cout << "---------------" << endl;

    std::cout << "This Pokemon is now " << levelUpArray[i].getEvolution() << endl; 

    std::cout << levelUpArray[i].getEvolution() << " gains the taunt ability!" << endl; 

    std::cout << "Ability: " << levelUpArray[i].getAbility() << endl;

    std::cout << "---------------" << endl;
}


  }



}
