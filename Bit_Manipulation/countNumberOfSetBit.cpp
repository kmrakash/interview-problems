#include <iostream>
using namespace std;

int countBit(int n)
{
    int count = 0;
    int mask = 1;
    for (int i = 0; i < 32; i++)
    {
        mask = (1 << i);
        if (mask & n)
            count++;
    }
    return count;
}

// * Fails in -1 case
int countBit2(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// ! Most Efficient
// * Does not fail in -1 case
// ? Basic idea here is n & n-1 convert the right most set bit to 0
int countBit3(int n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main()
{
    int num;
    cin >> num;

    cout << countBit3(num) << "\n";
    return 0;
}