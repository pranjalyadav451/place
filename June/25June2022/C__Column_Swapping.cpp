/*
name: C. Column Swapping
group: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
url: https://codeforces.com/problemset/problem/1684/C
interactive: false
memoryLimit: 256
timeLimit: 1000
Started At: 2:41:43 PM
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

pll check(vvl &A, vvl &C, int n, int m) {

	set<pll> anomalies;
	pll cant = pair(-1, -1), trivial = pair(1, 1);

	for (int i = 0; i < n; i++) {
		if (C[i].size() == 0) continue;
		if (C[i].size() != 2) return cant;
		anomalies.insert(pair(C[i][0], C[i][1]));
	}

	if (anomalies.size() != 1) return  (anomalies.size() == 0) ? trivial : cant;
	pll anomaly = *anomalies.begin();

	for (int i = 0; i < n; i++) {
		if (C[i].size() == 0) {
			if (A[i][anomaly.first] != A[i][anomaly.second]) return cant;
		}
	}
	return pair(anomaly.first + 1, anomaly.second + 1);
}


void solve() {
	ll n , m; cin >> n >> m;
	vvl A(n, vll(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> A[i][j];
	}
	vvl B = A;
	for (int i = 0; i < n; i++) sort(all(B[i]));

	vvl C(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j]) {
				C[i].push_back(j);
			}
		}
	}

	pll is = check(A, C, n, m);
	if (is != pair(-1LL, -1LL)) cout << is.first << " " << is.second << endl;
	else cout << -1 << endl;
}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}