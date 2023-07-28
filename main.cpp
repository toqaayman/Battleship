#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int BOARD_SIZE = 25;
// Game board represented as a 2D array
char gameBoard[BOARD_SIZE][BOARD_SIZE];
// Function to initialize the game board from a file
void initBoardFromFile(string filename) {
    ifstream infile(filename);
    string line;
    int row = 0;
    while (getline(infile, line)) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            gameBoard[row][col] = line[col];
        }
        row++;
    }
}
// Function to save the game board to a file
void saveBoardToFile() {
    ofstream outfile("game_board.txt");
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            outfile << gameBoard[row][col];
        }
        outfile << endl;
    }
}
// Function to print the game board
void printBoard() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (gameBoard[row][col] == '#') {
                cout << "~";
            } else {
                cout << gameBoard[row][col];
            }
        }
        cout << endl;
    }
}
// Function to fire a torpedo at a given coordinate (x, y)
void fire(int x, int y) {
    if (gameBoard[y][x] == '#') {
        if (gameBoard[y][x] == 'H') {
            cout << "HIT AGAIN" << endl;
        } else {
            cout << "HIT" << endl;
            gameBoard[y][x] = 'H';
            saveBoardToFile(); // Update the game board file
        }
    } else {
        cout << "MISS" << endl;
    }
}
// Function to check if all the ships have been sunk
bool fleetSunk() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (gameBoard[row][col] == '#') {
                return false;
            }
        }
    }
    return true;
}
int main() {
    // Initialize the game board from a file
    initBoardFromFile("game.dat");
    // Play the game
    while (!fleetSunk()) {
        int x, y;
        cout << "Enter x coordinate: ";
        cin >> x;
        cout << "Enter y coordinate: ";
        cin >> y;
        fire(x, y);
        printBoard(); // Print the game board after getting input
    }
    // Game over
    cout << "The fleet was destroyed!" << endl;
    printBoard();
    return 0;
}

