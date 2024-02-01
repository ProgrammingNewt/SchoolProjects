#include "AminoAcid.h"

AminoAcid::AminoAcid(string nameVal, char oneLetterCodeVal, double weightVal, double chargeVal) {

    name = nameVal;
    oneLetterCode = oneLetterCodeVal;
    weight = weightVal;
    charge = chargeVal;

}

AminoAcid::AminoAcid(){
//empty

}

string AminoAcid::getName() const {


    return name;
}


char AminoAcid::getOneLetterCode() const {

    return oneLetterCode;

}



double AminoAcid::getWeight() const {


    return weight;

}

double AminoAcid::getCharge() const {

    return charge;
}

AminoAcid AminoAcid::preDefAA(char oneLetterCode) {


    switch(oneLetterCode) {
        case 'A': 
            return AminoAcid("Alanine", 'A', 89.1, 0);

        case 'R': 
            return AminoAcid("Arginine", 'R', 174.2, 1);

        case 'N':
            return AminoAcid("Asparagine", 'N', 132.1, 0);

        case 'D': 
            return AminoAcid("Aspartic Acid", 'D', 133.1, -1);

        case 'C': 
            return AminoAcid("Cysteine", 'C', 121.2, 0);

        case 'E':  
            return AminoAcid("Glutamic Acid", 'E', 147.1, -1);

        case 'Q': 
            return AminoAcid("Glutamine", 'Q', 146.2, 0);

        case 'G': 
            return AminoAcid("Glycine", 'G', 75.1, 0);

        case 'H': 
            return AminoAcid("Histidine", 'H', 155.2, 0.1);

        case 'I': 
            return AminoAcid("Isoleucine", 'I', 131.2, 0);

        case 'L': 
            return AminoAcid("Leucine", 'L', 131.2, 0);

        case 'K': 
            return AminoAcid("Lysine", 'K', 146.2, 1);

        case 'M': 
            return AminoAcid("Methionine", 'M', 149.2, 0);

        case 'F': 
            return AminoAcid("Phenylalanine", 'F', 165.2, 0);

        case 'P': 
            return AminoAcid("Proline", 'P', 115.1, 0);

        case 'S': 
            return AminoAcid("Serine", 'S', 105.1, 0);

        case 'T': 
            return AminoAcid("Threonine", 'T', 119.1, 0);

        case 'W': 
            return AminoAcid("Tryptophan", 'W', 204.2, 0);

        case 'Y': 
            return AminoAcid("Tyrosine", 'Y', 181.2, 0);

        case 'V': 
            return AminoAcid("Valine", 'V', 117.1, 0);

        default: throw invalid_argument("Code does not exist for Aa.");
    }
}