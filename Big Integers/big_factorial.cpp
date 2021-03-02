#include <iostream>
#include <vector>
using namespace std;

#define mod 100000009
#define len 1000
#define deb(x) cout << #x << " " << x << "\n";

void printInt(vector<int> &num)
{
    int length = num.size();
    for (int i = length - 1; i >= 0; i--)
        cout << num[i];
    cout << "\n";
}

void big_factorial(int n)
{
    if (n < 0)
    {
        cout << "Not a valid number";
        return;
    }
    if (n <= 0)
    {
        cout << 1 << "\n";
        return;
    }
    vector<int> big_int(0);
    big_int.reserve(len);
    vector<int> big_int2(0);
    big_int2.reserve(len);
    int p = 1;
    big_int.push_back(1);
    int carry = 0, last_digit = 0;
    int intLen = 0;
    while (n > 0)
    {
        intLen = big_int.size();
        for (int i = 0; i < intLen; i++)
        {
            int digit = big_int[i];
            int num = (digit * n) + carry;
            last_digit = num % 10;
            carry = num / 10;
            big_int2.push_back(last_digit);
        }
        while (carry > 0)
        {
            big_int2.push_back((carry % 10));
            carry /= 10;
        }
        big_int.clear();
        big_int = big_int2;
        big_int2.clear();
        n--;
    }

    //print number
    printInt(big_int);
}

/*
    ! Method 2 - Using array of pointer
*/

void Multiply(int *a, int &N, int no)
{
    int carry = 0;
    for (int i = 0; i < N; i++)
    {
        int product = (a[i] * no) + carry;
        a[i] = product % 10;
        carry = product / 10;
    }

    while (carry)
    {
        a[N] = carry % 10;
        N++;
        carry /= 10;
    }
}

void big_fact(int number)
{
    if (number <= 1)
    {
        cout << 1 << "\n";
        return;
    }
    int *a = new int[len];
    a[0] = 1;
    int n = 1;
    for (int i = 2; i <= number; i++)
    {
        Multiply(a, n, i);
    }

    //Print Int
    for (int i = n - 1; i >= 0; i--)
        cout << a[i];
    cout << "\n";

    delete[] a;
    return;
}

int main()
{
    int n;
    cin >> n;
    //big_fact(n);
    big_factorial(n);
    return 0;
}