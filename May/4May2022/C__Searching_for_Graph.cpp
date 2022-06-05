/*
https://codeforces.com/contest/402/problem/C?f0a28=1
Time Limit: 1000
Memory Limit: 256
Wed May 04 2022 22:50:45 GMT+0530 (India Standard Time)
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
	ll N , P; cin >> N >> P;
	ll edges = 2 * N + P , vert = N;
	map<int, int> e_cnt;
	set<pll> visited;

	for (ll i = 0; i < N; i++) {
		if (e_cnt[i] >= 2) continue;
		ll next = (i - 1 + N) % N , nextt = (i + 1) % N;
		pll node1 = make_pair(min(i, next) + 1, max(i, next) + 1);
		pll node2 = make_pair(min(i, nextt) + 1, max(i, nextt) + 1);

		if (visited.count(node1) == 0) {
			visited.insert(node1);
			e_cnt[i]++;
			e_cnt[next]++;
		}
		if (visited.count(node2) == 0) {
			visited.insert(node2);
			e_cnt[i]++;
			e_cnt[nextt]++;
		}
	}
	edges -= visited.size();
	ll check = edges;

	ll step = 2 , curr = 0;
	while (edges != 0) {
		ll next = (curr + step) % N;
		pll node1 = make_pair(min(curr, next) + 1, max(curr, next) + 1);

		if (visited.count(node1) == 0) {
			visited.insert(node1);
			e_cnt[curr]++;
			e_cnt[next]++;
			edges--;
		}
		curr ++;
		if (curr == N) {
			step++;
			curr = 0;
		}
	}

	for (auto a : visited) {
		cout << a.first << " " << a.second << endl;
	}

}

int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}