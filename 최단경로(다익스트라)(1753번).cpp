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
	
	int n, m, k;

	queue<int> q[20001][2];
	priority_queue < pair<int,int>> pq;
	
	
	int main() {
		cin.tie(NULL);
		ios::sync_with_stdio(false);
		
		cin >> n >> m >> k;

		int *length;
		int *check;
		int x,y,z;

		length = new int[n + 1]();
		check = new int[n + 1]();

		for (int i = 0; i < m; i++) {
			cin >> x >> y >> z;
			q[x][0].push(y);
			q[x][1].push(z);
		}

		while (!q[k][0].empty()) {
			pq.push({ q[k][1].front()*(-1), q[k][0].front() });
			q[k][0].pop();
			q[k][1].pop();
//			cout << pq.top().first <<" "<<pq.top().second;
		}

		check[k] = 1;
		int dot, weight;
		while (!pq.empty()) {
			dot = pq.top().second;
			weight = pq.top().first * (-1);
//			cout << dot << " " << weight << "\n";
			if (check[dot] == 0 || check[dot] > 0 && length[dot] > weight) {
				length[dot] = weight;
				check[dot] = 1;
			}
			pq.pop();
			while (!q[dot][0].empty()) {
				pq.push({ (q[dot][1].front() + weight)*(-1), q[dot][0].front() });
				q[dot][0].pop();
				q[dot][1].pop();
			}
			
		}
		for (int i = 1; i <= n; i++) {
			if (check[i] == 1)
				cout << length[i] << "\n";
			else
				cout << "INF\n";
		}
	}
