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
	int **bing;
	int **check;
	int **check2;
	int bingcount = 0;
	int checkcount = 0;
	int year = 0;


	void zero(int **bing, int **check);
	void dfs(int x, int y, int **bing, int **check2);

	int main() {
		cin.tie(NULL);
		ios::sync_with_stdio(false);

		cin >> n >> m;
		
		bing = new int*[n + 1]();
		check = new int*[n + 1]();
		check2 = new int*[n + 1]();
		for (int i = 0; i <= n; i++) {
			bing[i] = new int[m + 1]();
			check[i] = new int[m + 1]();
			check2[i] = new int[m + 1]();
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> bing[i][j];
				if (bing[i][j] > 0)
					bingcount++;
			}
		}

		while (1) {
			year++;
			zero(bing, check);

			for (int i = 0; i <= n; i++)
				memset(check2[i], 0, sizeof(int)*(m + 1));

			for (int i = 2; i < n; i++) {
				for (int j = 2; j < m; j++) {
					if (bing[i][j] > 0) {
						dfs(i, j, bing,check2);
						break;
					}
				}
			}

			if (bingcount == checkcount) {
				if (bingcount == 0) {
					cout << "0";
					break;
				}
				checkcount = 0;
			}
			else {
				cout << year;
				break;
			}

		}
		

	}

	void dfs(int x, int y, int **bing, int **check2) {

		check2[x][y] = 1;
		if (checkcount == 0)
			checkcount++;

		if (x + 1 < n && bing[x+1][y]>0 && check2[x+1][y] == 0) {
			checkcount++;
			dfs(x + 1, y, bing, check2);
		}
		if (x - 1 > 1 && bing[x-1][y]>0 && check2[x-1][y] == 0) {
			checkcount++;
			dfs(x - 1, y, bing, check2);
		}
		if (y + 1 < m && bing[x][y+1]>0 && check2[x][y+1] == 0) {
			checkcount++;
			dfs(x, y+1, bing, check2);
		}
		if (y - 1 > 1 && bing[x][y-1]>0 && check2[x][y-1] == 0) {
			checkcount++;
			dfs(x, y-1, bing, check2);
		}
	}

	void zero(int **bing, int **check) {
		for (int i = 2; i < n; i++) {
			for (int j = 2; j < m; j++) {
				if (bing[i][j] > 0) {
					if (bing[i - 1][j] == 0) {
						check[i][j]++;
					}
					if (bing[i + 1][j] == 0) {
						check[i][j]++;
					}
					if (bing[i][j + 1] == 0) {
						check[i][j]++;
					}
					if (bing[i][j - 1] == 0) {
						check[i][j]++;
					}
				}
			}
		}
		for (int i = 2; i < n; i++) {
			for (int j = 2; j < m; j++) {
				if (check[i][j] > 0) {
					bing[i][j] = bing[i][j] - check[i][j];
					check[i][j] = 0;
					if (bing[i][j] <= 0) {
						bing[i][j] = 0;
						bingcount--;
					}
				}
			}
		}

	}