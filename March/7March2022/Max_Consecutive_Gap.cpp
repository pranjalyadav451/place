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



int maxSortedAdjacentDiff(const vector<int> &arr) {
    int N = arr.size();
    int mx = arr[0], mn = arr[0];
    for (int i = 0; i < N; i++) {
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    int gap = (mx - mn) / (N - 1);
    if (gap == 0) return mx - mn;
    vector<vector<int>> buckets(N, vector<int>(2, -1));
    for (int i = 0; i < N; i++) {
        int idx = (arr[i] - mn) / (gap);
        auto &current = buckets[idx];

        if (current[0] == -1) {
            current[0] = current[1] = arr[i];
        } else {
            current[0] = min(current[0], arr[i]);
            current[1] = max(current[1], arr[i]);
        }
    }

    vector<int> prev = buckets[0];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (buckets[i][0] == -1) continue;
        ans = max(ans, buckets[i][0] - prev[1]);
        prev = buckets[i];
    }
    return ans;
}

int maximumGap(const vector<int> &A) {
    if (A.size() < 2) return 0;
    int ans = maxSortedAdjacentDiff(A);
    return ans;
}


int main() {
    int tt = 1;
    // cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
    while (tt--) {
        int N; cin >> N;
        vector<int> arr(N);
        for (auto &a : arr) cin >> a;
        int ans = maximumGap(arr);
        cout << ans << endl;
    }
}