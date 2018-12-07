#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void m_coloring(int);
bool promising(int);
int n, m, **w, *vcolor;

int main() {

	cout << "n?";
	cin >> n;
	cout << "m?";
	cin >> m;
	w = new int*[n];
	for (int i = 0; i < n; i++)
		w[i] = new int[n];

	cout << "w?" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	vcolor = new int[n];


	m_coloring(-1);
}

void m_coloring(int i) {
	int color;
	if (promising(i))
		if (i == n - 1) {
			for (int j = 0; j < n; j++)
				cout << vcolor[j] << " ";
			cout << "| ";
		}
		else
			for (color = 1; color <= m; color++) {
				vcolor[i + 1] = color;
				m_coloring(i + 1);
			}
}

bool promising(int i) {
	int j = 0;
	bool s = true;
	while (j < i && s) {
		if (w[i][j] && vcolor[i] == vcolor[j])
			s = false;
		j++;
	}
	return s;
}