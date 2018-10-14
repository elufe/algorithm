#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void strassen(int, int **, int **, int **);
int** add(int n, int **A, int **B);
int** sub(int n, int **A, int **B);

int main() {
	int **A, **B, **C;
	int n = 0;

	printf("n:");
	scanf("%d", &n);
	A = new int*[n];
	B = new int*[n];
	C = new int*[n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
		B[i] = new int[n];
		C[i] = new int[n];
	}

	printf("A:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	printf("B:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &B[i][j]);
		}
	}

	strassen(n, A, B, C);

	for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++)
		printf("%4d", C[i][j]);
	cout << "\n";
}
}

void strassen(int n, int **A, int **B, int **C) {
	if(n <=1){
		C[0][0] = A[0][0] * B[0][0];
		cout << C[0][0]<<"\n";
	}
	else
	{
		int size = n / 2;
		int **A11 = new int*[size], **A12 = new int*[size], **A21 = new int*[size], **A22 = new int*[size];
		int **B11 = new int*[size], **B12 = new int*[size], **B21 = new int*[size], **B22 = new int*[size];
		int **C11 = new int*[size], **C12 = new int*[size], **C21 = new int*[size], **C22 = new int*[size];
		int **M1 = new int*[size], **M2 = new int*[size], **M3 = new int*[size], **M4 = new int*[size], **M5 = new int*[size], **M6 = new int*[size], **M7 = new int*[size];
		int **ADD1 = new int*[size], **ADD2 = new int*[size];

		
		//배열 생성
		for (int i = 0; i < size; ++i) {
			A11[i] = new int[size];
			A12[i] = new int[size];
			A21[i] = new int[size];
			A22[i] = new int[size];
			B11[i] = new int[size];
			B12[i] = new int[size];
			B21[i] = new int[size];
			B22[i] = new int[size];
			C11[i] = new int[size];
			C12[i] = new int[size];
			C21[i] = new int[size];
			C22[i] = new int[size];
			M1[i] = new int[size];
			M2[i] = new int[size];
			M3[i] = new int[size];
			M4[i] = new int[size];
			M5[i] = new int[size];
			M6[i] = new int[size];
			M7[i] = new int[size];
			ADD1[i] = new int[size];
			ADD2[i] = new int[size];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0;j<n;j++){
		//		cout << i << " " << j;
		//		cout << A[0][0];
			if (i < size&&j < size)
				A11[i][j]=A[i][j];
			else if (i < size&&j >= size)
				A12[i][j-size] = A[i][j];
			else if (i >= size && j < size)
				A21[i-size][j] = A[i][j];
			else
				A22[i-size][j-size] = A[i][j];
		}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i < size&&j < size)
					B11[i][j] = B[i][j];
				else if (i < size&&j >= size)
					B12[i][j - size] = B[i][j];
				else if (i >= size && j < size)
					B21[i - size][j] = B[i][j];
				else
					B22[i - size][j - size] = B[i][j];
			}
		}
		

		ADD1 = add(size, A11, A22);
		ADD2 = add(size, B11, B22);
		strassen(size, ADD1, ADD2, M1);
		if (size == 1)
			cout << "M1" << M1[0][0] << "\n";
		ADD1 = add(size, A21, A22);
		strassen(size, ADD1, B11, M2);
		if (size == 1)
			cout << "M2" << M2[0][0] << "\n";
		ADD1 = sub(size, B12, B22);
		strassen(size, A11, ADD1, M3);
		if (size == 1)
			cout << "M3" << M3[0][0] << "\n";
		ADD1 = sub(size, B21, B11);
		strassen(size, A22, ADD1, M4);
		if (size == 1)
			cout << "M4" << M4[0][0] << "\n";
		ADD1 = add(size, A11, A12);
		strassen(size, ADD1, B22, M5);
		if (size == 1)
			cout << "M5" << M5[0][0] << "\n";
		ADD1 = sub(size, A21, A11);
		ADD2 = add(size, B11, B12);
		strassen(size, ADD1, ADD2, M6);
		if (size == 1)
			cout << "M6" << M6[0][0] << "\n";
		ADD1 = sub(size, A12, A22);
		ADD2 = add(size, B21, B22);
		strassen(size, ADD1, ADD2, M7);
		if (size == 1)
			cout << "M7" << M7[0][0] << "\n";
		
		C11 = add(size, sub(size,  add(size, M1, M4)  , M5), M7);
		C12 = add(size, M3, M5);
		C21 = add(size, M2, M4);
		C22 = add(size, sub(size, add(size, M1, M3), M2), M6);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i < size&&j < size)
					C[i][j]=C11[i][j];
				else if (i < size&&j >= size)
					C[i][j] = C12[i][j - size];
				else if (i >= size && j < size)
					C[i][j] = C21[i - size][j];
				else
					C[i][j] = C22[i - size][j - size];
			}
		}

	
		
	}

}

int** add(int n, int **A, int **B) {
	int **C = new int*[n];
	for (int i = 0; i < n; ++i) 
		C[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			C[i][j] = A[i][j] + B[i][j];
	}
	return C;
}

int** sub(int n, int **A, int **B) {
	int **C = new int*[n];
	for (int i = 0; i < n; ++i)
		C[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			C[i][j] = A[i][j] - B[i][j];
	}
	return C;
}

