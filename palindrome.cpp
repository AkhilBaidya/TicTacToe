#include <iostream>
#include <cstring>

using namespace std;

int main(){
  
  char input[80];
  char otherin[80];
  char clean[80];
  int j = 0;

  
  cout << "Please input something. I will check if it is a palindrome." << endl;

  cin.get(input, 80);
  cin.get();

  strcpy(otherin, input);
  
  
  for (int i = 0; i < strlen(input); i++) {
      if ((int)input[i] >= 97 && (int)input[i] <= 122) {
	clean[j] = otherin[i];
	j++;
      }

      else if ((int)input[i] >= 48 && (int)input[i] <= 57) {
	clean[j] = otherin[i];
	j++;
      }

      else if ((int)input[i] >= 65 && (int)input[i] <= 90) {
	clean[j] = (char)((int)otherin[i] + 32);
	j++;
      }
      else {
	cout << "exclude: " << otherin[i];
      }
    }

  cout << "next" << endl;

  cout << j << endl;
  
  for (int l = 0; l < j; ++l) {

    cout << l << ":" << clean[l] << '|';
    
   }

  cout << "next" << endl;

  int full = 0;
  for (int k = 0; k < (j - (j%2))/2; k++) {
    if (clean[k] != clean[j-k-1]) {
      int full = 1;
    }
  }

  if (full == 0) {
  cout << "Palindrome!" << endl;
  }
  else if (full == 1) {
  cout << "Not a palindrome" << endl;
  }

  return 0;
}
