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
const int N = (int)(1 * 1e6 + 10);

int fen[N];

void update(int num, int add)
{
    while (num < N)
    {
        fen[num] += add;
        num = num + (num & (-num));
    }
}

int sum(int num)
{
    int s = 0;
    while (num > 0)
    {
        s += fen[num];
        num = num - (num & (-num));
    }
    return s;
}

int find(int k)
{
    int curr = 0, ans = 0, prevSum = 0;
    for (int i = 19; i >= 0; i--)
    {
        if ((curr + (1 << i)) < N && fen[curr + (1 << i)] + prevSum < k)
        {
            ans = curr + (1 << i);
            curr = ans;
            prevSum += fen[curr];
        }
    }
    return ans + 1;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        update(num, 1);
    }

    while (q--)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            update(x, 1);
        }
        else
        {
            x = -1 * x;
            int num = find(x);
            update(num, -1);
        }
    }

    int ans = sum(N);
    if (!ans)
    {
        cout << 0 << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (sum(i) > 0)
            {
                cout << i << endl;
                break;
            }
        }
    }
}

int32_t main()
{
    fast_io;

    solve();

    return 0;
}