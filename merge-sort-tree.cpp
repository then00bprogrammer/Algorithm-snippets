#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class SegmentTree {
public:
	vector<vector<int>> segTree;
	SegmentTree(int n) {
		segTree.resize(4 * n + 1);
	}

    // function to build the tree
    void build(vector <int> a, int node, int left, int right) {
        if (left == right) {
            segTree[node] = vector<int>(1, a[left]);
            return;
        } 
        int middle = (left + right) / 2;
        build(a, node*2, left, middle);
        build(a, node*2+1, middle+1, right);

        // merge the values from the left and right child into the current node
        merge(segTree[node*2].begin(), segTree[node*2].end(), segTree[node*2+1].begin(), segTree[node*2+1].end(),
                back_inserter(segTree[node]));
        
    }

    // query -> first number in left--right that is greater than or equal to x
    int query(int node, int left, int right, int qleft, int qright, int x) {
        if (qleft > qright)
            return INF;

        if (qleft == left && qright == right) {
            auto pos = lower_bound(segTree[node].begin(), segTree[node].end(), x);
            if (pos != segTree[node].end())
                return *pos;
            return INF;
        }

        int middle = (left + right) / 2;
        return min(query(node*2, left, middle, qleft, min(qright, middle), x), 
                   query(node*2+1, middle+1, right, max(qleft, middle+1), qright, x));
    }
};

int main() {
    vector<int> a = {5, 2, 4, 3, 8, 7, 9, 10, 1, 6};
    int n = a.size();

    SegmentTree tree(n);
    tree.build(a, 1, 0, n - 1);

    // Example 1: 
    // Find the minimum value in the range [2, 6] that is greater than or equal to 7
    int qleft = 2, qright = 6, x = 7;
    int result = tree.query(1, 0, n - 1, qleft, qright, x);
    cout << "Minimum value in range [" << qleft << ", " << qright << "] that is greater than or equal to " << x << ": " << result << endl;

    // Example 2: 
    // Find the minimum value in the range [0, 4] that is greater than or equal to 4
    qleft = 0, qright = 4, x = 4;
    result = tree.query(1, 0, n - 1, qleft, qright, x);
    cout << "Minimum value in range [" << qleft << ", " << qright << "] that is greater than or equal to " << x << ": " << result << endl;

    return 0;
}

