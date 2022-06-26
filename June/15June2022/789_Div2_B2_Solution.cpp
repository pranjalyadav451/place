#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, L = -1, x = 0, y = 0;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i + 1]) x += 1;
            else {
                if (L != s[i]) y += 1;
                L = s[i];
            }
        }
        cout << x << " " << max(y, 1) << "\n";
    }
}