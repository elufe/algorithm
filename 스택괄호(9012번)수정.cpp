#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>

#include<math.h>

using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	
	int n;
	
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		stack<char> s;
		char x[51] = { '\0' };
		cin >> x;
		for (int j = 0; j < 50 && x[j] != '\0'; j++) {
			if (x[j] == '(')
				s.push(x[j]);
			else if (!s.empty())
				s.pop();
			else {
				cout << "NO" << "\n";
				break;
			}
			if (x[j + 1] == '\0' && s.empty())
				cout << "YES" << "\n";
			else if(x[j + 1] == '\0')
				cout << "NO" << "\n";
		}
	}

}