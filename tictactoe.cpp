#include <iostream>

using namespace std;

int main(){

  char board[3][3];

  int turn = 1;
  int p1wins = 0;
  int p2wins = 0;
  int pTies = 0;

  bool playing = true;
  bool playing2;

  void printBoard(char board[3][3]);
  void clearBoard(char &board[3][3]);
  bool updateBoard(char &board[3][3], int a, int b, int &turn);

  bool playerTurn(char &board[3][3], int &turn);

  int checkWin(char board[3][3], int turn);
  bool checkFull(char board[3][3]);
  bool checkLegal(char board[3][3], int a, int b);
  

  clearBoard(board);
  cout << "Let's play a game of TicTacToe!" << endl;

  while (playing) {

    playing2 = true;
    
    while (playing2) {
      playing2 = playerTurn(board, turn);
    }

    cout << "player 1 has " << p1wins << " wins." << endl;
    cout << "player 2 has " << p2wins << " wins." << endl;
    cout << "There have been " << pTies < " ties." << endl;

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

void printBoard(char board[3][3]) {

  cout << "\ta\tb\tc" << endl;

  for (int i = 0; i < 3; i++) {

    cout << i+1;
    
    for (int j = 0; j < 3; j++) {
      cout << "\t" << theBoard[i][j];
   }
    
    cout << "\t" << endl;
  }
  
}

void clearBoard(char &board[3][3]) {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = '-';
    }
  }
  
}

void updateBoard(char &board[3][3], int a, int b, char &turn) {
  char place;

  if (turn == 1) {
    place = 'x';
  }
  else if (turn == -1) {
    place = 'o';
  }  

  if (checkLegal(board, a, b)) {
    board[a][b] = place; 
  }
  return;
}

bool playerTurn(char &board[3][3],int &turn) {

  char loc[3];
  
  if (turn == 1) {
    printBoard(board);
      cout << "Player 1 (x), tell me where you want to place your tac? (ex. 2a, 1b, 3c)" << endl;
      cin.get(loc, 3);
      updateBoard(board, (int)loc[0] - 49, (int)loc[1] - 97, turn);
      printBoard(board);

      if (checkWin(board, 1) == 1) {
	cout << "player 1 wins!" << endl;
	p1wins += 1;
        return false;
      }
      else if (checkwin(board, 1) == 3 {
	  cout << "it's a tie!" << endl;
	  pTies += 1;
	  return = false;
      }
  }
   if (turn == 1) {
    printBoard(board);
      cout << "Player 2 (x), tell me where you want to place your tac? (ex. 2a, 1b, 3c)" << endl;
      cin.get(loc, 3);
      updateBoard(board, (int)loc[0] - 49, (int)loc[1] - 97, turn);
      printBoard(board);

      if (checkWin(board, -1) == 1) {
	cout << "player 1 wins!" << endl;
	p1wins += 1;
        return false;
      }
      else if (checkwin(board, -1) == 3 {
	  cout << "it's a tie!" << endl;
	  pTies += 1;
	  return = false;
      }
  }
  turn *= -1;
  return true;
}

int checkWin(char board[3][3], int turn) {

  char lookfor;

  if (turn == 1) {
    lookfor = 'x';
  }
  else if (turn == -1) {
    lookfor = 'o';
  }
  
  //three horizontal:
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == lookfor && board[i][1] == lookfor && board[i][2] == lookfor) {
      return 1;
  }
    //three vertical:
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == lookfor && board[1][i] == lookfor && board[2][i] == lookfor) {
      return 1;
  }

   //two diagonals:
  if (board[0][0] == lookfor && board[1][1] == lookfor && board[2][2] == lookfor) {
      return 1;
  }

  else if (board[0][2] == lookfor && board[1][1] == lookfor && board[2][0] == lookfor) {
      return turn;
  }

  else if (checkFull(board)) {
    return 2;
  }

  return 0;
}

bool checkFull(char board[3][3]) {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] = '-') {
	return false;
      }
    }
  }

  return true;
}

bool checkLegal(char board[3][3], int a, int b) {
  
  if (board[a][b] != "-") {
    return false;
  }

  return true;
}

