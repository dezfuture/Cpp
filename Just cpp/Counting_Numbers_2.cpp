#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(0);
#define endl "\n"
#define ull unsigned long long
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, bool> pllb;
const ll MOD = 1000000007;
const int N = (int)(1 * 1e6 + 10);
const int MAXN = 2e5 + 5;

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll a[n + 1] = {0}, index[n + 1] = {0};
    for (ll i = 1; i < n + 1; i++)
    {
        ll x;
        cin >> x;
        index[x] = i;
        a[i] = x;
    }
    int l = 1;
    ll count = 1;
    for (ll i = 0; i < n; i++)
    {
        if (l > index[i])
        {
            count++;
        }
        l = index[i];
    }

    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        ll r = a[x], s = a[y];
        std::swap(a[x], a[y]);

        if (index[r - 1] <= index[r] && index[r - 1] > y)
        {
            count++;
        }
        else if (index[r - 1] > index[r] && index[r - 1] <= y)
        {
            count--;
        }
        else if (index[r] <= index[r + 1] && y > index[r + 1])
        {
            count++;
        }
        else if (index[r] > index[r + 1] && y <= index[r + 1])
        {
            count--;
        }

        index[r] = y;

        if (index[s - 1] <= index[s] && index[s - 1] > x)
        {
            count++;
        }
        else if (index[s - 1] > index[s] && index[s - 1] <= x)
        {
            count--;
        }
        else if (index[s] <= index[s + 1] && x > index[s + 1])
        {
            count++;
        }
        else if (index[s] > index[s + 1] && x <= index[s + 1])
        {
            count--;
        }

        index[s] = x;

        cout << count << endl;
    }
}
signed main()
{

    fast_io;

    solve();
}
