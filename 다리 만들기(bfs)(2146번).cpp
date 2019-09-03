#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<cstring>
#include<string.h>
#include<list>
#include<math.h>

using namespace std;

struct node {
	int x;
	int y;
	int count;
	node(int a, int b, int c) {
		x = a;
		y = b;
		count = c;
	}
};

queue<node> q[10001];

int map[101][101] = { 0 };
int check[101][101] = { 0 };

int n;

void bfs(int i, int j, int index);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int index = 1;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				bfs(i, j, index++);
			}
		}
	}
	


	int count1 = 0, xpoint=0, ypoint=0, count2=0, answer=2100000000, indexbackup=index;
	index = 1;
	while (1) {

		if (index >= indexbackup) {
			count1++;
			index = 0;
			while (q[index].empty() && index<indexbackup)
				index++;
		}

		

		while (!q[index].empty() && q[index].front().count == count1) {

			xpoint = q[index].front().x;
			ypoint = q[index].front().y;
			count2 = q[index].front().count;

			q[index].pop();
			if (xpoint < n) {
				if (map[xpoint + 1][ypoint] == 0 && check[xpoint + 1][ypoint] == 0) {
					q[index].push(node(xpoint + 1, ypoint, count2+1));
					check[xpoint + 1][ypoint] = count2+1;
					map[xpoint + 1][ypoint] = -index;
				}
				else if (map[xpoint + 1][ypoint] != -index && map[xpoint + 1][ypoint] != 0 && check[xpoint+1][ypoint]>0) {
					check[xpoint + 1][ypoint] += count2;
					answer = check[xpoint + 1][ypoint];
					break;
				}
			}
			if (xpoint > 1) {
				if (map[xpoint - 1][ypoint] == 0 && check[xpoint - 1][ypoint] == 0) {
					q[index].push(node(xpoint - 1, ypoint, count2 + 1));
					check[xpoint - 1][ypoint] = count2 + 1;
					map[xpoint - 1][ypoint] = -index;
				}
				else if (map[xpoint - 1][ypoint] != -index && map[xpoint - 1][ypoint] != 0 && check[xpoint - 1][ypoint] > 0) {
					check[xpoint - 1][ypoint] += count2;
					answer = check[xpoint - 1][ypoint];
					break;
				}
			}
			if (ypoint < n) {
				if (map[xpoint][ypoint + 1] == 0 && check[xpoint][ypoint + 1] == 0) {
					q[index].push(node(xpoint, ypoint + 1, count2 + 1));
					check[xpoint][ypoint + 1] = count2 + 1;
					map[xpoint][ypoint + 1] = -index;
				}
				else if (map[xpoint][ypoint + 1] != -index && map[xpoint][ypoint + 1] != 0 && check[xpoint][ypoint + 1] > 0) {
					check[xpoint][ypoint + 1] += count2;
					answer = check[xpoint][ypoint + 1];
					break;
				}
			}
			if (ypoint > 1) {
				if (map[xpoint][ypoint - 1] == 0 && check[xpoint][ypoint - 1] == 0) {
					q[index].push(node(xpoint, ypoint - 1, count2 + 1));
					check[xpoint][ypoint - 1] = count2 + 1;
					map[xpoint][ypoint - 1] = -index;
				}
				else if (map[xpoint][ypoint - 1] != -index && map[xpoint][ypoint - 1] != 0 && check[xpoint][ypoint - 1] > 0) {
					check[xpoint][ypoint - 1] += count2;
					answer = check[xpoint][ypoint - 1];
					break;
				}
			}

			
		}


		if (answer < 10000)
			break;
		else
			index++;
	}
	cout << answer;
}

void bfs(int i, int j, int index) {
	
	map[i][j] = -index;
	if (i < n && i>0 && j<=n && j>0) {
		if (map[i + 1][j] == 0 && check[i][j] == 0) {
			q[index].push(node(i, j, 0));
			check[i][j] = 1;
			map[i][j] = -index;
		}
		else if (map[i + 1][j] == 1)
			bfs(i + 1, j, index);
	}
	if (i > 1 && i <= n && j>0 && j<=n) {
		if (map[i - 1][j] == 0 && check[i][j] == 0) {
			q[index].push(node(i, j, 0));
			check[i][j] = 1;
			map[i][j] = -index;
		}
		else if (map[i - 1][j] == 1)
			bfs(i - 1, j, index);
	}
	if (j < n&&j>0 && i > 0 && i <= n) {
		if (map[i][j + 1] == 0 && check[i][j] == 0) {
			q[index].push(node(i, j, 0));
			check[i][j] = 1;
			map[i][j] = -index;
		}
		else if (map[i][j + 1] == 1)
			bfs(i, j + 1, index);
	}
	if (j > 1 && j<=n && i>0 && i<=n) {
		if (map[i][j - 1] == 0 && check[i][j] == 0) {
			q[index].push(node(i, j, 0));
			check[i][j] = 1;
			map[i][j] = -index;
		}
		else if (map[i][j - 1] == 1)
			bfs(i, j - 1, index);
	}
}