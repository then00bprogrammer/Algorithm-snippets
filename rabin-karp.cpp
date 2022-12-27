#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
const int alphabetSize = 256;

// Returns the index of the pattern in the text, or -1 if not found
int search(string pattern, string text, int prime) {
  int patternLength = pattern.length();
  int textLength = text.length();
  int hashPattern = 0;  // hash value for pattern
  int hashText = 0;  // hash value for text
  int power = 1;

  // The value of power would be "pow(d, M-1)%prime"
  for (int i = 0; i < patternLength - 1; i++) {
    power = (power * alphabetSize) % prime;
  }

  // Calculate the hash value of pattern and first window of text
  for (int i = 0; i < patternLength; i++) {
    hashPattern = (alphabetSize * hashPattern + pattern[i]) % prime;
    hashText = (alphabetSize * hashText + text[i]) % prime;
  }

  // Slide the pattern over text one by one
  for (int i = 0; i <= textLength - patternLength; i++) {

    // Check the hash values of current window of text and pattern.
    // If the hash values match then only check for characters one by one
    int j;
    if (hashPattern == hashText) {
      // Check for characters one by one
      for (j = 0; j < patternLength; j++) {
        if (text[i + j] != pattern[j]) {
          break;
        }
      }

      // If hashPattern == hashText and pat[0...M-1] = txt[i, i+1, ...i+M-1]
      if (j == patternLength) {
        return i;
      }
    }

    // Calculate hash value for next window of text: Remove leading digit, add trailing digit
    if (i < textLength - patternLength) {
      hashText = (alphabetSize * (hashText - text[i] * power) + text[i + patternLength]) % prime;

      // We might get negative value of hashText, converting it to positive
      if (hashText < 0) {
        hashText = (hashText + prime);
      }
    }
  }

  return -1;
}

// Driver code
int main() {
  string text = "GEEKS FOR GEEKS";
  string pattern = "GEEK";

  // We mod to avoid overflowing of value but we should
  // take as big prime as possible to avoid the collision
  int prime = INT_MAX;

  // Function Call
  int index = search(pattern, text, prime);
  if (index != -1) {
    cout << "Pattern found at index " << index << endl;
  } else {
    cout << "Pattern not found" << endl;
  }

  return 0;
}
