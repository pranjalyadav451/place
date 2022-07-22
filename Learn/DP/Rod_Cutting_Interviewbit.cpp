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

template<typename T> void in_arr(ll n, vector<T> &arr) {
    if (arr.size() != n) arr.resize(n); for (int i = 0; i < n; i++) cin >> arr[i];
}
template<typename... Args> void in(Args&... args) {
    ((cin >> args), ...);
}

vector<string >process(string &str) {
    vector<string> res; string temp = ""; for (int i = 0; i < str.size(); i++) {
        if (str[i] == '|') {
            res.push_back(temp); temp = "";
        }
        else temp.push_back(str[i]);
    } res.push_back(temp); return res;
}
template<typename ...Args> void logger(string vars, Args&&... values) {
    string delim = ""; stringstream ss; (..., (ss << delim << values, delim = "|")); delim = ""; string arrow = " : ", str_values = ss.str(); for (auto &a : vars) if (a == ',') a = '|'; auto labels = process(vars), content = process(str_values); cout << "[ "; for (int i = 0; i < labels.size(); i++) {
        cout << delim << labels[i] << arrow << content[i]; delim = ", ";
    } cout << " ]" << endl;
}
#define out(...)                        logger(#__VA_ARGS__, __VA_ARGS__)



using vi = vector<int>;
const long long INF = 1e18;
vi order;

vector<vector<pair<long long, long long>>> dp;


pair<long long, long long> rec(vi &arr, long long start, long long end) {
    if (start + 1 >= end) return { 0, -1 };


    long long curr = arr[end] - arr[start];

    auto &[ans, can] = dp[start][end];

    if (ans != -1) return dp[start][end];

    ans = INF; can = -1;

    for (long long k = start + 1; k < end; k++) {
        long long cost_at_k = rec(arr, start, k).first + rec(arr, k, end).first;
        if (cost_at_k + curr < ans) {
            ans = cost_at_k + curr;
            can = k;
        }
    }
    return dp[start][end];
}

void build(long long i, long long j) {
    if (i + 1 >= j) return;
    int k = dp[i][j].second;
    order.push_back(k);
    build(i, k);
    build(k, j);
}



vector<int> rodCut(int A, vector<int> &rod) {
    order.clear();
    rod.insert(rod.begin(), 0);
    rod.push_back(A);

    int n = rod.size();

    dp.assign(n + 1, vector<pair<long long, long long>>(n + 1, { -1, -1 }));
    int ans = rec(rod, 0, rod.size() - 1).first;

    build(0, n - 1);
    for (auto &a : order) {
        a = rod[a];
    }
    return order;
}

void solve() {
    int len, n; in(len, n);
    vector<int> arr(n); in_arr(n, arr);
    vector<int> ans = rodCut(len, arr);
    out(ans);
}
int main() {
    int tt = 1;
    while (tt--) {
        solve();
    }
}