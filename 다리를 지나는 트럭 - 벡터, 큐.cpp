#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int cweights = 0;   // 현재 다리위에 있는 트럭들의 총 무게
	reverse(truck_weights.begin(), truck_weights.end());

	queue<int> w;
	for (int i = 0; i < bridge_length; i++)    //초기상태 -> 다리위에 무게가 0인 트럭들이 다 있다고 가정
		w.push(0);

	while (cweights > 0 || !truck_weights.empty()) {

		cweights -= w.front();          //맨 앞의 트럭이 다리를 빠져나감
		w.pop();
		answer++;

		if (cweights + truck_weights.back() <= weight && (!truck_weights.empty())) {    //트럭의 무게를 
			cweights += truck_weights.back();                                       //비교후 다리에
			w.push(truck_weights.back());                                           //다리에 올림
			truck_weights.pop_back();
		}
		else                //트럭의 무게때문에 트럭이 못올라가는 경우
			w.push(0);

	}


	return answer;
}