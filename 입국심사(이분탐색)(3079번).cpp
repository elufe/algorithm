#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<string>

#include<math.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long int n, m, x=0, *t;
	long long int max = 0;

	cin >> n >> m;
	t = new long long int[n]();
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		if (max <= t[i])
			max = t[i];
	}
	
	long long int sum = 0;

	long long int start = 1, last = max*m,k;
	
	while (1) {
		if (start == last) {
			cout << last;
			return 0;
		}
		k = (start + last) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += (k / t[i]);
		}
		if (sum < m) {
			start = k+1;

		}
		else {
			last = k;
		}
		
	}
}

