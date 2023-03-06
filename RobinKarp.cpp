#include <bits/stdc++.h>
using namespace std;

const int alphabetSize = 256;

int search(string pattern, string text, int prime) {
  int patternLength = pattern.length();
  int textLength = text.length();
  int hashPattern = 0;  
  int hashText = 0;  
  int power = 1;

  for (int i = 0; i < patternLength - 1; i++) {
    power = (power * alphabetSize) % prime;
  }

  for (int i = 0; i < patternLength; i++) {
    hashPattern = (alphabetSize * hashPattern + pattern[i]) % prime;
    hashText = (alphabetSize * hashText + text[i]) % prime;
  }

  for (int i = 0; i <= textLength - patternLength; i++) {

    int j;
    if (hashPattern == hashText) {
      for (j = 0; j < patternLength; j++) {
        if (text[i + j] != pattern[j]) {
          break;
        }
      }
      if (j == patternLength) {
        return i;
      }
    }

    if (i < textLength - patternLength) {
      hashText = (alphabetSize * (hashText - text[i] * power) + text[i + patternLength]) % prime;

      if (hashText < 0) {
        hashText = (hashText + prime);
      }
    }
  }

  return -1;
}

int main() {
  string text = "GEEKS FOR GEEKS";
  string pattern = "GEEK";

  int prime = INT_MAX;

  int index = search(pattern, text, prime);
  if (index != -1) {
    cout << "Pattern found at index " << index << endl;
  } else {
    cout << "Pattern not found" << endl;
  }

  return 0;
}
