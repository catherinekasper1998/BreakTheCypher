/*
** AUTHOR: Catherine Kasper (github: catherinekasper1998)
** DATE: TUESDAY, MARCH 12TH, 2024
** PURPOSE: TO SOLVE THE NEW YORK TIMES CRYPTOGRAMS IN THE ARTS SECTION. THIS IS MEANT TO WORK PURELY AS AN EXERCISE AND IS NOT AFFILIATED NEW YORK TIMES RESOURCE.
** FILENAME: CypherBreaker
** VERSION: 0.0
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isWanted(const std::string & line);

int main()
{
    ifstream fin("TuesdayMarch12th2024.txt");
    
    string line;
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    
    return 0;
}
/*
bool isWanted(const std::string & line)
{
    // any selection criteria you like
    return (line.find("IQ") != string::npos);
}*/