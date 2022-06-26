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

const int N = 2e5 + 7;
const int INF = 1e9;
int c[N];
pll dp[N][2];

void solve() {
	ll n; cin >> n;
	string s; cin >> s;

	for (int i = 1; i <= n; i++)
		s[i] -= '0';
	for (int i = 1; i <= n / 2; i++)
		c[i] = s[i * 2] + s[i * 2 - 1] * 2;

	for (int i = 1; i <= n / 2; i++)
		for (int j = 0; j < 2; j++)
			dp[i][j] = {INF, INF};


	for (int i = 1; i <= n / 2; i++)
		for (int j = 0; j < 2; j++) {
			int cc = c[i], dd = j ? 3 : 0, cnt = ((dd % 2) ^ (cc % 2)) + ((dd / 2) ^ (cc / 2));
			for (int k = 0; k < 2; k++)
				dp[i][j] = min(dp[i][j], {dp[i - 1][k].first + cnt, dp[i - 1][k].second + (j != k)});
		}

	pll ans = min(dp[n / 2][0], dp[n / 2][1]);
	cout << ans.first << " " << ans.second + 1 << "\n";
}

int main() {
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
}