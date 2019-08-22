#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<cstring>
#include<string.h>
#include<list>
#include<math.h>

using namespace std;

typedef long long int ll;

ll n, k;

ll sum = 0;

vector<ll>v;

ll input[5001] = { 0 };


ll find(int start, int end, int x) {
	int mid = (start + end) / 2;
	if (v[mid] == x) {
		return mid;
	}
	else {
		if (end - start <= 1) {
			if (v[start] >= x) {
				return start;
			}
			else if (v[end] <= x) {
				return end + 1;
			}
			else
				return end;
		}
		else if (v[mid] >= x) {
			return find(start, mid, x);
		}
		else {
			return find(mid + 1, end, x);
		}
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> k;

	ll x;
	ll backup;
	ll locate;

	for (ll i = 1; i <= n; i++) {
		if (k > 1) {
			if (i%k == 0) {
				backup = input[k];
				cin >> input[k];
			}
			else {
				backup = input[i%k];
				cin >> input[i%k];
			}


			if (i <= k) {
				if (i == 1)
					v.push_back(input[1]);
				else {
					locate = find(0, i - 2, input[i]);
					v.insert(v.begin() + locate, input[i]);
				}
				if (i == k)
					sum += v[(0 + k - 1) / 2];
			}
			else if (i > k) {

				locate = find(0, k - 1, backup);
				if (locate == k)
					v.pop_back();
				else
					v.erase(v.begin() + locate);
				if (i%k == 0) {
					locate = find(0, k - 2, input[k]);
					v.insert(v.begin() + locate, input[k]);

				}
				else {
					locate = find(0, k - 2, input[i%k]);
					v.insert(v.begin() + locate, input[i%k]);

				}


				sum += v[(0 + k - 1) / 2];
			}
		}
		else {
			cin >> input[1];
			sum += input[1];
		}
	}
	cout << sum;
}
