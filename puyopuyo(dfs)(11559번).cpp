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

char pan[13][7] = { '\0' };
int check[13][7] = { 0 };
int temp[72][2] = { 0 };
int ccc=1;
int iii = 0;
int max1 = -1;
char update[12];

void dfs(int x, int y, char alpha);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> pan[i][j];
		}
	}
	int k, q;
	int count = 0;
	while (1) {
		k = 0;
		max1 = -1;
		
		for (int i = 0; i <= 12; i++)
			memset(check[i], 0, sizeof(int) * 7);

		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 6; j++) {
				
				if (check[i][j] == 0 && (pan[i][j] == 'R' || pan[i][j] == 'G' || pan[i][j] == 'B' || pan[i][j] == 'P' || pan[i][j] == 'Y')) {
					ccc = 1;
					temp[k][0] = i;
					temp[k][1] = j;
					iii = k + 1;
					dfs(i, j,pan[i][j]);
					if (max1 > 0) {
						k += ccc;
					}
					else {
						temp[k][0] = 0;
						temp[k][1] = 0;
					}
					max1 = -1;
				}
			}
		}

		if (k == 0)
			break;
		else
			count++;

		for (int i = 0; i <= k && temp[i] != 0; i++) {
			pan[temp[i][0]][temp[i][1]] = '.';
			temp[i][0] = 0;
			temp[i][1] = 0;
		}

		
		for (int j = 1; j <= 6; j++) {
			q = 0;
			memset(update, '\0', sizeof(char) * 12);
			for (int i = 12; i >= 1; i--) {
				if (pan[i][j] == 'R' || pan[i][j] == 'G' || pan[i][j] == 'B' || pan[i][j] == 'P' || pan[i][j] == 'Y') {
					update[q++] = pan[i][j];
					pan[i][j] = '.'; 
				}
			}
			for (q = q - 1; q >= 0; q--) {
				pan[12 - q][j] = update[q];
			}
		}
	
	}
	cout << count;
}

void dfs(int x, int y, char alpha) {
	
	if (ccc >= 4) {
		if (max1 < iii)
			max1 = iii;
	}
	check[x][y] = 1;

	if (x + 1 <= 12 && pan[x + 1][y] == alpha && check[x + 1][y] == 0) {
		temp[iii][0] = x + 1;
		temp[iii++][1] = y;
		check[x + 1][y] = 1;
		ccc++;
		dfs(x + 1, y, alpha);

	}
	if (x - 1 > 0 && pan[x - 1][y] == alpha && check[x - 1][y] == 0) {
		temp[iii][0] = x - 1;
		temp[iii++][1] = y;
		check[x - 1][y] = 1;
		ccc++;
		dfs(x - 1, y, alpha);
	}
	if (y + 1 <= 6 && pan[x][y + 1] == alpha && check[x][y + 1] == 0) {
		temp[iii][0] = x;
		temp[iii++][1] = y + 1;
		check[x][y + 1] = 1;
		ccc++;
		dfs(x, y + 1, alpha);
	}
	if (y - 1 > 0 && pan[x][y - 1] == alpha && check[x][y - 1] == 0) {
		temp[iii][0] = x;
		temp[iii++][1] = y - 1;
		check[x][y - 1] = 1;
		ccc++;
		dfs(x, y - 1, alpha);

	}


}