/*
    * To compute efficiently base(x) to the power(y) || x^y
    * time complexity : O(log(power))
    * Implementation of recursive and bit masking approach
*/

#include <iostream>
#include <cassert>
using namespace std;

#define lli long long int

// using Bit Masking
lli exponentiation(lli base, lli power)
{

    lli ans = 1;
    lli current = 0;
    while (power) // O(log(power))
    {
        current = power & 1;
        if (current == 1)
            ans *= base;

        power >>= 1;
        base *= base;
    }
    return ans;
}

// Recursive Approach
lli exponentiation2(lli base, lli power)
{

    lli temp;
    if (power == 0)
        return 1;

    temp = exponentiation2(base, power / 2);

    if (power % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        if (power > 0)
            return base * temp * temp;
        else
            return (temp * temp) / base; // handle negative power
    }
}

int main()
{
    // validating with some Test cases
    assert(exponentiation(3, 5) == 243);
    assert(exponentiation(5, 3) == 125);
    assert(exponentiation(2, 6) == 64);
    assert(exponentiation(789, 9) == 6247726042369092341);

    assert(exponentiation2(3, 5) == 243);
    assert(exponentiation2(5, 3) == 125);
    assert(exponentiation2(2, 6) == 64);
    assert(exponentiation2(789, 9) == 6247726042369092341);

    // Take Standard Input
    lli b, p;
    cin >> b >> p;
    cout << exponentiation2(b, p) << "\n";
    return 0;
}