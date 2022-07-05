// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++



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

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;


typedef tree<pair<ll, ll>,
    null_type,
    less<pair<ll, ll>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> opset;

typedef tree<ll, null_type, less<ll>, splay_tree_tag, tree_order_statistics_node_update> oset;

void fill_other(vector<int> &arr, int N, opset &other) {
    for (int i = N; i < 3 * N; i++) {
        other.insert({ arr[i],i });
    }
}

void print(opset &other) {
    for (auto a : other) {
        cout << "val : " << a.first << ", ";
    }
    cout << endl;
}


class Solution {
public:
    long long colosseum(int N, vector<int> arr) {
        priority_queue<ll, vector<ll>, greater<ll>> minH;
        opset other;

        ll one = 0, two = 0;

        for (int i = 0; i < N; i++) {
            one += arr[i];
            minH.push(arr[i]);
        }

        fill_other(arr, N, other);
        int cnt = 0;
        for (auto a : other) {
            if (cnt == N) break;
            two += a.first;
            cnt++;
        }
        ll ans = -1e18;


        for (int i = N; i < 2 * N; i++) {
            minH.push(arr[i]);
            ll min_on_heap = minH.top();
            minH.pop();
            one += arr[i] - min_on_heap;

            auto get = other.find(make_pair((ll)arr[i], (ll)i));
            ll index = other.order_of_key({ arr[i],i });
            if (index < N) {
                two -= arr[i];
                other.erase(get);
                ll min_in_set = other.find_by_order(N - 1)->first;
                two += min_in_set;
            }
            else
                other.erase(get);
            ans = max(ans, one - two);
        }
        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        Solution obj;
        int n;
        cin >> n;
        vector<int> a(3 * n);
        for (int i = 0; i < 3 * n; ++i) {
            cin >> a[i];
        }
        cout << obj.colosseum(n, a) << "\n";
    }
    return 0;
}