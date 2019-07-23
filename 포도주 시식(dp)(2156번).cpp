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
	int n;
	cin >> n;

	int a[10001] = { 0 };
	int max[10001] = { 0 };
	int count=0;
	int case1 = 0, case2 = 0, case3 = 0;
	
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i <= 2) {
				max[i] += max[i - 1] + a[i];
			}
			else {
				case1 = max[i - 3] + a[i - 1] + a[i];
				case2 = max[i - 2] + a[i];
				case3 = max[i - 1];
				if (case1 >= case2 && case1 >= case3) {
					max[i] = case1;
					count = 2;
				}
				else if (case2 >= case1 && case2 >= case3) {
					max[i] = case2;
					count = 1;
				}
				else{
					max[i] = case3;
					count = 0;
				}
			}
		}
		cout << max[n];
}

