#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void hamiltonian(int);

int n, **w, *vindex;
bool promising(int);

int main() {
	cout << "n?";
	cin >> n;
	w = new int*[n];
	for (int i = 0; i < n; i++)
		w[i] = new int[n];
	cout << "w?" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	vindex = new int[n];
	vindex[0] = 1;
	hamiltonian(0);

}

void hamiltonian(int i) {
	int j;

	if (promising(i)) {
		if (i == n - 1) {
			cout << "{";
			for (j = 0; j < n; j++)
				cout << "v" << vindex[j] << " ";
			cout << "}";
		}
		else
			for (j = 2; j <= n; j++) {
				vindex[i + 1] = j;
				hamiltonian(i + 1);
			}
	}
}

bool promising(int i) {
	int j;
	bool sw;
	if (i == n - 1 && !w[vindex[n - 1]-1][vindex[0]-1])
		sw = false;
	else if (i > 0 && !w[vindex[i - 1]-1][vindex[i]-1])
		sw = false;
	else {
		sw = true;
		j = 0;
		while (j < i && sw) {
			if (vindex[i] == vindex[j])
				sw = false;
			j++;
		}
	}
	return sw;
}