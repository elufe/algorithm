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

struct tree {
	int c;
	int x;
	int y;
	tree(int c, int x, int y) {
		this->c = c;
		this->x = x;
		this->y = y;
	}
};

struct compare {
	bool operator()(tree a, tree b) {
		if (a.c != b.c)
			return a.c<b.c;
		if (a.x != b.x)
			return a.x < b.x;
		if (a.c != b.c)
			return a.y < b.y;
	}
};

priority_queue<tree, vector<tree>, compare> pq;

int n;
int **forest;
int **length;//길이 입력
int max1 = 0;

int dp(int x, int y, int l);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	forest = new int*[n + 1];
	length = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		forest[i] = new int[n + 1]();
		length[i] = new int[n + 1]();
	}
	int x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x;
			forest[i][j] = x;
			pq.push(tree(x, i, j));
		}
	}
	int aaa;
	while (!pq.empty()) {
		aaa = dp(pq.top().x, pq.top().y, 1);
		if (max1 < aaa)
			max1 = aaa;
		pq.pop();
	}
	cout << max1;
	
}

int dp(int x, int y, int l) {
	int a = 0, b = 0, c = 0, d = 0;


	if (x + 1 <= n && forest[x][y] < forest[x + 1][y]) {
		a = length[x + 1][y];
	}
	if (x - 1 > 0 && forest[x][y] < forest[x - 1][y]) {
		b = length[x - 1][y];
	}
	if (y + 1 <= n && forest[x][y] < forest[x][y + 1]) {
		c = length[x][y + 1];
	}
	if (y - 1 > 0 && forest[x][y] < forest[x][y - 1]) {
		d = length[x][y - 1];
	}

	if (a >= b && a >= c && a >= d) {
		l += a;
	}
	else if (b >= c && b >= d && b >= a) {
		l += b;
	}
	else if (c >= a && c >= b && c >= d) {
		l += c;
	}
	else if (d >= a && d >= b && d >= c) {
		l += d;
	}
	length[x][y] = l;
	return l;
}
