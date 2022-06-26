#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A>                ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>                ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>      ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }


typedef long long                           ll;
typedef pair<ll, ll>                        pll;
typedef vector<vector<ll>>                  vvl;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;
typedef vector<ll>                          vll;

#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl

bool ans = false;


bool calc(ll total, ll pos, vll &arr) {
	if (pos == arr.size() - 1) {
		return (total  - arr[pos] == 23)
		       || (total + arr[pos] == 23)
		       || (total * arr[pos] == 23);
	}

	bool res = calc(total + arr[pos], pos + 1, arr)
	           || calc(total - arr[pos], pos + 1, arr)
	           || calc(total * arr[pos], pos + 1, arr);
	return res;
}

void perm(int i, vll &arr) {
	if (i == arr.size()) {
		ans |= calc(arr[0], 1, arr);
	}
	for (int j = i; j < arr.size(); j++) {
		swap(arr[i], arr[j]);
		perm( i + 1, arr);
		swap(arr[i], arr[j]);
	}
}



int main() {
	ll a = 0, b = 0, c = 0, d = 0, e = 0;
	while (cin >> a >> b >> c >> d >> e) {
		vll arr = {a, b, c, d , e};
		if (count(all(arr), 0) == 5) return 0;

		ans = false;
		perm(0, arr);
		cout << (ans ? "Possible" : "Impossible") << endl;
	}
}