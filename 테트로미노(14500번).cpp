	#include <iostream>
	#include <vector>
	#include <map>
	#include <queue>
	#include <algorithm>

	using namespace std;


	int m, n;
	int max1 = -1;
	int check2[501][501] = { 0 };
	vector<vector<int>> board(500, vector<int>(500, 0));

	int	dir[4][2] = { 1,0,	
					-1, 0,	
					0,1,	
					0, -1 };
	int	dir2[3][2] = { 	
					-1, 0,	
					0,1,	
					0, -1 };
	int	dir3[3][2] = { 1,0,	
						
					0,1,	
					0, -1 };
	int	dir4[3][2] = { 1,0,	
					-1, 0,	
						
					0, -1 };
	int	dir5[3][2] = { 1,0,	
					-1, 0,	
					0,1	
					 };



	void dfs(int x, int y, int num, int sum) {
		if (num == 4) {
			if (max1 < sum) {
				max1 = sum;
			}
			return;
		}

		for (int i = 0; i < 4; i++) {	//4°³
			x += dir[i][0];
			y += dir[i][1];
		
			if (x >= 0 && x < m && y >= 0 && y < n && (check2[x][y] == 0)) {
				check2[x][y] = 1;
				dfs(x, y, num + 1, sum + board[x][y]);
				check2[x][y] = 0;
			}
			x -= dir[i][0];
			y -= dir[i][1];
		}
	}

	void sfind(int x, int y) {
		int x1[3] = { 0 }, y1[3] = { 0 };
		int check = 0, sum = 0;

		for (int i = 0; i < 3; i++) {
			x1[i] = dir2[i][0] + x;
			y1[i] = dir2[i][1] + y;
			if (x1[i] < 0 || x1[i] >= m || y1[i] < 0 || y1[i] >= n) {
				check = -1;
			}
		}
		if (check < 0) {

		}
		else {
			sum += board[x][y];
			for (int i = 0; i < 3; i++) {
				sum += board[x1[i]][y1[i]];
			}
		}
		if (max1 < sum) {
			max1 = sum;
		}
		sum = 0;
		check = 0;

		for (int i = 0; i < 3; i++) {
			x1[i] = dir3[i][0] + x;
			y1[i] = dir3[i][1] + y;
			if (x1[i] < 0 || x1[i] >= m || y1[i] < 0 || y1[i] >= n) {
				check = -1;
			}
		}
		if (check < 0) {

		}
		else {
			sum += board[x][y];
			for (int i = 0; i < 3; i++) {
				sum += board[x1[i]][y1[i]];
			}
		}
		if (max1 < sum) {
			max1 = sum;
		}
		sum = 0;
		check = 0;

		for (int i = 0; i < 3; i++) {
			x1[i] = dir4[i][0] + x;
			y1[i] = dir4[i][1] + y;
			if (x1[i] < 0 || x1[i] >= m || y1[i] < 0 || y1[i] >= n) {
				check = -1;
			}
		}
		if (check < 0) {
	
		}
		else {
			sum += board[x][y];
			for (int i = 0; i < 3; i++) {
				sum += board[x1[i]][y1[i]];
			}
		}
		if (max1 < sum) {
			max1 = sum;
		}
		sum = 0;
		check = 0;

		for (int i = 0; i < 3; i++) {
			x1[i] = dir5[i][0] + x;
			y1[i] = dir5[i][1] + y;
			if (x1[i] < 0 || x1[i] >= m || y1[i] < 0 || y1[i] >= n) {
				check = -1;
			}
		}
		if (check < 0) {

		}
		else {
			sum += board[x][y];
			for (int i = 0; i < 3; i++) {
				sum += board[x1[i]][y1[i]];
			}
		}
		if (max1 < sum) {
			max1 = sum;
		}
		sum = 0;
		check = 0;
	}

	int main() {

		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				check2[i][j] = 1;
				dfs( i,j,1,board[i][j]);
				sfind( i, j);
				check2[i][j] = 0;
			}
		}
		cout << max1;
	}

