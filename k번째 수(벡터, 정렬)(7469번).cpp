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

struct node {
	int num;
	int seq;
	node(int a, int b) {
		num = a;
		seq = b;
	}
};


bool compare(struct node a, struct node b) {
	return a.num < b.num;
}


vector<struct node> v;



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	int x;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(node(x, i + 1));
	}
	
	sort(v.begin(), v.end(), compare);

	int a, b, c;
	int count = 0;
	int j;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		count = 0;
		for (j = 0; j < v.size(); j++) {
			if (v[j].seq >= a && v[j].seq <= b) {
				count++;
			}
			if (count == c)
				break;
		}
		cout << v[j].num<<"\n";
	}

}

