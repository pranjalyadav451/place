/*
https://codeforces.com/contest/1675/problem/C
Time Limit: 2000
Memory Limit: 256
Thu May 05 2022 20:22:04 GMT+0530 (India Standard Time)
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

ll find(vll &arr, int val) {
	ll left = 0, right = arr.size() - 1, mid = - 1, ans = -1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (arr[mid] <= val) {
			left = mid + 1;
		}
		else {
			ans =  mid;
			right = mid - 1;
		}
	}
	return ans;
}

void solve() {
	string S; cin >> S;
	vector<ll> ones, zeros;
	int N = S.size();
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') ones.push_back(i);
		if (S[i] == '0') zeros.push_back(i);
	}

	ll cnt = 0;

	for (int i = 0; i < N; i++) {
		if (S[i] == '0') {
			cnt++;
			break;
		}
		int curr = i;
		ll ans = find(ones, i);
		if (ans == -1) {
			cnt++;
		}
	}
	cout << cnt << endl;

}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}