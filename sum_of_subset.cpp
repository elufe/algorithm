#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void sum_of_subset(int, int, int);
bool promising(int i, int weight, int total);
int *w, W;
bool *include;
int compare(const void* a, const void* b) {
	const int* x = (int*)a;
	const int* y = (int*)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

int main() {
	int n, total = 0;
	cout << "n?";
	cin >> n;
	cout << "W?";
	cin >> W;
	w = new int[n];
	cout << "w?";
	include = new bool[n];
	for (int i = 0; i < n; i++)
		include[i] = false;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		total += w[i];
	}
	qsort(w, n, sizeof(int), compare);
	cout << w[0];
	sum_of_subset(-1, 0, total);

}

void sum_of_subset(int i, int weight, int total) {
	int cnt = 0;
	if (promising(i, weight, total)) {
		if (weight == W) {
			cout << "{";
			for (int j = 0; j <= i; j++)
				if (include[j]) {
					if (cnt > 0)
						cout << ",";
					cout << "w" << j + 1;
					cnt++;
				}
			cout << "}";
		}
		else {
			include[i + 1] = true;
			sum_of_subset(i + 1, weight + w[i + 1], total - w[i + 1]);
			include[i + 1] = false;
			sum_of_subset(i + 1, weight, total - w[i + 1]);

		}

	}

}

bool promising(int i, int weight, int total) {
	return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}