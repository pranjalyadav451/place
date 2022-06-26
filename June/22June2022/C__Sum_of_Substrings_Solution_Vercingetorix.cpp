#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt = 1;
    std::cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int r = n - 1;
        while (r >= 0 && s[r] == '0') r--;
        if (r >= 0 && n - 1 - r <= k) {
            k -= (n - 1 - r);
            swap(s[r], s[n - 1]);
        }
        int l = 0;
        while (l < n && s[l] == '0') l++;
        if (l < n - 1 && l <= k) {
            swap(s[l], s[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i < n - 1) ans += 10;
                if (i > 0) ans++;
            }
        }
        printf("%d\n", ans);
    }
}