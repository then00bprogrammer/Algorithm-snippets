#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    vector<int> left(leftSize);
    vector<int> right(rightSize);

    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[low + i];
    }

    for (int j = 0; j < rightSize; j++) {
        right[j] = arr[mid + 1 + j];
    }

    //Merging arrays
    int i = 0;
    int j = 0;
    int k = low;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Leftover values
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

vector<int> performMergeSort(vector<int> arr) {
    mergeSort(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();

    cout << "Before using merge sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = performMergeSort(arr);

    cout << "After using merge sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
