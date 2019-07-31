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
	
	int n;
	int root;
	int rootcheck[10001] = { 1 };
	int level[10001][2] = { 0 };
	queue <int> ql[10001];
	queue <int> qr[10001];
	
	int num = 1;

	void dfs(int root, int level);

	int main() {
		cin.tie(NULL);
		ios::sync_with_stdio(false);

		cin >> n;
		int p, l, r;
		for (int i = 1; i <= n; i++) {
			cin >> p >> l >> r;
			if (l != -1) {
				ql[p].push(l);
				rootcheck[l] = 1;
			}
			if (r != -1) {
				qr[p].push(r);
				rootcheck[r] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (rootcheck[i] == 0) {
				root = i;
				break;
			}
		}
		dfs(root, 1);
		int max = 0, index = 0;
		for (int i = 1; i <= 10000; i++) {
			if (level[i][1] - level[i][0] > max) {
				max = level[i][1] - level[i][0];
				index = i;
			}
		}
		if (max == 0)
			cout << root << " " << "1";
		else
			cout << index << " " << max+1;

	}
	void dfs(int root, int lev) {
		if (!ql[root].empty()) {
			dfs(ql[root].front(), lev + 1);
		}

		if (level[lev][0] == 0 || level[lev][0] > num) {
			level[lev][0] = num;
		}
		if (level[lev][1] == 0 || level[lev][1] < num) {
			level[lev][1] = num;
		}
		num++;

		if (!qr[root].empty()) {
			dfs(qr[root].front(), lev + 1);
		}
	}