/*
https://codeforces.com/contest/1668/problem/C
Time Limit: 2000
Memory Limit: 256
Tue Apr 19 2022 20:38:53 GMT+0530 (India Standard Time)
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

ll min_moves(vll &arr, int pos, int N) {
	ll moves = 0;
	vll brr(N);

	for (int i = pos + 1 ; i < N; i++) {
		ll q = brr[i - 1] / arr[i];
		brr[i] = arr[i] * (q + 1);
		moves += q + 1;
	}
	for (int i = pos - 1; i >= 0; i--) {
		ll q = abs(brr[i + 1] / arr[i]);
		brr[i] = -(arr[i] * (q + 1));
		moves += q + 1;
	}
	return moves;
}

void solve() {
	ll N;
	cin >> N;
	vll arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	ll moves = 1e18;
	for (int i = 0; i < N; i++) {
		ll current = min_moves(arr, i, N);
		if (moves > current) moves = current;
	}
	cout << moves << endl;
}
int main() {
	int tt = 1;
	// cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}