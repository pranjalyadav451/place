/*
https://codeforces.com/contest/1670/problem/C
Time Limit: 1000
Memory Limit: 256
Fri May 06 2022 21:07:48 GMT+0530 (India Standard Time)
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

const ll MOD = 1e9 + 7;

vector<bool> visited;
void dfs(vvl &graph, int node) {
	if (visited[node]) return;
	visited[node] = 1;
	for (auto a : graph[node]) {
		dfs(graph, a);
	}
}


long long binpow(long long a, long long b, long long m) {
	a %= m;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}


void solve() {
	ll N; cin >> N;
	vll A(N), B(N) , D(N);
	visited.assign(N + 1, false);

	REP(i, 0, N - 1) cin >> A[i];
	REP(i , 0 , N - 1) cin >> B[i];
	REP(i , 0 , N - 1) cin >> D[i];

	vvl graph(N + 1);
	for (int i = 0; i < N; i++) {
		if (A[i] == B[i]) continue;
		graph[A[i]].push_back(B[i]);
		graph[B[i]].push_back(A[i]);
	}
	ll cnt = 0;
	for (int i = 0; i < N; i++) {
		if ((D[i] != 0 or (A[i] == B[i])) and visited[A[i]] == false) {
			dfs(graph, A[i]);
		}
		else if (!visited[A[i]] and D[i] == 0) {
			dfs(graph, A[i]);
			cnt++;
		}
	}

	ll ans = binpow(2LL, cnt, MOD);
	cout << ans << endl;
}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}