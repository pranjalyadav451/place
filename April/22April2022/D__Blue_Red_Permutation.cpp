/*
https://codeforces.com/problemset/problem/1607/D
Time Limit: 1000
Memory Limit: 256
Fri Apr 22 2022 13:50:59 GMT+0530 (India Standard Time)
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
	ll N; cin >> N;
	vector<pair<ll, char>> arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i].first;
	for (int i = 0; i < N; i++) cin >> arr[i].second;

	map<ll, ll> red, blue;
	for (int i = 0; i < N; i++) {
		if (arr[i].second == 'R') red[-arr[i].first]++;
		else blue[arr[i].first]++;
	}
	bool is = true;
	ll prev = 0;

	for (auto a : red) {
		ll val = -a.first , cnt = a.second;
		ll req = N - val + 1 - prev;
		// dbgg(val, cnt);
		// dbgg(req, prev);
		// dbg(a);
		// cout << "\n" << endl;
		if (cnt > req) {
			is = false;
			break;
		}
		prev += cnt;
	}
	prev = 0;
	for (auto a : blue) {
		ll val = a.first , cnt = a.second;
		ll req = val - prev;
		if (cnt > req) {
			is = false;
			break;
		}
		prev += cnt;
	}
	cout << (is ? "YES" : "NO") << endl;
}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}