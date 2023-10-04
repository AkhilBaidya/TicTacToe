//C++ Programming: Tic-Tac-Toe Project
//by Akhil Baidya

//Date of Submission: 10/3/2023

/*Notes: The following code is for a two-player (no computer player) game of Tic-Tac-Toe. Player 1 is X and player 2 is O.
Players will have to input in specific coordinates based on the column and row labels of the Tic-Tac-Toe board (such as 1a, 2b, 3c,
without spaces and no capitals) on their turn to place a piece on the 3x3 board. Turns alternate, with player 1 starting.

First to 3 in a row/column/diagonal wins!

To continue the game, once prompted, please enter 'y' or 'n' (yes or no).*/

/*Credits: 

1. Mr. Galbraith's videos on Canvas were used to understand how to create functions in C++ (such as writing the function
prototype at the top of the code). 

2. Used Carnegie Mellon's ASCII chart when inputting indices into updateBoard() in playerTurn() to see
ASCII values of alphanumeric characters. Link to the chart: 
https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html to reference ASCII values

3. Used suggestion from my father to use integers instead of characters throughout my code. This final code was altered with that
suggestion (however, this turned out to not impact the performance of the code); the actual conversion from using characters to
integers was done by myself. 

4. Earlier versions of the code did not function correctly due to the use of "=" instead of "==" in the checkfull function.
This typo was spotted by my father when I was debugging my code */

#include <iostream>

using namespace std;

//FUNCTION PROTOTYPES (their purposes will be commented before each function):
//changing the board:
void printBoard(int board[3][3]); 
void clearBoard(int board[3][3]);
bool updateBoard(int board[3][3], int a, int b, int &turn);

//taking a player's move and changing the board using the above functions:
void playerTurn(int board[3][3], int &turn, int &p1wins, int &p2wins, int &pTies,bool &round);

//checking a player's move (for win or legality)"
int checkWin(int board[3][3], int turn);
bool checkFull(int board[3][3]);
bool checkLegal(int board[3][3], int a, int b);


//MAIN FUNCTION (this is where the code will be run):
int main(){

  //VARIABLES:
  int theBoard[3][3]; //the tic-tac-toe bard

  int turn = 1; //turn number (1 for player 1, -1 for player 2)#
  
  int p1wins = 0; //number of wins for each player and number of ties
  int p2wins = 0;
  int pTies = 0;

  bool game = true; //boolean determining whether the entire game continues
  bool round; //boolean determining whether players continue putting pieces for a round (determines round end)

  //GAME FORMAT:
  cout << "Let's play a game of TicTacToe!" << endl;
  
  while (game) {

    clearBoard(theBoard); //at the beginning of the game, clear and display board and the round beings (round = true)
    printBoard(theBoard);
    round = true;
    
    while (round) {
      playerTurn(theBoard, turn, p1wins, p2wins, pTies, round); //loop player turns until playerTurn changes round to false (if it detects a win or a tie)
    }

    //When the round ends, shows scores:
    cout << "player 1 has " << p1wins << " wins." << endl;
    cout << "player 2 has " << p2wins << " wins." << endl;
    cout << "There have been " << pTies << " ties." << endl;

    //Ask if player wants to play again (if so, game is true and the entire game loops):
    cout << "Would you like to play again? y/n" << endl;
    char answer;
    cin >> answer;

    if (answer == 'y') {
      game = true;
    }
    else if (answer == 'n') {
      game = false;
    }
  }

 cout << "Thanks for playing!" << endl;
 return 0;
}


//OTHER FUNCTIONS:
//The printBoard function takes in the board and print outs the board (converting the integers to Xs or Os) and adds labels to the column/rows (ex. 1,2,3):
void printBoard(int board[3][3]) {

  cout << "\ta\tb\tc" << endl; //add the column names

  for (int i = 0; i < 3; i++) {
    
    cout << i+1; //add each row number
    
    for (int j = 0; j < 3; j++) { //for each value in board in each row...

      if (board[i][j] == 1) {
	cout << "\t" << 'X'; //print an X for values of 1
      }
      else if (board[i][j] == 0){
	cout << "\t" << 'O'; //print an O for values of 0
      }
      else {
	cout << "\t" << '-'; //value of -1 signify empty spots
      }
   }
    
    cout << "\t" << endl;
  }

  return;
}

//The clearBoard function takes in the board and replaces all values in the board with -1, signifying empty spots when the board is printed:
void clearBoard(int board[3][3]) {

  for (int i = 0; i < 3; i++) {//for each row in the board...
    for (int j = 0; j < 3; j++) {//for each value in the row...
      board[i][j] = -1; //make the value -1
    }
  }
  
  return;
}

/*The updateBoard function takes in the board, the current turn, and some index (a,b). This index (a,b) will be the (row,column) the player, of the specified turn, places their piece. The function makes this change, if legal, and returns whether the player made an illegal move */ 
bool updateBoard(int board[3][3], int a, int b, int &turn) {

  int place;
  
  if (turn == 1) {
    place = 1; //it is player 1's turn (pieces have value of 1)
  }
  else if (turn == -1) {
    place = 0; //it is player 2's turn (pieces have value of 0)
  }  

  if (checkLegal(board, a, b)) { //if their desired move is legal, replace the place in the board given by (a,b) with the value of the player's piece
    board[a][b] = place;
    return false; //the move was legal
  }

  cout << "You can't pick that spot!" << endl;
  return true; //the move was illegal
}

