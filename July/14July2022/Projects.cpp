/*
name: Projects
group: CSES - CSES Problem Set
url: https://cses.fi/problemset/task/1140
interactive: false
memoryLimit: 512
timeLimit: 1000
Started At: 12:10:11 PM
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


struct Project {
    ll start, end, reward;
    Project(ll s, ll e, ll r) :start(s), end(e), reward(r) {}
};
ll bin(vector<Project> &arr, int n, int val) {
    int left = 0, right = n - 1, ans = -1, mid = -1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid].end >= val) {
            right = mid - 1;
        }
        else {
            ans = mid;
            left = mid + 1;
        }
    }
    return ans;
}

void solve() {
    ll n; in(n);
    vector<Project> arr;
    for (int i = 0; i < n; i++) {
        ll a, b, c; in(a, b, c);
        arr.push_back(Project(a, b, c));
    }
    auto comp = [](const Project &a, const Project &b) {return a.end == b.end ? a.start < b.start : a.end < b.end; };
    sort(all(arr), comp);

    vll dp(n + 1);

    // for (int i = 0; i < n; i++) {
    //     auto p = arr[i];
    //     out(p.start, p.end, p.reward);
    // }

    for (int i = 1; i <= n; i++) {
        ll just_smaller = bin(arr, n, arr[i - 1].start);
        dp[i] = dp[just_smaller + 1] + arr[i - 1].reward;
        dp[i] = max(dp[i], dp[i - 1]);
    }
    ll ans = dp[n];
    cout << ans << endl;
}
int main() {
    int tt = 1;
    while (tt--) {
        solve();
    }
}