//  BINARY SEARCH

// N-th root of an integer (use binary search) (square root, cube root, ..)

#include <bits/stdc++.h>
using namespace std;
double multiply(double number, int n)
{
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * number;
    }
    return ans;
}

void getNthRoot(int n, int m)
{
    double low = 1;
    double high = m;
    double eps = 1e-6;

    while ((high - low) > eps)
    {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) < m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    cout << low << " " << high << endl;

    // just to check
    cout << pow(m, (double)(1.0 / (double)n));
}

int main()
{
    int n, m;
    cin >> n >> m;
    getNthRoot(n, m);
    return 0;
}

// the time complexity of the above code is -> O(n*log2(m*10^d)) : considering the precision upto 10 decimal places.