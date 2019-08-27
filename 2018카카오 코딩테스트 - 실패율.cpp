#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	priority_queue<pair<double, int>> q;
	int *p = new int[N + 2]();
	int count = 0;
	while (!stages.empty()) {
		count++;
		p[stages[0]]++;
		stages.erase(stages.begin());
	}
	for (int i = 1; i <= N; i++) {
		q.push({ p[i] / (double)count,-i });
		count -= p[i];
	}
	while (!q.empty()) {
		answer.push_back(-q.top().second);
		q.pop();
	}

	return answer;
}