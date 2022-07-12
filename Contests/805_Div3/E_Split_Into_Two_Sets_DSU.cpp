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
#define out(...)                        logger(#__VA_ARGS__, __VA_ARGS__)


struct DSU {
    long long N;
    vector<long long> parent;
    vector<long long> degree;
    DSU(long long n) {
        N = n;
        parent.resize(N);
        degree.assign(N, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    void merge(long long a, long long b) {
        // find the root parent
        // doing pa = parent[a] and pb = parent[b] will give WA because they
        // (parent[a],parent[b]) are not the root level parents of a and b
        long long pa = find(a), pb = find(b);
        if (pa == pb) return;

        if (degree[pb] > degree[pa]) swap(pa, pb);
        parent[pb] = pa;
        degree[pa] += degree[pb];
        degree[pb] = 0;
    }
    long long find(long long a) {
        return (a == parent[a] ? a : parent[a] = find(parent[a]));
    }
};

bool check(vpl &arr) {
    int n = arr.size();
    map<ll, ll> cnt;
    for (int i = 0; i < n; i++) {
        auto [a, b] = arr[i];
        cnt[a]++; cnt[b]++;
    }
    for (auto a : cnt) {
        if (a.second != 2) {
            return false;
        }
    }
    return true;
}

void solve() {
    ll n; read(n);
    DSU dsu(n);
    vpl arr(n);
    for (int i = 0; i < n; i++) {
        ll a, b; read(a, b); a--; b--;
        arr[i] = pair(a, b);
        dsu.merge(a, b);
    }
    bool is = check(arr);
    for (int i = 0; i < n; i++) {
        if (dsu.degree[i] % 2) {
            is = false;
            break;
        }
    }

    cout << (is ? "YES" : "NO") << endl;
}
int main() {
    int tt = 1;
    cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
    while (tt--) {
        solve();
    }
}