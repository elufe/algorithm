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

	int a[11][11] = { 0 };
	int z[83][2] = { 0 };
	int num[83][10] = { 0 };
	int zcount=0;
	int close = 0;

	int check1(int x, int y, int n);

	void check2(int x, int y, int index) {
		int circlex = 0, circley = 0, zcheck = 0;
		num[index][0] = 1;

		if (x <= 3 && x>0)
			circlex = 1;
		else if (x <= 6 && x > 0)
			circlex = 4;
		else if(x<=9 && x > 0)
			circlex = 7;

		if (y <= 3 && y > 0)
			circley = 1;
		else if (y <= 6 && y > 0)
			circley = 4;
		else if(y<=9&& y > 0)
			circley = 7;
		zcheck = 0;
		for (int i = 1; i < 10; i++) {
			if (num[index][a[x][i]] == 0 && a[x][i] != 0) {
				num[index][a[x][i]] = 1;
				zcheck++;
			}
		}


		for (int i = 1; i < 10; i++) {
			if (num[index][a[i][y]] == 0 && a[i][y] != 0) {
				num[index][a[i][y]] = 1;
				zcheck++;
			}
		}

		for (int i = circlex; i < circlex + 3; i++) {
			for (int j = circley; j < circley + 3; j++) {
				if (num[index][a[i][j]] == 0 && a[i][j] != 0) {
					num[index][a[i][j]] = 1;
					zcheck++;
				}
			}
		}

	
	}

	void check3(int aaa, int i) {
		if (zcount==0) {
			for (int i = 1; i < 10; i++) {
				for (int j = 1; j < 10; j++) {
					cout << a[i][j] << " ";
				}
				cout << "\n";
			}
			exit(0);
		}
		int temp = z[i][0];

		while (z[i][0] < 1)
			i++;

		for (int j = 1; j < 10; j++) {
			if (num[i][j] == 0) {
				if (check1(z[i][0], z[i][1], j)) {
					a[z[i][0]][z[i][1]] = j;
					zcount--;
					temp = z[i][0];
					z[i][0] = -1;

					check3(aaa,i+1);
					
					z[i][0] = temp;
					a[z[i][0]][z[i][1]] = 0;
					zcount++;
				
				}
			}
		}
	}


	int main() {
		cin.tie(NULL);
		ios::sync_with_stdio(false);
		int index = 1;
		for (int i = 1; i < 10; i++) {
			for (int j = 1; j < 10; j++) {
				cin >> a[i][j];
				if (a[i][j] == 0) {
					zcount++;
					z[index][0] = i;
					z[index++][1] = j;
				}
			}
		}
		int aaa = index;

		for (int i = 1; i < aaa; i++) {
			check2(z[i][0], z[i][1], i);
		}

		check3(aaa, 1);


	}

	int check1(int x, int y, int n) {
		int circlex=0, circley=0, zcheck=0;

		if (x <= 3 && x > 0)
			circlex = 1;
		else if (x <= 6 && x > 0)
			circlex = 4;
		else if (x <= 9 && x > 0)
			circlex = 7;

		if (y <= 3 && y > 0)
			circley = 1;
		else if (y <= 6 && y > 0)
			circley = 4;
		else if (y <= 9 && y > 0)
			circley = 7; 
		zcheck = 0;

		for (int i = 1; i < 10; i++) {
			if (i == y)
				continue;
			if (a[x][i] == n)
				return 0;
		}

		for (int i = 1; i < 10; i++) {
			if (i == x)
				continue;
			if (a[i][y] == n)
				return 0;
		}

		for (int i = circlex; i < circlex+3; i++) {
			for (int j = circley; j < circley + 3; j++) {
				if (i == x && j == y)
					continue;
				else if (a[i][j] == n)
					return 0;
			}
		}
		return 1;
	}