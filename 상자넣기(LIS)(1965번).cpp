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

int box[1001] = { 0 };

int find(int start, int end, int x);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int index = 1, check, x;

	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (box[1] == 0) {
			box[index++] = x;
		}
		else {
			check = find(1, index - 1, x);
			box[check] = x;
			if (index <= check)
				index = check + 1;
		}
	}
	cout << index - 1;
}

int find(int start, int end, int x) {
	int mid = (start + end) / 2;
	
	if (end == start) {
		if (x <= box[start])
			return start;
		else
			return end + 1;
	}
	else {
		if (end - start == 1) {
			if (x <= box[start])
				return start;
			else if (x <= box[end])
				return end;
			else
				return end + 1;
		}
		if (box[mid] >= x)
			find(start, mid, x);
		else
			find(mid + 1, end, x);
	}

}