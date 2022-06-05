/*
https://codeforces.com/problemset/problem/1654/C
Time Limit: 2000
Memory Limit: 256
Mon May 02 2022 16:52:47 GMT+0530 (India Standard Time)
*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A>                ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>                ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>      ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }


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


multiset<ll> mset;

bool trav(ll sum) {
    if (mset.count(sum)) {
        mset.erase(mset.find(sum));
        return true;
    }
    if (sum == 1) return 0;
    ll one = sum / 2, other = sum - one;
    if (trav(one)) return trav(other); // optimization
    return false;
}

// Try to write optimized code when the code is basically simulating the process.
// Somehow while using multiset the code does not TLE with just 1 optimization.
// As opposed to using the same code with unordered_map
// https://codeforces.com/contest/1654/submission/155792469

void solve() {
    ll N; cin >> N;
    vll arr(N);
    ll sum = 0;

    mset.clear();
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        mset.insert(arr[i]);
        sum += arr[i];
    }
    bool is = trav(sum);
    cout << (is ? "YES" : "NO") << endl;
}
int main() {
    int tt = 1;
    cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
    while (tt--) {
        solve();
    }

}