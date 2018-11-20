#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void kruskal(int n, int m, int **e, int **f);

void qsort(int l, int h, int **edge);
void partition(int l, int h, int *p, int **edge);

class disjointset {
private:
	struct node {
		int parent;
		int depth;
	};
	struct node *universe;
public:
	void intial(int);
	void makeset(int);
	int find(int);
	void merge(int, int);
	bool equal(int p, int q);

};


int main() {
	int n,m;
	int p, q,tmp;
	cout << "number of vertex?";
	cin >> n;
	cout << "nuber of edge?";
	cin >> m;
	int **edge, **f;
	edge = new int*[m];
	for (int i = 0; i < m; i++)
		edge[i] = new int[3];
	for (int i = 0; i < m; i++) {
		cin >> p;
		cin >> q;
		if (p > q) {
			tmp = p;
			p = q;
			q = tmp;
		}
		edge[i][0] = p;
		edge[i][1] = q;
		cin >> edge[i][2];
	}
	
	
	f = new int*[n-1];
	for (int i = 0; i < n-1; i++)
		f[i] = new int[3];
	kruskal(n, m, edge, f);
	cout << "MST를 구성하는 edge :" << endl;
	for (int i = 0; i < n - 1; i++)
		cout << f[i][0] << " " << f[i][1] << " " << f[i][2] << endl;

}

void kruskal(int n, int m, int **e, int **f) {
	int i, j;
	int p, q;
	int **edge = e;
	int edge_num=0, f_num=0;

	qsort(0, m - 1, edge);
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < 3; j++)
			f[i][j] = 0;
	disjointset dst;
	dst.intial(n);


	while (f[n - 2][0] == 0) {
//		cout << edge_num << endl;
		i = edge[edge_num][0];
		j = edge[edge_num][1];
//		cout << "i" << i << "j" << j << endl;
		p = dst.find(i);
		q = dst.find(j);
//		cout << "p" << p << "q" << q << endl;

		if (!dst.equal(p, q)) {
			dst.merge(p, q);
			f[f_num][0] = edge[edge_num][0];
			f[f_num][1] = edge[edge_num][1];
			f[f_num][2] = edge[edge_num][2];
//			cout << f[f_num][0] << " " << f[f_num][1] << " " << f[f_num][2] << endl;
			f_num++;
		}

		edge_num++;
	}

}

void qsort(int l, int h, int **edge) {
	int pivot;
	if (h > l) {
		partition(l, h, &pivot, edge);
		qsort(l, pivot - 1, edge);
		qsort(pivot + 1, h, edge);
	}
}
void partition(int l, int h,int *pivot, int **edge) {
	int i, j,tmp;
	int pivotitem;
	int p;

	pivotitem = edge[l][2];
	j = l;
	for(i=l+1;i<=h;i++)
		if (edge[i][2] < pivotitem) {
			j++;
			tmp = edge[i][0];
			edge[i][0] = edge[j][0];
			edge[j][0] = tmp;
			tmp = edge[i][1];
			edge[i][1] = edge[j][1];
			edge[j][1] = tmp;
			tmp = edge[i][2];
			edge[i][2] = edge[j][2];
			edge[j][2] = tmp;
		}
	*pivot = j;
	tmp = edge[l][0];
	edge[l][0] = edge[*pivot][0];
	edge[*pivot][0] = tmp;
	tmp = edge[l][1];
	edge[l][1] = edge[*pivot][1];
	edge[*pivot][1] = tmp;
	tmp = edge[l][2];
	edge[l][2] = edge[*pivot][2];
	edge[*pivot][2] = tmp;

}

void disjointset::intial(int n) {
	universe = new struct node[n+1];
	for (int i = 1; i <= n; i++) {
		makeset(i);
	}
}
void disjointset::makeset(int i) {
	universe[i].parent = i;
	universe[i].depth = 0;

}
int disjointset::find(int i) {
	int j = i;
	while (universe[j].parent != j) {
		j = universe[j].parent;
	}
	return j;
}

void disjointset::merge(int p,int q) {
	if (universe[p].depth == universe[q].depth) {
		universe[p].depth += 1;
		universe[q].parent = p;
	}
	else if (universe[p].depth < universe[q].depth)
		universe[p].parent = q;
	else
		universe[q].parent = p;

}

bool disjointset::equal(int p, int q) {
	if (p == q)
		return true;
	else
		return false;
}