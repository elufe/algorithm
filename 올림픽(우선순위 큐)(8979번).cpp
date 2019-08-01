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

struct country {
	int gold;
	int silver;
	int bronze;
	int number;
	country(int a, int b, int c, int d) {
		gold = a;
		silver = b;
		bronze = c;
		number = d;
	}
};

struct compare {
	bool operator()(country a, country b) {
		if (a.gold != b.gold)
			return a.gold < b.gold;
		if (a.silver != b.silver)
			return a.silver < b.silver;
		if (a.bronze != b.bronze)
			return a.bronze < b.bronze;
		if (a.number != b.number)
			return a.number < b.number;

	}
};

int n, m;

priority_queue <country, vector<country>, compare> pq;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	int a, b, c, d;
	for (int i = 1; i <= n; i++) {
		cin >> d >> a >> b >> c;
		pq.push(country(a, b, c, d));
	}

	int count = 0;
	int g = -1, s = -1;
	b = -1;

	int count2 = 0;

	while (1) {

		count++;
		// 공동 여려명
		if (g == pq.top().gold && s == pq.top().silver && b == pq.top().bronze) {
			count--;
			count2++;
		}
		else {
			count += count2;
			count2 = 0;
		}
		if (m == pq.top().number) {
			break;
		}
		
		g = pq.top().gold;
		s = pq.top().silver;
		b = pq.top().bronze;
		
		pq.pop();
	}
	cout << count;
}