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
	
	int k,v,e;
	int *check;
	int circle = 0;
	queue <int> *q;

	void dfs(int before, int next);

	int main() {
		cin.tie(NULL);
		ios::sync_with_stdio(false);

		cin >> k;

		int a, b;

		for (int i = 1; i <= k; i++) {
			cin >> v >> e;
			q = new queue<int>[v + 1];
			check = new int[v + 1]();
			check[0] = 1;
			int a, b;
			for (int j = 1; j <= e; j++) {
				cin >> a >> b;
				q[a].push(b);
				q[b].push(a);
			}

			for (int i = 1; i <= v; i++) {
				if(check[i]==0)
					dfs(0, i);
			}

			if (circle == 0)
				cout << "YES\n";
			else
				cout << "NO\n";
			
			circle = 0;
			delete[]q;
			delete[]check;

		}

	}

	void dfs(int before, int next) {
		check[next] = check[before]*(-1);
		
		int x;
		while (!q[next].empty()) {
			x=q[next].front();
			if (x == before) {
				q[next].pop();
				continue;
			}

			q[next].pop();
			
			if (check[x] == 0)
				dfs(next,x);
			else if (check[x] == check[next]) {
				circle = 1;
				return;
			}
		}
	}