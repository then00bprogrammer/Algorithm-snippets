#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

bool is_prime[N];
vector<int> primes;

void sieve(int n) {
  memset(is_prime, true, sizeof(is_prime));  // Set all values to true
  is_prime[0] = is_prime[1] = false;  // 0 and 1 are not prime

  // Check all numbers up to sqrt(n)
  for (int i = 2; i <= n; i++) {
    // If i is prime
    if (is_prime[i]) {
      // Mark all of its multiples as non-prime
      for (int j = 2* i; j <= n; j += i) {
        is_prime[j] = false;
      }
      primes.push_back(i);  // Add i to the list of primes
    }
  }
}

int main() {
  sieve(1000000);  // Generate all primes up to 1 million

  // Print the first 20 primes
  for (int i = 0; i < 20; i++) {
    cout << primes[i] << " ";
  }
  cout << endl;

  return 0;
}
