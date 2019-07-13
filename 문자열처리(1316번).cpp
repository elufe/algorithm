#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>

#include<math.h>

using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,count=0;
	char **arr;

	cin >> n;
	arr = new char*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[100]();
		cin >> arr[i];
	}


	for (int i = 0; i < n; i++) {
		int a[26] = { 0 };
		for (int j = 0; j < 100 && arr[i][j] != '\0'; j++) {
			if (j != 0 && arr[i][j] != arr[i][j - 1] && a[arr[i][j] - 'a'] != 0) {
				break;
			}
			a[arr[i][j] - 'a']++;
			if (j == 99 || arr[i][j + 1] == '\0')
				count++;
		}
		
	}
	cout << count;

}

