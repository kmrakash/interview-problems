#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define mod 1000000007
#define vi vector<ll>
#define vii vector<vector<ll>>

vii t = {{1, 1}, {1, 0}};
vi f1 = {1, 1};

vii multiply(vii a, vii b)
{
    vii c(3, vi(3));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int x = 0; x < 2; x++)
            {
                c[i][j] = (c[i][j] + (a[i][x] * b[x][j]) % mod) % mod;
            }
        }
    }
    return c;
}

vii pow(vii A, ll p)
{
    if (p == 1)
        return A;
    if (p & 1)
    {
        return multiply(A, pow(A, p - 1));
    }
    vii x = pow(A, p / 2);
    return multiply(x, x);
}

ll CountWays(ll n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    t = pow(t, n - 1);
    ll res = 0;
    for (int i = 0; i < 2; i++)
    {
        res = (res + (t[0][i] * f1[i]) % mod) % mod;
    }
    return res;
}

int main()
{
    ll n;
    cin >> n;
    cout << CountWays(n) % mod << "\n";
    return 0;
}