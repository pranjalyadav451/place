#include <iostream>
#include <string>
#include <vector>
#include <sstream>

typedef long long ll;
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        vector<int> coef;
        int c;
        while (ss >> c)
            coef.push_back(c);

        getline(cin, s);
        stringstream num(s);
        vector<int>ans;

        while (num >> c) {
            int y = coef[0];
            for (int i = 1; i < coef.size(); ++i)
                y = y * c + coef[i];
            ans.push_back(y);
        }
        for (int i = 0; i < ans.size(); ++i) {
            if (i == 0)
                cout << ans[0];
            else
                cout << " " << ans[i];

        }
        cout << '\n';
    }
    return 0;
}