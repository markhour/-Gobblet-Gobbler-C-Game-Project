#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Class to represent the game board and handle game logic
class Board {
public:
    char getCurrentPlayer() {
        return currentPlayer;
    }
// Constructor to initialize the board and game state
    Board() {
// Initialize the board with empty spaces
        board = vector<vector<char>>(3, vector<char>(3, ' '));
// Initialize remaining pieces for each player
        yA = yB = yC = rA = rB = rC = 2;
// Set current player to yellow
        currentPlayer = 'y';
    }
// display the current state of the game board
    void displayBoard() {
// Display pieces on the board
// Large pieces are represented by 'A' and 'B'
// Medium pieces are represented by 'Y' and 'R'
// Small pieces are represented by 'y' and 'r'
        cout << endl << endl;
        for (int i = 0; i < 3; i++) {
            cout << "             ";
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'A')
                    cout << "YY";
                else if (board[i][j] == 'B')
                    cout << "RR";
                else if (board[i][j] == 'Y')
                    cout << "Y" << 3 * i + j + 1;
                else if (board[i][j] == 'R')
                    cout << "R" << 3 * i + j + 1;
                else if (board[i][j] == 'y')
                    cout << "y" << 3 * i + j + 1;
                else if (board[i][j] == 'r')
                    cout << "r" << 3 * i + j + 1;
                else
                    cout << " " << 3 * i + j + 1;

                if (j < 2)
                    cout << "|";
            }
            cout << endl;
            if (i < 2)
                cout << "             --------" << endl;
        }
        cout << endl;
    }
// display the remaining pieces for the current player
    void displayRemaining() {
        cout << "a. " << ((currentPlayer == 'y') ? "YY" : "RR") << "  " << ((currentPlayer == 'y') ? yA : rA) << " remain." << endl;
        cout << "b. " << ((currentPlayer == 'y') ? "Y" : "R") << "   " << ((currentPlayer == 'y') ? yB : rB) << " remain." << endl;
        cout << "c. " << ((currentPlayer == 'y') ? "y" : "r") << "   " << ((currentPlayer == 'y') ? yC : rC) << " remain." << endl;
        cout << "q to exit." << endl << endl;
    }
 // make a move on the board
    bool makeMove(char size, int location) {
    if (location < 1 || location > 9 || (size != 'a' && size != 'b' && size != 'c'))
        return false;
// Calculate the row and column indices on the board
    int row = (location - 1) / 3;
    int col = (location - 1) % 3;
// Get the piece at the specified location
    char piece = board[row][col];
// Calculate the index of the size ('a', 'b', 'c')
    int sizeIndex = size - 'a'; 
// Determine the color of the current player
    char color = (currentPlayer == 'y' ? 'y' : 'r');
// Reference to the remaining pieces of the current size for the current player
    int &remaining = (currentPlayer == 'y' ? (sizeIndex == 0 ? yA : sizeIndex == 1 ? yB : yC) 
                                           : (sizeIndex == 0 ? rA : sizeIndex == 1 ? rB : rC));
// Check if there are remaining pieces of the current size
    if (remaining <= 0) 
        return false;
// Determine the index of the current piece size ('A', 'B', 'Y', 'R', 'y', 'r')
    int pieceSizeIndex = (piece == 'A' || piece == 'B') ? 0 : 
                         (piece == 'Y' || piece == 'R') ? 1 : 
                         (piece == 'y' || piece == 'r') ? 2 : 3;
// Check if the current piece can cover the new piece size
    if (pieceSizeIndex <= sizeIndex) 
        return false;

// Assign the new piece based on the size and color of the current player
    char newPiece = (sizeIndex == 0 ? (currentPlayer == 'y' ? 'A' : 'B') :
                     sizeIndex == 1 ? (currentPlayer == 'y' ? 'Y' : 'R') :
                                      (currentPlayer == 'y' ? 'y' : 'r'));
// Update the board and remaining pieces
    board[row][col] = newPiece;
    remaining--;

    return true;
}


