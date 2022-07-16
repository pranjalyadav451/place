#include<bits/stdc++.h>

using namespace std;

int dp[1001];
// Implemented a recursive solution for Longest Increasing subsequence.

int rec(vector<int> &arr, int i, int prev) {
    if (i == arr.size()) return 0;

    int ans = rec(arr, i + 1, prev);
    if (prev == -1 or arr[i] > arr[prev]) {
        ans = max(ans, rec(arr, i + 1, i) + 1);
    }
    return ans;
}


int lcs(vector<int> &arr, int n) {

}

int main() {
    int tt = 1;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int ans = lcs(arr, n);
        cout << "the length of lcs is : " << ans << endl;
    }
    return 0;
}