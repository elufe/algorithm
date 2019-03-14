#include<iostream>

using namespace std;

int N;
int count;


void f(int n, int sum, int index, int*array) {
//	cout << "f(" << n << "," << sum << "," << index << ")" << endl;
	for (int x = n; x > 0; x--) {
		if (index == 0) {
			array[index] = x - 1;
			f(n - (x - 1), x - 1, index + 1,array);
		}
		else {
			array[index] = x;
			if (x <= array[index - 1]) {
				f(n - x, sum + x, index + 1,array);
			}
		}
	}
	
	if (N == sum) {
		for (int i = 0; i < index; i++) {
			cout << array[i];
			if (i != index-1)
				cout << "+";
		}
		cout << endl;
	}
}

int main() {
	cin >> N;
	int *array;
	array = new int[N];
	f(N, 0, 0,array);
}