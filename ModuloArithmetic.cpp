#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll MOD = 1e9 + 7;

ll bin_pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll mod_pow(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

ll mod_add(ll a, ll b) {
    ll sum = (a + b) % MOD;
    sum = (sum + MOD) % MOD;
    return sum;
}

ll mod_fact(ll n)
{
    ll ans=1;
    for(ll i=2;i<=n;i++)
      ans=((ans%MOD)*(i%MOD)+MOD)%MOD;
    ans = (ans + MOD) % MOD;
    return ans;
}

ll mod_nCr(ll n, ll r) {
    ll ri = mod_pow(mod_fact(r), MOD-2);
    ll nri = mod_pow(mod_fact(n-r), MOD-2);
    ll ans = ((mod_fact(n) % MOD) * (ri % MOD) * (nri % MOD)) % MOD;
    ans = (ans + MOD) % MOD;
    return ans;
}

ll n_factorial_with_divisors(ll n, vector<ll>& divisors)
{
    ll ans = 1;
    for(ll i=0; i<divisors.size(); i++) {
        ans = (ans * mod_pow(mod_fact(divisors[i]), MOD-2)) % MOD;
    }
    ans = (ans * mod_fact(n)) % MOD;
    for(ll i=0; i<divisors.size(); i++) 
        ans = (ans * mod_pow(mod_fact(divisors[i]), MOD-2)) % MOD;
    
    ans = (ans + MOD) % MOD;
    return ans;
}

