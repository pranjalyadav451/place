/*
https://atcoder.jp/contests/agc040/tasks/agc040_a
Time Limit: 2000
Memory Limit: 1024
Sun Apr 24 2022 17:19:57 GMT+0530 (India Standard Time)
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
	string str; cin >> str;
	ll N = str.size() + 1;

	ll curr = 0, score = 0 , cnt = 0;

	for (int i = 0; i < str.size(); i++) {
		int j = i;
		if (str[i] == '<') {
			while (j < str.size() and str[j] == '<') {
				j++;
				score += curr++;
			}
			// score += curr;
		}
		else {
			score += curr;
			while (j < str.size() and str[j] == '>') {
				j++;
			}
			cnt = j - i;

			if (cnt > curr) {
				score += cnt - curr;
			}
			curr = 0;
			score += (cnt - 1) * (cnt) / 2;
		}
		i = --j;
	}
	if (str.back() == '<') score += curr;
	cout << score << endl;

}
int main() {
	int tt = 1;
	// cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}