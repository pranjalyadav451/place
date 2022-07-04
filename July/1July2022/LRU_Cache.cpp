#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;

int fastio() {
    ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0;
} int __fastio = fastio();
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream &operator<<(ostream &os, const set<A> &m) {os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A>                ostream &operator<<(ostream &os, const multiset<A> &m) {os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B>    ostream &operator<<(ostream &os, const map<A, B> &m) {os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>                ostream &operator<<(ostream &os, const vector<T> &v) {os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>      ostream &operator<<(ostream &os, const array<T, L> &v) {os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B>    ostream &operator<<(ostream &os, const pair<A, B> &p) {os << '(' << p.first << ", " << p.second << ')'; return os; }


typedef long long ll;

template<typename T> void read_array(ll n, vector<T> &arr) {arr.resize(n); for (int i = 0; i < n; i++) cin >> arr[i]; }
template<typename... Args> void read(Args&... args) {((cin >> args), ...); }

vector<string >process(string &str) {vector<string> res; string temp = ""; for (int i = 0; i < str.size(); i++) {if (str[i] == '|') {res.push_back(temp); temp = ""; i++; } else temp.push_back(str[i]); } res.push_back(temp); return res; }
template<typename ...Args> void logger(string vars, Args&&... values) {string delim = ""; stringstream ss; (..., (ss << delim << values, delim = "| ")); delim = ""; string arrow = " : ", str_values = ss.str(); for (auto &a : vars) if (a == ',') a = '|'; auto labels = process(vars), content = process(str_values); cout << "[ "; for (int i = 0; i < labels.size(); i++) {cout << delim << labels[i] << arrow << content[i]; delim = ", "; } cout << " ]" << endl; }
#define log(...)                        logger(#__VA_ARGS__, __VA_ARGS__)


struct LRUCache {
    void set(int, int);
    int get(int);
    LRUCache(int);
};

struct DLL {
    int val = -1;
    DLL *prev = NULL , *next = NULL;
};



int MAX_SIZE = 0;
DLL *First = NULL, *Last = NULL;

map<int, int> mp;
map<int, DLL*> node;

void createAndInsertBetween(int key) {
    DLL *t = new DLL();
    DLL *one = First, *three = First->next;
    one->next = t;
    t->prev = one;

    three->prev = t;
    t-> next = three;

    t->val = key;
    node[key] = t;
    return;
}
void removeAndInsert(int key) {
    DLL *t = node[key];
    DLL *one = t->prev , *three = t->next;

    one->next = three;
    three->prev = one;

    one = First, three = First->next;

    one->next = t;
    three->prev = t;

    t->prev = one;
    t-> next = three;

    t->val = key;
    node[key] = t;
    return;
}
void removeLast() {
    DLL *rem = Last->prev;
    DLL *one = rem->prev , *three = rem->next;

    one->next = three;
    three->prev = one;

    mp.erase(rem->val);
    node.erase(rem->val);
    return;
}


LRUCache::LRUCache(int capacity) {
    MAX_SIZE = capacity;
    mp.clear();
    node.clear();

    First = new DLL() , Last = new DLL();

    First->val = -1, First->prev = NULL, First->next = Last;
    Last->val = - 1, Last->next = NULL, Last->prev = First;
}

int LRUCache::get(int key) {
    if (mp.find(key) == mp.end()) {
        return -1;
    }
    removeAndInsert(key);
    return mp[key];
}

void LRUCache::set(int key, int value) {
    if (mp.size() == MAX_SIZE and mp.count(key) == 0) {
        removeLast();
    }
    if (mp.count(key) == 0) {
        createAndInsertBetween(key);
    }
    else {
        removeAndInsert(key);
    }

    mp[key] = value;
}


int main() {
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int ops , cap;
        cin >> ops >> cap;

        LRUCache cache = LRUCache(cap);

        while (ops--) {
            char c ; int a, b;
            cin >> c;
            if (c == 'G') {
                cin >> a;
                int val = cache.get(a);
                cout << val << " ";
            }
            if (c == 'S') {
                cin >> a >> b;
                cache.set(a, b);
            }
        }
    }
}