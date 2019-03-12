#include<iostream>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> st;
	queue<int> q;
	int a, b, s, x, y, cnt = 1;
	int *check_in, *check_out;
	cin >> a >> b >> s;
	int **array = new int *[a];
	check_in = new int[a]();
	check_out = new int[a]();

	for (int i = 0; i < a; i++) {
			array[i] = new int[a]();
		}

	for (int i = 0; i < b; i++) {
		cin >> x >> y;
		array[x - 1][y - 1] = array[y - 1][x - 1] = 1;
	}
	int s1 = s;
	cout << s1 << " ";
	check_in[s1 - 1] = 1;
	check_out[s1 - 1] = 1;
	while (cnt != a) {
		
		for (int i = a-1; i >= 0; i--) {
			if (array[s1 - 1][i] == 1 && check_out[i] == 0) {
				st.push(i + 1);
			}
		}
		
		while (st.empty() == 0 && check_out[st.top() - 1] != 0) {
				st.pop();
		}
		if (st.empty()) {
			break;
		}
		else {
			s1 = st.top();
			check_out[s1 - 1]++;
			st.pop();
		}
		if (cnt < a - 1) {
			cout << s1 << " ";
		}
		else
			cout << s1<<endl;
		cnt++;

	}
	cnt = 1;
	check_out = new int[a]();
	check_out[s - 1] = 1;
	cout << s << " ";
	while (cnt != a) {
		for (int i = 0; i < a; i++) {
			if (array[s - 1][i] == 1 && check_in[i] == 0&&check_out[i]==0) {
				q.push(i + 1);
				check_in[i]++;
			}
		}
		if (q.empty() == 0) {
			check_out[q.front() - 1]++;
			s = q.front();
			if (cnt < a - 1)
				cout << s << " ";
			else
				cout << s;
			cnt++;

			q.pop();

		}
		else
			break;
		
	}
}

