#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int minmult(int, int *, int **);
void order(int, int,int **);

int main() {

	int n;
	int *d, **p;
	int cnt=0;

	cout << "n ?";
	cin >> n;
	d = new int[n+1];
	p = new int*[n];
	for (int i = 0; i < n; i++)
		p[i] = new int[n];
	for(int i=0;i<n+1;i++)
	cin >> d[i];
	
	cnt = minmult(n, d, p);

	cout <<"최소 연산 횟수 : "<<cnt<<"\n";
	cout << "최적의 순서";
	order(0, n-1, p);
}

int minmult(int n, int *d, int **p) {
	int i, j, k, diagonal;
	int **m;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			p[i][j] = 0;

	m = new int*[n];
	for (int i = 0; i < n; i++)
		m[i] = new int[n];

	for (i = 0; i < n; i++) {
		m[i][i] = 0;
	}
	for(diagonal=1;diagonal<n;diagonal++)
		for (i = 0; i < n - diagonal; i++) {
			j = i + diagonal;
			for (k = i; k < j; k++) {
				if (k == i) {
					m[i][j] = m[i][k] + m[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
					p[i][j] = k + 1;
				}
				else if (m[i][j] > (m[i][k] + m[k + 1][j] + d[i] * d[k + 1] * d[j + 1])) {
					m[i][j] = m[i][k] + m[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
					p[i][j] = k+1;
				}
			}
		}

	return m[0][n-1];


}

void order(int i, int j, int **p) {
	int k;
	if (i == j) cout << "A" << i+1;
	else {
		k = p[i][j];
		cout << "(";
		order(i, k-1,p);
		order(k, j,p);
		cout << ")";
	}

}

