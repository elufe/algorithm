#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<string>

#include<math.h>

using namespace std;

void dfs(int v, int **p, int *check);
void bfs(int v, int **p, int *check2);

int n, m;
queue<int> q;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int v, a, b;
	int **p, *check, *check2;

	cin >> n >> m >> v;
	
	p = new int *[n+1];
	for (int i = 1; i <= n; i++) {
		p[i] = new int[n+1]();
	}

	check = new int[n + 1]();
	check2 = new int[n + 1]();

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		p[a][b] = 1;
		p[b][a] = 1;
	}
	
	check[v] = 1;
	dfs(v, p, check);
	cout << "\n";
	bfs(v, p, check2);

}

void dfs(int v, int **p, int *check) {

	cout << v<< " ";
	for (int i = 1; i <= n; i++) {
		if (p[v][i] == 1 && check[i] !=1) {
			check[i]=1;
			dfs(i, p, check);
		}
	}
}

void bfs(int v, int **p, int *check2) {
	q.push(v);
	int length = 0;
	while (!q.empty() && length<n) {
		for (int i = 1; i <= n; i++) {
			if (p[v][i] == 1 && check2[i] != 1) {
				q.push(i);
			}
		}
		while (!q.empty() && check2[q.front()] == 1)
			q.pop();
		if (!q.empty()) {
			v = q.front();
			cout << v << " ";
			check2[v] = 1;
			q.pop();
			length++;
		}
	}
}