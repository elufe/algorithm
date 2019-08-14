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


int n, m;

int *tree;

int update(int start, int end, int index, int y, int num);

void multi(int start, int end, int index, int mstart, int mend);

int ans = 1;

int i;

int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
	int b, c, backup,input1;
	char a,x;
	tree = new int[400000]();
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(tree, 0, sizeof(int) * 400000);
		for (i = 1; i <= n; i++) {
			scanf("%d", &input1);
			if (input1 > 0) {
				update(1, n, 1, 1, i);
			}
			else if (input1 == 0) {
				update(1, n, 1, 0, i);
			}
			else {
				update(1, n, 1, -1, i);
			}
		}

		for(i=1;i<=m;i++){
			scanf(" %c %d %d", &a, &b, &c);
			if (a == 'C') {
				if (c > 0)
					c = 1;
				else if (c < 0)
					c = -1;
				update(1, n, 1, c, b);
			}
			else {
				multi(1, n, 1, b, c);
				if (ans > 0) {
					printf("+");
				}
				else if (ans == 0) {
					printf("0");
				}
				else {
					printf("-");
				}
				ans = 1;
			}
		}
		printf("\n");

	}

}


int update(int start, int end, int index, int y, int num) {
	int mid = (start + end) / 2;

	if (start > num || end < num) {
		return tree[index];
	}

	if (start == end) {
		return tree[index] = y;
	}
	else
		return tree[index] = update(start, mid, index * 2, y, num) * update(mid + 1, end, index * 2 + 1, y, num);
}



void multi(int start, int end, int index, int mstart, int mend) {
	
	int mid = (start + end) / 2;
	
	if (start >= mstart && end <= mend) {
		ans *= tree[index];
	}
	else {
		if (mid >= mstart) {
			multi(start, mid, index * 2, mstart, mend);
		}
		if (mid < mend) {
			multi(mid + 1, end, index * 2 + 1, mstart, mend);
		}
	}
	return;
}
