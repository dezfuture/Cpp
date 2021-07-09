// find the number of binary trees that exist for a given height h also use modulo to give your answer.

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
const int N = 1e3 + 2;
const int MAXN = 2e5 + 5;

const int M = 1e9 + 7;
long long mod(long long x)
{
    return ((x % M + M) % M);
}
long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}
long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}

ll modPow(ll a, ll b)
{
    if (b == 0)
        return 1LL;
    if (b == 1)
        return a % M;
    ll res = 1;
    while (b)
    {
        if (b % 2 == 1)
            res = mul(res, a);
        a = mul(a, a);
        b = b / 2;
    }
    return res;
}

int lcm(int a, int b)
{
    int c = __gcd(a, b);
    return (a / c) * b;
}

int numberOfBt(int h)
{
    if (h == 0 || h == 1)
    {
        return 1;
    }

    int m = pow(10, 9) + 7;
    int x = numberOfBt(h - 1);
    int y = numberOfBt(h - 2);

    long long res1 = (long long)x * x;
    long long res2 = (long long)x * y * 2;

    int ans1 = (int)(res1 % m);
    int ans2 = (int)(res2 % m);

    int ans = (ans1 + ans2) % m;

    return ans;
}

void solve()
{
    int h;
    cin >> h;
    cout << numberOfBt(h) << endl;
}

signed main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}