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

typedef struct hub {
	int length;
	int hnumber;
	int first;
	hub(int a, int b, int c) {
		length = a;
		hnumber = b;
		first = c;
	}
}hb;

struct compare {
	bool operator()(hb a, hb b) {
		return a.length > b.length;
	}
};

priority_queue <hb, vector<hb>, compare> pq;

int map[201][201] = { 0 };
int map2[201][201] = { 0 };
int visit[201] = { 0 };

void find(int x);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;

	int a, b, c;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		map[a][b] = c;
		map[b][a] = c;
	}
	for(int i=1;i<=n;i++)
		find(i);
}

void find(int x) {
	int l, h, f;
	memset(visit, 0, sizeof(int) * 201);
	visit[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (map[x][i] > 0) {
			pq.push(hb(map[x][i], i, i));
		}
	}
	while (!pq.empty()) {
		l = pq.top().length;
		h = pq.top().hnumber;
		f = pq.top().first;
	//	cout << h << " " << " " << f << " " << l << "\n";
		pq.pop();
		if (visit[h] == 0) {
			map2[x][h] = f;
			visit[h] = 1;
			if (map[x][f] > 0) {
				for (int i = 1; i <= n; i++) {
					if (map[h][i] > 0 && visit[i] == 0) {
						pq.push(hb(l + map[h][i], i, f));
					}
				}
			}
		}
	}
//	cout << "\n";
	for (int i = 1; i <= n; i++) {
		if (map2[x][i] == 0)
			cout << "- ";
		else
			cout << map2[x][i] << " ";
	}
	cout << "\n";
}
