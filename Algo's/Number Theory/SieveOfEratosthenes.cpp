// The ideal way to store the info. that a number is prime or not

#include <bits/stdc++.h>
using namespace std;

void makeSieve(int n)
{
    bool isPrime[n + 1];
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (isPrime[i] == true)
        {
            cout << i << endl;
        }
    }
}

int32_t main()
{
    int n;
    cin >> n;
    makeSieve(n);
}