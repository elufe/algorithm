#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<list>

#include<math.h>

	using namespace std;
	
	int n, m;
	
	int main() {
		cin.tie(NULL);
		ios::sync_with_stdio(false);

		cin >> n >> m;
		check = new int*[n + 1]();
		for (int i = 0; i <= n; i++)
			check[i] = new int[2]();

		q = new queue<int>[n + 1];
		
		int a, b;
		for (int i = 1; i <= m; i++) {
			cin >> a >> b;
			q[a].push(b);
			q[b].push(a);
		}

		int x = 0 ,length=-1;
		
		qq.push(1);
	//	check[1][0] = 1;
	//	check[1][1] = 0;

		while (!qq.empty()) {
			length++;
			while (!qq.empty()) {
				if (check[qq.front()][0] == 0) {
					qqq.push(qq.front());
					check[qq.front()][0] = 1;
					check[qq.front()][1] = length;
				}
				qq.pop();
			}

			while (!qqq.empty()) {
				while (!q[qqq.front()].empty()) {
					qq.push(q[qqq.front()].front());
					q[qqq.front()].pop();
				}
				qqq.pop();
			}
		}
		
		int count = 0, index = 0 ;
		for (int i = 1; i <= n; i++) {
			if (check[i][1] == length-1) {
				count++;
				if (index == 0)
					index = i;
			}
		}
		cout << index << " " << length - 1 << " " << count;
		
	}
