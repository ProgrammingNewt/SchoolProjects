#ifndef PROTEIN_H
#define PROTEIN_H
#include "AminoAcid.h"
#include <vector>
using namespace std;

class Protein {
private:

    vector<AminoAcid> aminoAcids;
    

public:

    Protein(vector<AminoAcid> aminoAcids);
    
    Protein();
    
    void addAminoAcid(const AminoAcid& aa);

    double netWeight() const;

    double netCharge() const;

    string aminoAcidSequence() const;

    void removeLastAA(); 

    void removeSpecificAA(char aa);

    bool operator<(Protein& p);

    bool operator>(Protein& p);

    bool operator==(Protein& p);

};

#endif