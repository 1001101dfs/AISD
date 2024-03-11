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

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	map<char, ll>a;
	string st;
	cin >> st;
	n = st.size();
	if (n % 2 == 1) {
		ll chislo = n, shag = n - 2;
		for (int i = 0; i < n; i++) {
			a[st[i]] += chislo;
			chislo = chislo + shag;
			shag -= 2;
		}
	}
	else {
		ll chislo = n, shag = n - 2;
		for (int i = 0; i < n / 2; i++) {
			a[st[i]] += chislo;
			a[st[n - i - 1]] += chislo;
			chislo = chislo + shag;
			shag -= 2;
		}
	}
	for (auto& i : a) {
		cout << i.first << ": " << i.second << endl;
	}
}
