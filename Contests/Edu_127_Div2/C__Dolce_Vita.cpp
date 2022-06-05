/*
https://codeforces.com/contest/1671/problem/C
Time Limit: 2000
Memory Limit: 256
Fri Apr 22 2022 20:29:58 GMT+0530 (India Standard Time)
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

ll just_smaller(vll &arr, ll req) {
	ll left = 0, right = arr.size() - 1, mid = 0, ans = -1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (arr[mid] <= req) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return ans;
}
void solve(vll &arr, ll N, ll X) {
	sort(all(arr));

	vll pref(N);
	pref[0] = arr[0];
	for (int i = 1; i < N; i++) {
		pref[i] = pref[i - 1] + arr[i];
	}

	ll initial = just_smaller(pref, X);
	ll sum = 0;

	if (initial == -1) {
		cout << sum << endl;
		return;
	}
	ll days_past = 0;
	for (int i = initial; i >= 0; i--) {
		ll curr_cost = pref[i] + (i + 1) * (days_past);
		if (X - curr_cost < 0) continue;
		ll contri = (X - curr_cost) / (i + 1);
		days_past += contri + 1;
		sum += (i + 1) * (contri + 1);
	}
	cout << sum << endl;
}

void input() {
	ll N , X; cin >> N >> X;
	vll arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	solve(arr, N, X);
}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		input();
	}

}