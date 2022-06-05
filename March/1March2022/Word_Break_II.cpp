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


// Time - O(N^3), Space - O(N^2)
// where N = size of sentence
vector<string> rec(const string& sentence, const vector<string>& dict, unordered_map<string, vector<string>>& found) {

    if (found.count(sentence)) {
        return found[sentence];
    }

    int n = sentence.size();
    vector<string> result;
    for (int i = 1; i <= n; i++) {
        string word = sentence.substr(0, i);
        string rem = sentence.substr(i);
        if (find(dict.begin(), dict.end(), word) != dict.end()) {
            if (rem.empty()) {
                result.push_back(word);
            }
            else {
                for (auto& s : rec(rem, dict, found)) {
                    result.push_back(word + " " + s);
                }
            }
        }
    }

    found[sentence] = result;
    return result;
}

vector<string> wordBreak(string A, vector<string> &B) {
    unordered_map<string, vector<string>> found;
    return rec(A, B, found);
}

int main() {
    string str; cin >> str;
    int N; cin >> N;
    vector<string> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> str;
    }
    vector<string> ans = wordBreak(str, arr);
    cout << ans << endl;
}