#include <iostream>
#include "Protein.h"

Protein::Protein(vector<AminoAcid> sequence) {

    aminoAcids = sequence;
}

//empty constructor
Protein::Protein(){
    
}

void Protein::addAminoAcid(const AminoAcid& aa) {

    aminoAcids.push_back(aa);
    
}


double Protein::netWeight() const {

    double netWeight = 0.0;
    
    for (int i = 0; i < aminoAcids.size(); ++i) {

        netWeight += aminoAcids[i].getWeight();
    }
    
    return netWeight;
}


double Protein::netCharge() const {

    double netCharge = 0.0;
    
    for (int i = 0; i < aminoAcids.size(); ++i) {

        netCharge += aminoAcids[i].getCharge();

    }
    
    return netCharge;
}


string Protein::aminoAcidSequence() const {

    string sequence;

    for (int i = 0; i < aminoAcids.size(); ++i) {

        sequence.push_back(aminoAcids[i].getOneLetterCode());
    }

    return sequence;
}

void Protein::removeLastAA() {

    if (!aminoAcids.empty()) {

        aminoAcids.pop_back();
        cout << "Last amino acid removed" << endl;

    } 
    
    else {

        cout << "Nothing in the protein" << endl;
    }
}


void Protein::removeSpecificAA(char aa) {

    for (int i = 0; i < aminoAcids.size(); ++i) {

        if (aminoAcids[i].getOneLetterCode() == aa) {

            aminoAcids.erase(aminoAcids.begin() + i);

            i--; 
        }
    }
}

bool Protein::operator<(Protein& p){

    return aminoAcids.size() < p.aminoAcids.size();

}

bool Protein::operator>(Protein& p){

    return aminoAcids.size() > p.aminoAcids.size();

}

bool Protein::operator==(Protein& p){

    return aminoAcids.size() == p.aminoAcids.size();
    
}