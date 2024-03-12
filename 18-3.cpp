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
//#define s .second
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
    ifstream in_stream("input.txt");
    int k, n;
    in_stream >> k >> n;
    vector<int> in_time(n), out_time(n);
    for (int i = 0; i < n; ++i)
        in_stream >> in_time[i] >> out_time[i];
    set<int> free_garages;
    for (int i = 1; i <= k; ++i)
        free_garages.insert(i);

    vector<int> ans(n);
    multiset<pair<int, int>> train_set;
    for (int i = 0; i < n; ++i)
    {
        for (auto j = train_set.begin(); j != train_set.end();)
            if (j->first < in_time[i])
            {
                for (auto x = j; x != train_set.end() && x->first == j->first; ++x)
                    free_garages.insert(x->second);
                j = train_set.erase(j);
            }
            else
                break;
        if (!free_garages.size())
            return (ofstream("output.txt") << 0 << endl << i + 1, 0);
        ans[i] = *free_garages.begin();
        train_set.insert({ out_time[i], *free_garages.begin() });
        free_garages.erase(free_garages.begin());
    }

    ofstream out_stream("output.txt");
    for (auto e : ans)
        out_stream << e << endl;
    return 0;
}
