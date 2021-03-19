/*
    * To get the Prime factors of a number
    * Example : 378 : 2 * 3 * 3 * 3 * 9
    * Input : N | where 1 < N < 2,147,483,647 (max value of an integer of the size of 4 bytes)
    * Output : a array of all prime factors
*/

#include <iostream>
#include <cmath>
using namespace std;

void primeFactors(int n)
{

    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }

    if (n > 2)
    {
        cout << n << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    primeFactors(n);
    return 0;
}