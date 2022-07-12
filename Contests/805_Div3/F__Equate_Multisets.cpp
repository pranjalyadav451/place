/*
name: F. Equate Multisets
group: Codeforces - Codeforces Round #805 (Div. 3)
url: https://codeforces.com/contest/1702/problem/F
interactive: false
memoryLimit: 256
timeLimit: 4000
Started At: 6:54:31 AM
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

// Verdict -: MLE, due to pushing so many things into the set.

void solve() {
    ll n; read(n);
    vector<int> A; read_array(n, A);

    bool is = true;
    for (int i = 0; i < n; i++) {
        while (A[i] > 0 and A[i] % 2 == 0) A[i] /= 2;
    }

    multiset<pair<int, int>> ele;

    for (int i = 0; i < n; i++) {
        int b; read(b);
        auto temp = b;
        while (temp) {
            auto key = pair(temp, b);
            // pruning all the even values
            if (temp % 2 == 1)
                ele.insert(key);
            temp /= 2;
        }
    }
    sort(all(A), greater<int>());
    // this part is necessary, we first have to match the biggest in A[]
    // because if we do not sort the array A[], we might remove the suitable
    // candidate for next A[i] 
    // because it is not guaranteed that removing smaller values of candidates
    // necessarily leaves cadidates for remaining A[i] undisturbed;

    /***
     * 6
        1 2 10 16 64 80
        20 43 60 74 85 99
    -> Had we not removed 20 to match with 1, we would have used it to match with 5.
    Dry Run
    [ i : 0, A[i] : 1 ]
    [ e : 1, init : 20 ]

    [ i : 1, A[i] : 1 ]
    [ e : 1, init : 43 ]

    [ i : 2, A[i] : 5 ]
    [ e : 5, init : 85 ]

    [ i : 3, A[i] : 1 ]
    [ e : 1, init : 60 ]

    [ i : 4, A[i] : 1 ]
    [ e : 1, init : 74 ]

    [ i : 5, A[i] : 5 ]
    [ e : 49, init : 99 ]

    NO

    */

    for (int i = 0; i < n; i++) {
        auto search = pair(A[i], 0);
        auto get = ele.lower_bound(search);
        auto [e, init] = *get;


        if (get != ele.end() and e == A[i]) {
            ll ele_in_B = init;
            while (ele_in_B and ele.size()) {
                auto to_remove = pair(ele_in_B, init);
                if (ele_in_B % 2 == 1)
                    ele.erase(ele.find(to_remove));
                ele_in_B /= 2;
            }
        }
        else {
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