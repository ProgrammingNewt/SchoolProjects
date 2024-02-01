

Page
1
of 5
//Names: Ariel Espinoza, BingFong (Curtis)
//Description: This is an expanded version of the lab 2 bookings project. Here the
user is allowed up to 10 bookings due to the use of arrays
/*Code analysis: This project was made a little differently than intended as per
the instrcutions. Instead of using four differen
arrays in order to keep track of the names, the origin airport, the destination,
and the date, the Booking object was used instead.
An array of the object was used in order to keep track of all of these values as it
was simpler to transition this way from lab 2 given
our code. The program allows for a max of 10 bookings as per the const int
Bookings. A user cannot make bookings past their 10th iteration
The delete bookings options deletes a booking based off of the name of the booking
provided by the user. The program iterates through the
names stored in the bookings objects and attempts to find a match. If found, it
will delete that booking and move all bookings that were at
indexes past that, down one spot in order to not have any "holes" in the array. The
show bookings option will return a printed text of all of the
current bookings the user has active ordered by when they were created. The program
takes into account the specified "bad inputs".
*/
//Date Finished: 9/12/2023
#include <iostream>
#include <string>
using namespace std;
//Total bookings allowed
const int BOOKINGS = 10;
class Booking{
public:
string name;
string originAirport;
string destAirport;
string date;
};
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
void showBooking(Booking &flight){
if((!flight.name.empty()) && (!flight.originAirport.empty()) && (!
flight.destAirport.empty()) && (!flight.date.empty()) ){
//cout << "Here is your current booking information!" << endl;
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
//Makes an array of bookings with 10 elements
Booking flight[BOOKINGS];
//Makes an index of bookings to keep track of how many bookings are actually
filled
int bookingIndex = 0;
bool running = true;
int choice;
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
bool validChoice = true;
//Makes sure input is a number that is valid
for (int i = 0; i < input.length(); i++) {
if (!isdigit(input[i])) {
validChoice = false;
break;
}
}
if (validChoice) {
choice = stoi(input);
} else {
cout << "Choice not selected. Please enter a valid number." << endl;
cout << endl;
continue;
}
if (choice == 1){
//Checks that there enough space to make a new bookings, since only 10
are allowed
if(bookingIndex < BOOKINGS){
bookFlight(flight[bookingIndex]); //Created new booking object in
array
bookingIndex++;
}
//Gives this is we are at 10 bookings
else {
cout << "Booking limit reached! You must delete at least one
booking to create a new one!" << endl;
}
}
else if (choice == 2){
//Makes sure that array is not empty, since we need a at least one
booking to delete.
if (bookingIndex > 0){
//input for user to define which booking they would like to delete
string nameToDelete;
bool nameExist = false;
int bookingDeleteIndex;
cout << "Please enter the name of the booking you would like to
delete" << endl;
getline(cin, nameToDelete);
//Goes through active bookings looking to see if name that user
gave matches a name in Bookings
for(int i = 0; i < bookingIndex; i++){
//Checking if names match
if(flight[i].name == nameToDelete){
nameExist = true;
//Keeps track of which index the booking to delete was
found
bookingDeleteIndex = i;
//Deletes specified booking
deleteBooking(flight[bookingDeleteIndex]);
//Move up all bookings past the booking that was deleted
for(int i = bookingDeleteIndex; i < bookingIndex-1; i++){
flight[i] = flight[i+1];
//Changes position of last one since loop is for
bookingIndex - 1. This is done to not break the program as if i was = to 9 and we
did flight[10], it would cause problems
if(bookingIndex == BOOKINGS){
flight[8] = flight[BOOKINGS-1];
}
}
//subtract one from booking index.
bookingIndex--;
}
}
//Checks if name given was actually valid, if it was then the
booking was deleted and everything else was moved up and gives user the
confirmation
if(nameExist){
cout << "Booking has been successfully deleted!" << endl;
}
//Tells user name was not found.
else
{
cout << "Name does not match booking to delete. Please try
again." << endl;
cout << endl;
}
}
else{
cout << "No booking curretly exist to deltete. Please book a flight
before deleting." << endl;
}
}
//Prints a list of the bookings in order by which they were booked
else if (choice == 3){
//Checks if there are bookings in array
if(bookingIndex > 0){
cout << "List of current bookings!" << endl;
for(int i = 0; i < bookingIndex; i++){
cout << "Booking #" << i+1 << ": " << endl;
showBooking(flight[i]);
}
}
//if no bookings
else {
cout << "No booking currently exists. Please book a flight to show
current booking." << endl;
cout << endl;
}
}
else if (choice == 4){
cout << "Goodbye!" << endl;
break;
}
else{
cout << "Option not in choices, please try again" << endl;
}
}
return 0;
}
