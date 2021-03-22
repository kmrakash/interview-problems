/*
    * Space Optimised implementation of Sieve of Eratosthenes
*/

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define N 10000005
#define ll long long int

bitset<10000005> b;
vector<int> primes;

void seive()
{

    // Mark all to 1
    b.set(); // 1, 1, 1, ......

    // Special Case Marking the Non Prime
    b[0] = b[1] = 0;

    for (ll i = 2; i < N; i++)
        if (b[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j < N; j += i)
                b[j] = 0;
        }
}

int main()
{
    seive();

    // print first 100 prime numbers
    for (int i = 0; i < 100; i++)
        cout << primes[i] << " ";
    cout << "\n";
    return 0;
}