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


void print(vector<vector<int>>&arr, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout <<  arr[i][j] << "\t";
		}
		cout << endl;
	}
}



vector<vector<int>> visited;
int CNT = 0;

void go_left(vector<vector<int>> &arr, pii &p, pii range, int &val) {
	int x = p.first , y = p.second;
	int N = range.first , M = range.second;
	for (int i = y; i < M; i++) {
		if (visited[x][i]) {
			break;
		}
		CNT++;
		p.second = i;
		swap(val, arr[x][i]);
		visited[x][i] = true;
	}
}
void go_right(vector<vector<int>> &arr, pii &p, pii range, int &val) {
	int x = p.first , y = p.second;
	int N = range.first , M = range.second;
	for (int i = y; i >= 0; i--) {
		if (visited[x][i]) {
			break;
		}
		CNT++;
		p.second = i;
		swap(val, arr[x][i]);
		visited[x][i] = true;
	}
}
void go_down(vector<vector<int>> &arr, pii &p, pii range, int &val) {
	int x = p.first , y = p.second;
	int N = range.first , M = range.second;
	for (int i = x; i < N; i++) {
		if (visited[i][y]) {
			break;
		}
		p.first = i;
		CNT++;
		swap(val, arr[i][y]);
		visited[i][y] = true;
	}
}
void go_up(vector<vector<int>> &arr, pii &p, pii range, int &val) {
	int x = p.first , y = p.second;
	int N = range.first , M = range.second;
	for (int i = x; i >= 0; i--) {
		if (visited[i][y]) {
			break;
		}
		CNT++;
		p.first = i;
		swap(val, arr[i][y]);
		visited[i][y] = true;
	}
}






void rotateMatrix(vector<vector<int>> &arr, int n, int m)
{
	visited.assign(n, vector<int>(m, 0));
	CNT = 0;
	int val = 0;

	if (1 < n) val = arr[1][0];
	else return;

	pair<int, int> p = {0, 0}, range = {n, m};

	while (CNT != n * m) {
		go_left(arr, p, range, val); p.first++;
		go_down(arr, p, range, val); p.second--;
		go_right(arr, p, range, val); p.first--;
		go_up(arr, p, range, val); p.second++;
		if (p.first + 1 < n and !visited[p.first + 1][p.second] and p.second + 1 < m and !visited[p.first][p.second + 1])
			val = arr[p.first + 1][p.second];
		else break;
	}
}

int main() {
	int tt = 1;
	cin >> tt;
	while (tt--) {
		int N , M; cin >> N >> M;
		vector<vector<int>> arr(N, vector<int>(M));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
			}
		}
		rotateMatrix(arr, N, M);
		print(arr, N, M);
	}
}