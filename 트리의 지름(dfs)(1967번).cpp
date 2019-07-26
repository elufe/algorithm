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
	
	int n;
	int **p;
	int max1 = 0;
	int node = 0;
	
	void find1(int x, int **p, int length);
	void change(int start, int **p);


	int main() {
		cin.tie(NULL);
		ios::sync_with_stdio(false);

		cin >> n;
		p = new int*[n - 1];

		for (int i = 0; i < n - 1; i++) {
			p[i] = new int[3]();
			cin >> p[i][0] >> p[i][1] >> p[i][2];
		}
		
		int start;
		find1(1, p, 0);
		start = node;
		change(start, p);
		find1(start, p, 0);
		cout << max1;
	}

	void find1(int x, int **p, int length) {
		int index = 0;
		int i = 0;

		for (i = 0; i < n - 1; i++) {
			if (p[i][0] == x)
				break;
		}
		if (i < n - 1) {
			index = i;
		}
		else {
			if(max1 < length){
				max1 = length;
				node = x;
			}
			return;
		}

		for (i = index; i < n - 1; i++) {
			if (p[i][0] != x)
				continue;
			find1(p[i][1], p, length + p[i][2]);
		}
	}

	void change(int start, int **p) {
		int temp;
		if (start == 1)
			return;

		for (int i = 0; i < n - 1; i++) {
			if (p[i][1] == start) {
				temp = p[i][0];
				p[i][0] = p[i][1];
				p[i][1] = temp;
				start = p[i][1];
				break;
			}
		}
		if(start != 1)
		change(start, p);
	}