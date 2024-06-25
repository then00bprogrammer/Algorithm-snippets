#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int sum, min, max, product;
    int lazyAdd, lazyMul;
    
    Node() : sum(0), min(INT_MAX), max(INT_MIN), product(1), lazyAdd(0), lazyMul(1) {}
};

class SegmentTree {
public:
    vector<Node> segTree;
    int n;

    SegmentTree(vector<int> &arr) {
        n = arr.size();
        segTree.resize(4 * n + 1);
        build(0, 0, n - 1, arr);
    }

    void build(int ind, int low, int high, vector<int> &arr) {
        if (low == high) {
            segTree[ind].sum = segTree[ind].min = segTree[ind].max = segTree[ind].product = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        merge(ind);
    }

    void merge(int ind) {
        segTree[ind].sum = segTree[2 * ind + 1].sum + segTree[2 * ind + 2].sum;
        segTree[ind].min = min(segTree[2 * ind + 1].min, segTree[2 * ind + 2].min);
        segTree[ind].max = max(segTree[2 * ind + 1].max, segTree[2 * ind + 2].max);
        segTree[ind].product = segTree[2 * ind + 1].product * segTree[2 * ind + 2].product;
    }

    void pushDown(int ind, int low, int high) {
        if (segTree[ind].lazyMul != 1) {
            segTree[ind].sum *= segTree[ind].lazyMul;
            segTree[ind].min *= segTree[ind].lazyMul;
            segTree[ind].max *= segTree[ind].lazyMul;
            segTree[ind].product *= segTree[ind].lazyMul;

            if (low != high) {
                segTree[2 * ind + 1].lazyMul *= segTree[ind].lazyMul;
                segTree[2 * ind + 2].lazyMul *= segTree[ind].lazyMul;
                segTree[2 * ind + 1].lazyAdd *= segTree[ind].lazyMul;
                segTree[2 * ind + 2].lazyAdd *= segTree[ind].lazyMul;
            }
            segTree[ind].lazyMul = 1;
        }

        if (segTree[ind].lazyAdd != 0) {
            segTree[ind].sum += (high - low + 1) * segTree[ind].lazyAdd;
            segTree[ind].min += segTree[ind].lazyAdd;
            segTree[ind].max += segTree[ind].lazyAdd;
            segTree[ind].product += (high - low + 1) * segTree[ind].lazyAdd;

            if (low != high) {
                segTree[2 * ind + 1].lazyAdd += segTree[ind].lazyAdd;
                segTree[2 * ind + 2].lazyAdd += segTree[ind].lazyAdd;
            }
            segTree[ind].lazyAdd = 0;
        }
    }

    void rangeUpdateAdd(int ind, int low, int high, int l, int r, int val) {
        pushDown(ind, low, high);
        if (low > r || high < l || low > high) return;

        if (low >= l && high <= r) {
            segTree[ind].lazyAdd += val;
            pushDown(ind, low, high);
            return;
        }
        int mid = (low + high) >> 1;
        rangeUpdateAdd(2 * ind + 1, low, mid, l, r, val);
        rangeUpdateAdd(2 * ind + 2, mid + 1, high, l, r, val);
        merge(ind);
    }

    void rangeUpdateMul(int ind, int low, int high, int l, int r, int val) {
        pushDown(ind, low, high);
        if (low > r || high < l || low > high) return;

        if (low >= l && high <= r) {
            segTree[ind].lazyMul *= val;
            pushDown(ind, low, high);
            return;
        }
        int mid = (low + high) >> 1;
        rangeUpdateMul(2 * ind + 1, low, mid, l, r, val);
        rangeUpdateMul(2 * ind + 2, mid + 1, high, l, r, val);
        merge(ind);
    }

    int querySum(int ind, int low, int high, int l, int r) {
        pushDown(ind, low, high);
        if (low > r || high < l || low > high) return 0;

        if (low >= l && high <= r) return segTree[ind].sum;

        int mid = (low + high) >> 1;
        return querySum(2 * ind + 1, low, mid, l, r) + querySum(2 * ind + 2, mid + 1, high, l, r);
    }

    int queryMin(int ind, int low, int high, int l, int r) {
        pushDown(ind, low, high);
        if (low > r || high < l || low > high) return INT_MAX;

        if (low >= l && high <= r) return segTree[ind].min;

        int mid = (low + high) >> 1;
        return min(queryMin(2 * ind + 1, low, mid, l, r), queryMin(2 * ind + 2, mid + 1, high, l, r));
    }

    int queryMax(int ind, int low, int high, int l, int r) {
        pushDown(ind, low, high);
        if (low > r || high < l || low > high) return INT_MIN;

        if (low >= l && high <= r) return segTree[ind].max;

        int mid = (low + high) >> 1;
        return max(queryMax(2 * ind + 1, low, mid, l, r), queryMax(2 * ind + 2, mid + 1, high, l, r));
    }
};

signed main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    SegmentTree st(arr);

    int sum = st.querySum(0, 0, 9, 1, 6);
    cout << sum << endl;

    st.rangeUpdateAdd(0, 0, 9, 2, 5, 10);
    sum = st.querySum(0, 0, 9, 1, 6);
    cout<< sum << endl;

    st.rangeUpdateMul(0, 0, 9, 2, 5, 2);
    sum = st.querySum(0, 0, 9, 1, 6);
    cout << sum << endl;

    int min = st.queryMin(0, 0, 9, 1, 6);
    cout << min << endl;

    int max = st.queryMax(0, 0, 9, 1, 6);
    cout << max << endl;

    return 0;
}
