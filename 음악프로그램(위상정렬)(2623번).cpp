#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<vector>

#include<math.h>

using namespace std;

int n, m;
//int **p;

int *check;
int *check2;
int *line;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue<int> q;
	int a, b, index=0;
	
	cin >> n >> m;

	queue<int> p[32001];
	
	check = new int[n + 1]();
	check2 = new int[n + 1]();

	line = new int[n]();

	
	int x, y, temp[1001] = {0};

	for (int i = 0; i < m; i++) {
		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> temp[j];
		}
		for (int j = 0; j < x; j++) {
			for (int k = j + 1; k < x; k++) {
				p[temp[j]].push(temp[k]);
				check[temp[j]] = 1;
				check[temp[k]] = -1;
				check2[temp[k]]++;
			}
		}		
		
	}
	for (int i = 1; i <= n; i++) {
		if (check[i]==0)
			line[index++] = i;
		else if (check2[i] == 0) {
			q.push(i);
		}
//		cout << line[index - 1] << " ";
	}

	while (!q.empty() && line[n-1]==0) {
		if (check[q.front()] != 0) {
			line[index++] = q.front();
			check[q.front()] = 0;
			while (!p[q.front()].empty()) {
				if ((--check2[p[q.front()].front()]) <= 0)
					q.push(p[q.front()].front());
				p[q.front()].pop();
			}

			q.pop();
		}
		else
			q.pop();
		
	}
	if (line[n - 1] == 0)
		cout << "0";
	else
	for (int i = 0; i < n; i++)
		cout << line[i] << "\n";


	
}

