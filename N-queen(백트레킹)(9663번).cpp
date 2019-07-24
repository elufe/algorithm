#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<list>

#include<math.h>

using namespace std;

void nqueen(int n, int index, int **locate, int *row);

int qcheck(int n, int index, int **locate);

int sum = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	int **a;
	int *row;
	int **locate;

	cin >> n;
	locate = new int *[n + 1]();
	row = new int[n + 1]();
	for (int i = 1; i <= n; i++) {
		locate[i] = new int[2]();
	}

	nqueen(n, 1, locate, row);
	cout << sum;
}

void nqueen(int n, int index, int **locate, int *row) {

	
	if (index == n+1) {
		sum++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (row[i] == 1)
			continue;
		locate[index][0] = index;
		locate[index][1] = i;
		row[i] = 1;
		if (qcheck(n, index, locate)) {
			nqueen(n, index + 1, locate, row);
		}
		row[i] = 0;
		locate[index][1] = 0;
	}
}

int qcheck(int n, int index, int **locate) {
	for (int i = 1; i < index; i++) {

		if (abs(locate[i][1] - locate[index][1]) == (index-i)) {
			return 0;
		}
	}
	return 1;
}