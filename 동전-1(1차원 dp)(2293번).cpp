#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<cstring>
#include<string.h>
#include<list>
#include<math.h>

using namespace std;

int n, k;

int dp[10001] = { 1 };

int *input;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	input = new int[n]();

	for (int i = 1; i <= n; i++) {
		cin >> input[i-1];
	}

	sort(input, input + n);


	for (int i = 0; i <n; i++) {
		for (int j = 0; j <= k; j++) {
			if (i == 0) {
				if (j%input[i] == 0)
					dp[j] = 1;
			}
			else if (j + input[i] <= k) {
				dp[j + input[i]] += dp[j];
			}
		}
	}

	cout << dp[k];
}

