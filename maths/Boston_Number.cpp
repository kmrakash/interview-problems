/*
    * Boston Number is a number whose sum of its digit is equal to the sum of its digit in prime factorisation
    * Example : 378 = 2 * 3 * 3 * 3 * 7 then 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7 = 18
    * Input : N | where 1 < N < 2,147,483,647 (max value of an integer of the size of 4 bytes)
    * Output : 1 if satisfy else 0
    ? Time Complexity : 
*/

#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

int digitSum(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += (x % 10);
        x /= 10;
    }
    return res;
}

bool isBoston(int n)
{

    int sum_n = digitSum(n), sum = 0;

    while (n % 2 == 0)
    {
        sum += 2;
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {

            int temp1 = i;
            sum += digitSum(temp1);
            n /= i;
        }
    }

    if (n > 2)
    {

        sum += digitSum(n);
    }

    return sum == sum_n;
}

int main()
{

    // Validating with some test cases
    assert(isBoston(4) == 1);
    assert(isBoston(22) == 1);
    assert(isBoston(378) == 1);
    assert(isBoston(666) == 1);
    assert(isBoston(123) == 0);

    int n;
    cin >> n;

    cout << (isBoston(n) ? "YES" : "NO")
         << "\n";
    return 0;
}