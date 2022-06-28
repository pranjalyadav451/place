/*
name: A - Range Flip Find Route
group: AtCoder - AtCoder Grand Contest 043
url: https://atcoder.jp/contests/agc043/tasks/agc043_a
interactive: false
memoryLimit: 1024
timeLimit: 2000
Started At: 12:03:56 PM
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
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
	arr.resize(n); for (int i = 0; i < n; i++) cin >> arr[i];
}
template<typename... Args> void read(Args&... args) {
	((cin >> args), ...);
}

vector<string >process(string &str) {
	vector<string> res; for (int i = 0; i < str.size(); i++) {
		string temp = ""; while (i < str.size() and str[i] != ',') {
			temp.push_back(str[i++]);
		} res.push_back(temp); i++;
	} return res;
}
template<typename ...Args> void logger(string vars, Args&&... values) {
	string delim = ""; stringstream ss; (..., (ss << delim << values, delim = ", ")); delim = ""; string arrow = " : ", str_values = ss.str(); auto labels = process(vars), content = process(str_values); cout << "[ "; for (int i = 0; i < labels.size(); i++) {
		cout << delim << labels[i] << arrow << content[i]; delim = ", ";
	} cout << " ]" << endl;
}
#define log_all(...)                        logger(#__VA_ARGS__, __VA_ARGS__)



void solve() {
	int a = 3, b = 4;
	string c = "here";	log_all(a, b, c);
}
int main() {
	int tt = 1;
	// cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}