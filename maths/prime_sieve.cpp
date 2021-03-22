/*
    * Implementation of Prime Sieve Algorith
    ! Time Complexity : O(N log log N)
*/

#include <iostream>
using namespace std;
#define ll long long int

int p[100005] = {0};

void primeSieve()
{
    int Max = 100000;
    //not prime
    p[0] = p[1] = 0;

    // only Even number which is prime
    p[2] = 1;

    // Assuming all odd number to prime marking them to 1
    for (int i = 3; i < Max; i += 2)
        p[i] = 1;

    // Marking All multiple of i (Which is prime) to 0 , Denotes Not Prime
    for (ll i = 3; i < Max; i += 2)
        if (p[i] == 1)
            for (ll j = i * i; j < Max; j += i)
                p[j] = 0;
}

// Print Prime Number upto n
void printPrime(int n)
{

    for (int i = 0; i <= n; i++)
        if (p[i] == 1)
            cout << i << " ";
    cout << "\n";
}

int main()
{

    primeSieve();

    int n;
    cin >> n;
    printPrime(n);

    return 0;
}