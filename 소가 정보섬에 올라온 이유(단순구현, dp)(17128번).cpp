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

int n, m;

int	a[200001] = { 0 };

int hap[200001] = { 0 };

int add = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	hap[1] = a[1] * a[2] * a[3] * a[4];
	add += hap[1];
	for (int i = 2; i <= n; i++) {
		if (i <= n - 3) {
			hap[i] = hap[i - 1] / a[i - 1] * a[i + 3];
		}
		else {
			hap[i] = hap[i - 1] / a[i - 1] * a[i + 3 - n];
		}
		add += hap[i];
	}
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;

		for (int i = x - 3; i <= x; i++) {
			if (i < 1) {
				hap[n + i] *= -1;
				add += hap[n + i] * 2;
			}
			else {
				hap[i] *= -1;
				add += hap[i] * 2;
			}
		}

		cout << add << "\n";
	}
}

