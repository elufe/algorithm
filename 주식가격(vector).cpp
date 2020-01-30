#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> v1;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	int len = prices.size();

	for (int i = 0; i < len; i++) {
		while ((!v1.empty()) && v1.back().first > prices[i]) {
			answer[v1.back().second] = i - v1.back().second;
			v1.pop_back();
		}
		v1.push_back({ prices[i],i });
	}
	while (!v1.empty()) {
		answer[v1.back().second] = len - v1.back().second - 1;
		v1.pop_back();
	}

	return answer;
}