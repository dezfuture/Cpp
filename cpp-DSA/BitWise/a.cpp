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
const int MOD = 1000000007;

bool isPossible(vector<int> &a, int pages, int students)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (sum + a[i] > pages)
        {
            count++;
            sum = a[i];
            if (sum > pages)
            {
                return false;
            }
        }
        else
        {
            sum += a[i];
        }
    }
    if (count < students)
    {
        return true;
    }
    return false;
}

int books(vector<int> &a, int n, int b)
{
    if (b > a.size())
    {
        return -1;
    }

    int low = a[0];
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        high += a[i];
        low = min(low, a[0]);
    }

    int res = -1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        // cout << low << " " << mid << " " << high << endl;
        if (isPossible(a, mid, b))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a;
    int b;

    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        a.pb(c);
    }

    cin >> b;
    int ans = books(a, n, b);
    cout << ans << endl;
}

int32_t main()
{

    fast_io;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}