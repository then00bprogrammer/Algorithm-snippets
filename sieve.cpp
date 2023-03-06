#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int spf[N];

vector<int> prime_factors;

void sieve(int n) {
	spf[1] = 1;
	for (int i=2; i<N; i++) spf[i] = i;

	for (int i=4; i<N; i+=2)
		spf[i] = 2;

	for (int i=3; i*i<N; i++)
	{
		if (spf[i] == i)
		{
			for (int j=i*i; j<N; j+=i)
				if (spf[j]==j)
					spf[j] = i;
		}
	}
}

void find_prime_factors(int n) {
  int x = n;
  while (x != 1) {
    prime_factors.push_back(spf[x]);
    x /= spf[x];
  }
}

int main() {
  sieve(100);  // Find the smallest prime factor of all numbers from 2 to 100

  find_prime_factors(100);  // Find the prime spf of 100

  // Print the prime spf
  for (int i = 0; i < prime_factors.size(); i++) {
    cout << prime_factors[i] << " ";
  }
  cout << endl;

  return 0;
}
