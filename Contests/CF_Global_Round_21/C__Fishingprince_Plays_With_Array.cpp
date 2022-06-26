/*
name: C. Fishingprince Plays With Array
group: Codeforces - Codeforces Global Round 21
url: https://codeforces.com/contest/1696/problem/C
interactive: false
memoryLimit: 512
timeLimit: 2000
Started At: 8:44:29 PM
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



template<typename T> void read_array(ll n, vector<T> &arr) {arr.resize(n); for (int i = 0; i < n; i++) cin >> arr[i]; }
vpl process(vll &A, ll m) {
	vpl C, D;
	ll n = A.size();
	for (int i = 0; i < n; i++) {
		ll t = A[i];
		ll freq = 0;
		while (t % m == 0) {
			t /= m;
			freq++;
		}

		C.push_back(make_pair(t, A[i] / t));
	}

	for (int i = 0; i < C.size();) {
		ll ele = C[i].first , freq = 0;
		while (i < n and C[i].first == ele) {
			freq += C[i].second;
			i++;
		}
		D.push_back(make_pair(ele, freq));
	}
	return D;
}


void solve() {
	ll n , m , k; cin >> n >> m;
	vll A, B;
	read_array(n, A);
	cin >> k;
	read_array(k, B);

	ll total_A = accumulate(all(A), 0) , total_B = accumulate(all(B), 0);

	if (total_B != total_A) {
		cout << "NO" << endl; return;
	}
	vpl D = process(A, m);
	vpl E = process(B, m);
	bool is = (D == E);
	cout << (is ? "yes" : "no") << endl;
}
int main() {
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

}