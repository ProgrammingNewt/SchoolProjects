//Author: Ariel Espinoza 

//Description: This is a simple 10 question, 4 operation, math game where solutions are in integer algebra. 

/*
Code explained: I made a loop which iterates 10 times. Each iteration it will generate a random number between 0-3 using the modulo operation. 
Each numer, 0-3 will correspond to an operation which will then be chosen to produce a question. 
Each question will have 2 numbers, each generated randomly and between values 1-100 inclusive. This is done intentionally to avoid divisionByZero errors. 
The program then takes the user input for the question and compares it to the actual integer value of the solution. If correct, the user is notified
and their score is increased. If incorrect, the user is notified of the correct solution and their score does not increase.
Additionally, I added if the user wanted to play again or exit the program using a simple boolean statment and a while loop. 
The program assumes the user will enter the correct type for each input, no exceptions or errors taken into account. 
*/

//Date completed: Aug 29, 2023

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    //Seeds randomness
    srand(time(0));

    //Welcomes user to game
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    std::cout <<  "Welcome to the Math Game. All operations and solutions will be using integer algebra (including integer division with no remanider! Therefore 1/2 = 0)!" << std::endl;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;

    //Initializes score to 0
    int userScore = 0; 

    //While loop if they want to keep playing
    while (true) {

        //For loop that runs 10 times and will ask the random questions
        for(int i = 0; i < 10;i++) {

            int randOperation = rand() % 4; //Random operation per iteration of loop
            int randomNum1 = rand() % 100 + 1; //Rand numbers
            int randomNum2 = rand() % 100 + 1;
            int userAnswer; //initializing the users inputs as an integer given by the rules of the game (integer alg)
            int solution;   //initializing actual solution to problems. 


            //Random addition question
            if (randOperation == 0) {
        

                std::cout<< "What is " << randomNum1 << " + " << randomNum2 << "? \n" << std::endl;
                std::cin >> userAnswer;

                solution = randomNum1 + randomNum2; 
                    

                    //user is correct
                    if (solution == userAnswer) {

                        std::cout <<  "Correct!\n"<< std::endl;
                        userScore++;
                    }
                    //user not correct
                    else{

                        std::cout <<  "Incorrect! The correct answer is "<< solution << ".\n" << std::endl;


                    }
            }
            //random subtraction question
            else if (randOperation == 1) {

                std::cout<<"What is " << randomNum1 << " - " << randomNum2 << "? \n" << std::endl;
                std::cin >> userAnswer;

                solution = randomNum1 - randomNum2; 

                    if (solution == userAnswer) {

                        std::cout <<  "Correct! \n"<< std::endl;
                        userScore++;
                    }

                    else{

                        std::cout <<  "Incorrect! The correct answer is "<< solution << ".\n" << std::endl;


                    }


            }
            //random mult question
            else if (randOperation == 2) {
            
                std::cout<<"What is " << randomNum1 << " * " << randomNum2 << "? \n" << std::endl;
                std::cin >> userAnswer;

                solution = randomNum1 * randomNum2; 

                    if (solution == userAnswer) {

                        std::cout <<  "Correct!\n"<< std::endl;
                        userScore++;
                    }

                    else{

                        std::cout <<  "Incorrect! The correct answer is "<< solution << ".\n" << std::endl;


                    }
            }
            //random division question
            //not if else bc if its not 0,1,2 it must be 3
            else {

            

            std::cout<<"What is " << randomNum1 << " / " << randomNum2 << "? \n" << std::endl;
            std::cin >> userAnswer;

                solution = randomNum1 / randomNum2; 

                    if (solution == userAnswer) {

                        std::cout <<  "Correct!\n"<< std::endl;
                        userScore++;
                    }

                    else{

                        std::cout <<  "Incorrect! The correct answer is "<< solution << ".\n" << std::endl;


                    }

            }

            

        }

        //Gives user their score /10.
        std::cout << "Your total score is: " << userScore << "/10\n" <<std::endl;

        //Asks to play again
        std::cout << "Would you like to play again? Please enter: [Y/N]\n" << std::endl;
        char playAgain = 'N'; 
        std::cin >> playAgain;
        //If they want to play again type Y or of not type N
        //I didnt take every single user input into account so this could break the code if user inputs something other than Y or N but I will assume user follows the rules.
       
        if(playAgain == 'Y'){

            userScore = 0;
            continue;


        }
        else if(playAgain == 'N'){
            std::cout << "Goodbye!" << std::endl;
            break;
        }
    
        
    
    
    }



    return 0;
}