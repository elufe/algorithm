#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct tomato {
	tomato(int a, int b, int c, int day) {
		x = a;
		y = b;
		z = c;
		d = day;
	}
	int x, y, z, d;
};

int m, n, h, box[101][101][101];
int count1 = 0, day=0;
queue<tomato> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x = 0, y = 0, z = 0, d1 = -1;

	cin >> n >> m >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> box[k][i][j];
				if (box[k][i][j] == 1) {
					q.push(tomato(i, j, k, 0));
				}
				else if (box[k][i][j] == 0) {
					count1++;
				}
			}
		}
	}
	if (count1 == 0) {
		cout << 0;
		return 0;
	}

	while (!q.empty()) {
		d1 = q.front().d;
		if (day < d1)
			day = d1;
		x = q.front().x;
		y = q.front().y;
		z = q.front().z;
		q.pop();

		if (x+1<m && box[z][x+1][y] == 0) {
			box[z][x + 1][y] = 1;
			count1--;
			q.push(tomato(x + 1, y, z, d1+1));
		}
		if (x-1>=0 && box[z][x-1][y] == 0) {
			box[z][x-1][y] = 1;
			count1--;
			q.push(tomato(x-1, y, z, d1 + 1));
		}
		if (y+1<n && box[z][x][y+1] == 0) {
			box[z][x][y+1] = 1;
			count1--;
			q.push(tomato(x, y+1, z, d1 + 1));
		}
		if (y-1>=0 && box[z][x][y-1] == 0) {
			box[z][x][y-1] = 1;
			count1--;
			q.push(tomato(x, y-1, z, d1 + 1));
		}
		if (z+1<h && box[z+1][x][y] == 0) {
			box[z+1][x][y] = 1;
			count1--;
			q.push(tomato(x, y, z+1, d1 + 1));
		}
		if (z-1>=0 && box[z-1][x][y] == 0) {
			box[z-1][x][y] = 1;
			count1--;
			q.push(tomato(x, y, z-1, d1 + 1));
		}
	}
	if (count1 == 0)
		cout << day;
	else
		cout << -1;
}