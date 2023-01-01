#include<bits/stdc++.h>
using namespace std;

int main() {
    // input data
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // preprocessing
    int len = (int) sqrt(n + .0) + 1; // size of the block and the number of blocks
    vector<int> b(len);
    for (int i = 0; i < n; i++) {
        b[i / len] += a[i];
    }

    // answering the queries
    for (;;) {
        int l, r;
        // read input data for the next query
        cin >> l >> r;
        int sum = 0;
        for (int i = l; i <= r; ) {
            if (i % len == 0 && i + len - 1 <= r) {
                // if the whole block starting at i belongs to [l, r]
                sum += b[i / len];
                i += len;
            } else {
                sum += a[i];
                ++i;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
