#include <iostream>
using namespace std;

enum Object { ROCK, PAPER, SCISSORS };

void displayRules() {
    cout << "Welcome to the game of Rock, Paper, and Scissors." << endl;
    cout << "Enter R or r to select Rock, P or p to select Paper, and S or s to select Scissors." << endl << endl;
}

bool validSelection(char choice) {
    return (choice == 'r' || choice == 'p' || choice == 's');
}

Object retrievePlay(char choice) {
    switch (choice) {
        case 'r':
            return ROCK;
        case 'p':
            return PAPER;
        case 's':
            return SCISSORS;
        default:
            // Handle invalid input
            cerr << "Invalid input. Please enter 'r', 'p', or 's'." << endl;
            exit(EXIT_FAILURE);
    }
}


void gameResult(Object player1, Object player2, int& totalGames, int& player1Wins, int& player2Wins) {
    Object winner = player1 == player2 ? static_cast<Object>(-1) :
                   (player1 == ROCK && player2 == SCISSORS) ||
                   (player1 == PAPER && player2 == ROCK) ||
                   (player1 == SCISSORS && player2 == PAPER) ? player1 : player2;
    
    if (winner == player1) {
        player1Wins++;
    } else if (winner == player2) {
        player2Wins++;
    }
    
    totalGames++;
}

void displayResults(int totalGames, int player1Wins, int player2Wins) {
    cout << "Number of games played: " << totalGames << endl;
    cout << "Player 1 wins: " << player1Wins << endl;
    cout << "Player 2 wins: " << player2Wins << endl;
}

int main() {
    int totalGames = 0, player1Wins = 0, player2Wins = 0;
    char playAgain;

    displayRules();

    cout << "Do you want to play the game? (Y/N): ";
    cin >> playAgain;

    while (toupper(playAgain) == 'Y') {
        cout << "Player 1, make your selection: ";
        char choice1;
        cin >> choice1;

        cout << "Player 2, make your selection: ";
        char choice2;
        cin >> choice2;

        if (validSelection(tolower(choice1)) && validSelection(tolower(choice2))) {
            Object player1 = retrievePlay(tolower(choice1));
            Object player2 = retrievePlay(tolower(choice2));

            gameResult(player1, player2, totalGames, player1Wins, player2Wins);
        } else {
            cout << "Invalid input. Please try again." << endl;
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    }

    displayResults(totalGames, player1Wins, player2Wins);

    return 0;
}
