#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << binpow(a, b) << endl;
    return 0;
}
