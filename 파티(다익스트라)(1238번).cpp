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

int n, m, x;

struct person {
	int length;
	int number;
	person(int a, int b) {
		length = a;
		number = b;
	}
};

struct compare {
	bool operator()(person a, person b) {
		return a.length > b.length;
	}
};

priority_queue<person, vector<person>, compare> pq;

vector<pair<int, int>> *v;

int find(int start, int end);
int visit[1001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> x;

	v = new vector<pair<int, int>>[n + 1];

	int a, b, c;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
	}
	int max1 = -1;
	int lll = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x)
			continue;
		lll = find(i, x) + find(x, i);
		if (max1 < lll)
			max1 = lll;
	}
	cout << max1;
}

int find(int start, int end) {
	memset(visit, 0, sizeof(int) * 1001);
	while (!pq.empty())
		pq.pop();

	visit[start] = 1;
	for (int i = 0; i < v[start].size(); i++) {
		pq.push(person(v[start][i].first, v[start][i].second));
	}
	int l, p;
	while (!pq.empty()) {
		l = pq.top().length;
		p = pq.top().number;
		pq.pop();
		if (visit[p] == 1)
			continue;
		else
			visit[p] = 1;
		if (p == end) {
			return l;
		}
		for (int i = 0; i < v[p].size(); i++) {
			if(visit[v[p][i].second]==0)
				pq.push(person(v[p][i].first + l, v[p][i].second));
		}
	}
	return -1;
}