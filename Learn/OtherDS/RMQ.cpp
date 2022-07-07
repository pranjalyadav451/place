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


class Sparse_Table {
public:
    ll LOG = 0;
    ll N = 0;
    vector<vector<ll>> table;
public:
    Sparse_Table(vector<ll> &arr) {
        ll number_ele = arr.size();
        assert(number_ele > 0);
        N = number_ele;
        LOG = __lg(number_ele);
        table.assign(number_ele, vector<ll>(LOG + 1, LONG_LONG_MAX));
        fill_table(arr);
    }
    void fill_table(vector<ll> &arr) {
        for (int i = 0; i < N; i++) {
            table[i][0] = arr[i];
        }

        for (int j = 1; j <= LOG; j++) {
            ll num_ele_in_range = (1 << j);
            ll idx_upper_limit = N - (num_ele_in_range);
            ll offset = (1LL << (j - 1));

            for (int i = 0; i <= idx_upper_limit; i++) {
                table[i][j] = min(table[i][j - 1], table[i + offset][j - 1]);
            }
        }
    }
    ll answer_queries(ll start, ll end) {
        start = start < 0 ? 0 : start;
        end = end >= N ? N - 1 : end;

        assert(start <= end);

        ll size_of_interval = end - start + 1;
        ll just_smaller_in_binary_power = __lg(size_of_interval);
        ll offset = (1LL << (just_smaller_in_binary_power));

        // logger(size_of_interval,
        //     just_smaller_in_binary_power,
        //     offset);
        // logger(start, end);
        // logger(LOG);

        ll first_part = table[start][just_smaller_in_binary_power];
        ll second_part = table[end - offset + 1][just_smaller_in_binary_power];
        // logger(first_part, second_part);


        ll ans = min(first_part, second_part);
        return ans;
    }



};


void solve() {
    int n; read(n);
    vll arr; read_array(n, arr);

    Sparse_Table rmq(arr);

    int q; read(q);

    // logger(rmq.table);

    while (q--) {
        int start, end; read(start, end);
        ll ans = rmq.answer_queries(start, end);
        cout << ans << endl;
    }
}
int main() {
    int tt = 1;
    // cin >> tt; // "UN - COMMENT THIS FOR TESTCASES"
    while (tt--) {
        solve();
    }
}