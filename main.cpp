// COMSC-210 | Lab 11 | Johnathan Perez Baltazar

#include <iostream>
using namespace std;

const int TEAM_AMOUNT = 4;

struct TeamPerformace {
    double pointsScored;
    double cycleTime;
};

struct FRCTeam {
    int teamNumber;
    string teamName;
    int matchesPlayed;
    double *performace;
};

void enterTeamData(FRCTeam*);

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    FRCTeam *teamList = new FRCTeam[TEAM_AMOUNT];
    return 0;
}

void enterTeamData (FRCTeam * tptr){
    static int tmNbr = 1;
    cout << "Team Name: ";

}