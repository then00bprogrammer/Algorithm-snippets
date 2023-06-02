#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    if (nums.size() == 1) return;
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    if (i >= 0) {
        int j = nums.size() - 1;
        while (nums[j] <= nums[i] && j > i) j--;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    nextPermutation(nums1);
    cout << "Next permutation: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {3, 2, 1};
    nextPermutation(nums2);
    cout << "Next permutation: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums3 = {1, 1, 5};
    nextPermutation(nums3);
    cout << "Next permutation: ";
    for (int num : nums3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
