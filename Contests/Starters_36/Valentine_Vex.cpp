/*
https://www.codechef.com/START36B/problems/VALVEX
Time Limit: 1000
Memory Limit: 256
Wed Apr 27 2022 21:28:46 GMT+0530 (India Standard Time)
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

// A = 1 => first move odd

pll score(vll &odd, vll &even, bool A, bool B) {
	int i = 0, j = 0;
	int N = odd.size() , M = even.size();
	ll last_A = A , last_B = B;

	ll alice = 0 , bob = 0;
	if (A == 1 and i < N) alice += odd[i++];
	if (not A and j < M) alice = even[j++];

	if (B and i < N) bob += odd[i++];
	if (not B and j < M) bob += even[j++];

	A = !A; B = !B;

	for (;;) {
		if (A) {
			if ( i >= N) break;
			alice += odd[i++];
		}
		if (!A ) {
			if (j >= M) break;
			alice += even[j++];
		}
		if (B and i < N) bob += odd[i++];
		if (not B and j < M) bob += even[j++];

		A = !A , B = !B;
	}

	return {alice, bob};
}


void solve() {
	ll N; cin >> N;
	vll arr(N);
	vll odd, even;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] & 1) odd.push_back(arr[i]);
		else even.push_back(arr[i]);
	}

	sort(odd.rbegin(), odd.rend());
	sort(even.rbegin(), even.rend());


	pll a = score(odd, even, 0, 0);
	pll b = score(odd, even, 0, 1);
	pll c = score(odd, even, 1, 0);
	pll d = score(odd, even, 1, 1);

	vpl res = {a, b, c, d};
	sort(all(res));
	cout << res << endl;


}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}