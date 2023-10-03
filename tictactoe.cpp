//C++ Programming: Tic-Tac-Toe Project
//by Akhil Baidya

//Date of Submission: 10/3/2023

//Notes: 

//Credits: 

//used https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html to reference ASCII values
/*used suggestion from my father to use integers instead of characters throughout my code: however, this turned out
to not be the source of error. but the use of "=" instead of "==" in the checkfull function. Additionally, code seemed
to work better after replacing cin.get() with the regular cin >>*/

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

    //used ASCII 
    ask = updateBoard(board, ((int) loc[0]) -49, ((int)loc[1]) - 97, turn);
    printBoard(board);
  }
 
    if (checkWin(board, 1) == 1) {
	cout << "player 1 wins!" << endl;
	p1wins += 1;
        round = false;
      }
    else if (checkWin(board, 1) == 2) {
	  cout << "it's a tie!" << endl;
	  pTies += 1;
	  round = false;
      }  
   
    else if (checkWin(board, -1) == 1) {
	cout << "player 2 wins!" << endl;
	p2wins += 1;
        round = false;
      }
    else if (checkWin(board, -1) == 2) {
	  cout << "it's a tie!" << endl;
	  pTies += 1;
	  round = false;
      }
    
  turn *= -1;
  return;
}

int checkWin(int board[3][3], int turn) {

  int lookfor;

  if (turn == 1) {
    lookfor = 1;
  }
  else if (turn == -1) {
    lookfor = 0;
  }
  
  //three horizontal:
 for (int i = 0; i < 3; i++) {
    if (board[i][0] == lookfor && board[i][1] == lookfor && board[i][2] == lookfor) {
      return 1;
    }
  }
    //three vertical:
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == lookfor && board[1][i] == lookfor && board[2][i] == lookfor) {
      return 1;
  }
  }
   //two diagonals:
  if (board[0][0] == lookfor && board[1][1] == lookfor && board[2][2] == lookfor) {
      return 1;
  }

  else if (board[0][2] == lookfor && board[1][1] == lookfor && board[2][0] == lookfor) {
      return 1;
  }

  if (checkFull(board)) {
    return 2;
  }

  return 0;
}

bool checkFull(int board[3][3]) {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == -1) {
	return false;
      }
    }
  }

  return true;
}

bool checkLegal(int board[3][3], int a, int b) {
  
  if (board[a][b] == 0 || board[a][b] == 1) {
    return false;
  }

  return true;
}
