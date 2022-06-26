/*
B - Unbalanced Squares
AtCoder - AtCoder Regular Contest 142
https://atcoder.jp/contests/arc142/tasks/arc142_b
Memory Limit : 1024
Time Limit : 2000

Sun Jun 19 2022 18:42:34 GMT+0530 (India Standard Time)
Started At: 6:42:34 PM
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

vvl arr;

void go_left(int &x, int &y, int &val) {
	int N = arr.size();
	int step = +1;
	for (int i = y; i < N; i += step) {
		if (arr[x][i] != 0) return;
		y = i;
		arr[x][i] = val++;
	}
}
void go_right(int &x, int &y, int &val) {
	int N = arr.size();
	int step = -1;
	for (int i = y; i < N; i += step) {
		if (arr[x][i] != 0) return;
		y = i;
		arr[x][i] = val++;
	}
}
void go_down(int &x, int &y, int &val) {
	int N = arr.size();
	int step = +1;
	for (int i = x; i < N; i += step) {
		if (arr[i][y] != 0) return;
		x = i;
		arr[i][y] = val++;
	}
}
void go_up(int &x, int &y, int &val) {
	int N = arr.size();
	int step = -1;
	for (int i = x; i < N; i += step) {
		if (arr[i][y] != 0) return;
		x = i;
		arr[i][y] = val++;
	}
}

ll get_zeros() {
	ll z = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			z += (arr[i][j] == 0);
		}
	}
	return z;
}

void fill_spiral(ll N) {
	int val = 1, i = 0, j = 0;
	while (get_zeros() != 0) {
		go_left(i, j, val); i++;
		go_down(i, j, val); j--;
		go_right(i, j, val); i--;;
		go_up(i, j, val); j++;
	}
}


void solve() {
	ll N; cin >> N;

	arr.assign(N, vll(N, 0));
	fill_spiral(N);
	for (auto a : arr) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}
}
int main() {
	int tt = 1;
	while (tt--) {
		solve();
	}
}