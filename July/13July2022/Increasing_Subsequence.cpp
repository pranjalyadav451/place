/*
name: Increasing Subsequence
group: CSES - CSES Problem Set
url: https://cses.fi/problemset/task/1145/
interactive: false
memoryLimit: 512
timeLimit: 1000
Started At: 11:14:59 PM
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

template<typename T> void in_arr(ll n, vector<T> &arr) {
    if (arr.size() != n) arr.resize(n); for (int i = 0; i < n; i++) cin >> arr[i];
}
template<typename... Args> void in(Args&... args) {
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


void insert_candi(map<ll, ll> &can, ll value, ll advantage) {
    // if any smaller value with same or bigger advantage exists we don't need to 
    // insert the current value

    auto start = can.lower_bound(value);
    if (start != can.begin() and (--start)->second >= advantage) {
        return;
    }

    start = can.lower_bound(value);

    // start at lower bound
    while (start != can.end() and start->second <= advantage) {
        auto temp = start;
        start++;
        can.erase(temp);
    }
    can[value] = advantage;
}
ll get_best_candi(map<ll, ll> &can, ll value) {
    auto get = can.lower_bound(value);
    if (get == can.begin()) return 0;
    --get;
    return get->second;
}

ll get_lcs(vll &arr, int n) {
    vll dp(n);
    map<ll, ll> can;
    dp[0] = 1;
    can[arr[0]] = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = get_best_candi(can, arr[i]) + 1;
        insert_candi(can, arr[i], dp[i]);
    }
    return *max_element(all(dp));
}

void solve() {
    ll n; in(n);
    vll arr; in_arr(n, arr);

    // finding longest increasing subsequence in O(n*log(n))
    ll ans = get_lcs(arr, n);
    cout << ans << endl;
}
int main() {
    int tt = 1;
    // cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
    while (tt--) {
        solve();
    }
}