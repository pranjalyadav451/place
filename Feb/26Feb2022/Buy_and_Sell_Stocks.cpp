#include <bits/stdc++.h>
using namespace std;


class Solution {
public:    vector<vector<int> > stockBuySell(vector<int> price, int n) {
        vector<vector<int>> res;
        if (n == 1)
            return res;

        int i = 0;
        while (i < n - 1) {
            while ((i < n - 1) && (price[i + 1] <= price[i]))
                i++;
            if (i == n - 1)
                break;
            int buy = i++;
            while ((i < n) && (price[i] >= price[i - 1]))
                i++;
            int sell = i - 1;
            res.push_back({buy, sell});
        }
        return res;
    }
};

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for (int i = 0; i < ans.size(); i++)
        c += A[ans[i][1]] - A[ans[i][0]];
    return (c == p) ? 1 : 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x = A[i + 1] - A[i];
            if (x > 0)
                p += x;
        }
        if (ans.size() == 0)
            cout << "No Profit";
        else {
            cout << check(ans, A, p);
        } cout << endl;
    }
    return 0;
}
