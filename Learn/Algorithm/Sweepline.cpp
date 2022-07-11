
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Point {
    int point, left, right, isLeft;
    Point(int p, int l, int r, int i) : point(p), left(l), right(r), isLeft(l) {}
};
bool compare(const Point &x, const Point &y) {
    return x.point < y.point;
}

void solve() {
    int n; cin >> n;
    vector<ll> L(n), R(n);
    for (int i = 0; i < n; i++) cin >> L[i];
    for (int i = 0; i < n; i++) cin >> R[i];

}


int main() {
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}

