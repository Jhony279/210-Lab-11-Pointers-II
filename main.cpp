// COMSC-210 | Lab 11 | Johnathan Perez Baltazar

#include <iostream>
#include <ios>
#include <iomanip>
using namespace std;

const int TEAM_AMOUNT = 2;

struct TeamPerformace {
    int pointsScored;
    double cycleTime;
    int matchNumber;
};

/**
 * @brief A struct that holds information on the team the user is scouting
*/
struct FRCTeam {
    int teamNumber;
    string teamName;
    int matchesPlayed;
    TeamPerformace *performace;
    
    ~FRCTeam() {
        if (performace) 
            delete [] performace;
        performace = nullptr;
    }
};

void enterTeamData(FRCTeam*);
void displayTeamInfo(FRCTeam*);

/**
 * @brief - Description of main
*/
int main() {
    FRCTeam *teamList = new FRCTeam[TEAM_AMOUNT];

    for (int i = 0; i < TEAM_AMOUNT; i++){
        enterTeamData(&teamList[i]);
    }

    for (int i = 0; i < TEAM_AMOUNT; i++){
        displayTeamInfo(&teamList[i]);
    }
    return 0;
}

void enterTeamData(FRCTeam *tptr){
    static int tmNbr = 1;
    cout << "Enter the data for team " << tmNbr << " on the list" << endl;
    cout << "Team Name: ";
    getline(cin, tptr->teamName);
    cout << "Team Number: "; cin >> tptr->teamNumber;
    cout << "Matches Played: "; cin >> tptr->matchesPlayed;
    tptr -> performace = new TeamPerformace[tptr->matchesPlayed];

    for (int i = 0; i < tptr->matchesPlayed; i++){
        tptr->performace[i].matchNumber = i;
        cout << "\nPoints scored for match " << i + 1<< ": ";
        cin >> tptr->performace[i].pointsScored;
        cout << "Team's Cycle Time: ";
        cin >> tptr->performace[i].cycleTime;
    }
    cin.ignore();
    cout << endl << endl;
    tmNbr++;
}

void displayTeamInfo(FRCTeam *tptr){
    cout << "--- Team " << tptr->teamNumber << " summary ---";
    cout << "\nName: " << tptr->teamName;
    cout << "\nTeam# : " << tptr->teamNumber;
    cout << "\nMatches played: " << tptr->matchesPlayed << endl;

    static int prtSpacing = 4;
    for (int i = 0; i < tptr->matchesPlayed; i++){
        cout << " -Performance for match " << i + 1 << ": " << endl;
        cout << "   Points scored: " 
            << tptr->performace[i].pointsScored << endl;
        cout << "   Cycle Time: "
            << tptr->performace[i].cycleTime << endl;
    }
    cout << endl << endl;
}