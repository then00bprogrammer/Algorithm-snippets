#include <bits/stdc++.h>

using namespace std;

class segmentTree {
public:
	vector<int> segTree;
	segmentTree(int n) {
		segTree.resize(4 * n + 1);
	}
	void build(int ind, int low, int high, vector<int> &arr) {
		if (low == high) {
			segTree[ind] = arr[low];
			return;
		}
		int mid = low + (high - low) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
	}

	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			segTree[ind] = val;
			return;
		}
		int mid = (low + high) >> 1;
		if (i <= mid) {
			update(2 * ind + 1, low, mid, i, val);
		}
		else {
			update(2 * ind + 2, mid + 1, high, i, val);
		}
		segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
	}

	int query(int ind, int low, int high, int l, int r) {
		if (low > r || high < l) {
			return 0;
		}
		if (low >= l && high <= r) {
			return segTree[ind];
		}
		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return left + right;
	}
};

int main() {
	// create a segment tree for an array of size 10
	segmentTree st(10);

	// build the segment tree using the build function
	vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	st.build(0, 0, 9, arr);

	// update the value at index 3 to be 10
	st.update(0, 0, 9, 3, 10);

	// query the sum of the values in the range [1, 6]
	int sum = st.query(0, 0, 9, 1, 6);
	// sum will be equal to the sum of the values in the original array: 1 + 3 + 5 + 7 + 9 + 11 = 36

	return 0;
}

