/*
    * Space Optimised implementation of Sieve of Eratosthenes
    ! Limitation : bitset can store upto 10^7 numbers only
*/

#include <iostream>
#include <bitset>
#include <vector>
#include <cassert>
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

// Method to check if a large number i.e greater than 10^7 is a prime or not
bool isPrime(ll No)
{

    // base case it is less than 10^7
    if (No <= N)
        return b[No] == 1;

    for (ll i = 0; primes[i] * (ll)primes[i] <= No; i++)
        if (No % primes[i] == 0)
            return false;
    return true;
}

int main()
{
    seive();

    // validating with some Test case : Source -> wikipedia
    assert(isPrime(2147483647) == true);     // 10 digit prime number
    assert(isPrime(999999000001) == true);   // 12 digit prime number
    assert(isPrime(67280421310721) == true); // 14 digit prime number
    assert(isPrime(99999900000) == false);   // 11 digit number

    // print first 100 prime numbers
    for (int i = 0; i < 100; i++)
        cout << primes[i] << " ";
    cout << "\n";
    return 0;
}