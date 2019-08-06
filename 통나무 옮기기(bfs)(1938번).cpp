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

int n;
char pan[51][51] = { '\0' };
int check1[51][51] = { 0 };
int check2[51][51] = { 0 };

int min1 = 2000000000;

typedef struct move {
	int x1, y1, x2, y2, x3, y3;
	int length;
	int spincheck;
	move(int a, int b, int c, int d, int e, int f, int l, int s) {
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
		x3 = e;
		y3 = f;
		length = l;
		spincheck = s;

	}
}mv;

queue <mv> q;

int bfs();


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	int x[3],y[3];
	int k = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> pan[i][j];
			if (pan[i][j] == 'B') {
				x[k] = i;
				y[k++] = j;
			}
		}
	}
	if (x[0] == x[1]) { // 가로
		check1[x[1]][y[1]] = 2;
		q.push(mv(x[0], y[0], x[1], y[1], x[2], y[2], 0, 1));
	}
	else {
		check2[x[1]][y[1]] = 2;
		q.push(mv(x[0], y[0], x[1], y[1], x[2], y[2], 0, 2));
	}

	

	int ans;
	ans = bfs();
	cout << ans;
	
}





int bfs() { //u ,d, l, r, t

	int x1, y1, x2, y2,  x3,  y3,  length, spincheck;
	int a, b, c;

	while (!q.empty()) {
		x1 = q.front().x1;
		y1 = q.front().y1;
		x2 = q.front().x2;
		y2 = q.front().y2;
		x3 = q.front().x3;
		y3 = q.front().y3;
		length = q.front().length;
		spincheck = q.front().spincheck;

		q.pop();
		
		

		if (pan[x1][y1] == 'E' &&pan[x2][y2] == 'E' &&pan[x3][y3] == 'E') {
			if (min1 > length)
				min1 = length;

			return min1;
		}


		if (x1 - 1 > 0 && x2 - 1 > 0 && x3 - 1 > 0 && pan[x1 - 1][y1] != '1' && pan[x3 - 1][y3] != '1' && pan[x2 - 1][y2] != '1' 
			&& ((spincheck == 1 && check1[x2 - 1][y2] == 0) || (spincheck == 2 && check2[x2 - 1][y2] == 0))) {
		
			if (spincheck == 1) {
				check1[x2 - 1][y2] = 1;
				q.push(mv(x1 - 1, y1, x2 - 1, y2, x3 - 1, y3, length + 1, 1));
			}
			else {
				check2[x2 - 1][y2] = 1;
				q.push(mv(x1 - 1, y1, x2 - 1, y2, x3 - 1, y3, length + 1, 2));
			}
			

		}//up
		if (x3 + 1 <= n && x1 + 1 <= n && x2 + 1 <= n && pan[x1 + 1][y1] != '1' && pan[x3 + 1][y3] != '1' && pan[x2 + 1][y2] != '1' 
			&& ((spincheck == 1 && check1[x2 + 1][y2] == 0) || (spincheck == 2 && check2[x2 + 1][y2] == 0))) {
			
			if (spincheck == 1) {
				check1[x2 + 1][y2] = 1;
				q.push(mv(x1 + 1, y1, x2 + 1, y2, x3 + 1, y3, length + 1, 1));
			}
			else {
				check2[x2 + 1][y2] = 1;
				q.push(mv(x1 + 1, y1, x2 + 1, y2, x3 + 1, y3, length + 1, 2));
			}

		}//down
		if (y1 - 1 > 0 && y2 - 1 > 0 && y3 - 1 > 0 && pan[x1][y1 - 1] != '1' && pan[x3][y3 - 1] != '1' && pan[x2][y2 - 1] != '1' 
			&& ((spincheck == 1 && check1[x2][y2 - 1] == 0) || (spincheck == 2 && check2[x2][y2 - 1] == 0))) {
			
			if (spincheck == 1) {
				check1[x2][y2 - 1] = 1;
				q.push(mv(x1 , y1 - 1, x2 , y2 - 1, x3 , y3 - 1, length + 1, 1));
			}
			else {
				check2[x2 ][y2 - 1] = 1;
				q.push(mv(x1 , y1 - 1, x2 , y2 - 1, x3 , y3 - 1, length + 1, 2));
			}

		}//left
		if (y3 + 1 <= n && y1 + 1 <= n && y2 + 1 <= n && pan[x1][y1 + 1] != '1' && pan[x3][y3 + 1] != '1' && pan[x2][y2 + 1] != '1' 
			&& ((spincheck == 1 && check1[x2][y2 + 1] == 0) || (spincheck == 2 && check2[x2][y2 + 1] == 0))) {

			if (spincheck == 1) {
				check1[x2][y2 + 1] = 1;
				q.push(mv(x1, y1 + 1, x2, y2 + 1, x3, y3 + 1, length + 1, 1));
			}
			else {
				check2[x2][y2 + 1] = 1;
				q.push(mv(x1, y1 + 1, x2, y2 + 1, x3, y3 + 1, length + 1, 2));
			}

		}//right

		if (x1 != x3 && y1<n && y1>1/*&& spincheck != 1*/) { // 세로
			if (pan[x1][y1 - 1] != '1' && pan[x1][y1 + 1] != '1' && pan[x2][y2 - 1] != '1' && pan[x2][y2 + 1] != '1' && pan[x3][y3 - 1] != '1' && pan[x3][y3 + 1] != '1' &&
				check1[x2][y2] == 0) {

				check1[x2][y2] = 1;

				q.push(mv(x2, y2 - 1, x2, y2, x2, y2 + 1, length + 1, 1));

			}

		}//spin
		else if (x1 == x3 && x2<n && x2>1/*&& spincheck != 1*/) { // 가로
			if (pan[x1 - 1][y1] != '1' && pan[x1 + 1][y1] != '1' && pan[x2 - 1][y2] != '1' && pan[x2 + 1][y2] != '1' && pan[x3 - 1][y3] != '1' && pan[x3 + 1][y3] != '1' &&
				check2[x2][y2]==0) {

				check2[x2][y2] = 1;

				q.push(mv(x2 - 1, y2, x2, y2, x2 + 1, y2, length + 1, 2));

			}
		}

	}

	return 0;
}



