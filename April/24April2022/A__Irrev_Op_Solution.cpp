#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>


#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)

using namespace std;
char s[300005];
ll ans = 0;
int main() {
	scanf("%s", s + 1);
	int len = strlen(s + 1), cnt = 0;
	For(i, 1, len) {
		if (s[i] == 'B') cnt++;
		else ans += cnt;
	}
	printf("%lld\n", ans);
}