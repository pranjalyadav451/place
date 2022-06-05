/*
https://codeforces.com/problemset/problem/1650/C
Time Limit: 2000
Memory Limit: 256
Fri Apr 15 2022 21:19:49 GMT+0530 (India Standard Time)
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


struct Segment {
	int x = 0, weight = 0;
};


bool comp(const Segment &A, const Segment &B ) {
	return A.weight < B.weight;
}

void solve() {
	ll N , M; cin >> N >> M;
	vector<Segment> arr(M);
	map<ll, ll> pos;
	for (int i = 0; i < M; i++) {
		cin >> arr[i].x >> arr[i].weight;
		pos[arr[i].x] = i + 1;
	}

	sort(all(arr), comp);

	ll mn = 0;
	vll ans;

	vpl weights;
	for (int i = 0; i < 2 * N; i++) {
		mn += arr[i].weight;
		weights.push_back({arr[i].x, pos[arr[i].x]});
	}
	sort(all(weights));

	cout << mn << endl;
	for (int i = 0; i < N; i ++) {
		cout << weights[i].second << " " << weights[2 * N - i - 1].second << endl;
	}
	cout << endl;
}




int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}