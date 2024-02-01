// Names: Ariel Espinoza, BingFong (Curtis)
// Description of code: This is a simple booking program which takes in a flight
booking, shows the user the booking detials, and deletes the current booking
// The code works based off of a numeric choosing system which the user can use to
indicate which option they would like to choose.
// Code analysis: This project was made using object oriented design and the usage
of fuctions. The Class bookings is used in order
//to store the values of the booking made by the user. There are three fucntions
that the user can call in order to operate on the booking object.
//the first is to make a booking which stores the input values of the user. The
second deltes the values the user has input, clearing up the booking made,
//lastly, there is a function which will return the most recent booking made as a
print statment for the user.
//The main runs within a while loop which allows for the user to exit the program
when they wish. The program also checks for valid inputs in the booking menu
//as only the numbers 1-4 inclusive are valid, all other ints, floats, strings, etc
will not be accepted. As for the each booking options,
//there is limited coverage of bad inputs as there would need to be more guidelines
to what a valid input should be for each option.
//Date Finished: 9/5/2023
#include <iostream>
#include <string>
using namespace std;
//creates booking class in order to make cooking objects in main
class Booking{
public: //Need this bc classes are inherently private. Could use struct which are
inherently public, but not mentioned in class I think.
string name;
string originAirport;
string destAirport;
string date;
};
//first of three fucntions, takes in a bookin with the specified information.
//Object "flight" is pass by referece in all functions as it needs to store the
information for future calls.
void bookFlight(Booking &flight){
cout << "Enter your name: ";
getline(cin, flight.name);
cout << "Enter your origin airport: ";
getline(cin, flight.originAirport);
cout << "Enter your destination airport: ";
getline(cin, flight.destAirport);
cout << "Enter date of flight: ";
getline(cin, flight.date);
cout << "Flight booked successfully!" << endl;
cout << endl;
}
//Deletes current booking. Checks if booking has already been made in order to
delete
//If no booking exists, lets user know that they cannot delete empty booking.
void deleteBooking(Booking &flight){
if((!flight.name.empty()) && (!flight.originAirport.empty()) && (!
flight.destAirport.empty()) && (!flight.date.empty()) ){
flight.name = "";
flight.originAirport = "";
flight.destAirport = "";
flight.date = "";
cout << "Booking successfully deleted." << endl;
cout << endl;
}
else{
cout << "No booking curretly exist to deltete. Please book a flight before
deleting." << endl;
cout << endl;
}
}
//Prints out the booking information for the user using the booking object.
//If no booking exists, then lets user know that booking is epmpty and therefore
cannot return the booking information.
void showBooking(Booking &flight){
if((!flight.name.empty()) && (!flight.originAirport.empty()) && (!
flight.destAirport.empty()) && (!flight.date.empty()) ){
cout << "Here is your current booking information!" << endl;
cout << "Booking name: " << flight.name << "." << endl;
cout << "Origin airport: " << flight.originAirport << "." << endl;
cout << "Destination airport: " << flight.destAirport << "." << endl;
cout << "Booking date: " << flight.date << "." << endl;
cout << endl;
}
else{
cout << "No booking currently exists. Please book a flight to show current
booking." << endl;
cout << endl;
}
}
int main() {
//created booking object
Booking flight;
//bool needed for while loop (which is needed for exit option)
bool running = true;
//int of valid choice in menu
int choice;
//user input string for menu
string input;
while (running){
cout << "Flight Booking Menu" << endl;
cout << "1. Book a flight" << endl;
cout << "2. Delete a booking" << endl;
cout << "3. Show current booking" << endl;
cout << "4. Exit" << endl;
cout << endl;
cout << "Enter your choice: " << endl;
getline(cin, input);
//Checks if the input is a number, as inputs that are strings or characters
would break the code for the menu.
bool validChoice = true;
//for loop checks each charatcer one by one using if statement
for (int i = 0; i < input.length(); i++) {
if (!isdigit(input[i])) {
validChoice = false;
break;
}
}
//if input is an number, sets the valis string input as an int
if (validChoice) {
choice = stoi(input);
//if not valid, lets user know and then user must try again until valid choice
is made
} else {
cout << "Choice not selected. Please enter a valid number." << endl;
cout << endl;
continue;
}
//checks int is valid (1-4)
//then choice calls approriate function
if (choice == 1){
bookFlight(flight);
}
else if (choice == 2){
deleteBooking(flight);
}
else if (choice == 3){
showBooking(flight);
}
//exits program, breaks while loop
else if (choice == 4){
cout << "Goodbye!" << endl;
break;
}
//if int is not in valid range, user must try again
else{
cout << "Option not in choices, please try again" << endl;
}
}
return 0;
}
