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

int n;

int num[501] = { 0 };

int jul[101] = { 0 };

int find(int start, int end, int x);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int a, b, index=1,check=0;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		num[a] = b;
	}
	for (int i = 1; i <= 500; i++) {
		if (num[i] == 0)
			continue;
		else {
			if (jul[1] == 0) {
				jul[index++] = num[i];
			}
			else {
				check = find(1, index - 1, num[i]);
				jul[check] = num[i];
				if (index <= check)
					index = check + 1;
			}
		}

	}
	cout << n - index + 1;
}

int find(int start, int end, int x) {
	int mid = (start + end) / 2;
	
	if (x < jul[start]) {
		return start;
	}
	else if (x > jul[end]) {
		return end + 1;
	}
	else {
		if (end - start==1) {
			return end;
		}
		else {
			if (jul[mid] >= x) {
				find(start, mid, x);
			}
			else {
				find(mid + 1, end, x);
			}
		}
	}
}