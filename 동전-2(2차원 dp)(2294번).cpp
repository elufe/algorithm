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

int dp[101][10002] = { 0 };

int *input;

int min1(int a, int b) {
	return a < b ? a : b;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	input = new int[n]();

	for (int i = 1; i <= n; i++) {
		cin >> input[i-1];
	}

	sort(input, input + n);
	// 작은 순서대로 동전가치 입력
	for (int i = 1; i <= n; i++) {
		dp[i][0] = input[i - 1];
	}


	// 첫번째 동전을 이용한 갯수 채우기
	for (int i = 2; i <= k + 1; i++) {
		if ((i - 1) % dp[1][0] == 0) {
			dp[1][i] = (i - 1) / dp[1][0];
		}
		else {
			dp[1][i] = -1;
		}
	}

	// 나머지 배열 채우기
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k + 1; j++) {
			if ((j - 1) / dp[i][0] > 0) {
				if (dp[i][j - dp[i][0]] > -1) {
					if(dp[i - 1][j]>0)
						dp[i][j] = min1(dp[i - 1][j], dp[i][j - dp[i][0]]+1);
					else
						dp[i][j] =dp[i][j - dp[i][0]] + 1;
				}
				else
					dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	   
	cout << dp[n][k + 1];
}

