#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<list>

#include<math.h>

using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long int n;
	cin >> n;

	long long int **a,**b;
	a = new long long int*[n + 1]();
	b = new long long int*[n + 1]();
	for (int i = 1; i <= n; i++) {
		a[i] = new long long int[n + 1]();
		b[i] = new long long int[n + 1]();
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	b[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == n && j == n)
				break;
			if (i + a[i][j] <= n && b[i][j]) {
				b[i + a[i][j]][j] += b[i][j];
			}
			if (j + a[i][j] <= n && b[i][j]) {
				b[i][j + a[i][j]] += b[i][j];
			}
		}
	}

	cout << b[n][n];
}

