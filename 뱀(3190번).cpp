#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, l;

int main() {
	vector<vector<int>> map(100, vector<int>(100, 0));
	queue<pair<int, char>> q;
	queue<pair<int, int>> tail;
	int dir[4][2] = { 0,1,
					1,0,
					0,-1,
					-1,0 };
	int index = 0;
	int x, y;
	char c;
	int x1, x2, y1, y2, time=0;

	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		map[x-1][y-1] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		q.push({ x,c });
	}
	map[0][0] = 2;
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	x = q.front().first;
	c = q.front().second;
	q.pop();
	tail.push({ 0,0 });
	
	while (1) {
		
		if (x == time) {
			if (c == 'D') {
				index++;
			}
			else {
				index--;
			}
			if (index > 3) {
				index -= 4;
			}
			if (index < 0) {
				index += 4;
			}
			if (!q.empty()) {
				x = q.front().first;
				c = q.front().second;
				q.pop();
			}
		}
		x1 += dir[index][0];
		y1 += dir[index][1];
		if (x1 < 0 || x1>n-1 || y1 < 0 || y1>n-1) {
			time++;
			break;
		}
		else if (map[x1][y1] == 2) {
			time++;
			break;
		}
		else if (map[x1][y1] == 0) {
			map[x1][y1] = 2;
			tail.push({ x1,y1 });
			x2 = tail.front().first;
			y2 = tail.front().second;
			tail.pop();
			map[x2][y2] = 0;
		}
		else {
			map[x1][y1] = 2;
			tail.push({ x1,y1 });
		}
		time++;

	}
	cout << time;
}