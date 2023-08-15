//Task-3 Tic-Tac-Toe game
#include <iostream>
using namespace std;

char gameBoard[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int row, col, choice;
char currentPlayer = 'X';
bool isDraw = false;

void displayBoard() {
    cout << "Player 1 [X]\tPlayer 2 [O]\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << gameBoard[0][0] << "  | " << gameBoard[0][1] << "  |  " << gameBoard[0][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << gameBoard[1][0] << "  | " << gameBoard[1][1] << "  |  " << gameBoard[1][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << gameBoard[2][0] << "  | " << gameBoard[2][1] << "  |  " << gameBoard[2][2] << " \n";
    cout << "\t\t     |     |     \n";
}

void playerMove() {
    if (currentPlayer == 'X')
        cout << "\nPlayer 1 [X] turn : ";
    else if (currentPlayer == 'O')
        cout << "\nPlayer 2 [O] turn : ";

    cin >> choice;

    switch (choice) {
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default: cout << "Invalid move. Try again.\n";
    }

    if (currentPlayer == 'X' && gameBoard[row][col] != 'X' && gameBoard[row][col] != 'O') {
        gameBoard[row][col] = 'X';
        currentPlayer = 'O';
    }
    else if (currentPlayer == 'O' && gameBoard[row][col] != 'X' && gameBoard[row][col] != 'O') {
        gameBoard[row][col] = 'O';
        currentPlayer = 'X';
    }
    else {
        cout << "This box is already filled!\nPlease choose another one.\n\n";
        playerMove();
    }
    displayBoard();
}

bool checkGameComplete() {
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2] || 
            gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
            return false;
    }

    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2] || 
        gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0])
        return false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] != 'X' && gameBoard[i][j] != 'O')
                return true;
        }
    }

    isDraw = true;
    return false;
}

int main() {
    cout << "\t\t\tTIC-TAC-TOE GAME\t\t\t";
    cout << "\n\t\t\tTHERE ARE 2 PLAYERS\n\t\t\t";

    while (checkGameComplete()) {
        displayBoard();
        playerMove();
        checkGameComplete();
    }

    if (currentPlayer == 'X' && isDraw == false) {
        cout << "\n\nCongratulations! Player 2 [O] won the game.\n";
    }
    else if (currentPlayer == 'O' && isDraw == false) {
        cout << "\n\nCongratulations! Player 1 [X] won the game.\n";
    }
    else {
        cout << "\n\nThe game is a draw!\n\n";
    }

    return 0;
}
