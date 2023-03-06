#include <bits/stdc++.h>
using namespace std;

class segmentTree {
public:
	vector<int> segTree;
	segmentTree(int n) {
		segTree.resize(4 * n + 1,0);
	}
	void build(int ind, int low, int high, vector<int> &arr) {
		if (low == high) {
			segTree[ind] +=1;
			return;
		}
		int mid = low + (high - low) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
	}
	void update(int ind, int low, int high, int i) {
		if (low == high) {
			segTree[ind] += 1;
			return;
		}
		int mid = (low + high) >> 1;
		if (i <= mid) {
			update(2 * ind + 1, low, mid, i);
		}
		else {
			update(2 * ind + 2, mid + 1, high, i);
		}
		segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
	}

	int order(int ind, int low, int high, int l, int r) {
		if (low > r || high < l) {
			return 0;
		}
		if (low >= l && high <= r) {
			return segTree[ind];
		}
		int mid = low + (high- low)/2;
		int left = order(2 * ind + 1, low, mid, l, r);
		int right = order(2 * ind + 2, mid + 1, high, l, r);
		return left + right;
	}
	int kth_smallest(int ind, int low, int high, int k) {
		if (low == high) {
			return low;
		}
		int mid = (low + high) >> 1;
		int left_sum = segTree[2*ind+1];
		return (k <= left_sum) ? kth_smallest(2 * ind + 1, low, mid, k)
							   : kth_smallest(2 * ind + 2, mid+1, high, k-left_sum);
	}
};

int main() {

    vector<int> arr = {1, 3, 2, 4, 50, 7, 6, 8};
    segmentTree segtree(arr.size());

    for(int i =0;i<arr.size();i++){
        segtree.update(0, 0, arr.size()-1, arr[i]);
    }
    // kth smallest element
    int kth = segtree.kth_smallest(0, 0, arr.size()-1, 5);
    cout<<"Kth smallest element in array is: "<<kth<<endl;

    // count of element <= 5
    int ans = segtree.order(0, 0, arr.size()-1, 0, 5);
    cout<<"Count of elements less than 5: "<<ans<<endl;
    return 0;
}

