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
	
	int n, m,k;
	int a[10001] = { 0 };
	
	void dfs(int x, int y, int **box, int *a, int index);

	int main() {
		cin.tie(NULL);
		ios::sync_with_stdio(false);

		cin >> n >> m >> k;

		int **box;

		box = new int*[n];
		for (int i = 0; i < n; i++) {
			box[i] = new int[m]();
		}
		int x1, y1, x2, y2;
		for (int i = 0; i < k; i++) {
			cin >> y1 >> x1 >> y2 >> x2;
			for (int j = x1; j < x2; j++) {
				for (int l = y1; l < y2; l++) {
					box[j][l] = 1;
				}
			}
		}
		int index = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[i][j] == 0) {
					dfs(i, j, box, a, index++);
				}
			}
		}
		cout << index << "\n";
		sort(a, a + 10001);
		for (int i = 0; i < 10001; i++) {
			if (a[i] > 0)
				cout << a[i] << " ";
		}
	}

	void dfs(int x, int y, int **box, int *a, int index) {
		a[index]++;
		box[x][y] = 1;
		if (x + 1 < n && box[x + 1][y] == 0) {
		//	box[x + 1][y] = 1;
		//	a[index]++;
			dfs(x + 1, y, box, a, index);
		}
		if (x - 1 >= 0 && box[x - 1][y] == 0) {
		//	box[x - 1][y] = 1;
		//	a[index]++;
			dfs(x - 1, y, box, a, index);
		}
		if (y + 1 < m && box[x][y+1] == 0) {
		//	box[x][y+1] = 1;
		//	a[index]++;
			dfs(x, y+1, box, a, index);
		}
		if (y - 1 >= 0 && box[x][y - 1] == 0) {
		//	box[x][y - 1] = 1;
		//	a[index]++;
			dfs(x, y - 1, box, a, index);
		}
	}
