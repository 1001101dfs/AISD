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
bool comp(ll a, ll b) {
	return a > b;
}
ll get_time(string st) {
	ll hh = (st[0] - '0') * 10 + (st[1] - '0');
	ll mm = (st[3] - '0') * 10 + (st[4] - '0');
	ll ss = (st[6] - '0') * 10 + (st[7] - '0');
	return hh * 60 * 60 + mm * 60 + ss;
}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string st1, st2, st3;
	cin >> st1 >> st2 >> st3;
	ll t1 = get_time(st1);
	ll t2 = get_time(st2);
	ll t3 = get_time(st3);
	ll time = (t3 + 24 * 3600 - t1) % (24 * 3600);
	time = (time + 1) / 2 + t2;
	time = time % (24 * 3600);
	ll hh = time / 60 / 60;
	time -= hh * 60 * 60;
	hh %= 24;
	ll mm = time / 60;
	time -= mm * 60;
	if (hh < 10)cout << 0;
	cout << hh << ':';
	if (mm < 10)cout << 0;
	cout << mm << ':';
	if (time < 10) cout << 0;
	cout << time;

}