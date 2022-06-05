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


vector<vector<int>> dp;

int super(string &A, string &B, int N, int M) {

	if (N == 0) return M;
	if (M == 0) return N;

	int ans = dp[N][M];
	if (ans != -1) return ans;
	ans = 0;
	if (A[N - 1] == B[M - 1]) {
		ans = 1 + super(A, B, N - 1, M - 1);
	}
	else {
		ans = 1 + min(super(A, B, N - 1, M), super(A, B, N, M - 1));
	}
	return dp[N][M] = ans;
}

string super_string(string &A, string &B) {
	int N = A.size(), M = B.size();
	string result;

	// for (int i = 0; i <= N; i++) {
	// 	for (int j = 0; j <= M; j++) {
	// 		cout << dp[i][j] << "\t\t";
	// 	}
	// 	cout << endl;
	// }

	while (N >= 1 and M >= 1) {
		if (A[N - 1] == B[M - 1]) {
			result.push_back(A[N - 1]);
			N--; M--;
		}
		else {
			if (dp[N - 1][M] < dp[N][M - 1]) {
				result.push_back(A[N - 1]);
				N--;
			} else {
				result.push_back(B[M - 1]);
				M--;
			}
		}
	}

	while (N >= 1) result.push_back(A[--N]);
	while (M >= 1) result.push_back(B[--M]);

	reverse(result.begin(), result.end());
	return result;
}

int solve(vector<string> &A) {
	string res = A[0];
	for (int i = 1; i < A.size(); i++) {
		dp.assign(res.size() + 1, vector<int>(A[i].size() + 1, -1));
		super(res, A[i], res.size(), A[i].size());
		res = super_string(res, A[i]);
	}
	return res.size();
}

int main() {
	int N; cin >> N;
	vector<string> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int ans = solve(arr);
	dbg(ans);
}