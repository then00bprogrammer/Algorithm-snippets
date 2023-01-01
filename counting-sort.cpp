#include <bits/stdc++.h>

using namespace std;

class CountingSort {
 public:
  // Sorts the given array in-place using counting sort
  void Sort(vector<int>& array) {
    // Find the maximum value in the array
    int max_value = *max_element(array.begin(), array.end());

    // Create the count array
    vector<int> count(max_value + 1);
    for (int i : array) {
      count[i]++;
    }

    // Iterate over the count array and use the counts to determine the positions of each element in the output array
    int j = 0;
    for (int i = 0; i <= max_value; i++) {
      for (int k = 0; k < count[i]; k++) {
        array[j] = i;
        j++;
      }
    }
  }
};

int main() {
  // Create an instance of the CountingSort class
  CountingSort sorter;

  // Example use case 1: sort an array of integers
  vector<int> array = {2, 5, 3, 5, 2, 0};
  sorter.Sort(array);
  for (int i : array) {
    cout << i << " ";
  }
  cout << endl;
}
