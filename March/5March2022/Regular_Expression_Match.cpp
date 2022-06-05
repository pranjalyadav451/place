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


vector<vector<int>> dp;
bool check(const string &exp, int j) {
    int N = exp.size();
    for (int i = j; i < N; i++) {
        if (exp[i] != '*') return false;
    }
    return true;
}

bool possible(const string &str, const string &exp, int i, int j) {
    if (i == str.size() and j == exp.size()) return true;
    // if (j == exp.size()) return i == str.size();
    if (i == str.size()) return check(exp, j);

    // dbgg(i, j);
    int &ans = dp[i][j];
    if (ans != -1) return ans;
    ans = 0;
    if (exp[j] == '*') {
        ans = possible(str, exp, i + 1, j) || possible(str, exp, i, j + 1) || possible(str, exp, i + 1, j + 1);
    }
    else if (exp[j] == '?') {
        ans = possible(str, exp, i + 1, j + 1);
    }
    else {
        if (exp[j] == str[i]) {
            cout << "here" << endl;
            ans = possible(str, exp, i + 1, j + 1);
        }
        else {
            ans = false;
        }
    }
    // dbg(ans);
    // cout << endl << endl;
    return ans;
}

int isMatch(const string A, const string B) {
    dp.assign(A.size() + 1, vector<int>(B.size() + 1, -1));
    int ans = possible(A, B, 0, 0);
    return ans;
}


int main() {
    string str, exp;
    cin >> str >> exp;
    int ans = isMatch(str, exp);
    dbg(ans);
}
