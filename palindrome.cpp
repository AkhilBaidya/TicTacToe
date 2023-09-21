/*
C++ Programming DC: Palindrome Checker

by Akhil Baidya 

(with help from Mr. Galbraith, Mr. Galbraith's videos on Canvas,

GeeksforGeeks - https://www.geeksforgeeks.org/type-conversion-in-c/#,

and Carnegie Mellon University - https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html) 


Date (mm/dd/yy): 9/21/23

Notes:
The user will input a series of characters after prompted to by the computer.
The computer will read a max of 80 characters (including non-alphanumeric characters)
and then print out whether the series is a palindrome or not. 

The non-alphanumeric characters will not be considered in whether the series of
characters is a palindrome (ex. tacocat and taco_!!cat are both palindromes)

WARNING - do not backspace when entering inputs, as these backspaces will be 
read by the computer as part of the input. 
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(){
  char input[81];
  char clean[81];
  int j = 0;

  cin.get(input, 80);
  cin.get();

  for (int i = 0; i < strlen(input); i++) {
      if ((int)input[i] >= 97 && (int)input[i] <= 122) {
	clean[j] = input[i];
	j++;
      }

      else if ((int)input[i] >= 48 && (int)input[i] <= 57) {
	clean[j] = input[i];
	j++;
      }

      else if ((int)input[i] >= 65 && (int)input[i] <= 90) {
	clean[j] = (char)((int)input[i] + 32);
	j++;
      }
      else {
	cout << "exclude: " << input[i];
      }
    }
  
  clean[j] = '\0'; 

  cout << "DONE" << endl;

  cout << j << endl;
  
  for (int l = 0; l < j; ++l) {

    cout << l << ":" << clean[l] << '|';
    
   }

  cout << "DONE" << endl;

  for (int k = 0; k < (j - (j%2))/2; k++) {
    if (clean[k] != clean[j-k-1]) {
      cout << "Not a palindrome" << endl;
      return 0;
    }
  }

  cout << "Palindrome!" << endl;
  return 0;
}
