#include "Protein.h"
#include "AminoAcid.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;



int main() {
   
    int choice;
    string sequence;
    vector<Protein> proteins;
    string line;


    ifstream inputFile("proteins.txt");

    

    while (getline(inputFile, line)) {
        
        Protein protein; 
        
            for (int i = 0; i < line.length(); ++i) { 
                char code = line[i];
                AminoAcid aa = AminoAcid::preDefAA(code); 
                protein.addAminoAcid(aa); 
            }
            
            proteins.push_back(protein); 
    }

inputFile.close();



    while (true) {
        
        
        cout << "Menu Options:" << endl;
        cout << "1. Show all Amino Acids" << endl;
        cout << "2. Create Protein (Up to 3 stored)" << endl;
        cout << "3. Show Protein(s)" << endl;
        cout << "4. Delete Last Amino Acids" << endl;
        cout << "5. Completely Delete Specific Amino Acid" << endl;
        cout << "6. Get Total Charge and Weight of a Protein" << endl;
        cout << "7. Delete a Protein by Index" << endl;
        cout << "8. Add Amino Acids to Existing Protein" << endl;
        cout << "9. Exit Program" << endl;

        cout << "Enter your choice: ";
        cin >> choice;




            if (choice == 1) {
                cout << "Showing all amino acids: " << endl;
            cout << "_______________________________________" << endl;
        
            string amino_acids[20] = {"Alanine", "Arginine", "Asparagine", "Aspartic Acid", "Cysteine",
                                "Glutamic Acid", "Glutamine", "Glycine", "Histidine", "Isoleucine",
                                "Leucine", "Lysine", "Methionine", "Phenylalanine", "Proline", 
                                "Serine", "Threonine", "Tryptophan", "Tyrosine", "Valine"};
        
            char one_letter_code[20] = {'A', 'R', 'N', 'D', 'C', 'E', 'Q', 'G', 'H', 'I', 'L', 'K', 'M', 'F', 'P', 'S', 'T', 'W', 'Y', 'V'};
        
            double grams_per_mol[20] = {89.1, 174.2, 132.1, 133.1, 121.2, 147.1, 146.2, 75.1, 155.2, 131.2, 131.2, 146.2, 149.2, 165.2, 115.1, 105.1, 119.1, 204.2, 181.2, 117.1};
        
            string charges[20] = {"0", "+", "0", "-", "0", "-", "0", "0", "0/+", "0", "0", "+", "0", "0", "0", "0", "0", "0", "0", "0"};
        
            for(int i = 0; i < 20; i++) {

                cout << i+1 << ". " << amino_acids[i] << endl;
                cout << "One letter code: " << one_letter_code[i] << endl;
                cout << "Grams/mol: " << grams_per_mol[i] << endl;
                cout << "Charge: " << charges[i] << endl << endl;
            }
            
            cout << "_______________________________________" << endl;
            
            
            } 



           else if (choice == 2) {


            if (proteins.size() >= 3) {
                cout << "Cannot store more than 3 proteins." << endl;
            } 
            
            else {
                
                string sequence;
                cout << "Enter the amino acid sequence (one letter codes, no spaces): ";
                cin >> sequence;

                Protein newProtein;

                for (int i = 0; i < sequence.length(); ++i) {
                    char code = sequence[i];
                    AminoAcid aa = AminoAcid::preDefAA(code); 
                    
                    newProtein.addAminoAcid(aa);
                    


                }
                proteins.push_back(newProtein);
                cout << "Protein created successfully." << endl;
            }
        } 


        else if (choice == 3) {

            if (proteins.empty()) {

                cout << "No proteins stored." << endl;
            } 
            
            else {
                
                for (int i = 0; i < proteins.size(); ++i) {
                    cout << "Protein " << i+1 << ": " << proteins[i].aminoAcidSequence() << endl;
                }

            }
        } 


            else if (choice == 4) {

                int proteinIndex, numToDel;

                cout << "Enter which protein you wish to modify: ";
                cin >> proteinIndex;

                cout << "Enter the number of amino acids to delete from the end of the protein: ";
                cin >> numToDel;

                proteinIndex--;

                if (proteinIndex >= 0 && proteinIndex < proteins.size()) {


                    
                    for (int i = 0; i < numToDel; ++i) {
                        
                        proteins[proteinIndex].removeLastAA();
                    }

                    cout << "AA removed.\n";
                } else {
                    cout << "Protein does not exist. Please try again.\n";
                }
            }





            else if (choice == 5) {

                int proteinIndex;
                char aaCode;

                cout << "Enter which protein you wish to modify: ";
                cin >> proteinIndex;
                cout << "Enter the letter code of the amino acids to remove: ";
                cin >> aaCode;


                proteinIndex--;
    
                if (proteinIndex >= 0 && proteinIndex < proteins.size()) {
                    proteins[proteinIndex].removeSpecificAA(aaCode);
                    cout << "Amino acids removed.\n";
                } else {
                    cout << "Protein does not exist. Please try again.\n";
                }
            }
            else if (choice == 9) {
                cout << "Exiting program." << endl;


                ofstream outputFile("proteins.txt");

                for (int i = 0; i < proteins.size(); ++i) {

                    string sequence = proteins[i].aminoAcidSequence();

                    for (int j = 0; j < sequence.length(); ++j) {

                        outputFile << sequence[j];
                    }

                    outputFile << endl;
                }
                outputFile.close();

                break;
            } 
            else if (choice == 7) {
                int proteinIndex;

                cout << "Enter the index of the protein to delete: ";
                cin >> proteinIndex;

                proteinIndex--; 

                if (proteinIndex >= 0 && proteinIndex < proteins.size()) {
                    proteins.erase(proteins.begin() + proteinIndex);
                    cout << "Protein at index " << proteinIndex + 1 << " has been deleted" << endl;
                } else {
                    cout << "No protein exists" << endl;
                }
            }
            else if (choice == 6) {
                int proteinIndex;
                
                cout << "Enter the index of the protein to analyze: ";
                cin >> proteinIndex;
                
                proteinIndex--; 
                
                if (proteinIndex >= 0 && proteinIndex < proteins.size()) {
                    double totalCharge = proteins[proteinIndex].netCharge();
                    double totalWeight = proteins[proteinIndex].netWeight();
                    
                    cout << "Total charge of the protein at index " << proteinIndex + 1 << ": " << totalCharge << endl;
                    cout << "Total weight of the protein at index " << proteinIndex + 1 << ": " << totalWeight << " g/mol" << endl;
                } else {
                    cout << "Invalid index. Unable to calculate charge and weight" << endl;
                }
            }
            else if (choice == 8) {
                int proteinIndex;
                
                cout << "Enter the index of the protein to modify: ";
                cin >> proteinIndex;
                
                proteinIndex--; 
                
                if (proteinIndex >= 0 && proteinIndex < proteins.size()) {


                    string additionalSequence;
                    cout << "Enter the amino acid sequence to add (one letter w/o spaces): ";
                    cin >> additionalSequence;

                    for (int i = 0; i < additionalSequence.length(); ++i) {


                        char code = additionalSequence[i];

                        AminoAcid aa = AminoAcid::preDefAA(code);

                        proteins[proteinIndex].addAminoAcid(aa);

                    }

                    cout << "Amino acid edited" << endl;
                } else {
                    cout << "Protein does not exist, try again" << endl;
                }
             }   
            

            else {
                cout << "Choice does not exist, try again" << endl;
            }

            
        }

    return 0;

}

