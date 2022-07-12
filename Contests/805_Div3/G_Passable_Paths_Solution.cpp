// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ld eps = 1e-9;
const ll maxn = 1e5 + 1;
const ll inf = 5e18;
const ll minf = -inf;

#define mp make_pair
#define pb push_back
#define endl "\n"

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        }
        else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

void solve() {
    ll n, q, k;
    cin >> n;
    vector<vector<int>> adj(n);

    for (ll i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        x--, y--;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    LCA ancestor(adj);

    auto dist = [&](ll u, ll v) {
        ll currlca = ancestor.lca(u, v);
        return ancestor.height[u] + ancestor.height[v] - 2 * ancestor.height[currlca];
    };

    cin >> q;

    while (q--) {
        cin >> k;

        vector<ll> nodes(k), group0, group1;

        ll maxm = -1, leftend = -1, rightend = -1;

        for (ll i = 0; i < k; ++i) {
            cin >> nodes[i];
            nodes[i]--;
            if (ancestor.height[nodes[i]] > maxm) {
                maxm = ancestor.height[nodes[i]];
                leftend = nodes[i];
            }
        }

        maxm = -1;

        for (ll i = 0; i < k; ++i) {
            ll currlca = ancestor.lca(leftend, nodes[i]);
            if (currlca != nodes[i]) {
                if (ancestor.height[nodes[i]] > maxm) {
                    maxm = ancestor.height[nodes[i]];
                    rightend = nodes[i];
                }
            }
        }

        if (rightend == -1) {
            cout << "Yes" << endl;
            continue;
        }

        ll found = true;

        for (ll i = 0; i < k; ++i) {
            if (dist(leftend, rightend) != dist(leftend, nodes[i]) + dist(rightend, nodes[i])) {
                found = false;
            }
        }

        if (!found)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}