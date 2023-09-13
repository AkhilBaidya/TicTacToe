#include <iostream>

using namespace std;

int main(){

  char input[80];
  char clean[80];

  cin.get(input, 80); 

  int j = 0;
  
  for (int i = 0; i < 80; i++) {

    if ((int)input[i] >= 97 && (int)input[i] <= 122) {
      clean[j] = input[i];
      j++;
    }

    else if ((int)input[i] >= 65 && (int)input[i] <= 90) {
      clean[j] = (char)((int)input[i] + 32);
      j++; 
    }
  }
  
  for (int k = 0; k < (j-1)/2; k++) {
    if (clean[k] != clean[j-k-1]) {
      cout << "not a palindrome" << endl;
      return 0;
    }
  }

  cout << "is a palindrome!" << endl;
  return 0;
}
