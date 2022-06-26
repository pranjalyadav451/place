/*
B. Palindromic Numbers
Codeforces - Codeforces Round #802 (Div. 2)
https://codeforces.com/contest/1700/problem/B
Memory Limit : 256
Time Limit : 2000

Sun Jun 19 2022 14:41:37 GMT+0530 (India Standard Time)
Started At: 2:41:37 PM
*/
/*
B. Palindromic Numbers
Codeforces - Codeforces Round #802 (Div. 2)
https://codeforces.com/contest/1700/problem/B
Memory Limit : 256
Time Limit : 2000

Sun Jun 19 2022 14:41:37 GMT+0530 (India Standard Time)
Started At: 2:41:37 PM
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
	ll N; cin >> N;
	string str;
	cin >> str;

	string res;
	for (int i = 0; i < N; i++) {
		res.push_back('9' - str[i] + '0');
	}
	if (str[0] != '9') {
		cout << res << endl;
		return;
	}
	int carry = 0;
	res = "";
	for (int i = N - 1; i >= 0; i--) {
		int req = '9' + 2 - carry;


		int get = req - str[i] + '0';

		if (get == 58 or get == 59) {
			get -= 10;
			carry = 0;
		}
		else
			carry = 1;

		res.push_back((char)get);
	}
	reverse(res.begin(), res.end());
	cout << res << endl;

}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}