/*
name: B - Minesweeper
group: AtCoder - AtCoder Beginner Contest 075
url: https://atcoder.jp/contests/abc075/tasks/abc075_b
interactive: false
memoryLimit: 256
timeLimit: 2000
Started At: 2:20:50 PM
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


vvl moves;
void gen_moves() {
	for (ll i = - 1; i <= 1; i++) {
		for (ll j = -1; j <= 1; j++) {
			if (i == 0 and j == 0) continue;
			moves.push_back({i, j});
		}
	}
}
bool is_valid(ll i, ll j , ll h , ll w) {
	return i >= 0 and i < h and j >= 0 and j < w;
}

void solve() {
	ll h , w; cin >> h >> w;
	vector<string>arr(h);
	for (ll i = 0; i < h; i++)
		cin >> arr[i];

	gen_moves();

	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
			if (arr[i][j] == '#')continue;

			ll cnt = 0;
			for (ll k = 0; k < moves.size(); k++) {
				ll x = i + moves[k][0], y = j + moves[k][1];
				if (is_valid(x, y, h, w) and arr[x][y] == '#') {
					cnt++;
				}
			}
			arr[i][j] = cnt + '0';
		}
	}

	for (auto a : arr) {
		cout << a << endl;
	}
}


int main() {
	int tt = 1;
	// cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}