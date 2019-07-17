#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<string.h>

#include<math.h>

using namespace std;


char *a, *temp, *bomb;
int i;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	a = new char[1000001]();
	temp = new char[1000001]();
	bomb = new char[37]();

	cin >> a;
	cin >> bomb;

	int alength, blength;
	int index = 0;
	int count = 0;
	int j = 1;
	for (alength = 0; alength < 10000001 && a[alength] != '\0'; alength++);
	for (blength = 0; blength < 37 && bomb[blength] != '\0'; blength++);

	for (int i = 0; i < alength; i++) {
		temp[index] = a[i];
		if (temp[index] == bomb[blength - 1]) {
			j = 0;
			if (index - blength + 1 >= 0) {
				while (temp[index - j] == bomb[blength - 1 - j]) {
					j++;
					if (blength - 1 - j < 0)
						break;
					if (index - j < 0)
						break;
				}
			}
			if (blength - 1 - j < 0) {
				index = index - j + 1;
				j = index;
				while (temp[j] != '\0') {
					temp[j] = '\0';
					j++;
				}
			}
			else
				index++;
		}
		else
			index++;
	}
	if (temp[0] == '\0')
		cout << "FRULA";
	else
		cout << temp;
}

