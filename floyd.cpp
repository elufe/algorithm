#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void floyd(int, int**, int**,int**);
void path(int**, int, int);

int main() {
	int size;
	int q, r;
	scanf("%d", &size);
	int **W = new int*[size], **D = new int*[size], **P = new int*[size];
	for (int i = 0; i < size; i++) {
		W[i] = new int[size];
		D[i] = new int[size];
		P[i] = new int[size];
	}

	cout << "W : "<<"\n";
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%d", &W[i][j]);
		}
		
	}


	floyd(size, W, D, P);
	
	cout << "D : " << "\n";

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << D[i][j]<<" ";
		}
		cout << "\n";
	}
	
	cout << "P : " << "\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << P[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "q : ";
	cin >> q;
	cout << "r : ";
	cin >> r;
	cout << "V" << q;
	path(P, q-1, r-1);
	cout << "V" << r;

}


void floyd(int n, int **W, int **D, int **P) {
	int i, j, k;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			P[i][j] = 0;
		}
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			D[i][j] = W[i][j];
		}
	}
	
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k+1;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}

void path(int **P, int q, int r) {
	if (P[q][r] != 0) {
		path(P, q, P[q][r]-1);
		cout << "V" << P[q][r];
		path(P, P[q][r]-1,r);
	}
}
