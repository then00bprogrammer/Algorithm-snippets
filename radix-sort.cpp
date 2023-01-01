#include <bits/stdc++.h>

using namespace std;

class RadixSort{
// Sorts the given array in-place using radix sort
public:
void sort(vector<int>& array) {
  // Find the maximum number of digits in the elements of the array
  int max_digits = 0;
  for (int i : array) {
    max_digits = max(max_digits, GetNumDigits(i));
  }

  // Iterate over the digits, starting with the least significant digit
  for (int digit = 1; digit <= max_digits; digit++) {
    // Sort the elements based on the current digit
    SortByDigit(array, digit);
  }
}

// Sorts the given array in-place based on the specified digit
public:
// Sorts the given array in-place based on the specified digit
void SortByDigit(vector<int>& array, int digit) {
  // Find the maximum element in the array
  int max_ele = *max_element(array.begin(), array.end());

  // Create the count array and the output array
  vector<int> count(max_ele + 1);
  vector<int> output(array.size());

  // Count the number of occurrences of each element in the array based on the specified digit
  for (int i : array) {
    count[GetDigit(i, digit)]++;
  }

  // Iterate over the count array and use the counts to determine the positions of each element in the output array
  for (int i = 1; i <= max_ele; i++) {
    count[i] += count[i - 1];
  }
  for (int i = array.size() - 1; i >= 0; i--) {
    output[count[GetDigit(array[i], digit)] - 1] = array[i];
    count[GetDigit(array[i], digit)]--;
  }

  // Copy the sorted elements back into the original array
  for (int i = 0; i < array.size(); i++) {
    array[i] = output[i];
  }
}




// Returns the specified digit of the given number (counting from the least significant digit)
private:
int GetDigit(int number, int digit) {
  int divisor = pow(10, digit - 1);
  return (number / divisor) % 10;
}

// Returns the number of digits in the given number
private:
int GetNumDigits(int number) {
  if (number == 0) return 1;
  return floor(log10(number)) + 1;
}
};



int main() {
  // Test the RadixSort function
  RadixSort rs;
  vector<int> array = {170, 45, 75, 90, 802, 24, 2, 66};
  rs.sort(array);
  for (int i : array) {
    cout << i << " ";
  }
  cout << endl;
}
