#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int factors[N];
vector<int> prime_factors;

void sieve(int n) {
  // Initialize all elements of factors to 0
  memset(factors, 0, sizeof(factors));

  // Set factors[i] to i for all i from 2 to n
  for (int i = 2; i <= n; i++) {
    factors[i] = i;
  }

  // Set factors[i] to the smallest prime factor of i for all i from 2 to n
  for (int i = 2; i <= n; i++) {
    // If i is prime, skip it
    if (factors[i] == i) {
      // Set the smallest prime factor of all multiples of i to i
      for (int j = i * i; j <= n; j += i) {
        if (factors[j] == j) factors[j] = i;
      }
    }
  }
}

void find_prime_factors(int n) {
  int x = n;
  while (x != 1) {
    prime_factors.push_back(factors[x]);
    x /= factors[x];
  }
}

int main() {
  sieve(100);  // Find the smallest prime factor of all numbers from 2 to 100

  find_prime_factors(100);  // Find the prime factors of 100

  // Print the prime factors
  for (int i = 0; i < prime_factors.size(); i++) {
    cout << prime_factors[i] << " ";
  }
  cout << endl;

  return 0;
}
