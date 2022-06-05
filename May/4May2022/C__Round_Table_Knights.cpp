/*
https://codeforces.com/contest/71/problem/C
Time Limit: 500
Memory Limit: 256
Wed May 04 2022 22:50:46 GMT+0530 (India Standard Time)
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

vll divisors(ll N) {
	vll res;
	for (int i = 1; i * i <= N; i++) {
		ll one = -1, other = -1;
		if (N % i == 0) {
			one  = i; other = N / i;
		}
		// dbgg(one, other);
		if (one != - 1 and one < (N + 1) / 2) res.push_back(one);
		if (other != - 1 and other < (N + 1 ) / 2) res.push_back(other);
	}
	return res;
}

bool go(ll i, ll K, ll N, vll &arr) {
	ll start = i;
	// dbgg(i, K);

	do {
		if (arr[i] == 1) {
			i = (i + K) % N;
		}
		else {
			return false;
		}
	}
	while (start != i);

	return start == i;
}


void solve() {
	ll N; cin >> N; vll arr(N); for (auto &a : arr) cin >> a;

	vll good;
	for (auto &a : arr) if (a == 1) good.push_back(&a - &arr[0]);


	vll opt = divisors(N);

	// cout << opt << endl;

	bool ans = false;
	for (int i = 0; i < opt.size(); i++) {
		int K = opt[i];

		for (int j = 0; j < K; j++) {
			if (arr[j] == 1) {
				ans |= go(j, K, N, arr);
			}
		}
		if (ans) break;
	}
	cout << (ans ? "YES" : "NO") << endl;

}
int main() {
	int tt = 1;
	// cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}