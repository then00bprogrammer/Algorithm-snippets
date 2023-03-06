#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int bit[N];

void update(int i, int x){
	for(; i < N; i += (i&-i))
		bit[i] += x;
}

int sum(int i){
	int ans = 0;
	for(; i > 0; i -= (i&-i))
		ans += bit[i];
	return ans;
}

int main(){
	// Read in the size of the array and the elements.
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		update(i, x);
	}

	// Find the sum of the first 10 elements.
	cout << sum(10) << endl;

	// Find the sum of the elements from index 3 to index 6.
	cout << sum(6) - sum(2) << endl;

	// Find the sum of all the elements in the array.
	cout << sum(n) << endl;

	return 0;
}
