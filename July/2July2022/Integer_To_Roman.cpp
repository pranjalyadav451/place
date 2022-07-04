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

map<string, int> to_int = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}};
map<int, string, greater<int>> to_roman;
map<string, int> can_sub = {{"I", 1}, {"X", 10}, {"C", 100}, {"M", 1000}};
map<string, pair<int, int>> range;




int fill() {
    to_roman[0] = "";
    for (auto t : to_int) {
        to_roman[t.second] = t.first;
    }

    for (auto a : to_int) {
        auto [roman, x] = a;
        if (can_sub.count(roman)) {
            int value = can_sub[roman];
            int l = value - value / 10, r = value * 4 - 1;
            range[roman] = {l, r};
        }
        else {
            int l = x - x / 5 , r = 2 * x - x / 5 - 1;
            range[roman] = {l, r};
        }
    }
    return 0;
}
int fill_to_roman = fill();


string rec(int A) {
    if (A == 0) return "";
    if (to_roman.count(A)) return to_roman[A];


    string res = "";
    int rem = 0;

    for (auto [roman, limit] : range) {
        if (A >= limit.first and A <= limit.second) {
            if (A < to_int[roman]) {
                if (can_sub.count(roman)) {
                    int value = can_sub[roman];
                    rem = A - (value - value / 10);
                    res = to_roman[value / 10] + to_roman[value];
                    return res + rec(rem);
                }
                else {
                    int value = to_int[roman];
                    rem = A - (value - value / 5);
                    res = to_roman[value / 5] + to_roman[value];
                    return res + rec(rem);
                }
            }
            else {
                int rem = A;
                while (rem >= to_int[roman]) {
                    rem -= to_int[roman];
                    res += roman;
                }
                return res + rec(rem);
            }
        }
    }
    return res;
}




string intToRoman(int A) {
    string res = rec(A);
    return res;
}

void solve() {
    int n; read(n);
    string s = intToRoman(n);

    log(range);
    log(s);
}
int main() {
    int tt = 1;
    // cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
    while (tt--) {
        solve();
    }
}