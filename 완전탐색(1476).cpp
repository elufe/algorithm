#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main() {
	int e, s, m,year=0;
	int ec=0, sc=0, mc=0;
	cin >> e >> s >> m;
	queue<int> es, ss, ms;
	es.push(year%15+1);
	ss.push(year%28+1);
	ms.push(year%19+1);
	year++;
	while (es.front() != e || ss.front() != s || ms.front() != m) {
		es.pop();
		ss.pop();
		ms.pop();
		
		es.push(year % 15 + 1);
		ss.push(year % 28 + 1);
		ms.push(year % 19 + 1);
		year++;
	}
	cout << year;
}