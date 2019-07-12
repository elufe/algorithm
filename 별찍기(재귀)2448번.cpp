#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>

#include<math.h>

using namespace std;

void dot(int x, int y, char **arr, int length);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,k,l;
	char **arr;//[3072][6143] = { '\0' };

	arr = new char*[3072]();
	for (int i = 0; i < 3072; i++)
		arr[i] = new char[6143]();

	cin >> n;
	dot(0, n - 1, arr, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n/3 * 5 + n/3 - 1); j++) {
			if (arr[i][j] == '*')
				cout << arr[i][j];
			else
				cout << ' ';
		}
//		cout << "333"<<endl;
	
		if(i<n-1)
			cout << endl;
	}


}

void dot(int x, int y, char **arr, int length) {
	if (length == 3) {
		arr[x][y] = '*';
		arr[x + 1][y - 1] = '*';
		arr[x + 1][y + 1] = '*';
		arr[x + 2][y - 2] = '*';
		arr[x + 2][y - 1] = '*';
		arr[x + 2][y] = '*';
		arr[x + 2][y + 1] = '*';
		arr[x + 2][y + 2] = '*';
		return;
	}
	else {
		dot(x, y, arr, length / 2);
		dot(x + length / 2, y - length / 2, arr, length / 2);
		dot(x + length / 2, y + length / 2, arr, length / 2);
	}
}