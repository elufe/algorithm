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
int check[101] = { 0 };
int kcount[101] = { 0 };

queue <int> q[101];
queue <int> qbackup[101];
queue <int> q1;
queue <int> q2;

void bfs(int a);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		q[a].push(b);
		q[b].push(a);
		qbackup[a].push(b);
		qbackup[b].push(a);
	}
	int min = 5051, index = 0;
	for (int i = 1; i <= n; i++) {
		bfs(i);
		if (min > kcount[i]) {
			min = kcount[i];
			index = i;
		}
	}
	cout << index;
}

void bfs(int a) {
	int x;
	int length = 0;
	q1.push(a);
	for (int i = 1; i <= n; i++) {
		q[i] = qbackup[i];
	}
	memset(check, 0, sizeof(int)*(n + 1));

	while (!q1.empty()) {

		while (!q1.empty()) {
			x = q1.front();
			if (check[x] == 0) {
				check[x] = 1;
				kcount[a] += length;
				q2.push(x);
			}
			q1.pop();
		}
		length++;
		while (!q2.empty()) {
			x = q2.front();
			while (!q[x].empty()) {
				if (check[q[x].front()] == 0) {
					q1.push(q[x].front());
				}
				q[x].pop();
			}
			q2.pop();
		}
	}
}