// COMSC-210 | Lab 11 | Johnathan Perez Baltazar

#include <iostream>
using namespace std;

const int TEAM_AMOUNT = 4, TEAM_MEMBERS = 6;

struct Team {
    int teamNumber;
    string teamName;
    string *memberNames;
};

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    Team *teamList = new Team[TEAM_AMOUNT];
    return 0;
}

// Function Definitions:

// Reminder lines must be 80 characters or less, no more than one empty line, no magic numbers,
// and Reminder to comment code where neccessary.