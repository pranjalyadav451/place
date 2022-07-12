/*
name: G2. Passable Paths (hard version)
group: Codeforces - Codeforces Round #805 (Div. 3)
url: https://codeforces.com/contest/1702/problem/G2
interactive: false
memoryLimit: 256
timeLimit: 3000
Started At: 5:01:30 AM
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


struct LCA {
    int LOG;
    int N;
    vector<vector<int>> ancestor;
    vector<int> parent;
    vector<int> visited;
    vector<int> depth;


    LCA(vector<vector<int>> &graph, int n) {
        N = n;
        LOG = __lg(n) + 1;
        parent.assign(n, 0);
        depth.assign(n, 0);
        visited.assign(n, false);
        ancestor.assign(n, vector<int>(LOG));

        dfs(graph);
        build();
    }
    void dfs(vector<vector<int>> &graph, int node = 0) {
        if (visited[node]) return;
        visited[node] = true;
        for (auto a : graph[node]) {
            if (visited[a]) continue;
            depth[a] = depth[node] + 1;
            parent[a] = node;
            dfs(graph, a);
        }
    }
    void build() {
        for (int i = 0; i < N; i++) {
            ancestor[i][0] = parent[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < N; i++) {
                ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
            }
        }
    }


    int get_lca(int u, int v) {
        assert(u >= 0 and u < N);
        assert(v >= 0 and v < N);

        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        int depth_diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (depth_diff & (1LL << j)) {
                u = ancestor[u][j];
            }
        }

        if (u == v) {
            return u;
        }

        for (int j = LOG - 1; j >= 0; j--) {
            if (ancestor[u][j] != ancestor[v][j]) {
                u = ancestor[u][j];
                v = ancestor[v][j];
            }
        }
        return ancestor[u][0];
    }


};

void query(LCA &anc) {
    ll k; read(k);
    vll vert(k);
    for (int i = 0; i < k; i++) {
        ll a; read(a); a--;
        vert[i] = a;
    }

    auto dist = [&](int u, int v) {
        int lca = anc.get_lca(u, v);
        ll distance = anc.depth[u] + anc.depth[v] - 2 * anc.depth[lca];
        return distance;
    };

    int left_end = -1, right_end = -1, max_dep = -1;
    for (int i = 0; i < vert.size(); i++) {
        if (anc.depth[vert[i]] > max_dep) {
            max_dep = anc.depth[vert[i]];
            left_end = vert[i];
        }
    }
    max_dep = -1;
    for (int i = 0; i < vert.size(); i++) {
        if (anc.get_lca(left_end, vert[i]) != vert[i]) {
            if (max_dep < anc.depth[vert[i]]) {
                max_dep = anc.depth[vert[i]];
                right_end = vert[i];
            }
        }
    }

    if (right_end == -1) {
        cout << "YES" << endl; return;
    }
    ll dist_left_right = dist(left_end, right_end);
    bool is = true;
    for (int i = 0; i < vert.size(); i++) {
        ll dist_left_vert = dist(left_end, vert[i]);
        ll dist_right_vert = dist(right_end, vert[i]);
        if (dist_left_right != dist_left_vert + dist_right_vert) {
            is = false;
            break;
        }
    }

    cout << (is ? "YES" : "NO") << endl;
}

void solve() {
    ll n; read(n);
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        ll a, b; read(a, b);
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    LCA anc(graph, n);
    // out("HERE");
    ll q; read(q);
    while (q--) {
        query(anc);
    }
}
int main() {
    int tt = 1;
    // cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
    while (tt--) {
        solve();
    }
}