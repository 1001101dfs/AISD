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
	string st, st1;
	cin >> st;
	stack<pair<char, ll>>q;
	st = '(' + st + ')';
	for (int i = 0; i < st.size(); i++) {
		if (st[i] == '1' || st[i] == '0') {
			st1 += st[i];
		}
		else {
			bool ok = true;
			ll pr = 2;
			if (st[i] == '(')pr = 1;
			if (st[i] == '!')pr = 4;
			if (st[i] == '&')pr = 3;
			while (ok) {
				if (q.empty()) {
					q.push({ st[i], pr });
					ok = false;
					continue;
				}
				if (st[i] == '(') {
					q.push({ st[i], pr });
					ok = false;
					continue;
				}
				if (st[i] == ')') {
					while (!q.empty() && q.top().first != '(') {
						st1 += q.top().first;
						q.pop();
					}
					if (!q.empty())q.pop();
					ok = false;
					continue;
				}
				if (q.top().second < pr)q.push({ st[i], pr }), ok = false;
				else {
					st1 += q.top().first;
					q.pop();
				}
			}
		}
	}
	stack<ll>b;
	for (int i = 0; i < st1.size(); i++) {
		if (st1[i] == '0' || st1[i] == '1') {
			b.push(st1[i] - '0');
		}
		else {
			if (st1[i] == '!') {
				ll x = b.top();
				b.pop();
				if (x == 1) x = 0;
				else x = 1;
				b.push(x);
			}
			if (st1[i] == '&') {
				ll x = b.top();
				b.pop();
				ll y = b.top();
				b.pop();
				b.push(x & y);
			}
			if (st1[i] == '|') {
				ll x = b.top();
				b.pop();
				ll y = b.top();
				b.pop();
				b.push(x | y);
			}
			if (st1[i] == '^') {
				ll x = b.top();
				b.pop();
				ll y = b.top();
				b.pop();
				b.push(x ^ y);
			}
		}
	}
	cout << b.top();
}
