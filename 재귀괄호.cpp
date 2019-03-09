
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

void f(int open, int close, int check, int n, char *p) {
	
	if (check == 1) {
		p[open + close] = '(';
		open++;
	}
	else if (check == 2) {
		p[open + close] = ')';
		close++;
	}
	if (open > n || close > n || close>open) {
		return;
	}
	else if (open == n && close == n) {
		for (int i = 0; i < n * 2; i++)
			cout << p[i];
		cout << endl;
		return;
	}
	f(open, close, 1, n,p);
	f(open, close, 2, n,p);
}

int main() {
	int n;
	char *p;
	cin >> n;
	p = new char[n*2];
	f(0, 0, 1,n,p);

}