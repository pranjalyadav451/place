/*
name: Coin Combinations II
group: CSES - CSES Problem Set
url: https://cses.fi/problemset/task/1636
interactive: false
memoryLimit: 512
timeLimit: 1000
Started At: 10:26:27 AM
*/
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

int fastio() {
	ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0;
} int __fastio = fastio();
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream &operator<<(ostream &os, const set<A> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A>                ostream &operator<<(ostream &os, const multiset<A> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}";
}
template<typename A, typename B>    ostream &operator<<(ostream &os, const map<A, B> &m) {
	os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}";
}
template<typename T>                ostream &operator<<(ostream &os, const vector<T> &v) {
	os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]";
}
template<typename T, size_t L>      ostream &operator<<(ostream &os, const array<T, L> &v) {
	os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]";
}
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p) {
	os << '(' << p.first << ", " << p.second << ')'; return os;
}


typedef long long                           ll;
typedef vector<ll>                          vll;
typedef pair<ll, ll>                        pll;
typedef vector<vector<ll>>                  vvl;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;




#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl

template<typename T> void read_array(ll n, vector<T> &arr) {
	if (arr.size() != n) arr.resize(n); for (int i = 0; i < n; i++) cin >> arr[i];
}
template<typename... Args> void read(Args&... args) {
	((cin >> args), ...);
}

vector<string >process(string &str) {
	vector<string> res; string temp = ""; for (int i = 0; i < str.size(); i++) {
		if (str[i] == '|') {
			res.push_back(temp); temp = ""; i++;
		}
		else temp.push_back(str[i]);
	} res.push_back(temp); return res;
}
template<typename ...Args> void logger(string vars, Args&&... values) {
	string delim = ""; stringstream ss; (..., (ss << delim << values, delim = "| ")); delim = ""; string arrow = " : ", str_values = ss.str(); for (auto &a : vars) if (a == ',') a = '|'; auto labels = process(vars), content = process(str_values); cout << "[ "; for (int i = 0; i < labels.size(); i++) {
		cout << delim << labels[i] << arrow << content[i]; delim = ", ";
	} cout << " ]" << endl;
}
#define out(...)                        logger(#__VA_ARGS__, __VA_ARGS__)



// ** not the correct intuition and approach to the problem


int dp[(int)1e6 + 1][101];
const int mod = 1e9 + 7;
const int mx = 1e6;

int rec(vector<int> &coins, int total, int i = 0) {
	if (total == 0) return 1;
	if (i == coins.size()) return 0;

	int &ans = dp[total][i];
	if (ans != -1) return ans;
	ans = 0;
	if (total >= coins[i]) ans += rec(coins, total - coins[i], i);
	ans += rec(coins, total, i + 1);
	return ans;
}

void solve() {
	ll n, total; read(n, total);
	vector<int> coins(n); read_array(n, coins);
	memset(dp,-1,sizeof(dp));
	ll ans = rec(coins, total);
	cout << ans << endl;
}
int main() {
	int tt = 1;
	while (tt--) {
		solve();
	}
}