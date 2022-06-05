/*
https://codeforces.com/contest/1675/problem/D
Time Limit: 2000
Memory Limit: 256
Thu May 05 2022 20:43:04 GMT+0530 (India Standard Time)
*/
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


vector<bool> VIS;
ll CNT = 0;
vll PARENT;


ll dfs(vvl &graph, int node) {
	if (VIS[node]) return 0;
	VIS[node] = true;
	ll mx = 0;

	PARENT[node] = node;

	ll n = 0;
	ll best = 0;

	for (auto a : graph[node]) {
		if (VIS[a]) continue;
		ll path = dfs(graph, a);
		// dbgg(node, a);
		if (path > mx) {
			mx = path;
			best = a;
		}
		n++;
	}
	if (best != 0)
		PARENT[best] = node;

	CNT += max(0LL, n - 1);
	return mx + 1;
}

void show_graph(vvl &graph) {
	for (int i = 1; i < graph.size(); i++) {
		dbgg(i, graph[i]);
	}
}

void printPath(int j, vll &temp)
{
	if (PARENT[j] == j) {
		temp.push_back(j);
		return;
	}

	printPath(PARENT[j], temp);
	temp.push_back(j);
}

void solve() {

	ll N; cin >> N;
	vvl graph(N + 1);

	PARENT.resize(N + 1);
	CNT = 0;

	VIS.assign(N + 1, false);

	ll root = -1;
	for (int i = 0; i < N; i++) {
		ll node; cin >> node;
		if (node == i + 1) {
			graph[node].push_back(node);
			root = node;
			continue;
		}
		graph[node].push_back(i + 1);
		graph[i + 1].push_back(node);
	}


	ll some = dfs(graph, root);

	vvl paths;

	for (int i = 1; i <= N; i++) {
		if (graph[i].size() == 1) {
			vector<ll> temp;
			printPath(i, temp);
			paths.push_back(temp);
		}
	}

	cout << paths.size() << endl;
	for (auto a : paths) {
		cout << a.size() << endl;
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	int tt = 1;
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}
}