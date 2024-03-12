#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <iostream>
#include <cmath>
#include <iomanip>
#include <set>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <climits>
#include <ctime>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define ll long long
#define f .first
#define s .second
#define mp make_pair
#define pb push_back
using namespace std;
vector<vector<ll>>g;
vector<bool>t;
void dfs(ll v) {
	t[v] = 1;
	for (auto& i : g[v]) {
		if (!t[i]) {
			dfs(i);
		}
	}
}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	g.resize(n);
	t.resize(n, false);
	for (int x, y,i = 0; i < m; i++) {
		cin >> x >> y;
		g[y - 1].push_back(x - 1);
	}
	dfs(0);
	for (int i = 0; i < n; i++) {
		if (t[i]) {
			cout << i + 1 << " ";
		}
	}
}
