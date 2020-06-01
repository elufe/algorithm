#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int m, n;

vector<vector<int>> board(8,vector<int>(8,0));
vector<vector<int>> board2(8, vector<int>(8, 0));
vector<pair<int, int>> blank;
vector<pair<int, int>> virus;
int safe_size, safe_max = -1;

int dir[4][2] = { 1,0,
				0,1,
				-1,0,
				0,-1 };

void spread(int x, int y) {
	
	if (x < 0 || x >= m || y < 0 || y >= n) {
		return;
	}
	if (board2[x][y] == 0) {
		board2[x][y] = 2;
		safe_size--;
	}
	else{
		return;
	}
	for (int i = 0; i < 4; i++) {
		x += dir[i][0];
		y += dir[i][1];
		spread(x, y);
		x -= dir[i][0];
		y -= dir[i][1];
	}
}


int main() {
	cin >> m >> n;

	blank.reserve(m*n);
	virus.reserve(m*n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				blank.push_back({ i,j });
			}
			else if (board[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < blank.size(); i++) {
		for (int j = i + 1; j < blank.size(); j++) {
			for (int k = j + 1; k < blank.size(); k++) {
				board2 = board;
				safe_size = blank.size() - 3;
				board2[blank[i].first][blank[i].second] = 1;
				board2[blank[j].first][blank[j].second] = 1;
				board2[blank[k].first][blank[k].second] = 1;
				for (int l = 0; l < virus.size(); l++) {
					spread(virus[l].first, virus[l].second);
					for (int p = 0; p < 4; p++) {
						virus[l].first += dir[p][0];
						virus[l].second += dir[p][1];
						spread(virus[l].first, virus[l].second);
						virus[l].first -= dir[p][0];
						virus[l].second -= dir[p][1];
					}
				}
				if (safe_max < safe_size) {
					safe_max = safe_size;
				}
			}
		}
	}
	cout << safe_max;
}

