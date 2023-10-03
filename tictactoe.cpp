
//used https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html to reference ASCII values
/*used suggestion from my father to use integers instead of characters throughout my code: however, this turned out
to not be the source of error. but the use of "=" instead of "==" in the checkfull function. Additionally, code seemed
to work better after replacing cin.get() with the regular cin >> */

#include <iostream>

using namespace std;

void printBoard(int board[3][3]); //change the board
void clearBoard(int board[3][3]);
void updateBoard(int board[3][3], int a, int b, int &turn);

void playerTurn(int board[3][3], int &turn, int &p1wins, int &p2wins, int &pTies,bool &playing2); //player move

int checkWin(int board[3][3], int turn); //check end conditions
bool checkFull(int board[3][3]);
bool checkLegal(int board[3][3], int a, int b);

int main(){

  //VARIABLES:
  int theBoard[3][3]; //the board

  int turn = 1; //turn #, wins
  int p1wins = 0;
  int p2wins = 0;
  int pTies = 0;

  bool playing = true; //whether the game continues
  bool playing2;
  
  
  clearBoard(theBoard);
  cout << "Let's play a game of TicTacToe!" << endl;
  printBoard(theBoard);

  while (playing) {

    playing2 = true;
    
    while (playing2) {
      playerTurn(theBoard, turn, p1wins, p2wins, pTies, playing2);
    }

    cout << "player 1 has " << p1wins << " wins." << endl;
    cout << "player 2 has " << p2wins << " wins." << endl;
    cout << "There have been " << pTies << " ties." << endl;

    cout << "Would you like to play again? y/n" << endl;
    char answer;
    cin >> answer;
    if (answer == 'y') {
      playing = true;
    }
    else if (answer == 'n') {
      playing = false;
    }
  }

 cout << "Thanks for playing!" << endl;
 return 0;
}


void printBoard(int board[3][3]) {

  cout << "\ta\tb\tc" << endl;

  for (int i = 0; i < 3; i++) {

    cout << i+1;
    
    for (int j = 0; j < 3; j++) {

      if (board[i][j] == 1) {
      cout << "\t" << 'X';
      }
      else if (board[i][j] == 0){
	cout << "\t" << 'O';
      }
      else {
	cout << "\t" << '-';
      }
      
      
   }
    
    cout << "\t" << endl;
  }

  return;
}

void clearBoard(int board[3][3]) {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = -1;
    }
  }

  return;
  
}

void updateBoard(int board[3][3], int a, int b, int &turn) {
  int place;

  cout << "a = " << a << "  b =" << b << endl;
  
  if (turn == 1) {
    place = 1;
  }
  else if (turn == -1) {
    place = 0;
  }  

  if (checkLegal(board, a, b)) {
    board[a][b] = place; 
  }
  return;
}

void playerTurn(int board[3][3],int &turn, int &p1wins, int &p2wins, int &pTies, bool &playing2) {

  char loc[3];
  
  if (turn == 1) {
    cout << "Player 1 (x), tell me where you want to place your tac? (ex. 2a, 1b, 3c)" << endl;
  }
  else {
    cout << "Player 2 (x), tell me where you want to place your tac? (ex. 2a, 1b, 3c)" << endl;
   }
  
    cin >> loc;
    printBoard(board);
    updateBoard(board, ((int) loc[0]) -49, ((int)loc[1]) - 97, turn);
    printBoard(board);
   
    if (checkWin(board, 1) == 1) {
	cout << "player 1 wins!" << endl;
	p1wins += 1;
        playing2 = false;
      }
    else if (checkWin(board, 1) == 3) {
	  cout << "it's a tie!" << endl;
	  pTies += 1;
	  playing2 = false;
      }  
   
    else if (checkWin(board, -1) == 1) {
	cout << "player 2 wins!" << endl;
	p2wins += 1;
        playing2 = false;
      }
    else if (checkWin(board, -1) == 3) {
	  cout << "it's a tie!" << endl;
	  pTies += 1;
	  playing2 = false;
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
 
  else if (checkFull(board)) {
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
