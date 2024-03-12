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
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<double>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		bool ok = true;
		for (int i = 0; i < n - 2; i++) {
			if (a[i] < a[i + 1] && a[i + 2] < a[i] && a[i] < a[i + 1]) {
				cout << 0 << endl;
				ok = false;
				break;
			}
		}
		if (ok)cout << 1 << endl;
	}
}
