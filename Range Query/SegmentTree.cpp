#include <bits/stdc++.h>

using namespace std;

struct Node {
    int sum;
    
    Node() {
        sum = 0;
    }
};

class SegmentTree {
public:
    vector<Node> segTree;
    vector<int> lazy;

    SegmentTree(vector<int> &arr) {
        int n = arr.size();
        segTree.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
        build(0, 0, n - 1, arr);
    }

    void build(int ind, int low, int high, vector<int> &arr) {
        if (low == high) {
            segTree[ind].sum = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        segTree[ind].sum = segTree[2 * ind + 1].sum + segTree[2 * ind + 2].sum;
    }

    void pushDown(int ind, int low, int high) {
        if (lazy[ind] != 0) {
            segTree[ind].sum += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
    }

    void update(int ind, int low, int high, int i, int val) {
        pushDown(ind, low, high);
        if (low == high) {
            segTree[ind].sum = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid) {
            update(2 * ind + 1, low, mid, i, val);
        }
        else {
            update(2 * ind + 2, mid + 1, high, i, val);
        }
        segTree[ind].sum = segTree[2 * ind + 1].sum + segTree[2 * ind + 2].sum;
    }

    void rangeUpdate(int ind, int low, int high, int l, int r, int val) {
        pushDown(ind, low, high);
        if (low > r || high < l || low > high) return;

        if (low >= l && high <= r) {
            segTree[ind].sum += (high - low + 1) * val;
            if (low != high) {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        int mid = (low + high) >> 1;
        rangeUpdate(2 * ind + 1, low, mid, l, r, val);
        rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
        segTree[ind].sum = segTree[2 * ind + 1].sum + segTree[2 * ind + 2].sum;
    }

    int query(int ind, int low, int high, int l, int r) {
        pushDown(ind, low, high);
        if (low > r || high < l || low > high) return 0;

        if (low >= l && high <= r) return segTree[ind].sum;

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    SegmentTree st(arr);

    int sum = st.query(0, 0, 9, 1, 6);
    cout << sum << endl;

    st.update(0, 0, 9, 3, 10);
    sum = st.query(0, 0, 9, 1, 6);
    cout << sum << endl;

    st.rangeUpdate(0, 0, 9, 2, 5, 10);
    sum = st.query(0, 0, 9, 1, 6);
    cout << sum << endl;

    return 0;
}
