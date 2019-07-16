#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<string>

#include<math.h>

using namespace std;

void virus(int x, int y, int **room);
int newwall(int x1, int y1, int x2, int y2, int x3, int y3, int **room);

int vcount;
int n, m;
int vlocate[10][3];



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int **room,**wall;

	cin >> n >> m;

	room = new int*[n];
	for (int i = 0; i < n; i++) {
		room[i] = new int[m]();
	}

	wall = new int*[n*m];
	for (int i = 0; i < n*m; i++) {
		wall[i] = new int[3]();
	}
	
	int windex = 0,vindex=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
			if (room[i][j] == 0) {
				wall[windex][0] = i;
				wall[windex][1] = j;
				wall[windex][2] = 1;
				windex++;
			}
			else if (room[i][j] == 2) {
				vlocate[vindex][0] = i;
				vlocate[vindex][1] = j;
				vlocate[vindex][2] = 1;
				vindex++;
			}
		}
	}
	int check = 0, min =64;
	for (int i = 0; i < windex-2 && wall[i][2]==1; i++) {
		for (int j = i + 1; j < windex - 1 && wall[j][2] == 1; j++) {
			for (int k = j + 1; k < windex && wall[k][2] == 1; k++) {
				check = newwall(wall[i][0], wall[i][1], wall[j][0], wall[j][1], wall[k][0], wall[k][1], room);
				if (check < min) {
					min = check;
//					cout << "(" << wall[i][0] << ", " << wall[i][1] << "), " << "(" << wall[j][0] << ", " << wall[j][1] << "), " << "(" << wall[k][0] << ", " << wall[k][1] << ")\n";
				}
			}
		}
	}
//	cout << windex << " " << vindex << " " << min << "\n";
	cout << windex - 3 - min;
}


void virus(int x, int y, int **room) {
	if (x < n - 1 && room[x + 1][y] == 0) {
		room[x + 1][y] = 2;
		vcount++;
		virus(x + 1, y, room);
	}
	if (y < m - 1 && room[x][y + 1] == 0) {
		room[x][y + 1] = 2;
		vcount++;
		virus(x, y + 1, room);
	}
	if (x > 0 && room[x - 1][y] == 0) {
		room[x - 1][y] = 2;
		vcount++;
		virus(x - 1, y, room);
	}
	if (y > 0 && room[x][y - 1] == 0) {
		room[x][y - 1] = 2;
		vcount++;
		virus(x, y - 1, room);
	}
}

int newwall(int x1, int y1, int x2, int y2, int x3, int y3, int **room) {
	
	int **temp;
	
	temp = new int*[n];
	for (int i = 0; i < n; i++) {
		temp[i] = new int[m]();
		for (int j = 0; j < m; j++) {
			temp[i][j] = room[i][j];
		}
	}

	temp[x1][y1] = 1;
	temp[x2][y2] = 1;
	temp[x3][y3] = 1;

	vcount = 0;

	for (int i = 0; i < 10 && vlocate[i][2] == 1; i++) {
		virus(vlocate[i][0], vlocate[i][1], temp);
	}

	return vcount;
}