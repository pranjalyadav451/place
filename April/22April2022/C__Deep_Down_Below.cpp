/*
https://codeforces.com/problemset/problem/1561/C
Time Limit: 2000
Memory Limit: 512
Fri Apr 22 2022 18:47:49 GMT+0530 (India Standard Time)
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


pll get_powers(vvl &arr, ll pos) {
	ll N = arr.size();
	ll mn = arr[pos][0] + 1 , end = mn;
	for (int i = 0; i < arr[pos].size(); i++) {
		if (mn <= arr[pos][i]) {
			mn = arr[pos][i] + 1 - i;
			end = arr[pos][i] + 1;
		}
		end = end + 1;
	}
	return make_pair(mn, end);
}

bool comp(const pll &a, const pll&b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

void solve() {
	ll N; cin >> N;

	vvl arr(N);
	for (int i = 0; i < N; i++) {
		ll M; cin >> M;
		for (int j = 0; j < M; j++) {
			ll t; cin >> t;
			arr[i].push_back(t);
		}
	}
	vpl power(N);
	for (int i = 0; i < N; i++) {
		power[i] = get_powers(arr, i);
	}
	sort(all(power), comp);
	auto [mn, curr] = power[0];
	for (int i = 1; i < power.size(); i++) {
		auto [start, end] = power[i];
		if (curr < start) {
			mn = start;
			curr = start;
		}
		curr += (end - start);
	}
	cout << mn << endl;
}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}