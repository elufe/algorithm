#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;



int main() {
	vector<vector<int>> map(20, vector<int>(20, 0));
	queue<int> q;
	vector<int> dice(6,0);
	vector<int> dice2(6,0);
	int dir[4][6] = { 3,1,0,5,4,2,
					2,1,5,0,4,3,
					4,0,2,3,5,1,
					1,5,2,3,0,4 };
	int dir2[4][2] = { 0, 1,
						0, -1,
						-1, 0,
						1, 0 };
	int m, n, k;
	int x, y, temp;
	int d;

	cin >> m >> n >> x >> y >> k;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> temp;
		q.push(temp);
	}
	while (!q.empty()) {
		d = q.front();
		d--;
		q.pop();
		dice2 = dice;
		
		x += dir2[d][0];
		y += dir2[d][1];
		
		if (x < 0 || x >= m || y < 0 || y >= n) {
			x -= dir2[d][0];
			y -= dir2[d][1];
			continue;
		}

		for (int i = 0; i < 6; i++) {
			dice[i] = dice2[dir[d][i]];
		}
		if (map[x][y] == 0) {
			map[x][y] = dice[5];
		}
		else {
			dice[5] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[0]<<"\n";
	}
}