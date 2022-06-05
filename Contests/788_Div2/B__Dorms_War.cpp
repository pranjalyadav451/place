/*
https://codeforces.com/contest/1670/problem/B
Time Limit: 1000
Memory Limit: 256
Fri May 06 2022 20:12:33 GMT+0530 (India Standard Time)
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

string process(string &pass, set<char>&sp) {
	string pro;
	int N = pass.size();
	for (int i = 0; i < N; i++) {
		if (sp.count(pass[i]) == 0) {
			pro.push_back(pass[i]);
			continue;
		}
		int j = i;
		while (j < N and sp.count(pass[j])) {
			j++;
		}
		pro.push_back(pass[i]);
		i = --j;
	}
	return pro;
}

void solve() {
	ll N; cin >> N;
	string pass; cin >> pass;
	ll K; cin >> K;
	set<char> sp;
	for (int i = 0; i < K; i++) {
		char c; cin >> c; sp.insert(c);
	}

	string pro = process(pass, sp);


	pro = pass;

	vll idx;
	for (int i = 0; i < pro.size(); i++) {
		if (sp.count(pro[i])) idx.push_back(i);
	}

	ll start = 0;
	ll mx = 0, ans = 0;

	for (int i = 0; i < idx.size(); i++) {
		ll current = idx[i] - start  - 1;
		start = idx[i];
		if (mx <= current) {
			mx = current;
			ans = mx + 1;
		}
		else {
			ans = max(ans, mx);
		}
	}

	cout << ans << endl;

}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}