#include <bits/stdc++.h>

using namespace std;

class segmentTree {
public:
	vector<int> segTree;
	vector<int> lazy;
	segmentTree(vector<int> &arr) {
		int n = arr.size();
		segTree.resize(4 * n + 1);
		lazy.resize(4* n + 1);
		build(0,0,n-1,arr);
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

	void pushDown(int ind,int low,int high){
		if (lazy[ind] != 0) {
			segTree[ind] += (high - low + 1) * lazy[ind];
			if (low != high) {
				//propogate the lazy update downwards
				//for the remaining nodes to get updated
				lazy[2 * ind + 1] += lazy[ind];
				lazy[2 * ind + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}
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

	void rangeUpdate(int ind, int low, int high, int l, int r, int val) {
		pushDown(ind,low,high);
		if (low > r || high < l || low>high) return;

		// complete overlap
		if (low >= l && high <= r) {
			segTree[ind] += (high - low + 1) * val;
			if (low != high) {
				lazy[2 * ind + 1] += val;
				lazy[2 * ind + 2] += val;
			}
			return;
		}
		// partial overlap
		int mid = (low + high) >> 1;
		rangeUpdate(2 * ind + 1, low, mid, l, r, val);
		rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
		segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
	}

	int query(int ind, int low, int high, int l, int r) {
		pushDown(ind,low,high);
		if (low > r || high < l || low>high) return 0;

		if (low >= l && high <= r) return segTree[ind];
		
		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return left + right;
	}
};

int main() {
	// create a segment tree for an array of size 10

	// build the segment tree using the build function
	vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	segmentTree st(arr);

	int sum = st.query(0, 0, 9, 1, 6);
	cout<<sum<<endl;
	// sum will be equal to the sum of the values in the original array: 3 + 5 + 7 + 9 + 11 + 13 = 48

	// update the value at index 3 to be 10
	st.update(0, 0, 9, 3, 10);

	// query the sum of the values in the range [1, 6]
	sum = st.query(0, 0, 9, 1, 6);
	cout<<sum<<endl;
	// sum will be equal to the sum of the values in the original array: 3 + 5 + 10 + 9 + 11 + 13 = 51

	// update the values in the range [2, 5] by 10
	st.rangeUpdate(0, 0, 9, 2, 5, 10);

	// query the sum of the values in the range [1, 6]
	sum = st.query(0, 0, 9, 1, 6);
	cout<<sum<<endl;
	// sum will be equal to the sum of the values in the original array with the updates applied: 3 + 15 + 20 + 19 + 21 + 13 = 91

	return 0;
}

