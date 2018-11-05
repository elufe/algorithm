#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void optsearchtree(int , float*, float *,int **);

int main() {
	int n, **r;
	float *p, minavg=0;

	cout << "n?";
	cin >> n;

	r = new int *[n + 2];
	for (int i = 0; i <= n + 1; i++) {
		r[i] = new int[n + 1];
	}

	p = new float[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	optsearchtree(n, p, &minavg,r);
}

void optsearchtree(int n, float *p, float *minavg, int **r) {
	float **a, sum_p = 0.0;
	int diagonal=0;
	int i, j, k;

	a = new float *[n+2];
	
	for (i = 0; i <= n+1; i++) {
		a[i] = new float[n+1];
//		r[i] = new int[n+1];
	}

	for (i = 1; i <= n; i++) {
		a[i][i - 1] = 0;
		a[i][i] = p[i-1];
		r[i][i] = i;
		r[i][i - 1] = 0;
	}
	a[n + 1][n] = 0;
	r[n + 1][n] = 0;

	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			sum_p = 0;
			for (k = i; k <= j; k++)
				sum_p += p[k-1];
			for (k = i; k <= j; k++) {
				if (k == i) {
					a[i][j] = a[i][k - 1] + a[k + 1][j] + sum_p;
					r[i][j] = k;
				}
				else if (a[i][j] > a[i][k - 1] + a[k + 1][j] + sum_p) {
					a[i][j] = a[i][k - 1] + a[k + 1][j] + sum_p;
					r[i][j] = k;
				}
			}
		}
	}

	for (i = 0; i <= n + 1; i++) {
		for (j = 0; j <= n; j++) {
			if (a[i][j] > 0)
				cout << a[i][j] << " ";
			else
				cout << "0";
		}
		cout << endl;
	}


	for (i = 0; i <= n + 1; i++) {
		for (j = 0; j <= n; j++) {
			if (a[i][j] > 0)
				cout << r[i][j] << " ";
			else
				cout << "0";
		}
		cout << endl;
	}

	*minavg = a[1][n];

}

