/*
name: Strict Permutation
group: CodeChef - Starters 48 Division 2 (Rated)
url: https://www.codechef.com/START48B/problems/STRPERM
interactive: false
memoryLimit: 256
timeLimit: 1000
Started At: 9:06:06 PM
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

#define ff first
#define ss second



void solve() {
    ll n, m; in(n, m);
    vpl arr(m);

    for (int i = 0; i < m; i++) {
        in(arr[i].ff, arr[i].ss);
    }
    sort(all(arr), [](const pll &a, const pll &b) {
        return a.ss == b.ss ? a.ff < b.ff : a.ss < b.ss;
        });

    // solution starts

    set<ll> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    vector<ll> ans(n);

    bool possible = true;

    for (int i = 0; i < m; i++) {
        auto [ele, closed] = arr[i];

        if (st.count(closed)) {
            ans[closed - 1] = ele;
            st.erase(closed);
        }
        else {
            auto get = st.lower_bound(closed);
            if (get == st.begin() or get == st.end()) {
                possible = false;
                break;
            }
            else {
                get--;
                ans[*get - 1] = ele;
                st.erase(get);
            }
        }
    }

    if (not possible) {
        cout << -1 << endl;
        return;
    }
    set<ll> remain;
    for (int i = 0; i < n; i++) {
        remain.insert(i + 1);
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] != 0) remain.erase(ans[i]);
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) {
            ans[i] = *remain.begin();
            remain.erase(ans[i]);
        }
    }

    cout << ans << endl;
}
int main() {
    int tt = 1;
    cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
    while (tt--) {
        solve();
    }
}