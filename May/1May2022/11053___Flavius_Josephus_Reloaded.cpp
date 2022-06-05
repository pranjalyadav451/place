/*
https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1994
Time Limit: 3000
Memory Limit: 32
Sun May 01 2022 17:17:45 GMT+0530 (India Standard Time)
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
typedef unsigned long long 					ull;
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

ull N , A , B;

ull f(ull X) {
	ull ans = (((((A % N) * X) % N) * (X % N)) % N + B) % N;
	return ans;
}



void solve() {
	// Learn Floyd Cycle algorithm.
	ull X0 = 0; ull tor = f(X0) , hare = f(f(X0));
	while (tor != hare) {
		hare = f(f(hare));
		tor = f(tor);
	}

	hare = 0;
	ull mu = 0;
	while (tor != hare) {
		hare = f(hare);
		tor = f(tor);
		mu++;
	}
	hare = f(tor);
	ull lambda = 1;
	while (tor != hare) {
		hare = f(hare);
		lambda++;
	}

	// dbg(N);
	// dbgg(mu, lambda);
	cout << N - lambda << endl;
	// cout << endl;

}
int main() {
	while (cin >> N) {
		if (N == 0) return 0;
		cin >> A >> B;
		solve();
	}

}