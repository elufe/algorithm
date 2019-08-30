#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

typedef unsigned long long ll;

using namespace std;

bool compare1(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first > b.first;
}

bool compare2(pair<ll, ll> a, pair<ll, ll> b) {
	return a.second < b.second;
}

long long solution(vector<int> food_times, long long k) {

	vector<pair<long long, long long>>v;
	long long answer = 0;
	ll n = 0, size = food_times.size();
	long long backup = -1, temp = -1;
	ll time = 0;
	long long min = 100000001, max = -1;
	while (n < size) {
		v.push_back({ food_times[n],++n });
		if (min > food_times[n - 1])
			min = food_times[n - 1];
		if (max < food_times[n - 1])
			max = food_times[n - 1];
	}
	if (max * size <= k)
		answer = -1;
	else if (min * size <= k) {

		sort(v.begin(), v.end(), compare1);
		n = 0;
		// long long index=0;    
		while (!v.empty()) {
			backup = temp;
			temp = v[size - 1].first;
			if (backup == -1) {

				if (k >= temp * size)
					k -= temp * size;
				else
					break;

			}
			else {
				if (k >= (temp - backup)*size)
					k -= (temp - backup)*size;
				else
					break;

			}

			v.pop_back();
			size--;
		}

		if (v.empty())
			answer = -1;
		else {
			sort(v.begin(), v.end(), compare2);
			answer = v[k%size].second;

		}
	}
	else {
		answer = k % size + 1;
	}
	return answer;
}
