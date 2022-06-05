#include <array>
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

const int mxn = 60;
int dp[mxn][mxn];
const int INF = 2e7;

int cut(vector<int>&arr, int start, int end) {
	if (end - start == 1) return 0;// cut is complete

	int &ans = dp[start][end];
	if (ans != -1) return ans;
	ans = INF;

	for (int i = start + 1; i < end; i++) {
		int left_part = cut(arr, start, i),
		    right_part = cut(arr, i, end);
		ans = min(ans, left_part + right_part + arr[end] - arr[start]);
	}
	return ans;
}

int main() {
	int L;
	while (cin >> L and L != 0) {
		int N;
		cin >> N;
		vector<int> arr(N + 2);
		arr[0] = 0;
		arr[N + 1] = L;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		memset(dp, -1, sizeof(dp));
		int ans = cut(arr, 0, N + 1);
		cout << "The minimum cutting is " << ans << "." << endl;
	}
}