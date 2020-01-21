#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
	string answer = "";
	string pasing = "";
	int tcount = 0, pcount = 1;
	int num = 1, temp = 0;

	if (p == 1) {
		answer.push_back('0');
		tcount++;
	}
	pcount++;   //2

	while (tcount < t) {
		temp = num;
		num++;
		pasing.clear();
		while (temp) {
			if (temp%n > 9) {
				pasing.push_back(temp%n - 10 + 'A');
			}
			else {
				pasing.push_back(temp%n + '0');
			}
			temp /= n;
		}
		temp = pasing.size();
		for (int i = 0; i < temp; i++) {
			if (pcount > m)
				pcount = 1;
			if (pcount == p) {
				answer.push_back(pasing[temp - 1 - i]);
				tcount++;
			}
			if (tcount >= t)
				break;
			pcount++;
		}
		pasing.clear();
	}

	return answer;
}
