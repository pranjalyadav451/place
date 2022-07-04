// https://codeforces.com/contest/1690/submission/159740396
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	i64 ans = 0;
	std::vector<int> a(n);
	std::multiset<int> s;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		ans += a[i] / k;
		a[i] %= k;
		s.insert(a[i]);
	}

	while (!s.empty()) {
		int x = *s.begin();
		s.erase(s.begin());

		auto it = s.lower_bound(k - x);
		if (it != s.end()) {
			s.erase(it);
			ans++;
		}
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}

// Editorial Solution
/*
#include<bits/stdc++.h>
#define len(s) (int)s.size()
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll>a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i] / k;
        a[i] = a[i] % k;
    }
    sort(a.begin(), a.end(), [] (int x, int y){
        return x > y;
    });

    for(int i = 0, j = n - 1; i < j; i++, j--){
        while(a[i] + a[j] < k && i < j) j--;
        if(i == j) break;
        sum++;
    }
    cout << sum << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
*/