/*
https://codeforces.com/contest/1669/problem/E
Time Limit: 2000
Memory Limit: 256
Thu Apr 21 2022 20:39:44 GMT+0530 (India Standard Time)
*/
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A>                ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>                ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>      ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }


typedef long long                           ll;
typedef pair<ll, ll>                        pll;
typedef vector<vector<ll>>                  vvl;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;
typedef vector<ll>                          vll;

#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl

set<pll>vis;

ll pair_count(vector<string> &arr, vector<ll> &temp, ll N, bool first) {
	vll cntt(26);

	int ptr = first ? 1 : 0;

	for (int i = 0; i < temp.size(); i++) {
		// dbgg(arr[temp[i]], temp[i]);
		cntt[arr[temp[i]][ptr] - 'a']++;
	}

	ll ans = 0;
	for (int i = 0; i < cntt.size(); i++) {
		for (int j = i + 1; j < cntt.size(); j++) {
			if (cntt[i] != 0 and cntt[j] != 0 and vis.count(make_pair(i, j)) == 0) {
				// vis.insert({i, j});
				ans += cntt[i] * cntt[j];
			}
		}
	}
	// dbg(ans);
	// dbg(vis);
	// cout << endl;
	return ans;
}

void solve() {
	vis.clear();


	ll N; cin >> N;
	vector<string> arr(N);

	map<char, vector<ll>> one, two;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		one[arr[i][0]].push_back(i);
		two[arr[i][1]].push_back(i);
	}

	ll ans = 0;

	for (auto t : one) {
		vll temp = t.second;
		ans += pair_count(arr, temp, N, true);
	}
	for (auto t : two) {
		vll temp = t.second;
		ans += pair_count(arr, temp, N, false);
	}
	cout << ans << endl;
}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}