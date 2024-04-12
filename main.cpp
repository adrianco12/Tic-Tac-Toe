// Adrian Cortez
// This program creates a game of tic tac toe by utilizing decision structures, loops, arrays, functions, and more

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// prints the tic tac toe grid
void printGrid (char grid[4][4]) {
    // print grid
    for (int row = 1; row < 4; ++row) {
        cout << "+---+---+---+ \n";
        for (int col = 1; col < 4; ++col){
            cout << "| " << grid[row][col] << " ";
        }
        cout << "|\n";
    }
    cout << "+---+---+---+\n\n";
}

// validates data input from user
void dataValidation (int col, int row)
{
    // data validation
    while (col < 1 || col > 3 || row < 1 || row > 3) { // data validation
        cout << "Error. That is not a valid row/column. Pick a row (1, 2, 3): ";
        cin >> row;
        
        cout << "Pick a column (1, 2, 3): ";
        cin >> col;
        cout << endl;
    }
}

// checks if the spot the user takes is already taken
bool occupiedCheck (char grid[4][4], int col, int row)
{
    bool isOccupied;
    // determine if chosen pick is occupied
    if (grid[row][col] == 'X' || grid[row][col] == 'O'){
        isOccupied = true;
    }
    else {
        isOccupied = false;
    }
    return isOccupied;
}

// determines if there is a winner, or if it is a tie
bool checkWin (char grid[4][4], char players[9], int index)
{
    bool gameEnd = false;
    
    // determine if there is a winner
    for (int i = 0; i < 2; i++) {
        // check rows and columns
        for (int x = 1; x < 4; x++) {
            if ((grid[x][1] == players[i] && grid[x][2] == players[i] && grid[x][3] == players[i]) || (grid[1][x] == players[i] && grid[2][x] == players[i] && grid[3][x] == players[i])) {
                cout << "Player " << players[i] << " has won the game! Congratulations! Game over." << endl;
                gameEnd = true;
            }
        }
        // check diagonals
        if ((grid[1][1] == players[i] && grid[2][2] == players[i] && grid[3][3] == players[i]) || (grid[3][1] == players[i] && grid[2][2] == players[i] && grid[1][3] == players[i])) {
               cout << "Player " << players[i] << " has won the game! Congratulations! Game over." << endl;
            gameEnd = true;
        }
    }
    // determine if it is a tie
    if (index == 9 && gameEnd != true) {
        cout << "The game is a tie. No one wins. Game over :(" << endl;
        gameEnd = true;
    }
    
    return gameEnd;
}

// main method
int main ()
{
    // declare variables
    char grid[4][4] = {{' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}}; // 2d array
    bool gameOver = false; // used to end game
    int col = 0;
    int row = 0;
    char players[9] = {'X','O','X','O','X','O','X','O','X'}; // used to switch between players
    int index = 0; // used with players array to switch between players
    
    
    cout << "Welcome to Tic Tac Toe" << endl;
    
    printGrid(grid);
    
    // begin loop
    while (gameOver != true) {
        
        // prompt user to input row and column
        cout << players[index] << "'s turn" << endl << "Pick a row (1, 2, 3): ";
        cin >> row;
        cout << "Pick a column (1, 2, 3): ";
        cin >> col;
        
        // data validation
        dataValidation(col, row);
        
        // determine if chosen pick is occupied
        bool isOccupied = occupiedCheck(grid, col, row);
        
      // show error message if spot is occupied
        while (isOccupied != false){
            cout << endl << "ERROR: That spot is occupied. " << players[index] << "'s turn again." << endl << " Pick a row (1, 2, 3): ";
            cin >> row;
            
            cout << "Pick a column (1, 2, 3): ";
            cin >> col;
            
            // data validation
            dataValidation(col, row);
            // check if it is occupied (again)
            isOccupied = occupiedCheck(grid, col, row);
        }
        
        // place character in chosen spot,
        grid[row][col] = players[index];
        
        // print table with character in spot
        printGrid(grid);
        
        // increase index for next player's turn on the list
        index++;
        
        // check if there is a winner
        gameOver = checkWin(grid, players, index);
    }
    
    // end program
    cout << endl << "Bye!" << endl;
        return 0;
}
    


