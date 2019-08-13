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

#define mod 1000000007

typedef long long int ll;

ll a[4000001] = { 0 };
ll input[1000001] = { 0 };
ll n, m, k,ans=1;

ll init(ll start, ll end, ll index);

ll update(ll start, ll end, ll index, ll before, ll after, ll num);

ll multi(ll start, ll end, ll index, ll mstart, ll mend);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	for (ll i = 1; i <= n; i++) {
		cin >> input[i];
	}
	init(1, n, 1);

	ll d, b, c, x;
	for (ll i = 1; i <= m + k; i++) {
		cin >> d >> b >> c;
		if (d == 1) {
			x = input[b];
			input[b] = c;
			if (x == 0)
				init(1, n, 1);
			else
				update(1, n, 1, x, c, b);
		}
		else {
			ans = 1;
			multi(1, n, 1, b, c);
			cout << ans % mod << "\n";
		}

	}

}

ll init(ll start, ll end, ll index) {
	
	ll mid = (start + end) / 2;

	if (start == end) {
		return a[index] = input[start];
	}
	else {
		return a[index] = ((init(start, mid, index * 2) % mod) * (init(mid + 1, end, index * 2 + 1) % mod)) % mod;
	}
}


ll update(ll start, ll end, ll index, ll before, ll after, ll num) {
	ll mid = (start + end) / 2;
	if (start <= num && end >= num) {
		if (start == end)
			return a[index] = after;
		if (mid >= num) {
			return a[index] = ((update(start, mid, index * 2, before, after, num) % mod) * a[index*2+1])%mod;
		}
		else {
			return a[index] = (a[index*2] *(update(mid + 1, end, index * 2 + 1, before, after, num) % mod))%mod;
		}
	}
	else
		return a[index];

}
	
ll multi(ll start, ll end, ll index, ll mstart, ll mend) {

	ll mid = (start + end) / 2;

	if (mstart<=start && end<=mend) {
		ans = ((ans % mod)*(a[index]%mod)) % mod;
		return ans;
	}

	else {
		if (mstart<=mid) {
			multi(start, mid, index * 2, mstart, mend);
		}
		if (mend> mid) {
			multi(mid + 1, end, index * 2 + 1, mstart, mend);
		}

	}

	return 0;

}