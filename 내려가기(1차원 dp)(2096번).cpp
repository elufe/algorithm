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

int n;

int max1[7] = { 0 }, min1[7] = { 0 };

int max2[7] = { 0 }, min2[7] = { 0 };

int input[3];

int max3(int a, int b) {
	return a >= b ? a : b;
}

int min3(int a, int b) {
	return a <= b ? a : b;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a=-1, b=2100000000;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> input[0] >> input[1] >> input[2];
		
		max2[0] = max3(max1[0], max1[1])+ input[0];
		max2[1] = max3(max3(max1[2], max1[3]), max1[4]) + input[0];
		max2[2] = max3(max1[0], max1[1]) + input[1];
		max2[3] = max3(max3(max1[2], max1[3]), max1[4]) + input[1];
		max2[4] = max3(max1[5],max1[6]) + input[1];
		max2[5] = max3(max3(max1[2], max1[3]), max1[4]) + input[2];
		max2[6] = max3(max1[5], max1[6]) + input[2];

		min2[0] = min3(min1[0], min1[1]) + input[0];
		min2[1] = min3(min3(min1[2], min1[3]), min1[4]) + input[0];
		min2[2] = min3(min1[0], min1[1]) + input[1];
		min2[3] = min3(min3(min1[2], min1[3]), min1[4]) + input[1];
		min2[4] = min3(min1[5], min1[6]) + input[1];
		min2[5] = min3(min3(min1[2], min1[3]), min1[4]) + input[2];
		min2[6] = min3(min1[5], min1[6]) + input[2];
		
		max1[0] = max2[0];
		max1[1] = max2[1];
		max1[2] = max2[2];
		max1[3] = max2[3];
		max1[4] = max2[4];
		max1[5] = max2[5];
		max1[6] = max2[6];

		min1[0] = min2[0];
		min1[1] = min2[1];
		min1[2] = min2[2];
		min1[3] = min2[3];
		min1[4] = min2[4];
		min1[5] = min2[5];
		min1[6] = min2[6];
			
	}
	for (int i = 0; i < 7; i++) {
		if (a < max2[i])
			a = max2[i];
		if (b > min2[i])
			b = min2[i];
	}
	cout << a << " " << b;
}

