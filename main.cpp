// COMSC-210 | Lab 11 | Johnathan Perez Baltazar

/** <Description of code>: This program creates a struct to hold data on a FRC team, then creates a list 
 *  of teams and allows the user to enter the data for each team and display it It,
 *  meant to simulate the process of scouting teams in FRC, where you would want
 *  to keep track of how each team performed in each match they played, and then be
 *  able to see the data when needed
*/

#include <iostream>
#include <ios>
#include <iomanip>
using namespace std;

const int TEAM_AMOUNT = 2;

/**
 * @brief A struct that holds data on how the team performed in each 
 *        match they played
*/
struct TeamPerformace {
    int pointsScored;   // Amount of Points scored by the team
    double cycleTime;   // Average amount of time in between each scored point
    int matchNumber;    // The match in which they got this performance
};

/**
 * @brief A struct that holds information on the team the user is scouting
*/
struct FRCTeam {
    int teamNumber;     // The team's #
    string teamName;    // Team's name
    int matchesPlayed;  // Number of matches played
    TeamPerformace *performace; // List of team's performace per match
    
    ~FRCTeam() {
        if (performace) 
            delete [] performace;
        performace = nullptr;
    }
};

void enterTeamData(FRCTeam*);
void displayTeamInfo(FRCTeam*);

/**
 * @brief Main function that creates a list of teams, then calls the functions to
 *        enter the data for each team and display it
*/
int main() {
    // Create a dynamic list of teams
    FRCTeam *teamList = new FRCTeam[TEAM_AMOUNT];

    // Enter the data for each team in the list
    for (int i = 0; i < TEAM_AMOUNT; i++){
        enterTeamData(&teamList[i]);
    }

    // Display the data for each team in the list
    for (int i = 0; i < TEAM_AMOUNT; i++){
        displayTeamInfo(&teamList[i]);
    }
    return 0;
}

/**
 * @brief Enters data in for a specific team
 * @param tptr A pointer to the team struct that will have its data entered
*/
void enterTeamData(FRCTeam *tptr){
    // Static variable to keep track of the team number being entered
    static int tmNbr = 1;

    // Enter the data for the team
    cout << "Enter the data for team " << tmNbr << " on the list" << endl;
    cout << "Team Name: ";
    getline(cin, tptr->teamName);
    cout << "Team Number: "; cin >> tptr->teamNumber;
    cout << "Matches Played: "; cin >> tptr->matchesPlayed;
    tptr -> performace = new TeamPerformace[tptr->matchesPlayed];

    // Enter the data for each match the team played
    for (int i = 0; i < tptr->matchesPlayed; i++){
        tptr->performace[i].matchNumber = i;
        cout << "\nPoints scored for match " << i + 1<< ": ";
        cin >> tptr->performace[i].pointsScored;
        cout << "Team's Cycle Time: ";
        cin >> tptr->performace[i].cycleTime;
    }
    cin.ignore();   // Clear the input buffer for the next team
    cout << endl << endl;
    tmNbr++;    // Increment the team number for the next team to be entered
}

/**
 * @brief Displays the data for a specific team
 * @param tptr A pointer to the team struct that will have its data displayed
*/
void displayTeamInfo(FRCTeam *tptr){
    // Display the data for the team
    cout << "--- Team " << tptr->teamNumber << " summary ---";
    cout << "\nName: " << tptr->teamName;
    cout << "\nTeam# : " << tptr->teamNumber;
    cout << "\nMatches played: " << tptr->matchesPlayed << endl;

    // Display the data for each match the team played
    for (int i = 0; i < tptr->matchesPlayed; i++){
        cout << " -Performance for match " << i + 1 << ": " << endl;
        cout << "   Points scored: " 
            << tptr->performace[i].pointsScored << endl;
        cout << "   Cycle Time: "
            << tptr->performace[i].cycleTime << endl;
    }
    cout << endl << endl;
}