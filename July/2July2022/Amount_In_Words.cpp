#include <bits/stdc++.h>
using namespace std;
// ghatiya sawal // this is not the correct solution


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

map<int, vector<string>> mp = {
	{0, {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}},
	{1, {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}},
	{2, {"hundred"}},
};

map<int, vector<string>> placevalue = {
	{1, {"thousand"}},
	{2, {"lakh"}},
	{3, {"crore"}},
};

vector<string> for11to19 = {
	"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};



void genParts(string &A, vector<string> &num) {
	int n = A.size();
	bool flag = false;
	int step = 3;

	for (int i = n - 1; i >= 0;) {
		string temp;
		int t = step;

		flag = true;

		while (t and i >= 0) {
			temp.push_back(A[i]);
			t--; i--;
		}
		reverse(temp.begin(), temp.end());
		if (temp.size() > 0)
			num.push_back(temp);

		if (step == 3) {
			step = 2;
		}
	}
	if (num.size() == 5) {
		string last = num.back();
		num.pop_back();
		last += num[num.size() - 1];
		num[num.size() - 1] = last;
	}
	reverse(num.begin(), num.end());
}

int amount_in_words(string A, string B) {
	vector<string> num;
	genParts(A, num);
	// log(num);
	int n = num.size();


	string words;

	for (int i = n - 1; i >= 0; i--) {
		int pos = n - 1 - i;
		int digit = stoi(num[i]);
		if (digit == 0) continue;

		int hundreds = (digit % 1000) / 100 , tens = (digit % 100) / 10 , ones = digit % 10;

		string to_add = "";
		if (hundreds) {
			to_add += mp[0][hundreds - 1] + "-" + mp[2][0] + "-";
		}
		int tensAndOnes = digit % 100;
		if (tensAndOnes >= 11 and tensAndOnes <= 19) {
			if (hundreds) to_add = to_add + "and" + "-";
			to_add += for11to19[tensAndOnes - 11] + "-";
		}
		else {
			if (hundreds and (tens or ones)) to_add = to_add + "and" + "-";
			if (tens) {
				to_add += mp[1][tens - 1] + "-";
			}
			if (ones) {
				to_add += mp[0][ones - 1] + "-";
			}
		}
		if (pos != 0) {
			to_add += placevalue[pos][0];
			words = to_add + "-" + words;
		}
		else {
			words = to_add;
		}
	}
	if (words.size() and words.back() == '-')
		words.pop_back();
	return words == B;
}

void solve() {
	string a , b;
	read(a, b);
	int ans = amount_in_words(a, b);

}
int main() {
	// ghatiya sawal // this is not the correct solution

	int tt = 1;
	// cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}