/*
https://codeforces.com/problemset/problem/1649/C
Time Limit: 2000
Memory Limit: 256
Mon May 02 2022 16:52:48 GMT+0530 (India Standard Time)
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



ll proc(vll &arr) {
	int N = arr.size();
	ll current = 0 , sum = 0;

	sort(all(arr));

	for (int i = 1; i < N; i++) {current += arr[i] - arr[0]; }

	sum += current; ll add = 0;

	for (int i = 1; i < N; i++) {ll diff = arr[i] - arr[0]; add = current - diff * (N - i); current -= (arr[i] - arr[0]); sum += add; }

	return sum;
}

void solve() {
	ll N , M; cin >> N >> M;
	vvl arr(N, vll(M));
	REP(i, 0, N - 1) REP(j, 0, M - 1) cin >> arr[i][j];

	map<ll, vpl> pos;
	REP(i, 0, N - 1) {
		REP(j, 0, M - 1) {
			pos[arr[i][j]].push_back(make_pair(i, j));
		}
	}
	ll sum = 0;

	for (auto p : pos) {
		vll row, col;
		for (int i = 0; i < (p.second).size(); i++) {
			row.push_back(p.second[i].first);
			col.push_back(p.second[i].second);
		}
		sum += proc(row) + proc(col);
	}
	cout << sum << endl;

}
int main() {
	int tt = 1;
	while (tt--) {
		solve();
	}

}