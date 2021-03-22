/*
    * To print All the prime Numbers from range 1<=m<n<=1000000000 , where n-m<=100000
    ? We can't sieve since it can give output upto 10^8 , So we will use segment sieve
*/

#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

const int N = 10000000;
int p[N] = {0};
vector<int> primes;

#define deb(x) cout << #x << " " << x << "\n";

// Sieve Eratosthenes
void sieve()
{
    p[0] = p[1] = 1; // not Prime
    for (ll i = 2; i < N; i++)
    {

        if (p[i] == 0)
        {
            primes.push_back(i);

            for (ll j = i * i; j < N; j += i)
                p[j] = 1; // Not Prime
        }
    }
}

int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m; // m <= n
        cin >> m >> n;

        // if (n - m > 100000)
        // {
        //     cout << "Range Exceeded by " << n - m << "\n";
        //     n = m + 100000;
        //     cout << "Thus computing for " << m << " " << n
        //          << "\n";
        // t++;
        // continue;
        // }

        bool segment[n - m + 1];

        for (ll i = 0; i < n - m + 1; i++) // shifting each value by m
        {
            segment[i] = 0;
        }

        // Segment sieve
        for (auto x : primes)
        {
            if (x * x > n)
                break;

            ll start = (m / x) * x;
            if (x >= m and x <= n)
                start = 2 * x;

            for (ll i = start; i <= n; i += (ll)x)
            {
                segment[i - m] = 1;
            }
        }

        // Print The Range
        for (ll i = m; i <= n; i++)
        {
            if (segment[i - m] == 0 and i != 1)
                cout << i << "\n";
        }
    }
    return 0;
}