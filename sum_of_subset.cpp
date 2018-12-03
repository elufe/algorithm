#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void sum_of_subset(int, int, int, int*, bool*, int);
bool promising(int i, int weight, int total, int *w, int W);


int main() {
	int n, *w, total=0,W;
	bool  *include;
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

	sum_of_subset(-1, 0, total, w, include,W);

}

void sum_of_subset(int i, int weight, int total, int *w, bool *include, int	W) {
	int cnt = 0;
	if (promising(i,weight,total,w,W)) {
		if (weight == W) {
			cout << "{";
			for (int j = 0; j <=i; j++)				
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
			sum_of_subset(i + 1, weight + w[i + 1], total - w[i + 1], w, include, W);
			include[i + 1] = false;
			sum_of_subset(i + 1, weight, total - w[i + 1], w, include, W);

		}
			
	}

}

bool promising(int i, int weight, int total, int *w, int W) {
	return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}