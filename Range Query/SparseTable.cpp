#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// RMQ in O(1)
// Build in N*logN

class SparseTable {
private:
    vector<vector<int>> table;
    vector<int> logValues;
    
public:
    SparseTable(const vector<int>& arr) {
        int n = arr.size();
        int logn = log2(n) + 1;
        
        table.resize(n, vector<int>(logn));
        logValues.resize(n + 1);
        
        // Precompute the logarithms
        logValues[1] = 0;
        for (int i = 2; i <= n; i++) {
            logValues[i] = logValues[i / 2] + 1;
        }
        
        // Initialize the Sparse Table
        for (int i = 0; i < n; i++) {
            table[i][0] = arr[i];
        }
        
        // Fill the Sparse Table
        for (int j = 1; j <= logValues[n]; j++) {
            for (int i = 0; (i + (1 << j) - 1) < n; i++) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    int query(int left, int right) {
        int length = right - left + 1;
        int log = logValues[length];
        return min(table[left][log], table[right - (1 << log) + 1][log]);
    }
};

int main() {
    vector<int> arr = {1, 3, 2, 7, 9, 11, 3, 5, 6, 8, 4};
    SparseTable st(arr);
    
    cout << "RMQ(0, 5): " << st.query(0, 5) << endl;  // Output: 1
    cout << "RMQ(3, 7): " << st.query(3, 7) << endl;  // Output: 3
    cout << "RMQ(4, 9): " << st.query(4, 9) << endl;  // Output: 3
    cout << "RMQ(7, 10): " << st.query(7, 10) << endl;  // Output: 4

    return 0;
}
