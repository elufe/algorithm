#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void dijkstra(int, int**, int**);

int main() {
	int n, **w,**f;
	cout << "n?" << endl;
	cin >> n;
	f = new int*[n - 1];
	for (int i = 0; i < n; i++)
		f[i] = new int[3];
	w = new int*[n];
	for (int i = 0; i < n; i++)
		w[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];

	dijkstra(n, w, f);
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < 3; j++) {
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
}

void dijkstra(int n, int **w, int **f) {
	int *touch, *length;
	int min, vnear;
	touch = new int[n - 1];
	length = new int[n - 1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			f[i][j] = 0;

	for (int i = 0; i < n - 1; i++) {
		touch[i] = 1;
		length[i] = w[0][i + 1];
	}

	for (int t = 1; t < n; t++) {
		min = 999;
		for(int i=0;i<n-1;i++)
			if (length[i] >= 0 && length[i] <= min) {
				min = length[i];
				vnear = i+2;
			}
		cout << "vnear:" << vnear<<endl;
		f[t-1][0] = touch[vnear-2];
		f[t-1][1] = vnear;
		f[t-1][2] = min;
		for (int i = 0; i < n-1; i++)
			if ((length[vnear-2] + w[vnear-1][i+1]) < length[i]) {
				length[i] = length[vnear-2] + w[vnear-1][i+1];
				touch[i] = vnear;
			}
		length[vnear-2] = -1;
		
	}
}