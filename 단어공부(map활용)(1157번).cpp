#include<iostream>
#include<string>
#include<cstdio>
#include<map>


using namespace std;

map<char, int> m;

int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
	
	char temp;
	int x;

	map<char, int>::iterator maxiter;
	int maxcount = -1;
	int check1 = 0;

	while (1) {
		temp = getchar();
		if (temp >= 'a' && temp <= 'z') {
			temp -= ('a' - 'A');
		}
		else if (temp >= 'A' && temp <= 'Z') {
			
		}
		else {
			break;
		}

		if (m.count(temp)) {
			x = m[temp] + 1;
			m.erase(temp);
			m.insert(pair<char, int>(temp, x));
		}
		else
			m.insert(pair<char, int>(temp, 1));
	}
	for (map<char, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
		if (maxcount < iter->second) {
			maxcount = iter->second;
			maxiter = iter;
		}
	}
	for (map<char, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
		if (maxcount == iter->second) {
			check1++;
		}
		if (check1 > 1) {
			printf("?");
			return 0;
		}
	}
	printf("%c", maxiter->first);
}