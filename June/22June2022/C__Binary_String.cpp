/*
C. Binary String
Codeforces - Educational Codeforces Round 128 (Rated for Div. 2)
https://codeforces.com/problemset/problem/1680/C
Memory Limit : 512
Time Limit : 2000

Wed Jun 22 2022 10:49:09 GMT+0530 (India Standard Time)
Started At: 10:49:09 AM
*/
#include <bits/stdc++.h>
using namespace std;
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

template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[" << "( " << vars << " )" << " :-> ( "; string delim = ""; (..., (cout << delim << values, delim = ", ")); cout << " )]" << endl;
}
typedef long long                           ll;
typedef pair<ll, ll>                        pll;
typedef vector<vector<ll>>                  vvl;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;
typedef vector<ll>                          vll;

#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl
#define log_all(...)                        logger(#__VA_ARGS__, __VA_ARGS__)


int check(string &str, vll &pos, ll req) {
    ll N = str.size(), k = pos.size(), z = N - k;
    if (k == 0) return true;

    vll prem(k + 1), srem(k + 1);
    prem[0] = pos[0] - 1; prem[k] = N - 1;
    for (int i = 1; i < k; i++) {
        prem[i] = pos[i] - 1;
    }
    srem[0] = pos[k - 1] + 1, srem[k] = 0;
    for (int i = 1; i < k; i++) {
        srem[i] = pos[k - i - 1] + 1;
    }

    ll score = 1e9;
    for (int i = 0; i <= req; i++) {
        ll removed_zeros = (prem[i] + 1) + (N - srem[req - i]) - req;
        score = min(max(req, z - removed_zeros), score);
    }
    return score <= req;
}

void solve() {
    string str;
    cin >> str;
    ll N = str.size(), left = 0, right = count(all(str), '1'), mid = 0, ans = right;
    vll pos;
    for (int i = 0; i < N; i++) {
        if (str[i] == '1') pos.push_back(i);
    }
    while (left <= right) {
        mid = left + (right - left) / 2;
        bool is = check(str, pos, mid);
        if (is) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    int tt = 1;
    cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
    while (tt--) {
        solve();
    }
}
