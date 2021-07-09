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
    while (num > 0 && num < N)
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
            int low = 0;
            int high = N;

            while (low < high)
            {
                int mid = (low + high) / 2;
                int val = sum(mid);

                if (x <= val)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            update(low, -1);
        }
    }
    int ans = sum(N);
    if (!ans)
    {
        cout << 0 << endl;
    }
    else
    {
        int low = 0;
        int high = N;

        while (low < high)
        {
            int mid = (low + high) / 2;
            int val = sum(mid);

            if (ans <= val)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << low << endl;
    }
}

int32_t main()
{

    fast_io;

    solve();

    return 0;
}