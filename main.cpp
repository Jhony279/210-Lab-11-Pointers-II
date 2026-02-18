// COMSC-210 | Lab 11 | Johnathan Perez Baltazar

#include <iostream>
using namespace std;

const int TEAM_AMOUNT = 4;

struct TeamPerformace {
    double pointsScored;
    double cycleTime;
    int matchNumber;
};

struct FRCTeam {
    int teamNumber;
    string teamName;
    int matchesPlayed;
    TeamPerformace *performace;
};

void enterTeamData(FRCTeam*);

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    FRCTeam *teamList = new FRCTeam[TEAM_AMOUNT];

    for (int i = 0; i < TEAM_AMOUNT; i++){
        enterTeamData(&teamList[i]);
    }
    return 0;
}

void enterTeamData (FRCTeam * tptr){
    static int tmNbr = 1;
    cout << "Enter the data for team " << tmNbr << "on the list" << endl;
    cout << "Team Name: " << tptr->teamName << endl;
    cout << "Team Number: " << tptr->teamNumber << endl;
    cout << "Matches Played: " << tptr->matchesPlayed << endl;
    tptr -> performace = new TeamPerformace[tptr->matchesPlayed];
    for (int i = 0; i < tptr->matchesPlayed; i++){
        cout << "Match Number: " << tptr->performace->matchNumber << endl;
        cout << "Points scored: " << tptr->performace->pointsScored << endl;
        cout << "Team's Cycle Time" << tptr->performace->cycleTime << endl;
    }
    cin.ignore();
    cout << endl << endl;
    tmNbr++;
}