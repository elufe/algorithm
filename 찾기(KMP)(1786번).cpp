#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<string>

#include<math.h>

using namespace std;

int a[1000001];
int index[1000001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string t, p;
	int x = 0, count = 0;

	getline(cin, t);
	getline(cin, p);


	int plength = p.length();
	int tlength = t.length();


	for (int i = 1, j = 0; i < plength;) {
		if (p[j] != p[i]) {
			//			a[i] = 0;
			if (j == 0)
				i++;
			j=a[j-1];
		}
		else {
			a[i] = j + 1;
			i++;
			j++;
		}
	}


	int j = 0;
	for (int i = 0; i <= tlength - plength;) {
		while (j < plength) {
			if (t[i + j] != p[j]) {
				if (j == 0) {
					i++;
					j = 0;
				}
				else {
					i += j - a[j - 1];
					j = a[j - 1];
				}
				break;
			}
			else if (j == (plength - 1)) {
				index[x++] = i + 1;
				count++;
				i += plength - a[plength - 1];
				j = a[plength - 1];
				break;
			}
			else
				j++;
		}
	}
	cout << count << "\n";

	for (int i = 0; index[i] != 0; i++)
		cout << index[i] << " ";
}