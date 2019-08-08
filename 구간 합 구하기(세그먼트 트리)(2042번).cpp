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

long long int n, m, k;

long long int input[1000001] = { 0 };

long long int *tree;

long long int add=0, cha=0;

long long int init(long long int start, long long int end, long long int index);
long long int update(long long int start, long long int end, long long int index, long long int number, long long int set);
long long int find(long long int start, long long int end, long long int index, long long int hstart, long long int hend);
long long int sub1(long long int start, long long int end, long long int index, long long int number, long long int set);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> k;

	tree = new long long int[n * 4+1]();

	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	
	init(1, n, 1);
	
	long long int a, b, c, d;
	for (long long int i = 1; i <= m + k; i++) {
		cin >> a >> b >> c;

		if (a == 1) {
			d = sub1(1, n, 1, b, c);
			update(1, n, 1, b, d);
		}
		else {
			find(1, n, 1, b, c);
			cout << add << "\n";
			add = 0;
		}
	}
	
}

long long int init(long long int start, long long int end, long long int index) {
	if (start == end) {
		return tree[index] = input[start];
	}
	else {
		long long int mid = (start + end) / 2;
		return tree[index] = init(start, mid, index * 2) + init(mid + 1, end, index * 2 + 1);
	}
}

long long int update(long long int start, long long int end, long long int index, long long int number, long long int set) {
	
	if (start <= number && end >= number) {
		tree[index] += set;
		if (start == end)
			return 0;
	}


	long long int mid = (start + end) / 2;

	if (number >= start && number <= mid) {
		return update(start, mid, index * 2, number, set);
	}
	else if (number > mid && number <= end) {
		return update(mid + 1, end, index * 2 + 1, number, set);
	}
	
}

long long int sub1(long long int start, long long int end, long long int index, long long int number, long long int set) {
	if (start == number && end == number) {
		cha = set - tree[index];
		return cha;
	}
	
	long long int mid = (start + end) / 2;

	if (number >= start && number <= mid) {
		return sub1(start, mid, index * 2, number, set);
	}
	else if (number > mid && number <= end) {
		return sub1(mid + 1, end, index * 2 + 1, number, set);
	}
}

long long int find(long long int start, long long int end, long long int index, long long int hstart, long long int hend) {
	
	if (start >= hstart && end <= hend) {
		return add += tree[index];
	}
	long long int mid = (start + end) / 2;
	if (hstart <= mid) {
		find(start, mid, index * 2, hstart, hend);
	}
	if (hend > mid) {
		find(mid + 1, end, index * 2 + 1, hstart, hend);
	}
	return 0;
}