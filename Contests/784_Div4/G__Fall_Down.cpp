/*
https://codeforces.com/contest/1669/problem/G
Time Limit: 1000
Memory Limit: 256
Thu Apr 21 2022 21:31:01 GMT+0530 (India Standard Time)
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

void simulate(vector<string> &arr, int N, int M) {

	vector<int> empty(M);

	// for (int i = 0; i < M; i++) {
	// 	empty[i] = arr[N - 1][i] == '.';
	// }

	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '.' or arr[i][j] == 'o') continue;
			int k = i + 1;

			while (k < N and arr[k][j] == '.') {
				k++;
			}
			// dbgg(i, j);
			// dbgg(k, j);
			if (k - 1 < N) {
				arr[i][j] = '.';
				arr[k - 1][j] = '*';
			}
			// cout << endl;
		}
	}
}

void solve() {
	int N , M;
	cin >> N >> M;
	vector<string> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	simulate(arr, N, M);
	for (auto v : arr) {
		for (auto c : v) {
			cout << c;
		}
		cout << endl;
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