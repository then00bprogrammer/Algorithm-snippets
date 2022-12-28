#include <bits/stdc++.h>
using namespace std;

class bucketSort{
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create a frequency map
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Create a bucket to store the elements in order of frequency
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& [num, count] : freq) {
            bucket[count].push_back(num);
        }
        
        // Collect the top k most frequent elements from the bucket
        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0 && res.size() < k; i--) {
            for (int num : bucket[i]) {
                res.push_back(num);
                if (res.size() == k) break;
            }
        }
        return res;
    }   

public:
    vector<string> sortByLength(vector<string>& strs) {
    // Create a bucket to store the strings in order of length
    vector<vector<string>> bucket(strs.size() + 1);
    for (string& s : strs) {
        bucket[s.length()].push_back(s);
    }
    
    // Collect the strings from the bucket in order
    vector<string> res;
    for (vector<string>& group : bucket) {
        for (string& s : group) {
            res.push_back(s);
        }
    }
    return res;
}

public:
    vector<int> sortByDigits(vector<int>& nums) {
    // Create a bucket to store the integers in order of the number of digits
    vector<vector<int>> bucket(nums.size() + 1);
    for (int num : nums) {
        int digits = (int)log10(num) + 1;
        bucket[digits].push_back(num);
    }
    
    // Collect the integers from the bucket in order
    vector<int> res;
    for (vector<int>& group : bucket) {
        for (int num : group) {
            res.push_back(num);
        }
    }
    return res;
}

public:
    vector<string> sortByVowels(vector<string>& strs) {
    // Create a bucket to store the strings in order of the number of vowels they contain
    vector<vector<string>> bucket(strs.size() + 1);
    for (string& s : strs) {
        int vowels = 0;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowels++;
            }
        }
        bucket[vowels].push_back(s);
    }
    
    // Collect the strings from the bucket in order
    vector<string> res;
    for (vector<string>& group : bucket) {
        for (string& s : group) {
            res.push_back(s);
        }
    }
    return res;
}
};

int main() {
    bucketSort bs;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> topK = bs.topKFrequent(nums, k);
    for (int num : topK) {
        cout << num << " ";  // Outputs: 1 2
    }
    cout << endl;
    return 0;
}
