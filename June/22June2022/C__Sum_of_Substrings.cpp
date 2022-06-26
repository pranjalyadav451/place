/*
C. Sum of Substrings
Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
https://codeforces.com/problemset/problem/1691/C
Memory Limit : 256
Time Limit : 1000

Wed Jun 22 2022 10:48:49 GMT+0530 (India Standard Time)
Started At: 10:48:49 AM
*/
#include <bits/stdc++.h>
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


void reduced(string &str, ll K) {
    ll last = str.find_last_of('1'), N = str.size();
    if (last == string::npos) return;

    if (N - last - 1 <= K) {
        swap(str[last], str[N - 1]);
        K -= N - last - 1;
    }

    ll first = str.find_first_of('1');
    if (first != N - 1 and first <= K) {
        swap(str[first], str[0]);
    }
}

// Take care of corner cases.
// Dry run the solution when you are not sure of it thoroughly.
// Better to be late than to be wrong.
// Try to run it on testcases other than the samples on which you think it might fail.
// Never use int - Lost too much
// Always use pen and paper for doing the dry run of the test cases.

void solve() {
    ll N , K;
    string str;
    cin >> N >> K >> str;

    reduced(str, K);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += ((ll)(i > 0) + (ll)(i < N - 1) * 10) * (str[i] == '1');
    }
    cout << ans << endl;
}

int main() {
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}

