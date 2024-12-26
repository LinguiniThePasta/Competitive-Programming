#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>

#define ll long long

using namespace std;
ll checkIfPossible(ll n, map<char, ll> a, ll tot, ll p1, ll p2, ll p3, ll n1, ll n2, ll n3) {
    ll cost = n * (a['B'] * p1 + a['S'] * p2 + a['C'] * p3);
    cost -= a['B'] == 0? 0 : min(n * a['B'], n1) * p1;
    cost -= a['S'] == 0? 0 : min(n * a['S'], n2) * p2;
    cost -= a['C'] == 0? 0 : min(n * a['C'], n3) * p3;

    if (tot >= cost)
    {
        return 1;
    }
    return 0;
}

int main() {
    string s;
    cin >> s;
    ll n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    ll p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    ll t;
    cin >> t;

    map<char, ll> needed;
    for (ll i = 0; i < s.size(); i++)
    {
        needed[s[i]]++;
    }

    ll costForOne = max(needed['B'] - n1, (ll)0) * p1 + max(needed['S'] - n2, (ll)0) * p2 + max(needed['C'] - n3, (ll)0) * p3;
    n1 = max(n1 - needed['B'], (ll)0);
    n2 = max(n2 - needed['S'], (ll)0);
    n3 = max(n3 - needed['C'], (ll)0);

    t -= costForOne;
    if (t < 0)
    {
        cout << 0;
        return 0;
    }
    ll lo = 0;
    ll hi = 1e14;
    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (checkIfPossible(mid, needed, t, p1, p2, p3, n1, n2, n3))
        {
            lo = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans + 1;
    return 0;
}

