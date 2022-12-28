#include <bits/stdc++.h>
using namespace std;

//QUICK-SELECT

int findKthLargest(vector<int>& nums, int k) {
    if (nums.empty()) return 0;
    
    // Choose a random pivot
    int pivot = nums[rand() % nums.size()];
    
// First, we need to choose so-called pivot and partition element of nums into 3 parts: elements, smaller than pivot, equal to pivot and bigger than pivot. (sometimes two groups enough: less and more or equal)

    vector<int> greaterThanPivot, equalToPivot, lessThanPivot;
    
    for (int x : nums) {
        if (x > pivot) greaterThanPivot.push_back(x);
        else if (x == pivot) equalToPivot.push_back(x);
        else lessThanPivot.push_back(x);
    }

    
    int greaterLength = greaterThanPivot.size();
    int equalLength = equalToPivot.size();

// Next step is to see how many elements we have in each group: if k <= greaterLength, where greaterLength is size of greaterThanPivot, than we can be sure that we need to look into the greaterThanPivot part. If k > greaterLength + equalLength, where equalLength is size of equalToPivot group, than we can be sure, that we need to look into the lessThanPivot part. Finally, if none of these two condition holds, we need to look in the equalToPivot part, but because all elements there are equal, we can immedietly return equalToPivot[0].
    
    if (k <= greaterLength) {
        return findKthLargest(greaterThanPivot, k);
    }
    else if (k > greaterLength + equalLength) {
        return findKthLargest(lessThanPivot, k - greaterLength - equalLength);
    }
    else {
        return equalToPivot[0];
    }
}

int main() {
    // Example usage
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargest(nums, k) << endl;  // Outputs: 5
    return 0;
}
