#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9 + 7;
const ld eps  = 1e-9 ;
const ll maxn = 1e5 + 1;
const ll inf  = 5e18 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

bool solve()
{
	ll n, x;
	cin >> n >> x;
	vector<ll> v(n);

	for (ll i = 0 ; i < n ; ++i) cin >> v[i];

	ll minm = *min_element(v.begin(), v.end());
	ll maxm = *max_element(v.begin(), v.end());

	ll ans = 0;

	for (ll i = 1 ; i < n ; ++i) {
		ans += abs(v[i] - v[i - 1]);
	}

	ll minm_add = 0, maxm_add = 0;
	if (1 < minm) {
		minm_add = min({2 * (minm - 1), v[0] - 1, v[n - 1] - 1});
	}

	if (x > maxm) {
		maxm_add = min({2 * (x - maxm), x - v[0], x - v[n - 1]});
	}

	cout << ans + minm_add + maxm_add << endl;
	return true;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t = 1;
	cin >> t;
	while (t--)
	{
		if (solve())
		{
			// cout << "YES" << endl;
		}
		else
		{
			// cout << "NO" << endl;
		}
	}
	return 0;
}