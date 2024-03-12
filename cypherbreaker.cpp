/*
** AUTHOR: Catherine Kasper (github: catherinekasper1998)
** DATE: TUESDAY, MARCH 12TH, 2024
** PURPOSE: TO SOLVE THE NEW YORK TIMES CRYPTOGRAMS IN THE ARTS SECTION. THIS IS MEANT TO WORK PURELY AS AN EXERCISE AND IS NOT AFFILIATED NEW YORK TIMES RESOURCE.
** FILENAME: CypherBreaker
** VERSION: 0.0
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

bool isWanted(const std::string & line);
string alphabetForwards = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string flipWord(string textOnly) {
    string newString = "";
    for(int i = textOnly.length()-1; i >=0; i++){
        newString = newString + textOnly[i];
    }
    return newString;
};

string alphabetBackwards = flipWord(alphabetForwards);

class letter{
    public:
        bool isPunctuation;
        int cypherPlacement;
        string cypherLetter;
        int resultPlacement;
        string resultLetter;
        letter *nextLetter;
};

class word{
    public:
        int workPlacement;
        letter firstLetter;
        bool hasPunctuation;
        int placementOfPunctuation;
        int lengthOfWord; 
};

char reverseChar(char oldChar) {
    int index = alphabetForwards.find(oldChar);
    return alphabetBackwards[index];
};

string reverseLinearShift(string text, int shiftValue)
{
    string newText = "";
    char newChar = 'A';
    char oldChar = 'A';
    for(int i = 0; i < text.length(); i++) {
        oldChar = text[i];
        if( '@' < oldChar && oldChar <  'a') {
            newChar = text[i] + shiftValue; // Values now rand
            if(newChar>='[') {
                newChar = newChar-26;
            }
            newChar = reverseChar(newChar);
            newText = newText + newChar;
        } else {
            newText = newText + oldChar;
        }
    }
    return newText;
};

string linearShift(string text, int shiftValue)
{
    string newText = "";
    char newChar = 'A';
    char oldChar = 'A';
    for(int i = 0; i < text.length(); i++) {
        oldChar = text[i];
        newChar = text[i] + shiftValue;
        if( '@' < oldChar && oldChar <  'a') {
            if(newChar>='[') {
                newChar = newChar-26;
            }
            newText = newText + newChar;
        } else {
            newText = newText + oldChar;
        }
    }
    return newText;
};


bool runAllLinearOptions(string line){
    cout << "------------------------ ORIGINAL CYPHER ------------------------" << endl;
    cout << line << endl << endl;

    cout << "--------------------- LINEAR SHIFT ATTEMPT ----------------------" << endl;
    for (int i = 0; i < 26; i++) {
        cout << "SOLUTION ATTEMPT Value of " << i << ":  ";
        cout << linearShift(line, i) << endl;
    }

    cout << endl << "------------ REVERSE ALPHABET LINEAR SHIFT ATTEMPT --------------" << endl;
    int i = 0;
    cout << "SOLUTION ATTEMPT Value of " << i << ":  ";
    cout << reverseLinearShift(line, i) << endl;

    return true;
}




int main()
{
    ifstream fin("TuesdayMarch12th2024.txt");
    
    string line;
    while (getline(fin, line))
    {
        //runAllOptions(line);
    }
    
    return 0;
}
/*
bool isWanted(const std::string & line)
{
    // any selection criteria you like
    return (line.find("IQ") != string::npos);
}*/