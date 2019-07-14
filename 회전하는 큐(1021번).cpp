#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>

#include<math.h>

using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int size, n, x, tmp, c=0,count = 0;

	queue<int> q;

	cin >> size >> n;

	for (int i = 1; i <= size;i++)
		q.push(i);

	for (int i = 0; i < n; i++) {
		cin >> x;
		
		while (q.front() != x) {
			tmp = q.front();
			q.pop();
			q.push(tmp);
			c++;
		}
		q.pop();
		if (c > size / 2)
			count += size - c;
		else
			count += c;
		c = 0;
		size--;

	}
	cout << count;

}