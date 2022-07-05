#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long colosseum(int N, vector<int> arr) {};
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