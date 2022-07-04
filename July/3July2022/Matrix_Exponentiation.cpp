#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;

int fastio() {
	ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0;
} int __fastio = fastio();
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream &operator<<(ostream &os, const set<A> &m) {os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A>                ostream &operator<<(ostream &os, const multiset<A> &m) {os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B>    ostream &operator<<(ostream &os, const map<A, B> &m) {os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>                ostream &operator<<(ostream &os, const vector<T> &v) {os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>      ostream &operator<<(ostream &os, const array<T, L> &v) {os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p) {os << '(' << p.first << ", " << p.second << ')'; return os; }

vector<string >process(string &str) {vector<string> res; string temp = ""; for (int i = 0; i < str.size(); i++) {if (str[i] == '|') {res.push_back(temp); temp = ""; i++; } else temp.push_back(str[i]); } res.push_back(temp); return res; }
template<typename ...Args> void logger(string vars, Args&&... values) {string delim = ""; stringstream ss; (..., (ss << delim << values, delim = "| ")); delim = ""; string arrow = " : ", str_values = ss.str(); for (auto &a : vars) if (a == ',') a = '|'; auto labels = process(vars), content = process(str_values); cout << "[ "; for (int i = 0; i < labels.size(); i++) {cout << delim << labels[i] << arrow << content[i]; delim = ", "; } cout << " ]" << endl; }
#define log(...)                        logger(#__VA_ARGS__, __VA_ARGS__)

typedef long long                           ll;
typedef vector<ll>                          vll;
typedef pair<ll, ll>                        pll;
typedef vector<vector<ll>>                  vvl;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;




#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl

template<typename T> void read_array(ll n, vector<T> &arr) {arr.resize(n); for (int i = 0; i < n; i++) cin >> arr[i]; }
template<typename... Args> void read(Args&... args) {((cin >> args), ...); }


int mod = 1e9 + 7;
struct matrix {
	vector<vector<long long>> mat;


	matrix(int n , int m) {
		mat.assign(n, vector<long long>(m));
	}
	matrix() {

	}
	matrix operator*(const matrix &B) {
		int order = B.mat.size();
		vector<vector<long long>> tempMat(order, vector<long long> (order));

		for (int i = 0; i < order; i++) {
			for (int j = 0; j < order; j++) {
				for (int k = 0; k < order; k++) {
					if (mod == 0)
						tempMat[i][j] += this->mat[i][k] * B.mat[k][j];
					else {
						tempMat[i][j] = (tempMat[i][j] % mod + ((this->mat[i][k] % mod) * (B.mat[k][j] % mod) % mod)) % mod;
					}
				}
			}
		}
		log(tempMat);
		matrix C; C.mat = tempMat;
		return C;
	}
};

matrix binPow(matrix A, int n) {
	int order = A.mat.size();
	matrix res(order, order);


	for (int i = 0; i < order; i++) res.mat[i][i] = 1;

	while (n) {
		if (n % 2) res = res * A;
		A = A * A;
		n /= 2;
	}
	return res;
}



int getNthFib(int n) {
	matrix A;
	A.mat = {{1, 1}, {1, 0}};

	n--;
	if (n <= 2) return 1;

	A = binPow(A, n - 1);


	int nthFib  = ( A.mat[0][0] % mod + A.mat[0][1] % mod) % mod;
	return nthFib;
}

void solve() {
	int n; cin >> n;
	int res = getNthFib(n);
	log(res);
}
int main() {
	int tt = 1;
	// cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}