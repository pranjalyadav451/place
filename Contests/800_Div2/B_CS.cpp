#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t ;
	cin >> t ;
	while (t--) {
		ll n ;
		cin >> n ;
		string s ;
		cin >> s ;

		ll ans = 0;
		for (int i = 1 ; i < n ; i++) {
			if (s[i] != s[i - 1]) {
				ans += i ;
			}
		}
		ans += n;
		cout << ans << "\n" ;
	}
	return 0;
}