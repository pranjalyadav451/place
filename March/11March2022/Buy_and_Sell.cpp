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

int dp[800][400][2];
int max_profit(vector<int> &price, int txn, int i = 0, bool can_sell = false) {
    if (i == price.size() or txn == 0) return 0;

    int &ans = dp[i][txn][can_sell];
    if (ans != -1) return ans;
    ans = 0;
    if (can_sell) {
        int without_selling_current = max_profit(price, txn, i + 1, true);
        int after_selling = max_profit(price, txn - 1, i + 1, false);
        ans = max(price[i] + after_selling, without_selling_current);
    }
    else {
        int buying_current = max_profit(price, txn - 1, i + 1, true);
        int not_buying_current = max_profit(price, txn, i + 1, false);
        ans = max(-price[i] + buying_current, not_buying_current);
    }
    return ans;
}

int solve(vector<int> &A, int B) {
    int txn = min(B, (int)A.size() / 2 + 1);
    memset(dp, -1, sizeof(dp));
    int ans = max_profit(A, txn);
    return ans;
}


int main() {
    int N; cin >> N;
    vector<int> arr(N);
    for (auto &a : arr) cin >> a;
    int B; cin >> B;
    int ans = solve(arr, B);
    dbg(ans);
}