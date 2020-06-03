#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> v(20, vector<int>(20.0));

int n;
int sub = 40001;
int temp = 0;

void dfs(int index, int num_a, int sum_a, vector<int>a, int num_b, int sum_b, vector<int> b) {
	
	if (num_a == n / 2 && num_b == n/2) {
		temp = abs(sum_a - sum_b);
		if (sub > temp) {
			sub = temp;
		}
		return;
	}
	
	temp = 0;
	if (num_a < n / 2) {
		for (int i = 0; i < a.size(); i++) {
			temp += v[index][a[i]] + v[a[i]][index];
		}
		a.push_back(index);
		dfs(index + 1, num_a + 1, sum_a + temp, a, num_b, sum_b, b);
		a.pop_back();
	}

	temp = 0;
	if (num_b < n / 2) {
		for (int i = 0; i < b.size(); i++) {
			temp += v[index][b[i]] + v[b[i]][index];
		}
		b.push_back(index);
		dfs(index + 1, num_a, sum_a, a, num_b + 1, sum_b + temp, b);
		b.pop_back();
	}

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	
	vector<int> num_a;// (n / 2, 0);
	vector<int> num_b;// (n / 2, 0);
	
	num_a.push_back(0);
	dfs(1, 1, 0, num_a, 0, 0, num_b);
	num_a.pop_back();
	
	num_b.push_back(0);
	dfs(1, 0, 0, num_a, 1, 0, num_b);
	num_b.pop_back();

	cout << sub;
}

