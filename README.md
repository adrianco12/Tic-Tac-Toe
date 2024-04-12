# Tic-Tac-Toe
This program is a simple tic tac toe game in C++. It is a console-based game that utilizes various programming concepts such as decision structures, loops, arrays, functions, and more to manage the game's logic and flow.

The program allows two players to take turns placing their symbols ('X' and 'O') on a 3x3 grid.

Upon starting the program, the grid is initialized with empty spaces (' ') and displayed to the players. The game then enters a loop where players take turns making their moves until the game is won or ends in a tie. During each player's turn, they are prompted to input the row and column where they want to place their symbol. The program performs data validation to ensure that the input is within the valid range (1-3) and that the chosen spot is not already occupied.If the chosen spot is occupied, an error message is displayed, and the player is prompted to choose another spot. Once a valid and unoccupied spot is chosen, the player's symbol is placed on the grid, and the updated grid is displayed.

After each move, the program checks if the current player has won the game by achieving three of their symbols in a row, column, or diagonal. If a player wins, a congratulatory message is displayed, and the game ends. If no player wins after nine moves (the grid is full), the game ends in a tie, and a corresponding message is displayed.

Finally, the program terminates, bidding farewell to the players.
