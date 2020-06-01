#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int n;

int s[15], t[15], p[15];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	for (int i = 0; i < n; i++) {
		
		if (i == 0) {
			s[i] = 0;
			s[t[i] - 1] = p[i];
		}
		else {
			if (i + t[i] - 1 < n  && s[i + t[i] - 1] < s[i - 1] + p[i]) {
				s[i + t[i] - 1] = s[i - 1] + p[i];
			}
			
			if (s[i] < s[i - 1])
				s[i] = s[i - 1];
		}
	}
	cout << s[n-1];
}

