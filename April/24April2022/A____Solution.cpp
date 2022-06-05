#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 500100;

int N;
string s;
int A[MAXN];
int blo[MAXN];
int res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> s;
    N = s.length();

    blo[N] = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (s[i] == '<')
        {
            blo[i] = 0;
        }
        else
        {
            blo[i] = blo[i + 1] + 1;
        }
    }

    res[0] = blo[0];
    for (int i = 0; i < N; i++)
    {
        if (s[i] == '<')
        {
            res[i + 1] = max (blo[i + 1], res[i] + 1);
        }
        else
        {
            res[i + 1] = blo[i + 1];
        }
    }

    ll ans = 0;
    for (int i = 0; i <= N; i++)
        ans += res[i];
    cout << ans << "\n";
}