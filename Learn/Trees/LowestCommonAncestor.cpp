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
#define log(...)                        logger(#__VA_ARGS__, __VA_ARGS__)

const int MAX_N = 10000;
const int LOG = 14;
vector<int> children[MAX_N];
int up[MAX_N][LOG];
int depth[MAX_N];


void dfs(int a) {
    for (int b : children[a]) {
        depth[b] = depth[a] + 1;
        up[b][0] = a;
        for (int j = 1; j < LOG; j++) {
            up[b][j] = up[up[b][j - 1]][j - 1];
        }
        dfs(b);
    }
}


int get_lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    int k = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            a = up[a][i];
        }
    }

    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

void solve() {
    int n; read(n);
    for (int i = 0; i < n; i++) {
        int m; read(m);
        for (int j = 0; j < m; j++) {
            int child; read(child);
            children[i].push_back(child);
        }
    }

    dfs(0);

    int q; read(q);
    while (q--) {
        int u, v; read(u, v);
        int lca = get_lca(u, v);
        cout << lca << endl;
    }
}

int main() {
    int tt = 1;
    // cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
    while (tt--) {
        solve();
    }
}