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
const int MOD = 1000000007;

// COIN CHANGE PROBLEM
// vector<int> v{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
// int n;
// cin >> n;
// std::sort(v.begin(), v.end(), greater<int>());
// int ans = 0;
// for (int i = 0; i < v.size(); i++)
// {
//     ans += n / v[i];
//     n -= n / v[i] * v[i];
// }

// cout << ans << endl;

// ACTIVITY SELECTOR PROGRAM
// int n;
// cin >> n;
// vector<vector<int>> v;
// for (int i = 0; i < n; i++)
// {
//     int start, end;
//     cin >> start >> end;
//     v.pb({start, end});
// }
// std::sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)
//           { return a[1] < b[1]; });
// int ans = 1;
// int end = v[0][1];
// for (int i = 1; i < n; i++)
// {
//     if (v[i][0] >= end)
//     {
//         ans++;
//         end = v[i][1];
//     }
// }
// cout << ans << endl;

// OPTIMAL MERGE PATTERN
// int n;
// cin >> n;
// vector<int> v;
// for (int i = 0; i < n; i++)
// {
//     int x;
//     cin >> x;
//     v.pb(x);
// }

// std::priority_queue<int, vector<int>, greater<int>> a;
// for (int i = 0; i < n; i++)
// {
//     a.push(v[i]);
// }
// int ans = 0;

// while (a.size() > 1)
// {
//     int x = a.top();
//     a.pop();
//     int y = a.top();
//     a.pop();
//     ans += x + y;
//     a.push(x + y);
// }
// cout << ans << endl;

void solve()
{
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    //     ll n;
    //     cin >> n;
    //     vector<pll> v;
    //     for (int i = 0; i < n; i++)
    //     {
    //         ll a, b;
    //         cin >> a >> b;
    //         v.pb({a, b});
    //     }
    //     ll l, p;
    //     cin >> l >> p;

    //     for (int i = 0; i < n; i++)
    //     {
    //         v[i].first = l - v[i].first;
    //     }
    //     std::sort(v.begin(), v.end());

    //     int ans = 0;
    //     int curr = p;
    //     bool flag = false;
    //     std::priority_queue<ll, vector<ll>> pq;

    //     for (int i = 0; i < n; i++)
    //     {
    //         if (curr >= l)
    //         {
    //             break;
    //         }
    //         while (curr < v[i].first)
    //         {
    //             if (pq.empty())
    //             {
    //                 flag = true;
    //                 break;
    //             }
    //             ans++;
    //             curr += pq.top();
    //             pq.pop();
    //         }
    //         if (flag)
    //         {
    //             break;
    //         }
    //         pq.push(v[i].second);
    //     }
    //     if (flag)
    //     {
    //         cout << -1 << endl;
    //         continue;
    //     }
    //     while (!pq.empty() && curr < l)
    //     {
    //         curr += pq.top();
    //         pq.pop();
    //         ans++;
    //     }

    //     if (curr < l)
    //     {
    //         cout << -1 << endl;
    //         continue;
    //     }
    //     cout << ans << endl;
    // }

    int a = 5, b = 4, c = 3;
    cout << (a & b) << endl;
}

int32_t main()
{

    fast_io;

    solve();

    return 0;
}