#include <iostream>
#include <cassert>
using namespace std;

int exponentiation(int base, int power)
{

    int ans = 1;
    int current = 0;
    while (power) // O(log(power))
    {
        current = power & 1;
        if (current == 1)
        {
            ans *= base;
        }
        power >>= 1;
        base *= base;
    }
    return ans;
}

int main()
{
    assert(exponentiation(3, 5) == 243);
    assert(exponentiation(5, 3) == 125);
    assert(exponentiation(2, 6) == 64);
    int b, p;
    cin >> b >> p;
    cout << exponentiation(b, p) << "\n";
    return 0;
}