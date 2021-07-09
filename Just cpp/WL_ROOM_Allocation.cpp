#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(0);
#define endl "\n"
#define ull unsigned long long
#define pb push_back
#define ar array
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1000000007;

const int mxN = 2e5;
int n, ans[mxN];
ar<int, 3> a[mxN];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][1] >> a[i][0];
        a[i][2] = i;
    }

    std::sort(a, a + n);

    std::set<ar<int, 2>> s;
    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound({a[i][1]});
        if (it != s.begin())
        {
            --it;
            ans[a[i][2]] = (*it)[1];
            s.erase(it);
        }
        else
        {
            ans[a[i][2]] = s.size();
            s.insert({a[i][0], ans[a[i][2]]});
        }
    }
    cout << s.size() << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << " ";
    }
}

int32_t main()
{

    fast_io;

    solve();

    return 0;
}