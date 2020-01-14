#include <iostream>
#include <cstdio>
using namespace std;

int q1[8] = { 0 };
int q2[8] = { 0 };
int q3[8] = { 0 };
int q4[8] = { 0 };

int q1s = 0;
int q2s = 0;
int q3s = 0;
int q4s = 0;

int main() {

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	char input;
	int k, a, b, spincheck1=0, spincheck2 = 0, spincheck3 = 0, spincheck4 = 0;

	for (int i = 0; i < 8; i++) {
		input = getchar();
		q1[i] = input - '0';
	}
	getchar();
	for (int i = 0; i < 8; i++) {
		input = getchar();
		q2[i] = input - '0';
	}
	getchar();
	for (int i = 0; i < 8; i++) {
		input = getchar();
		q3[i] = input - '0';
	}
	getchar();
	for (int i = 0; i < 8; i++) {
		input = getchar();
		q4[i] = input - '0';
	}

	

	// q1s+2 : q2e-1 / q2s+2 : q3e-1 / q3s+2 : q4e-1 

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a;
		if (a == 1) {
			cin >> spincheck1;
			if (q1[(q1s + 2) % 8] != q2[(q2s + 6) % 8]) {
				spincheck2 = spincheck1 * (-1);
				if (q2[(q2s + 2) % 8] != q3[(q3s + 6) % 8]) {
					spincheck3 = spincheck2 * (-1);
					if (q3[(q3s + 2) % 8] != q4[(q4s + 6) % 8])
						spincheck4 = spincheck3 * (-1);
				}

			}
			q1s = (q1s - spincheck1) % 8;
			if (q1s < 0)
				q1s = 8 + q1s;
			q2s = (q2s - spincheck2) % 8;
			if (q2s < 0)
				q2s = 8 + q2s;
			q3s = (q3s - spincheck3) % 8;
			if (q3s < 0)
				q3s = 8 + q3s;
			q4s = (q4s - spincheck4) % 8;
			if (q4s < 0)
				q4s = 8 + q4s;
			
		}
		else if (a == 2) {
			cin >> spincheck2;
			if (q1[(q1s + 2) % 8] != q2[(q2s + 6) % 8]) {
				spincheck1 = spincheck2 * (-1);
			}
			if (q2[(q2s + 2) % 8] != q3[(q3s + 6) % 8]) {
				spincheck3 = spincheck2 * (-1);
				if (q3[(q3s + 2) % 8] != q4[(q4s + 6) % 8])
					spincheck4 = spincheck3 * (-1);
			}
			q1s = (q1s - spincheck1) % 8;
			if (q1s < 0)
				q1s = 8 + q1s;
			q2s = (q2s - spincheck2) % 8;
			if (q2s < 0)
				q2s = 8 + q2s;
			q3s = (q3s - spincheck3) % 8;
			if (q3s < 0)
				q3s = 8 + q3s;
			q4s = (q4s - spincheck4) % 8;
			if (q4s < 0)
				q4s = 8 + q4s;
		}
		else if (a == 3) {
			cin >> spincheck3;
			if (q2[(q2s + 2) % 8] != q3[(q3s + 6) % 8]) {
				spincheck2 = spincheck3 * (-1);
				if (q1[(q1s + 2) % 8] != q2[(q2s + 6) % 8]) {
					spincheck1 = spincheck2 * (-1);
				}
			}
			if (q3[(q3s + 2) % 8] != q4[(q4s + 6) % 8]) {
				spincheck4 = spincheck3 * (-1);
			}
			q1s = (q1s - spincheck1) % 8;
			if (q1s < 0)
				q1s = 8 + q1s;
			q2s = (q2s - spincheck2) % 8;
			if (q2s < 0)
				q2s = 8 + q2s;
			q3s = (q3s - spincheck3) % 8;
			if (q3s < 0)
				q3s = 8 + q3s;
			q4s = (q4s - spincheck4) % 8;
			if (q4s < 0)
				q4s = 8 + q4s;
		}
		else if (a == 4) {
			cin >> spincheck4;
			if (q3[(q3s + 2) % 8] != q4[(q4s + 6) % 8]) {
				spincheck3 = spincheck4 * (-1);
				if (q2[(q2s + 2) % 8] != q3[(q3s + 6) % 8]) {
					spincheck2 = spincheck3 * (-1);
					if (q1[(q1s + 2) % 8] != q2[(q2s + 6) % 8]) {
						spincheck1 = spincheck2 * (-1);
					}
				}
			}

			q1s = (q1s - spincheck1) % 8;
			if (q1s < 0)
				q1s = 8 + q1s;
			q2s = (q2s - spincheck2) % 8;
			if (q2s < 0)
				q2s = 8 + q2s;
			q3s = (q3s - spincheck3) % 8;
			if (q3s < 0)
				q3s = 8 + q3s;
			q4s = (q4s - spincheck4) % 8;
			if (q4s < 0)
				q4s = 8 + q4s;
		}
		
		spincheck1 = spincheck2 = spincheck3 = spincheck4 = 0;
	}
	cout << q1[q1s] * 1 + q2[q2s] * 2 + q3[q3s] * 4 + q4[q4s] * 8;
}