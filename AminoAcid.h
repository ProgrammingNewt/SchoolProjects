#ifndef AMINOACID_H
#define AMINOACID_H
#include <string>
#include <stdexcept>
using namespace std;

class AminoAcid {
private:

    string name;
    char oneLetterCode;
    double weight;
    double charge;

public:
    
    AminoAcid(string name = "", char oneLetterCode = ' ', double weight = 0.0, double charge = 0.0);
    
    AminoAcid();

    static AminoAcid preDefAA(char oneLetterCode);

    string getName() const; 

    char getOneLetterCode() const; 

    double getWeight() const; 
    
    double getCharge() const; 

    
};

#endif 





