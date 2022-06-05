/*
https://codeforces.com/problemset/problem/1650/D
Time Limit: 2000
Memory Limit: 256
Thu Apr 14 2022 11:59:59 GMT+0530 (India Standard Time)
*/

#include <bits/stdc++.h>
#include <vector>
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

void rotate_left(vll &arr, int N, int times, map<ll, ll> &pos) {
	vector<bool> rotated(N, false);

	for (int i = 0; i < N; i++) {
		if (rotated[i]) continue;
		int current_pos = i;
		int value = arr[i];
		do {
			int new_pos = (current_pos - times + N) % N;
			int temp_value = arr[new_pos];
			arr[new_pos] = value;
			pos[value] = new_pos;
			value = temp_value;
			rotated[current_pos] = true;
			current_pos = new_pos;
		}
		while (current_pos != i);
	}
}

void solve(vll &arr, int N , map<ll, ll>&pos) {

	map<ll, ll> ans;
	for (auto itr = pos.rbegin(); itr != pos.rend(); itr++) {
		ll ele =  itr->first, curr_pos = itr->second;
		ans[ele] = 0;
		if (curr_pos + 1 == ele) {
			continue;
		}

		ll ideal_pos = ele - 1;
		ll times = (curr_pos - ideal_pos + ele ) % ele;

		ans[ele] = times;
		rotate_left(arr, ideal_pos + 1, times, pos);
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] != i + 1) {
			cout << -1 << endl;
			return;
		}
	}

	for (auto ele : ans) {
		cout << ele.second << " ";
	}
	cout << endl;
}

void input() {
	int N; cin >> N;
	vll arr(N);
	map<ll, ll> pos;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		pos[arr[i]] = i;
	}

	solve(arr, N, pos);
}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		input();
	}
}