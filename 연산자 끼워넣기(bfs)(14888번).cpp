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

struct node {
	int index;
	int result;
	int add, sub, mul, div;
	node(int a, int b, int c, int d, int e, int f) {
		index = a;
		result = b;
		add = c;
		sub = d;
		mul = e;
		div = f;
	}
};

queue<node> q;

int n;

int num[12] = { 0 };
int oper[4] = { 0 };

int min1 = 1000000001, max1 = -1000000001;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	cin >> oper[0];
	cin >> oper[1];
	cin >> oper[2];
	cin >> oper[3];

	q.push(node(1, num[1], 0, 0, 0, 0));

	int in=0, r=0, a=0, s=0, m=0, d=0;

	while (!q.empty()) {
		in = q.front().index;
		r = q.front().result;
		a = q.front().add;
		s = q.front().sub;
		m = q.front().mul;
		d = q.front().div;

		q.pop();

		if (in == n) {
			if (min1 > r) {
				min1 = r;
			}
			if (max1 < r) {
				max1 = r;
			}
		}
		
		if (a < oper[0]) {
			q.push(node(in + 1, r + num[in + 1], a + 1, s, m, d));
		}
		if (s < oper[1]) {
			q.push(node(in + 1, r - num[in + 1], a, s + 1, m, d));
		}
		if (m < oper[2]) {
			q.push(node(in + 1, r * num[in + 1], a, s, m + 1, d));
		}
		if (d < oper[3]) {
			q.push(node(in + 1, r / num[in + 1], a, s, m, d + 1));
		}

	}
	cout << max1 << "\n" << min1;
}

