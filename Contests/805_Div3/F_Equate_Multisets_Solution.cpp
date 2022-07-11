#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define all(x) x.begin(),x.end()
#define mp make_pair
#define google "Case #" << tc << ": "

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int32_t N = 1e5 + 1;

// user : sapta0506

void solve(int tc) {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i, 0, n) {
        cin >> a[i];
        while (a[i] % 2 == 0) a[i] /= 2;
    }
    priority_queue<int> pq;
    rep(i, 0, n) {
        cin >> b[i];
        while (b[i] % 2 == 0) b[i] /= 2;
        pq.push(b[i]);
    }
    sort(all(a));
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        int y = a.back();
        if (x == y) {
            a.pop_back();
            continue;
        }
        if (y > x) {
            cout << "NO" << endl;
            return;
        }
        x /= 2;
        pq.push(x);
    }
    cout << "YES" << endl;
}


/*
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1005, logN = 20, M = 6e6;

struct Dsu {
    vector <int> rt, sz;
    int n, cc;
    Dsu () = default;
    Dsu (int _n) : n(_n), cc(_n) {
        rt.resize(n), iota(rt.begin(), rt.end(), 0);
        sz.assign(n, 1);
    }
    int Find(int v) {
        return rt[v] == v ? v : rt[v] = Find(rt[v]);
    }
    bool Union(int v, int u) {
        u = Find(u), v = Find(v);
        if (u == v)
            return false;
        if (sz[u] > sz[v])
            swap(u, v);
        rt[u] = v;
        sz[v] += sz[u];
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            while (a[i] & 1 ^ 1)
                a[i] >>= 1;
        }
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        sort(all(a));
        priority_queue <int> pq(all(b));
        bool ans = true;
        while (!pq.empty()) {
            int x = pq.top(); pq.pop();
            if (x < a.back()) {
                ans = false;
                break;
            }
            if (x == a.back())
                a.pop_back();
            else
                pq.push(x >> 1);
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;
    for(int& x : a) while(x % 2 == 0) x /= 2;
    for(int& x : b) while(x % 2 == 0) x /= 2;
    map<int,int> freq;
    for(int x : a){
        while(x){
            freq[x] -= 1;
            x /= 2;
        }
    }
    for(int x : b){
        while(x){
            freq[x] += 1;
            x /= 2;
        }
    }
    bool works = true;
    for(auto [z, f] : freq){
        if(f < 0) works = false;
    }
    if(works){
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}