// determine the winner of the game
    char getWinner() {
// Check rows for a winning condition
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == 'A' || board[i][0] == 'Y' || board[i][0] == 'y') &&
            (board[i][1] == 'A' || board[i][1] == 'Y' || board[i][1] == 'y') &&
            (board[i][2] == 'A' || board[i][2] == 'Y' || board[i][2] == 'y'))
            return 'y';
        if ((board[i][0] == 'B' || board[i][0] == 'R' || board[i][0] == 'r') &&
            (board[i][1] == 'B' || board[i][1] == 'R' || board[i][1] == 'r') &&
            (board[i][2] == 'B' || board[i][2] == 'R' || board[i][2] == 'r'))
            return 'r';
    }
// Check columns for a winning condition
    for (int j = 0; j < 3; j++) {
        if ((board[0][j] == 'A' || board[0][j] == 'Y' || board[0][j] == 'y') &&
            (board[1][j] == 'A' || board[1][j] == 'Y' || board[1][j] == 'y') &&
            (board[2][j] == 'A' || board[2][j] == 'Y' || board[2][j] == 'y'))
            return 'y';
        if ((board[0][j] == 'B' || board[0][j] == 'R' || board[0][j] == 'r') &&
            (board[1][j] == 'B' || board[1][j] == 'R' || board[1][j] == 'r') &&
            (board[2][j] == 'B' || board[2][j] == 'R' || board[2][j] == 'r'))
            return 'r';
    }
// Check diagonals for a winning condition
    if ((board[0][0] == 'A' || board[0][0] == 'Y' || board[0][0] == 'y') &&
        (board[1][1] == 'A' || board[1][1] == 'Y' || board[1][1] == 'y') &&
        (board[2][2] == 'A' || board[2][2] == 'Y' || board[2][2] == 'y'))
        return 'y';
    if ((board[0][0] == 'B' || board[0][0] == 'R' || board[0][0] == 'r') &&
        (board[1][1] == 'B' || board[1][1] == 'R' || board[1][1] == 'r') &&
        (board[2][2] == 'B' || board[2][2] == 'R' || board[2][2] == 'r'))
        return 'r';
    if ((board[0][2] == 'A' || board[0][2] == 'Y' || board[0][2] == 'y') &&
        (board[1][1] == 'A' || board[1][1] == 'Y' || board[1][1] == 'y') &&
        (board[2][0] == 'A' || board[2][0] == 'Y' || board[2][0] == 'y'))
        return 'y';
    if ((board[0][2] == 'B' || board[0][2] == 'R' || board[0][2] == 'r') &&
        (board[1][1] == 'B' || board[1][1] == 'R' || board[1][1] == 'r') &&
        (board[2][0] == 'B' || board[2][0] == 'R' || board[2][0] == 'r'))
        return 'r';
// No winner
    return ' ';
}
// check if the game has ended in a tie
    bool isTie() {
        return yA == 0 && yB == 0 && yC == 0 && rA == 0 && rB == 0 && rC == 0;
    }
// switch the current player after each move
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'y') ? 'r' : 'y';
    }
// Data members to represent the game board, remaining pieces, and current player
private:
    vector<vector<char>> board;
    int yA, yB, yC, rA, rB, rC;
    char currentPlayer;
};

int main() {
// Create a board to play the game 
    Board game;
    string input;

    while (true) {
// Display the current state of the game
        game.displayBoard();
        game.displayRemaining();
// Player input loop
        while (true) {
            cout << "It is " << (game.getCurrentPlayer() == 'y' ? "yellow" : "red") << "'s turn." << endl;
            cout << "Choose action and location, for example a2: ";
            cin >> input;
// Check if the player wants to quit the game
            if (input == "q") {
                return 0; 
            }
// Validate the player's move and handle invalid moves
            if (input.length() != 2 || !game.makeMove(input[0], input[1] - '0')) {
                cout << "Invalid move. Try again.\n" << endl;
                continue; 
            }

            break;
        }
// Check for a winner
        char winner = game.getWinner();
        if (winner != ' ') {
            game.displayBoard();
            cout << ((winner == 'y') ? "Yellow" : "Red") << " wins!" << endl;
            break;
        }
// Check for a tie
        if (game.isTie()) {
            game.displayBoard();
            cout << "Tie game." << endl;
            break;
        }
// Switch players 
        game.switchPlayer();
    }
    return 0;
}
