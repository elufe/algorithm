#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int cweights = 0;   // ���� �ٸ����� �ִ� Ʈ������ �� ����
	reverse(truck_weights.begin(), truck_weights.end());

	queue<int> w;
	for (int i = 0; i < bridge_length; i++)    //�ʱ���� -> �ٸ����� ���԰� 0�� Ʈ������ �� �ִٰ� ����
		w.push(0);

	while (cweights > 0 || !truck_weights.empty()) {

		cweights -= w.front();          //�� ���� Ʈ���� �ٸ��� ��������
		w.pop();
		answer++;

		if (cweights + truck_weights.back() <= weight && (!truck_weights.empty())) {    //Ʈ���� ���Ը� 
			cweights += truck_weights.back();                                       //���� �ٸ���
			w.push(truck_weights.back());                                           //�ٸ��� �ø�
			truck_weights.pop_back();
		}
		else                //Ʈ���� ���Զ����� Ʈ���� ���ö󰡴� ���
			w.push(0);

	}


	return answer;
}