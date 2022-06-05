#include<bits/stdc++.h>
using namespace std;

// good question using properties of 'And' operation.



void solveTestCase() {
    int MOD = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];

    int min1 = *min_element(a.begin(), a.end());
    int cnt = 0;

    for (int x : a) {
        if (min1 == x)cnt++;
        // checking if the remaining elements are a superset of the min elements 
        // which are to be placed at both ends.
        if ((min1 & x) != min1) {
            printf("0\n");
            return;
        }
    }

    int fact = 1;
    for (int i = 1; i <= n - 2; i++)fact = (1LL * fact * i) % MOD;
    int ans = (1LL * cnt * (cnt - 1)) % MOD; // nP2 -> order of elements matters here.
    ans = (1LL * ans * fact) % MOD;
    printf("%d\n", ans);
}

int main() {
    int tests;
    cin >> tests;
    while (tests--)
        solveTestCase();
    return 0;
}