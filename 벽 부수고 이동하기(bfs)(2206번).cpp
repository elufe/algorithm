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
	int x;
	int y;
	int wallcheck;
	int length;
	node(int a, int b, int c, int d) {
		x = a;
		y = b;
		wallcheck = c;
		length = d;
	}
};

queue<node>q;

int n, m;

int min1 = 2100000000;

int pan[1001][1001] = { 0 };

int check[1001][1001] = { 0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	char input;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> input;
			pan[i][j] = input - '0';
		}
	}
	q.push(node(1, 1, 0, 1));
	check[1][1] = 3;
	int x, y, wc, l;

	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		wc = q.front().wallcheck;
		l = q.front().length;
		
		q.pop();
		if (x == n && y == m) {
			min1 = l;
			break;
		}

		if (wc == 0) {
			if (x + 1 <= n && pan[x + 1][y] == 0 && check[x + 1][y] == 0 ) {
				q.push(node(x + 1, y, 0, l + 1));
				check[x + 1][y] = 1;
			}
			else if (x + 1 <= n && pan[x + 1][y] == 0 && check[x + 1][y] == 2) {
				q.push(node(x + 1, y, 0, l + 1));
				check[x + 1][y] = 3;
			}
			if (x - 1 > 0 && pan[x - 1][y] == 0 && check[x - 1][y] == 0) {
				q.push(node(x - 1, y, 0, l + 1));
				check[x - 1][y] = 1;
			}
			else if (x - 1 > 0 && pan[x - 1][y] == 0 && check[x - 1][y] == 2) {
				q.push(node(x - 1, y, 0, l + 1));
				check[x - 1][y] = 3;
			}
			if (y + 1 <= m && pan[x][y + 1] == 0 && check[x][y + 1] == 0) {
				q.push(node(x, y + 1, 0, l + 1));
				check[x][y + 1] = 1;
			}
			else if (y + 1 <= m && pan[x][y + 1] == 0 && check[x][y + 1] == 2) {
				q.push(node(x, y + 1, 0, l + 1));
				check[x][y + 1] = 3;
			}
			if (y - 1 > 0 && pan[x][y - 1] == 0 && check[x][y - 1] == 0) {
				q.push(node(x, y - 1, 0, l + 1));
				check[x][y - 1] = 1;
			}
			else if (y - 1 > 0 && pan[x][y - 1] == 0 && check[x][y - 1] == 2) {
				q.push(node(x, y - 1, 0, l + 1));
				check[x][y - 1] = 3;
			}

			if (x + 1 <= n && pan[x + 1][y] == 1 && check[x + 1][y] == 0) {
				q.push(node(x + 1, y, 1, l + 1));
				check[x + 1][y] = 1;
			}
			if (x - 1 > 0 && pan[x - 1][y] == 1 && check[x - 1][y] == 0) {
				q.push(node(x - 1, y, 1, l + 1));
				check[x - 1][y] = 1;
			}
			if (y + 1 <= m && pan[x][y + 1] == 1 && check[x][y + 1] == 0) {
				q.push(node(x, y + 1, 1, l + 1));
				check[x][y + 1] = 1;
			}
			if (y - 1 > 0 && pan[x][y - 1] == 1 && check[x][y - 1] == 0) {
				q.push(node(x, y - 1, 1, l + 1));
				check[x][y - 1] = 1;
			}
			
		}
		else {
			if (x + 1 <= n && pan[x + 1][y] == 0 && check[x + 1][y] == 0) {
				q.push(node(x + 1, y, 1, l + 1));
				check[x + 1][y] = 2;
			}
			else if (x + 1 <= n && pan[x + 1][y] == 0 && check[x + 1][y] == 1) {
				q.push(node(x + 1, y, 1, l + 1));
				check[x + 1][y] = 3;
			}
			if (x - 1 > 0 && pan[x - 1][y] == 0 && check[x - 1][y] == 0) {
				q.push(node(x - 1, y, 1, l + 1));
				check[x - 1][y] = 2;
			}
			else if (x - 1 > 0 && pan[x - 1][y] == 0 && check[x - 1][y] == 1) {
				q.push(node(x - 1, y, 1, l + 1));
				check[x - 1][y] = 3;
			}
			if (y + 1 <= m && pan[x][y + 1] == 0 && check[x][y + 1] == 0) {
				q.push(node(x, y + 1, 1, l + 1));
				check[x][y + 1] = 2;
			}
			else if (y + 1 <= m && pan[x][y + 1] == 0 && check[x][y + 1] == 1) {
				q.push(node(x, y + 1, 1, l + 1));
				check[x][y + 1] = 3;
			}
			if (y - 1 > 0 && pan[x][y - 1] == 0 && check[x][y - 1] == 0) {
				q.push(node(x, y - 1, 1, l + 1));
				check[x][y - 1] = 2;
			}
			else if (y - 1 > 0 && pan[x][y - 1] == 0 && check[x][y - 1] == 1) {
				q.push(node(x, y - 1, 1, l + 1));
				check[x][y - 1] = 3;
			}
		}
	}
	if (min1 > 210000000)
		cout << "-1";
	else
		cout << min1;
}

