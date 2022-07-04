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

template <long long MOD = 1000000007>
class Modular {
public:
	long long value;
	static const long long MOD_value = MOD;

	Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
	Modular(long long a, long long b) : value(0) { *this += a; *this /= b;}

	Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
	Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD; return *this;}
	Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD; return *this;}

	friend Modular mexp(Modular a, long long e) {
		Modular res = 1LL; while (e) { if (e & 1LL) res *= a; a *= a; e >>= 1LL; }
		return res;
	}
	friend Modular inverse(Modular a) { return mexp(a, MOD - 2LL); }

	Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
	friend Modular operator+(Modular a, Modular const b) { return a += b; }
	friend Modular operator-(Modular a, Modular const b) { return a -= b; }
	friend Modular operator-(Modular const a) { return 0LL - a; }
	friend Modular operator*(Modular a, Modular const b) { return a *= b; }
	friend Modular operator/(Modular a, Modular const b) { return a /= b; }
	friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
	friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
	friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};


template<typename T> void read_array(ll n, vector<T> &arr) {arr.resize(n); for (int i = 0; i < n; i++) cin >> arr[i]; }
template<typename... Args> void read(Args&... args) {((cin >> args), ...); }

vector<string >process(string &str) {vector<string> res; string temp = ""; for (int i = 0; i < str.size(); i++) {if (str[i] == '|') {res.push_back(temp); temp = ""; i++; } else temp.push_back(str[i]); } res.push_back(temp); return res; }
template<typename ...Args> void logger(string vars, Args&&... values) {string delim = ""; stringstream ss; (..., (ss << delim << values, delim = "| ")); delim = ""; string arrow = " : ", str_values = ss.str(); for (auto &a : vars) if (a == ',') a = '|'; auto labels = process(vars), content = process(str_values); cout << "[ "; for (int i = 0; i < labels.size(); i++) {cout << delim << labels[i] << arrow << content[i]; delim = ", "; } cout << " ]" << endl; }
#define log(...)                        logger(#__VA_ARGS__, __VA_ARGS__)



int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

string str_slope(int num , int den, int neg) {
	string ret = (neg ? "-" : "") + to_string(num) + "/" + to_string(den);
	return ret;
}

string get_slope(pair<int, int> a, pair<int, int> b) {

	// log(a, b);
	int den = a.first - b.first , num = a.second - b.second;
	// log(num, den);
	// cout << endl;

	bool neg = false;
	if (num < 0 and den < 0)  neg  = false;
	else if (neg < 0 or den < 0) {
		neg = true;
	}

	num = abs(num), den = abs(den);
	string ret = "";
	if (den == 0) {
		ret = "pi/2";
	}
	else if (num == 0) {
		ret = "0";
	}
	else {
		int common = gcd(num, den);
		num /= common; den /= common;
		ret = str_slope(num, den, neg);
	}
	return ret;
}


int maxPoints(vector<int> &A, vector<int> &B) {
	int n = A.size();

	vector<pair<int, int>> points;
	map<pair<int, int>, int> cnt;

	for (int i = 0; i < n; i++) {
		points.push_back(pair(A[i], B[i]));
		cnt[points.back()]++;
	}
	sort(points.begin(), points.end());

	map<pair<int, int>, map<string, int>> mp;

	for (int i = 0; i < n;) {
		auto curr = points[i];
		mp[curr]["SAME"] = cnt[curr];
		i += cnt[curr];

		for (int j = i; j < n;) {
			auto t = points[j];
			j += cnt[t];
			string slope = get_slope(curr, t);
			if (mp[curr][slope] == 0) mp[curr][slope] += cnt[curr];
			mp[curr][slope] += cnt[t];
		}
	}
	int mx = 0;
	for (auto [point, map_slopes] : mp) {
		// log(point, map_slopes);
		for (auto [slope, cnt] : map_slopes) {
			mx = max(mx, cnt);
		}
	}

	return mx;
}



void solve() {
	int n; read(n);
	vector<int> X(n), Y(n);
	for (int i = 0; i < n; i++) {
		read(X[i], Y[i]);
	}

	int ans = maxPoints(X, Y);
	log(ans);
}
int main() {
	int tt = 1;
	// cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}