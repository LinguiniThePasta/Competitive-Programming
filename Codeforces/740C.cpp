#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second - a.first < b.second - b.first;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>>  v(m);
    int k = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        cin >> v[i].first >> v[i].second;
        k = min(k, v[i].second- v[i].first + 1);
    }
    vector<int> a(n);
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] = num;
        num++;
        num %=k;
    }

    cout << k << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}