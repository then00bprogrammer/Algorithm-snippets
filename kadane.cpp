#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>& arr) {
    int max_ending_here = 0, max_so_far = 0;
    for (int x : arr) {
        max_ending_here = max(0, max_ending_here + x);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main() {
    // Use case 1: Maximum subarray sum is 7 (elements 3 and 4)
    vector<int> arr1 = {1, -2, 3, 4, -5};
    cout << "Max subarray sum: " << kadane(arr1) << endl;

    // Use case 2: Maximum subarray sum is 15 (elements 1, 2, and 3)
    vector<int> arr2 = {-1, 2, 3, -4, 5};
    cout << "Max subarray sum: " << kadane(arr2) << endl;

    // Use case 3: Maximum subarray sum is 4 (elements 3 and 4)
    vector<int> arr3 = {-1, -2, -3, 4, 5};
    cout << "Max subarray sum: " << kadane(arr3) << endl;

    return 0;
}
