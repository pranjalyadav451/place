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

const int BLACK = 1, WHITE = 0;

bitset<110>visited;
vvl graph;
vll color;
vll ansls;
ll mx = 0;
ll N , K;

void find_coloring(int u, int col) {
	if (visited[u]) return;
	visited[u] = true;
	color[u] = col;

	if (visited.count() == N) {
		ll b = 0, w = 0;
		for (int i = 0; i < N; i++) {
			if (color[i] == BLACK) b++;
			else w++;
		}
		if (b >= mx) {
			mx = b;
			ansls.clear();
			for (int i = 0; i < N; i++) {
				if (color[i] == BLACK) ansls.push_back(i);
			}
		}
	}

	for (auto v : graph[u]) {
		if (color[u] == WHITE) {
			find_coloring(v, col);
			find_coloring(v, !col);
		}
		else
			find_coloring(v, !col);
	}
	color[u] = WHITE;
	visited[u] = false;
}

int main() {
	ll tt; cin >> tt;
	ll a, b;


	while (tt--) {
		cin >> N >> K;
		graph.assign(N, vector<ll>());
		color.assign(N, WHITE);
		mx = 0;


		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			a--, b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}


		visited.reset();
		find_coloring(0, 0);

		visited.reset();
		mx = 0;
		find_coloring(0, 1);

		cout << ansls.size() << endl;
		for (int i = 0; i < ansls.size(); i++) {
			cout << ansls[i] + 1 << " ";
		}
		cout << endl;
	}
}