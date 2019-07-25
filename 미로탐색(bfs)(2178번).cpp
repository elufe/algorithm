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
	
	int n, m;
	int min1 = 10001;

	
	int main() {
//		cin.tie(NULL);
//		ios::sync_with_stdio(false);

		
		cin >> n >> m;

		queue<int> q[2];
		char **pan;
		char x;
		int check[101][101] = { 0 };
		
		pan = new char*[n + 1];
		for (int i = 0; i <= n; i++) {
			pan[i] = new char[m + 1]();
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				x = getchar();
				if (x == '\n')
					x = getchar();
				pan[i][j]=x;
			}
		}
		check[1][1] = 1;
		int length = 1;
		int row,col;
		q[0].push(1);
		q[1].push(1);
		
		while (!q[0].empty()) {
			if (q[0].front() == n && q[1].front() == m) {
				break;
			}

			row = q[0].front();
			col = q[1].front();
			q[0].pop();
			q[1].pop();

			length = check[row][col] + 1;

			if (row + 1 <= n && col <= m && pan[row + 1][col] == '1' && check[row + 1][col] == 0) {
				check[row + 1][col] = length;
				q[0].push(row + 1);
				q[1].push(col);
			}
			if (row - 1 >= 1 && col <= m && pan[row - 1][col] == '1' && check[row - 1][col] == 0) {
				check[row - 1][col] = length;
				q[0].push(row - 1);
				q[1].push(col);
			}
			if (col + 1 <= m && row <= n && pan[row][col+1] == '1' && check[row][col+1] == 0) {
				check[row][col+1] = length;
				q[0].push(row);
				q[1].push(col+1);
			}
			if (col - 1 >= 0 && row <= n && pan[row][col - 1] == '1' && check[row][col - 1] == 0) {
				check[row][col - 1] = length;
				q[0].push(row);
				q[1].push(col - 1);
			}
		}
	
		cout << check[n][m];

	}

