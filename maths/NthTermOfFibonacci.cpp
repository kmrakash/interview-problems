/* 
  * Matrix Exponentiation Aprroach To get Nth term of Fibonacci Series
  
  ! Note : Output is mod of 1e9+7 
   
*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
#define ll long long
#define mod 1000000007
#define vi vector<ll>
#define vii vector<vector<ll>>

vii t = {{1, 1}, {1, 0}}; // transformation Matrix for Fibonnacci Series
vi f1 = {1, 0};           // F1 for Fibonacci

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

ll compute(ll n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    vii T = pow(t, n - 1);
    ll res = 0;
    for (int i = 0; i < 2; i++)
        res = (res + (T[0][i] * f1[i]) % mod) % mod;

    return res;
}

// to get Sequence Upto Nth term
void getSeqUptoN(ll n)
{
    for (int i = 0; i <= n; i++)
        cout << compute(i) << " ";
    cout << "\n";
}

int main()
{

    // validating with some test cases
    assert(compute(14) == 377);
    assert(compute(20) == 6765);
    assert(compute(9) == 34);

    // take Input for Nth term of Fibonacci Series
    ll n;
    cin >> n;

    cout << compute(n) << "\n";
    // getSeqUptoN(n);
    return 0;
}