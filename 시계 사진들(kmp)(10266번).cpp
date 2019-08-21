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

int input[200000] = { 0 };

int *sub1, *sub2, *fail;

int max1 = -1, max2 = -1, index1 = -1, index2 = -1;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;

	sub1 = new int[2*n-1]();
	sub2 = new int[n]();
	fail = new int[n]();

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			sub1[i] = input[i + 1] - input[i];
		}
		else {
			sub1[i] = input[0] - input[i]+360000;
		}
		if (max1 < sub1[i]) {
			max1 = sub1[i];
			index1 = i;
		}
	}
	for (int i = n; i < 2*n - 1; i++) {
		sub1[i] = sub1[i - n];
	}
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			sub2[i] = input[i + 1] - input[i];
		}
		else {
			sub2[i] = input[0] - input[i] + 360000;
		}
		if (max2 < sub2[i]) {
			max2 = sub2[i];
			index2 = i;
		}
	}

	
	for (int i = 1, j = 0; i < n && j < n && i+j<n;) {
	
		if (sub2[i+j] != sub2[j]) {
			if (j == 0)
				i++;
			else {
				i = i + j - fail[j-1];
				j = fail[j-1];
			}
		}
		else {
			fail[i + j] = j + 1;
			j++;
		}
	}
	


	int i = 0, j=0;
	while (i < n) {
	
		if (sub1[i+j] != sub2[j]) {
			if (j == 0)
				i++;
			else {
				i = i + j - fail[j - 1];
				j = fail[j - 1];
			}
		}
		else {
			if (j == n - 1)
				break;
			else
				j++;
		}
		
	}
	if (i < n)
		cout << "possible";
	else
		cout << "impossible";
}

