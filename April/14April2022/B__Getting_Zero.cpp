/*
https://codeforces.com/problemset/problem/1661/B
Time Limit: 2000
Memory Limit: 256
Thu Apr 14 2022 19:11:40 GMT+0530 (India Standard Time)
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

const ll MOD = 32768;

ll power_diff(ll number) {
	ll temp = MOD, cnt = 0;
	while (number < temp) {
		number *= 2;
		cnt++;
	}
	return cnt;
}

void solve(vll &arr, int N) {
	vector<ll> num;
	for (int i = 1; i <= 15; i++) {
		num.push_back((1LL << i));
	}

	for (int i = 0; i < N; i++) {
		ll ans = 1e9;
		for (int j = 0; j < num.size(); j++) {
			ll each = (arr[i] % num[j] == 0 ? 0 : num[j] - arr[i] % num[j]) + num.size() - j - 1;
			ans = min(each, ans);
		}
		cout << ans << " ";
	}
}

void input() {
	int N ; cin >> N;
	vll arr(N);
	for (auto &a : arr) cin >> a;
	solve(arr, N);
}

int main() {
	int tt = 1;
	// cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
	while (tt--) {
		input();
	}
}