#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct tree {
	int parent = 0;
	int num;
	int x;
	int y;
	int left = 0;
	int right = 0;
}tr;

struct node {
	int num;
	int x;
	int y;
	node(int a, int b, int c) {
		num = a;
		x = b;
		y = c;
	}
};

struct compare {
	bool operator()(node node1, node node2) {
		if (node1.y != node2.y)
			return node1.y < node2.y;
		else
			return node1.x > node2.x;
	}
};

vector<int> v1;
vector<int> v2;

void dfs1(int root, tr t[], vector<vector<int>> v) {
	v1.push_back(root);
	if (t[root].left > 0)
		dfs1(t[root].left, t, v);
	if (t[root].right > 0)
		dfs1(t[root].right, t, v);
	return;
}

void dfs2(int root, tr t[], vector<vector<int>> v) {

	if (t[root].left > 0)
		dfs2(t[root].left, t, v);
	if (t[root].right > 0)
		dfs2(t[root].right, t, v);
	v2.push_back(root);
	return;
}

priority_queue<node, vector<node>, compare> pq;

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	int size = nodeinfo.size();

	tr t[10001];

	for (int i = 0; i < size; i++) {
		pq.push(node(i + 1, nodeinfo[i][0], nodeinfo[i][1]));
	}

	int p, l, r, num, x, y, root, start;
	num = pq.top().num;
	x = pq.top().x;
	y = pq.top().y;
	pq.pop();
	t[num].num = num;
	t[num].x = x;
	t[num].y = y;
	t[num].parent = -1;
	root = num;

	while (!pq.empty()) {
		num = pq.top().num;
		x = pq.top().x;
		y = pq.top().y;
		pq.pop();

		t[num].num = num;
		t[num].x = x;
		t[num].y = y;
		start = root;

		while (1) {

			if (x < t[start].x && t[start].left == 0) {
				t[num].parent = start;
				t[start].left = num;
				break;
			}
			else if (x > t[start].x && t[start].right == 0) {
				t[num].parent = start;
				t[start].right = num;
				break;
			}
			else if (x < t[start].x) {
				start = t[start].left;
			}
			else if (x > t[start].x) {
				start = t[start].right;
			}
		}
	}


	dfs1(root, t, answer);
	dfs2(root, t, answer);

	answer.push_back(v1);
	answer.push_back(v2);

	return answer;
}