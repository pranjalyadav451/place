/*
https://codeforces.com/contest/1669/problem/H
Time Limit: 2000
Memory Limit: 256
Thu Apr 21 2022 21:51:27 GMT+0530 (India Standard Time)
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


void solve() {
	ll N, K;
	cin >> N >> K;

	vll arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vll cnt(31);

	for (int i = 0; i < N; i++) {
		ll j = 0;
		while (j < 31) {
			ll res = (arr[i]) & (1LL << j);
			if (res)
				cnt[j]++;
			j++;
		}
	}
	// dbg(cnt);
	string res;
	for (int i = cnt.size() - 1; i >= 0; i--) {
		bool one = false;
		if (cnt[i] == N) {
			one = 1;
		}
		else if (K >= N - cnt[i]) {
			one = 1;
			K -= N - cnt[i];
		}
		char ch = '0';
		if (one) ch = '1';
		res.push_back(ch);
	}

	ll ans = 0;
	reverse(all(res));
	for (int i = res.size() - 1; i >= 0; i--) {
		if (res[i] == '1') {
			ans += (1LL << i);
		}
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