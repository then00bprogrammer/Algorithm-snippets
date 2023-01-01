#include <bits/stdc++.h>
using namespace std;

vector<int> find_prime_factors(int n) {
    vector<int> factors;
    int i = 2;
    while (i <= n) {
        if (n % i == 0) {
            factors.push_back(i);
            n /= i;
        } else {
            i++;
        }
    }
    return factors;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<int> factors = find_prime_factors(n);
    cout << "The prime factors of " << n << " are:";
    for (int factor : factors) {
        cout << " " << factor;
    }
    cout << endl;
}
