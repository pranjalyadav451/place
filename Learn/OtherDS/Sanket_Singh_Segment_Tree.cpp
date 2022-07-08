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
#define logger(...)                        logger(#__VA_ARGS__, __VA_ARGS__)

/**
 * Segment Tree by Sanket Singh
 * Source -: https://www.youtube.com/watch?v=oOufBRAEnUA&ab_channel=CodeChef
 *

 * Properties of Segment Tree
    * It is a binary tree.
    * Type of Binary Tree - Full
    * * What is a full binary tree ?
    *   * A binary tree in which every node has exactly either 2 or 0 children.
    * * Heap is a complete binary tree but segment tree is a 'full' binary tree.
    *
*/

class Segment_Range_Sum {
    long long N;
    vector<ll> arr;
    vector<ll> tree;
    inline int get_left(int node) {
        return (node >> 1);
    };
    inline int get_right(int node) {
        return get_left(node) + 1;
    };
    inline int get_mid(int start, int end) {
        return start + (end - start) / 2;
    }

    void build(int current_node, int start, int end) {
        if (start == end) {
            tree[current_node] = arr[start];
            return;
        }
        int mid = get_mid(start, end), left_child = get_left(current_node), right_child = get_right(current_node);

        build(left_child, start, mid);
        build(right_child, mid + 1, end);
        tree[current_node] = tree[left_child] + tree[right_child];
    }

    // point update
    void update(int current_node, int idx_to_update, long long val_to_update, int start, int end) {
        if (start == end) {
            tree[current_node] = val_to_update;
            return;
        }

        int mid = get_mid(start, end), left_child = get_left(current_node), right_child = get_right(current_node);
        if (idx_to_update <= mid) {
            update(left_child, idx_to_update, val_to_update, start, mid);
        }
        else {
            update(right_child, idx_to_update, val_to_update, mid + 1, end);
        }
        tree[current_node] = tree[left_child] + tree[right_child];
    }
    long long query(int current_node, int query_start, int query_end, int start, int end) {
        if (end < query_start or start > query_end) return 0;
        if (query_start <= start and query_end >= end) {
            return tree[current_node];
        }

        int mid = get_mid(start, end), left_child = get_left(current_node), right_child = get_right(current_node);

        ll get_from_left = query(left_child, query_start, query_end, start, mid);
        ll get_from_right = query(right_child, query_start, query_end, mid + 1, end);

        return get_from_left + get_from_right;
    }
public:
    Segment_Range_Sum(int number_ele) {
        this->N = number_ele;
        arr.assign(4 * N, 0);
        tree.assign(4 * N, 0);
    }
    long long find_query(int start, int end) {
        assert(start <= end);
        return query(1, start, end, 0, N - 1);
    }
    void update_idx(int idx, long long val) {
        assert(idx >= 0 and idx < N);
        update(1, idx, val, 0, N - 1);
    }

};

void solve() {

}
int main() {
    int tt = 1;
    // cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
    while (tt--) {
        solve();
    }
}