/*The playerTurn function takes in the board, player turn, the win and tie counts, and the boolean looping the round. The function prompts the player of the current turn to place their tac, calls other functions to place it, and sets the round to discontinue due to a win or tie. It additionally flips the turn number to the next player  (with x -1) */
void playerTurn(int board[3][3],int &turn, int &p1wins, int &p2wins, int &pTies, bool &round) {

  char loc[3]; //this will contain the player's choice for placing their piece (the location)
  bool ask = true; //this will loop the prompt of asking the player's choice if their previous choice is illegal

  while (ask) {

    //ask the player for the index of where they want to place their piece:
    if (turn == 1) {
      cout << "Player 1 (x), tell me where you want to place your tac? (ex. 2a, 1b, 3c)" << endl;
    }
    else {
      cout << "Player 2 (x), tell me where you want to place your tac? (ex. 2a, 1b, 3c)" << endl;
    }
    cin >> loc; //place that inputted index into the loc character array

     /*used ASCII chart from Carnegie Mellon School of Computer Science at:
      https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html

      This helped determine what number to subtract from the index inputs (put into updateBoard) when converted to integers in order to get the correct
      index for the array (ex. (1, a) needs to become (0,0)) */
    
    ask = updateBoard(board, ((int) loc[0]) -49, ((int)loc[1]) - 97, turn);
    /*updateBoard places the current player's piece at the desired location
   (and returns whether the player has entered an illegal move and the program needs to ask them for a move again, with ask = true)*/
    printBoard(board);
  }

  //check for wins or ties: 
  if (checkWin(board, 1) == 1) { //player one wins
	cout << "player 1 wins!" << endl;
	p1wins += 1;
        round = false; //end the round
      }

  else if (checkWin(board, 1) == 2) { //a tie on player one's turn
	  cout << "it's a tie!" << endl;
	  pTies += 1;
	  round = false;
      }  
   
  else if (checkWin(board, -1) == 1) {//player two wins
	cout << "player 2 wins!" << endl;
	p2wins += 1;
        round = false;
      }
  else if (checkWin(board, -1) == 2) {//a tie on player two's turn
	  cout << "it's a tie!" << endl;
	  pTies += 1;
	  round = false;
      }
    
  turn *= -1; //switch turns
  return;
}

//The checkWin function takes the board and the current turn and returns whether there is win for the player of that turn or a tie:
int checkWin(int board[3][3], int turn) {

  int lookfor; //which type of piece to look for (the player of the current turn)

  if (turn == 1) { //player 1
    lookfor = 1;
  }
  else if (turn == -1) {//player 2
    lookfor = 0;
  }
  
 //check for three horizontal pieces (win):
 for (int i = 0; i < 3; i++) {
    if (board[i][0] == lookfor && board[i][1] == lookfor && board[i][2] == lookfor) {
      return 1; //returning 1 represents a win occurred 
    }
  }

 //check for three vertical pieces (win):
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == lookfor && board[1][i] == lookfor && board[2][i] == lookfor) {
      return 1;
    }
  }
  
   //check for diagonal from top left to bottom right (win):
  if (board[0][0] == lookfor && board[1][1] == lookfor && board[2][2] == lookfor) {
      return 1;
  }

  //check for diagonal from bottom left to top right (win):
  else if (board[0][2] == lookfor && board[1][1] == lookfor && board[2][0] == lookfor) {
      return 1;
  }

  //if the board is full but none of these win cases occur, a tie occurred:
  if (checkFull(board)) {
    return 2; //returning 2 signifies a tie occured
  }

  return 0; //else return 0, meaning nothing happened
}


/*The checkFull function takes in the board and checks if there still exists a value of -1 (representin an empty spot) in the board array.
  If so, then the board not full. If not, then the board is full. The function returns this observation as a boolean.*/
bool checkFull(int board[3][3]) {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == -1) { //as soon as there is a -1 (empty) value in the board...

	/*Note: earlier drafts had board[i][j] = -1, messing with the performance of the game (deleting values at the spot 1a)
	  The typo from '==' to '=' was spotted by my father while I was debugging my code. 
	 */
	
	return false; //it is false that the board is full 
      }
    }
  }

  return true; //else the board is full
}

/*The checkLegal function takes in the board and some index (a,b) where the player want to place a piece.
  The function returns whether the location is empty or already occupied (if is empty, the move is legal).
 */
bool checkLegal(int board[3][3], int a, int b) {
  
  if (board[a][b] == 0 || board[a][b] == 1) {
    return false; //there is a piece (0 and 1 represent the player piece values, player 2 and player 1 respectively) already at (a,b), so the move is illegal
  }

  return true; //the spot (a,b) is open, so the move is legal!
}
